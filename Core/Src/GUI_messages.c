/*
 * GUI_messages.c
 *
 *  Created on: Feb 12, 2021
 *      Author: Rafal
 */

#include "GUI_messages.h"
#include <string.h>
#include "lwip.h"
#include "main.h"

extern struct netif gnetif;
extern UART_HandleTypeDef huart3;

void GUI_taskThread(void const * argument)
{
	while(1)
	{
		if(HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_13) == 1)
		{
			// print IP address
			snprintf(GUI_buffer, sizeof(GUI_buffer) - 1, "IP = %lu\n\n", gnetif.ip_addr.addr);
			HAL_UART_Transmit(&huart3, (unsigned char*)GUI_buffer, strlen(GUI_buffer) + 1, 200);

			// print freeRTOS statistics
			osThreadList((unsigned char*)GUI_buffer);
			HAL_UART_Transmit(&huart3, (unsigned char*)GUI_buffer, strlen(GUI_buffer) + 1, 200);

			snprintf(GUI_buffer, sizeof(GUI_buffer) - 1, "\nxPortGetFreeHeapSize() = %u\n\n", xPortGetFreeHeapSize());
			HAL_UART_Transmit(&huart3, (unsigned char*)GUI_buffer, strlen(GUI_buffer) + 1, 200);

			snprintf(GUI_buffer, sizeof(GUI_buffer) - 1, "xPortGetMinimumEverFreeHeapSize() = %u\n\n", xPortGetMinimumEverFreeHeapSize());
			HAL_UART_Transmit(&huart3, (unsigned char*)GUI_buffer, strlen(GUI_buffer) + 1, 200);

			osDelay(500);
		}
		osDelay(100);
	}
}

void vApplicationStackOverflowHook( xTaskHandle xTask, signed char *pcTaskName )
{
	snprintf(GUI_buffer, sizeof(GUI_buffer) - 1, "Overflow detected in: %s\n", pcTaskName);
	HAL_UART_Transmit(&huart3, (unsigned char*)GUI_buffer, strlen(GUI_buffer) + 1, 200);
	osDelay(1000);
}

// Note: osThreadList shows only used heap memory (inside task) instead of defined stack size. If sum of all defined stack sizes is more than configTOTAL_HEAP_SIZE it will cause problems!

// Defined stack sizes (for now):
// tcpip_thread,  TCPIP_THREAD_STACKSIZE - 1024
// what about queues ?
// INTERFACE_THREAD_STACK_SIZE ( 350 )
// IDLE task - apparently = configMINIMAL_STACK_SIZE - 128

/*
Call xPortGetFreeHeapSize(), create your tasks queues semaphores etc. then call xPortGetFreeHeapSize() again to find the difference. http://www.freertos.org/a00111.html
Actually, there’s also
xPortGetMinimumEverFreeHeapSize()
but only when using heap4
*/


