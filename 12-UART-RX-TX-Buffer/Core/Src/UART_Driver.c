/*
 * UART_Driver.c
 *
 *  Created on: Jan 12, 2023
 *      Author: Bilal Habes Akcam
 */

#include "UART_Driver.h"

char myData[8];
uint8_t i = 0;
uint8_t dataFlag = 0;


void UartEnable(void){

	USART2->CR1 |= (1<<13);
}

void UartRXInterruptInit(void){

	USART2->CR1 |= (1<<5);

	NVIC_EnableIRQ(USART2_IRQn);
	NVIC_SetPriority(USART2_IRQn, 1);

}

void UartTXInterruptInit(void){

	USART2->CR1 |= (1<<7);

	NVIC_EnableIRQ(USART2_IRQn);
	NVIC_SetPriority(USART2_IRQn, 1);

}



void USART2_IRQHandler(void) {

	if ((USART2->SR & USART_SR_RXNE) && (USART2->CR1 & USART_CR1_RXNEIE)) {

		myData[i] = USART2->DR;
		i++;

		if (i == 7) {
			i = 0;
			dataFlag = 1;

		}
	}
}
