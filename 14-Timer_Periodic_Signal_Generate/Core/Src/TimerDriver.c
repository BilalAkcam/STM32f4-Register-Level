/*
 * TimerDriver.c
 *
 *  Created on: Dec 16, 2022
 *      Author: BILAL HABES AKCAM
 */

#include "TimerDriver.h"


void timerInit(void){

	__HAL_RCC_TIM3_CLK_ENABLE();
	TIM3->PSC = 15999;		//16 Mhz'lik timer clk'u 15999'a Bolunerek Her Adimi 1 ms Olan Sinyal Elde Edilmis Olur.
	TIM3->ARR = 499;		//Her 499 Degerinde, Update Gerceklesir. (500 ms)


	TIM3->DIER |= (1<<0);	// TIM3->DIER |= TIM_DIER_UIE


	NVIC_EnableIRQ(TIM3_IRQn);
	NVIC_SetPriority(TIM3_IRQn, 1);

}



void timerEnable(void){

	TIM3->CR1 |= (1<<0);		// TIM3->CR1 |= TIM_CR1_CEN;

}
void timerDisable(void){

	TIM3->CR1 &=  ~(1<<0);		// TIM3->CCR1 &= ~TIM_CR1_CEN;
}



void timerAutoReload(uint32_t reloadValue){

	TIM3->ARR |= reloadValue;

}





void TIM3_IRQHandler(void){

	TIM3->SR &= ~(1<<0);		//TIM3->SR &= ~TIM_SR_UIF;
	GPIOD->ODR ^= (1<<15);		//15. Her Kesme Aninda D portunun 15. Bitine Blink Yaptirilir.
}


