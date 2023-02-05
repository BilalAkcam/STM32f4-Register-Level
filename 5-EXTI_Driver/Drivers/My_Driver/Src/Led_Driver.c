/*
 * Led_Driver.c
 *
 *  Created on: Oct 13, 2022
 *      Author: Bilal Habes Akcam
 */

#include "Led_Driver.h"
#include "stm32f4xx_hal.h"
#include "Button_Driver.h"

void Led_Driver_Init(void){

	RCC->AHB1ENR |= (1<<3);

	GPIOD->MODER |= (1<<30);
	GPIOD->MODER &= ~(1<<31);

	GPIOD->OTYPER &= ~(1<<15);

	GPIOD->OSPEEDR &= ~(1<<31);
	GPIOD->OSPEEDR &= ~(1<<30);

}

void Led_State(void){


	if(Button_Get_State()==1){
		GPIOD->ODR |= (1<<15);
		HAL_Delay(300);
		GPIOD->ODR &= ~(1<<15);
		HAL_Delay(300);

	}
	else
		GPIOD->ODR &= ~(1<<15);



}
