/*
 * led.c
 *
 *  Created on: Oct 27, 2022
 *      Author: user
 */
#include "led.h"
#include "stm32f4xx_hal.h"
#include "button.h"

void led_init(void){

	__HAL_RCC_GPIOD_CLK_ENABLE();




	GPIOD->MODER &= ~(1<<29);
	GPIOD->MODER |= (1<<28);

	GPIOD->OTYPER = 0;
	GPIOD->OSPEEDR = 0;
}

void led_status(void){
	if(button_get_state()==1){
		GPIOD->ODR |= (1<<14);
		HAL_Delay(250);
		GPIOD->ODR &= ~(1<<14);
		HAL_Delay(250);


	}
	else
		GPIOD->ODR &= ~(1<<14);


}
