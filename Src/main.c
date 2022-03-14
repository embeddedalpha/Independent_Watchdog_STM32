/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Kunal Salvi
 * @brief          : Main program body
 ******************************************************************************
 */

#include <stdint.h>
#include "main.h"
#include "Independent_Watchdog/IDWatchdog.h"





int main(void)
{
	MCU_Clock_Setup();
	Delay_Config();
	Console_Init(USART1, 9600);

	int val;
    /* Loop forever */


	val = IWDG_Init(10000);
	if(val == -1)
	{
		printConsole(USART1, "Error: IWDG Init failed. Line number : 104 \r\n");
	}
	for(;;);
}
