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
	int baudrate = 9600;
	int IWDG_Timeout = 40; //40ms max timeout

	MCU_Clock_Setup();
	Delay_Config();
	Console_Init(USART1, baudrate);
	GPIO_Pin_Setup(GPIOA, 0, GENERAL_PURPOSE_OUTPUT_PUSHPULL, NONE);

	int val;
    /* Loop forever */


	val = IWDG_Init(IWDG_Timeout); //40ms
	if(val == -1)
	{
#if IWD_DEBUG
		printConsole(USART1, "Error: IWDG Init failed. \r\n");
		printConsole(USART1, "File: main.c\r\n");
		printConsole(USART1, "Line: 25\r\n");
#endif
	}
	IWDG_Start();


	for(;;)
	{
		GPIOA -> BSRR |= GPIO_BSRR_BS0;
		IWDG_Prevent_Reset();

	}
}
