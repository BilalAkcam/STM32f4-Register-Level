/*
 * timer.c
 *
 *  Created on: Apr 19, 2023
 *      Author: Bilal Habes Akcam
 */


/*   Used TIM2 CH2   */

#include "timer.h"



void timerInit(void)
{

	// RCC ENABLE
	__HAL_RCC_TIM2_CLK_ENABLE();


	//	A step is 1 ms
	TIM2->PSC = 15999;
	TIM2->ARR = 249;
}

void timerOC_Init(void)
{

	__HAL_RCC_GPIOA_CLK_ENABLE();

	//	GPIO SETTINGS
	GPIOA->MODER |= (1<<3);
	GPIOA->AFR[0] |= (1<<4);

	//	COMPARE SETTINGS
	TIM2->CCMR1 &= ~(1<<9);
	TIM2->CCMR1 &= ~(1<<8);

	TIM2->CCER |= (1<<4);
	TIM2->CCER &= ~(1<<5);

	TIM2->CCR2 = 249;
	TIM2->CCMR1 |= (3<<12);

}


void timerEnable(void)
{
	TIM2->CR1 |= TIM_CR1_CEN;
}


void timerDisable(void)
{
	TIM2->CR1 &= ~TIM_CR1_CEN;
}



void timerSetPeriod(uint32_t timPeriod)
{
	TIM2->ARR = timPeriod - 1;
	TIM2->CCR2 = timPeriod - 1;

}

uint32_t timerGetCounterVal(void)
{
	return (TIM2->CNT);
}


void timerInterruptEnable(void)
{
	TIM2->DIER |= (1<<0);

	NVIC_EnableIRQ(TIM2_IRQn);
	NVIC_SetPriority(TIM2_IRQn, 1);

}

void TIM2_IRQHandler(void){

	TIM2->SR &= ~TIM_SR_UIF;
	GPIOD->ODR ^= (1<<14);
}



