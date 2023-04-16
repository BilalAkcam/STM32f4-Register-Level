/*
 * CircularBufferDriver.c
 *
 *  Created on: Jan 11, 2023
 *      Author: Bilal Akcam
 */


#include "CircularBufferDriver.h"

#define BUFFER_SIZE 8



typedef struct {

	int32_t buffer[BUFFER_SIZE];
	int8_t headPointer;
	int8_t tailPointer;

}UART_Buffer_t;


UART_Buffer_t UART_Buffer_TX;
UART_Buffer_t UART_Buffer_RX;






void UART_Enable(void){

	USART2->CR1 |= (1<<13);
//	SET_BIT(USART2->CR1 ,USART_CR1_UE);

}



void UART_Disable(void){

	USART2->CR1 &= ~(1<<13);

}



void UART_RXInterruptEnable(void){

	USART2->CR1 |= (1<<5);

	NVIC_EnableIRQ(USART2_IRQn);
	NVIC_SetPriority(USART2_IRQn, 1);

}


void UART_TXInterruptEnable(void){

	USART2->CR1 |= (1<<7);

	NVIC_EnableIRQ(USART2_IRQn);
	NVIC_SetPriority(USART2_IRQn, 1);


}


void sendData(uint8_t data){

	UART_Buffer_TX.buffer[UART_Buffer_TX.headPointer++] = data;

	if(UART_Buffer_TX.headPointer == BUFFER_SIZE){

		UART_Buffer_TX.headPointer = 0;
	}
	USART2->CR1 |= USART_CR1_TXEIE;

}



void USART2_IRQHandler(void){

	if((USART2->CR1 & USART_CR1_RXNEIE) && (USART2->SR & USART_SR_RXNE)){

		UART_Buffer_RX.buffer[UART_Buffer_RX.headPointer++] = USART2->DR;


		if(UART_Buffer_RX.headPointer == BUFFER_SIZE){

			UART_Buffer_RX.headPointer = 0;

		}

		return ;
	}


	else if((USART2->CR1 & USART_CR1_TXEIE) && (USART2->SR & USART_SR_TXE)){

		if(UART_Buffer_TX.tailPointer != UART_Buffer_TX.headPointer){

			USART2->DR = UART_Buffer_TX.buffer[UART_Buffer_TX.tailPointer++];

			if(UART_Buffer_TX.tailPointer == UART_Buffer_TX.headPointer){

				UART_Buffer_TX.tailPointer = 0;
			}
			return ;
		}

		else{
			USART2->CR1 &= ~USART_CR1_TXEIE;

		}


	}


}








