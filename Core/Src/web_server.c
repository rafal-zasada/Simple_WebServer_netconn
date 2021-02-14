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

//static void WEbServerServe(xxx);
static void WebServerThread(void *arg);
static void http_server_serve(struct netconn *conn);

// !!! fsdata_custom.c must contain 404.html page otherwise application will crash regardless whether 404 is called or not !!!

void WebServerInit(void)
{
	sys_thread_new("myHTTP", WebServerThread, NULL, DEFAULT_THREAD_STACKSIZE, osPriorityNormal);
}


static void WebServerThread(void *arg)
{
  struct netconn *conn, *newconn;
  err_t err, accept_err;

  /* Create a new TCP connection handle */
  conn = netconn_new(NETCONN_TCP);


	snprintf(GUI_buffer, sizeof(GUI_buffer), " \n\n:))))))))) http_server_netconn_thread\n\n ");
	HAL_UART_Transmit(&huart3, (unsigned char*)&GUI_buffer , strlen(GUI_buffer) + 1, 200);


  if (conn!= NULL)
  {
    /* Bind to port 80 (HTTP) with default IP address */
    err = netconn_bind(conn, NULL, 80);

    if (err == ERR_OK)
    {
      /* Put the connection into LISTEN state */
      netconn_listen(conn);

      while(1)
      {
        /* accept any icoming connection */
        accept_err = netconn_accept(conn, &newconn);
        if(accept_err == ERR_OK)
        {
          /* serve connection */
          http_server_serve(newconn);

          /* delete connection */
          netconn_delete(newconn);
        }
      }
    }
  }
}

static void http_server_serve(struct netconn *conn) // it is the newconn passed here
{
  struct netbuf *inbuf;
  err_t recv_err;
  char* buf;
  u16_t buflen;
  struct fs_file file;

  /* Read the data from the port, blocking if nothing yet there.
   We assume the request (the part we care about) is in one netbuf */
  recv_err = netconn_recv(conn, &inbuf);

  if (recv_err == ERR_OK)
  {
    if (netconn_err(conn) == ERR_OK)
    {
    //	snprintf(GUI_buffer, sizeof(GUI_buffer), " Website service \n ");
    //	HAL_UART_Transmit(&huart3, (unsigned char*)&GUI_buffer , strlen(GUI_buffer) + 1, 200);

      netbuf_data(inbuf, (void**)&buf, &buflen);

    	snprintf(GUI_buffer, sizeof(GUI_buffer), "\n\nbuflen = %d\n", buflen);
    	HAL_UART_Transmit(&huart3, (unsigned char*)&GUI_buffer , strlen(GUI_buffer) + 1, 300);

    	snprintf(GUI_buffer, sizeof(GUI_buffer), "\nString in GUI size =  %d\n", sizeof(GUI_buffer));
    	HAL_UART_Transmit(&huart3, (unsigned char*)&GUI_buffer , strlen(GUI_buffer) + 1, 300);

  	snprintf(GUI_buffer, sizeof(GUI_buffer), "\n %s  ", buf);
  	HAL_UART_Transmit(&huart3, (unsigned char*)&GUI_buffer , strlen(GUI_buffer) + 1, 300);

      /* Is this an HTTP GET command? (only check the first 5 chars, since
      there are other formats for GET, and we're keeping it very simple )*/
      if ((buflen >=5) && (strncmp(buf, "GET /", 5) == 0))
      {

        /* Check if request to get ST.gif */
        if (strncmp((char const *)buf,"GET /js/main.js",15) == 0)
        {
          fs_open(&file, "/js/main.js");
          netconn_write(conn, (const unsigned char*)(file.data), (size_t)file.len, NETCONN_NOCOPY);
          fs_close(&file);
        }

        else if (strncmp((char const *)buf,"GET /cs/styles.css", 18) == 0)
        {
          fs_open(&file, "/cs/styles.css");
          netconn_write(conn, (const unsigned char*)(file.data), (size_t)file.len, NETCONN_NOCOPY);
          fs_close(&file);
        }
        else if((strncmp(buf, "GET /index.html", 15) == 0)||(strncmp(buf, "GET / ", 6) == 0))
        {
          fs_open(&file, "/index.html");
          netconn_write(conn, (const unsigned char*)(file.data), (size_t)file.len, NETCONN_NOCOPY);
          fs_close(&file);
        }
        else if (strncmp((char const *)buf,"GET /data1", 10) == 0)
        {
          const char my_data[] = "Zasada AAAA";
          netconn_write(conn, (const unsigned char*)(my_data), strlen(my_data) + 1, NETCONN_NOCOPY);
          fs_close(&file);
        }
        else
        {
          fs_open(&file, "/404.html");
          netconn_write(conn, (const unsigned char*)(file.data), (size_t)file.len, NETCONN_NOCOPY);
          fs_close(&file);
        }
      }
    }
  }
  /* Close the connection (server closes in HTTP) */
  netconn_close(conn);

  /* Delete the buffer (netconn_recv gives us ownership,
   so we have to make sure to deallocate the buffer) */
  netbuf_delete(inbuf);
}

