/*
 * buton.c
 *
 *  Created on: Jan 31, 2023
 *      Author: user
 */

#include "buton.h"
#include "stm32f4xx_hal.h"

int buton_state;

void butonInit(void){

	// Buton Başlangıç Ayarları

	RCC->AHB1ENR |= (1<<0);

	GPIOA->MODER &= ~(1<<0);
	GPIOA->MODER &= ~(1<<1);

}


int32_t butonState(void){

	//Buton Durumu

	if(GPIOA->IDR & (1<<0)){
		buton_state = 1;
	}
	else
		buton_state = 0;

	return buton_state;
}


