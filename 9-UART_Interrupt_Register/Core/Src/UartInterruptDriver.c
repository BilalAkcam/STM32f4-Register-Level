/*
 * UartInterruptDriver.c
 *
 *  Created on: Dec 12, 2022
 *      Author: Bilal
 */

#include "UartInterruptDriver.h"


volatile void UartInterruptInit(void){

	SET_BIT(USART2->CR1, USART_CR1_RXNEIE);

	NVIC_SetPriority(USART2_IRQn, 0);
	NVIC_EnableIRQ(USART2_IRQn);


}



void USART2_IRQHandler(void) {                                //UART Kesme Servis Fonksiyonu

	if (((USART2->SR & USART_SR_RXNE) != RESET)
			&& ((USART2->CR1 & USART_CR1_RXNEIE) != RESET)) { //Eğer veri geldiyse ve kesme aktif edildiyse if icersine girilir.

		HAL_GPIO_WritePin(GPIOD, GPIO_PIN_15, SET);

		return;
	}

}
