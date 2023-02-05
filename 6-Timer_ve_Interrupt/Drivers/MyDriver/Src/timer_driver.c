/*
 * timer_driver.c
 *
 *  Created on: Oct 27, 2022
 *      Author: Bilal Habes Akcam
 */

#include "timer_driver.h"
#include "stm32f4xx_hal.h"

void timer_init(void){

	//SPESIFIK TIMER FONKSIYONUMUZ ICIN DEGERLER REGISTERLARA YAZILIR.

	__HAL_RCC_TIM3_CLK_ENABLE();
	TIM3->PSC = 15999;
	TIM3->ARR = 499;
	TIM3->DIER = TIM_DIER_UIE;

	NVIC_EnableIRQ(TIM3_IRQn);
	NVIC_SetPriority(TIM3_IRQn,1);
}

void timer_enable(void){
	TIM3->CR1 |= TIM_CR1_CEN;
}

void TIM3_IRQHandler(void){
	TIM3->SR &= ~(TIM_SR_UIF);
	GPIOD->ODR ^= (GPIO_PIN_14);

}
