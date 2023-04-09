/*
 * UART_Driver.h
 *
 *  Created on: Jan 12, 2023
 *      Author: Bilal Habes Akcam
 */

#ifndef INC_UART_DRIVER_H_
#define INC_UART_DRIVER_H_

#include "stm32f4xx_hal.h"

void UartEnable(void);
void UartRXInterruptInit(void);
void UartTXInterruptInit(void);


#endif /* INC_UART_DRIVER_H_ */
