/*
 * UartInterruptDriver.c
 *
 *  Created on: Dec 12, 2022
 *      Author: Bilal Habes Akcam
 */

#include "UartInterruptDriver.h"
#include <stdint.h>
#include <string.h>

int8_t MyIndex = 0;
volatile char  RxBuffer[20];
volatile int8_t dataFlag = 0;



volatile void UartInterruptInit(void){

	SET_BIT(USART2->CR1, USART_CR1_RXNEIE);

	NVIC_SetPriority(USART2_IRQn, 0);
	NVIC_EnableIRQ(USART2_IRQn);


}



void USART2_IRQHandler(void) {                                //UART Kesme Servis Fonksiyonu

	if(((USART2->SR & USART_SR_RXNE) != RESET) && (USART2->CR1 & USART_CR1_RXNEIE) != RESET){

		RxBuffer[MyIndex++] = (uint16_t) USART2->DR;
		if(MyIndex == 7){
			MyIndex = 0;
			dataFlag = 1;
		}
		return;
	}





}
