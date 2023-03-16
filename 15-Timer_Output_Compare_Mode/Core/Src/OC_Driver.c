/*
 * OC_Driver.c
 *
 *  Created on: Dec 18, 2022
 *      Author: BILAL HABES AKCAM
 */


#include "OC_Driver.h"





void OC_gpioInit(void){


	//TIM4'un CH1'i Kullanilmaktadir. (PD12)


	__HAL_RCC_GPIOD_CLK_ENABLE();



	GPIOD->MODER |= (1<<25);
	GPIOD->MODER &= ~(1<<24);


	GPIOD->OTYPER &= ~(1<<12);

	GPIOD->OSPEEDR &= ~(1<<25);
	GPIOD->OSPEEDR |= (1<<24);

	GPIOD->PUPDR &= ~(1<<25);
	GPIOD->PUPDR &= ~(1<<24);


	//PD12 AF2 Olarak Ayarlanir.

	GPIOD->AFR[1] |= (0X2UL<<16);

//	GPIOD->AFR[1] &= ~(1<<16);
//	GPIOD->AFR[1] |= (1<<17);
//	GPIOD->AFR[1] &= ~(1<<18);
//	GPIOD->AFR[1] &= ~(1<<19);




}

void OC_timerInit(void){

	__HAL_RCC_TIM4_CLK_ENABLE();

	TIM4->PSC = 15999;
	TIM4->ARR = 249;
	TIM4->CCR1 = 249;


	TIM4->CCMR1 &= ~(1<<0);					//	TIM4->CCMR1 &= ~TIM_CCMR1_CC1S_0;
	TIM4->CCMR1 &= ~(1<<1);					//	TIM4->CCMR1 &= ~TIM_CCMR1_CC1S_1

	TIM4->CCMR1 |= (1<<4);					//	TIM4->CCMR1 |= TIM_CCMR1_OC1M_0;
	TIM4->CCMR1 |= (1<<5);					//	TIM4->CCMR1 |= TIM_CCMR1_OC1M_1;
	TIM4->CCMR1 &= ~(1<<6);					//	TIM4->CCMR1 &= ~TIM_CCMR1_OC1M_2;

	TIM4->CCER |= (1<<0);					//	TIM4->CCER |= TIM_CCER_CC1E;
	TIM4->CCER &= ~(1<<1);					//	TIM4->CCER |= TIM_CCER_CC1P;



}




void OC_timerEnable(void){

	TIM4->CR1 |= TIM_CR1_CEN;	//TIM4->CR1 |= (1<<0);
}

void OC_timerDisable(void){

	TIM4->CR1 &= ~(1<<0);

}


void OC_timerCompareValue(uint32_t);
