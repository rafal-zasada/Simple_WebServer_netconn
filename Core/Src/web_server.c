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

void WebServerInit(void)
{
	sys_thread_new("myHTTP", WebServerThread, NULL, DEFAULT_THREAD_STACKSIZE, osPriorityNormal);
}


static void WebServerThread(void *arg)
{
	struct netconn *connection, *newconnection;
	err_t err;

	// Create a new TCP connection handle
	connection = netconn_new(NETCONN_TCP);

	if (connection != NULL)
	{
		// Bind connection to port 80 (HTTP) with default IP address
		err = netconn_bind(connection, NULL, 80);

		if (err == ERR_OK)
		{
			// Put connection into LISTEN state
			netconn_listen(connection);

			while(1)
			{
				netconn_accept(connection, &newconnection);

				snprintf(GUI_buffer, sizeof(GUI_buffer) - 1, "New connection\n");
				HAL_UART_Transmit(&huart3, (unsigned char*)GUI_buffer, strlen(GUI_buffer) + 1, 200);

				struct fs_file file;

				fs_open(&file, "/index.html");
				netconn_write(newconnection, (const unsigned char*)(file.data), (size_t)file.len, NETCONN_NOCOPY);
				fs_close(&file);

				netconn_close(newconnection);

				// delete connection
				netconn_delete(newconnection);

			}
		}
	}
}

