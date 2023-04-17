/*
 * CircularBufferDriver.h
 *
 *  Created on: Jan 11, 2023
 *      Author: Bilal Akcam
 */

#ifndef INC_CIRCULARBUFFERDRIVER_H_
#define INC_CIRCULARBUFFERDRIVER_H_

#include "stm32f4xx_hal.h"


void UART_Enable(void);
void UART_Disable(void);

void UART_RXInterruptEnable(void);
void UART_TXInterruptEnable(void);

void sendData(uint8_t);




#endif /* INC_CIRCULARBUFFERDRIVER_H_ */
