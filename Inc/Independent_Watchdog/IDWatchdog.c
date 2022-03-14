/*
 * IDWatchdog.c
 *
 *  Created on: 17-Jan-2022
 *      Author: Kunal
 */


#include "IDWatchdog.h"



/*
 * ----------------------------------------------------------------------------------------------------
 * @function : IWDG_Init
 * @brief : Initialization of Independent Watchdog Unit of STM32. The timer is setup so that every tick
 *          is 1ms. The IWDG resets when the downcounter is at 0x0000 i.e, 1ms. The max value would be
 *          4095.
 * @param[in] : timeout ( 0 to 4095)
 * @param[out] : -1 (if any error occurs)
 *               0  (if no error occurs)
 * ----------------------------------------------------------------------------------------------------
 */

int IWDG_Init(int32_t timeout)
{
	// Variable declaration.
	int __timer;
	int __timeout;

	//Variable initialization.
	__timer = 0;
	__timeout = 1000;

	//Check scope of importing parameter.

	if (timeout > 4095)
	{
#if IWD_DEBUG
		printConsole(USART1, "Error: Importing timeout value out of bounds.\r\n");
		printConsole(USART1, "File: IDWatchdog.c\r\n");
		printConsole(USART1, "Line: 37\r\n");
		printConsole(USART1, "Error: timeout = %d\r\n",timeout);
#endif
		return -1;
	}

	// 0x5555 to KR value allows configuration of Independent Watchdog Timer registers.
	IWDG -> KR = 0x5555;

	//Wait till PVU bit is low or till timer overflows.
	while( ((IWDG -> SR & IWDG_SR_PVU) == IWDG_SR_PVU) && (__timer < __timeout))
	{
		// increment timer.
		__timer ++;
	}
	// Check if timer has overflowed. Return back to main program.
	if(__timer > __timeout)
	{
#if IWD_DEBUG
		printConsole(USART1, "Error: Timeout error \r\n");
		printConsole(USART1, "File: IDWatchdog.c\r\n");
		printConsole(USART1, "Line: 52\r\n");
#endif
		return -1;
	}

	// Set Prescaler to 1/32. Minimum
	IWDG -> PR |= IWDG_PR_PR_0 | IWDG_PR_PR_1;

	//Wait till RVU bit is low or till timer overflows.
	__timer = 0;
	while( ((IWDG -> SR & IWDG_SR_RVU) == IWDG_SR_RVU) && (__timer < __timeout))
	{
		// increment timer.
		__timer ++;
	}
	// Check if timer has overflowed. Return back to main program.
	if(__timer > __timeout)
	{
#if IWD_DEBUG
		printConsole(USART1, "Error: Timeout error \r\n");
		printConsole(USART1, "File: IDWatchdog.c\r\n");
		printConsole(USART1, "Line: 73\r\n");
#endif
		return -1;
	}

	IWDG -> RLR = timeout;

	//Stop the watchdog during debugging

	DBGMCU->APB1FZ |= DBGMCU_APB1_FZ_DBG_IWDG_STOP;
	return 0;
}



/*
 * ----------------------------------------------------------------------------------------------------
 * @function : IWDG_Prevent_Reset
 * @brief : Prevents system reset by reloading value to the appropriate register.
 * @param[in] : none
 * @param[out] : none
 * ----------------------------------------------------------------------------------------------------
 */
void IWDG_Prevent_Reset(void)
{
	IWDG -> KR = 0xAAAA;
}


/*
 * ----------------------------------------------------------------------------------------------------
 * @function : IWDG_Start
 * @brief : Starts the independent watchdog. To be called only once after initialization.
 * @param[in] : none
 * @param[out] : none
 * ----------------------------------------------------------------------------------------------------
 */
void IWDG_Start(void)
{
	IWDG -> KR = 0xCCCC;
}

