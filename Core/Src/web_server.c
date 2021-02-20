/*
 * web_server.c
 *
 *  Created on: Feb 12, 2021
 *      Author: Rafal
 */

#include "web_server.h"
#include "api.h"
#include "lwip/apps/fs.h"
#include "GUI_messages.h"
#include "string.h"

extern UART_HandleTypeDef huart3;

static void WebServerThread(void *arg);
static void http_server_serve(struct netconn *conn);
static void http_server_serve_dynamic_data(struct netconn *conn);

// !!! fsdata_custom.c must contain 404.html page otherwise application will crash regardless whether 404 is called or not !!!

void WebServerInit(void)
{
	sys_thread_new("myHTTP", WebServerThread, NULL, DEFAULT_THREAD_STACKSIZE, osPriorityNormal);
}

static void WebServerThread(void *arg)
{
	struct netconn *conn, *newconn;
	err_t err, accept_err;

	conn = netconn_new(NETCONN_TCP); // Create a new TCP connection handle
	if(conn!= NULL)
	{
		err = netconn_bind(conn, NULL, 80);	// Bind to port 80 (HTTP) with default IP address

		if(err == ERR_OK)
    	{
			netconn_listen(conn);			// Put the connection into LISTEN state

			while(1)
			{
				accept_err = netconn_accept(conn, &newconn);	// accept any incoming connection

				if(accept_err == ERR_OK)
				{
					http_server_serve(newconn);		// serve connection
					netconn_delete(newconn);		// delete connection
				}
			}
		}
	}
}

static void http_server_serve(struct netconn *conn) // new connection service
{
	// debug start
	// snprintf(GUI_buffer, sizeof(GUI_buffer), " \nServing HTTP request \n ");
	// HAL_UART_Transmit(&huart3, (unsigned char*)&GUI_buffer , strlen(GUI_buffer) + 1, 200);
	// debug end

	struct netbuf *inbuf;
	err_t recv_err;
	char* buf;			// just a pointer without copying inbuf ???
	u16_t buflen;
	struct fs_file file;

	recv_err = netconn_recv(conn, &inbuf); // Read the data from the port, blocking if nothing yet there. We assume the request (the part we care about) is in one netbuf

	if(recv_err == ERR_OK)
	{
		if(netconn_err(conn) == ERR_OK)
		{
			 netbuf_data(inbuf, (void**)&buf, &buflen); // Get the data pointer and length of the data inside a netbuf.


			// debug start
			// print whole input buffer
			snprintf(GUI_buffer, sizeof(GUI_buffer), "\n\n%s \n\n ", buf);		// buf is not \0 terminated hence need to use buflen for UART transmit !
			HAL_UART_Transmit(&huart3, (unsigned char*)&GUI_buffer , buflen, 200); //

			// print zise of the input buffer
			snprintf(GUI_buffer, sizeof(GUI_buffer), "\n buflen =  %d\n\n ", buflen);
			HAL_UART_Transmit(&huart3, (unsigned char*)&GUI_buffer , strlen(GUI_buffer) + 1, 200);
			// debug end


			if((buflen >= 5) && (strncmp(buf, "GET /", 5) == 0)) // Is this an HTTP GET command? (only check the first 5 chars, since there are other formats for GET, and we're keeping it very simple. Rest of the header is ignored )
			{
				if(strncmp((char const *)buf,"GET /js/main.js",15) == 0) // Check if request to get ST.gif
				{
					fs_open(&file, "/js/main.js");
					netconn_write(conn, (const unsigned char*)(file.data), (size_t)file.len, NETCONN_NOCOPY);
					fs_close(&file);
				}

				else if(strncmp((char const *)buf,"GET /cs/styles.css", 18) == 0)
				{
					fs_open(&file, "/cs/styles.css");
					netconn_write(conn, (const unsigned char*)(file.data), (size_t)file.len, NETCONN_NOCOPY);
					fs_close(&file);
				}

				else if((strncmp(buf, "GET /pic1.jpg", 13) == 0))
				{
					fs_open(&file, "/pic1.jpg");
					netconn_write(conn, (const unsigned char*)(file.data), (size_t)file.len, NETCONN_NOCOPY);
					fs_close(&file);
				}

				else if((strncmp(buf, "GET /index.html", 15) == 0)||(strncmp(buf, "GET / ", 6) == 0))
				{
					fs_open(&file, "/index.html");
					netconn_write(conn, (const unsigned char*)(file.data), (size_t)file.len, NETCONN_NOCOPY);
					fs_close(&file);
				}

				else if(strncmp((char const *)buf,"GET /data1", 10) == 0)
				{
					http_server_serve_dynamic_data(conn);
				}

				else
				{
					fs_open(&file, "/404.html");
					netconn_write(conn, (const unsigned char*)(file.data), (size_t)file.len, NETCONN_NOCOPY);
					fs_close(&file);
				}
			}

			if((buflen >= 6) && (strncmp(buf, "POST /", 6) == 0)) // check if it is HTTP POST request
				{
					char *receivedPOST = strstr(buf, "\r\n\r\n");

					if(receivedPOST != NULL)
					{
						snprintf(GUI_buffer, sizeof(GUI_buffer), "\n\n POST request received \n\n ");		// buf is not \0 terminated hence need to use buflen for UART transmit !
						HAL_UART_Transmit(&huart3, (unsigned char*)&GUI_buffer , strlen(GUI_buffer) , 200); //


						receivedPOST += 4; // skip 2 new line characters and point to POST body

						u16_t POST_length = buflen - (receivedPOST - buf); // subtract header length from the length of whole message

						HAL_UART_Transmit(&huart3, (unsigned char*)receivedPOST, POST_length, 200);

					// below
						char *responseToPOST = 	"HTTP/1.1 200 OK\r\n"
												"Content-Type: text/html\r\n"
												"Access-Control-Allow-Origin:* \r\n" 	// allow access for other clients than from within this webserver
												"\r\n";

						netconn_write(conn, (const unsigned char*)responseToPOST, strlen(responseToPOST), NETCONN_NOCOPY);
					}
				}
		}
	}

	netconn_close(conn); // Close the connection (server closes in HTTP)
	netbuf_delete(inbuf); // Delete the buffer (netconn_recv gives us ownership, so we have to make sure to deallocate the buffer)
}


int voltage1 = 233;
int voltage2 = 223;
int voltage3 = 255;

void http_server_serve_dynamic_data(struct netconn *conn)
{
	char JSON_data[200] = {0};

	snprintf(JSON_data, sizeof(JSON_data),  "{\"voltage1\" : \"%d\","
											"\"voltage2\" : \"%d\","
											"\"voltage3\" : \"%d\""
											"}", ++voltage1, --voltage2, ++voltage3);

	char header1_and_JSON_data[300] = 	"HTTP/1.1 200 OK\r\n"
										"Content-Type: text/html\r\n"
										"Access-Control-Allow-Origin:* \r\n" 	// allow access for other clients than from within this webserver
									//	"Content-Length : 20\r\n"				// not necessary, length will be established in other way
									//	"Connection: keep-alive \r\n";			// purpose?
										"\r\n";  								// second\r\n mandatory to mark end of header!

	strcat(header1_and_JSON_data, JSON_data);
	netconn_write(conn, (const unsigned char*)(header1_and_JSON_data), strlen(header1_and_JSON_data), NETCONN_NOCOPY);

	//debug

	snprintf(GUI_buffer, sizeof(GUI_buffer), "\n------ Start of server response to GET data1 ------- \n ");
	HAL_UART_Transmit(&huart3, (unsigned char*)&GUI_buffer , strlen(GUI_buffer) + 1, 200);
	HAL_UART_Transmit(&huart3, (unsigned char*)&header1_and_JSON_data , strlen(header1_and_JSON_data) + 1, 300);


}

