/*
 * IDWatchdog.h
 *
 *  Created on: 17-Jan-2022
 *      Author: Kunal
 */

#ifndef INDEPENDENT_WATCHDOG_IDWATCHDOG_H_
#define INDEPENDENT_WATCHDOG_IDWATCHDOG_H_


#include "main.h"

#define IWD_DEBUG 0


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
int IWDG_Init(int32_t timeout);


/*
 * ----------------------------------------------------------------------------------------------------
 * @function : IWDG_Prevent_Reset
 * @brief : Prevents system reset by reloading value to the appropriate register.
 * @param[in] : none
 * @param[out] : none
 * ----------------------------------------------------------------------------------------------------
 */
void IWDG_Prevent_Reset(void);


/*
 * ----------------------------------------------------------------------------------------------------
 * @function : IWDG_Start
 * @brief : Starts the independent watchdog. To be called only once after initialization.
 * @param[in] : none
 * @param[out] : none
 * ----------------------------------------------------------------------------------------------------
 */
void IWDG_Start(void);


#endif /* INDEPENDENT_WATCHDOG_IDWATCHDOG_H_ */
