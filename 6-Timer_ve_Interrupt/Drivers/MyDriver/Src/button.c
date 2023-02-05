/*
 * button.c
 *
 *  Created on: Oct 27, 2022
 *      Author: Bilal Habes Akcam
 */

#include "stm32f4xx_hal.h"
#include "button.h"



void button_init(void){

	__HAL_RCC_GPIOA_CLK_ENABLE();
//	__HAL_RCC_SYSCFG_CLK_ENABLE();


	GPIOA->MODER &= ~(1<<0);
	GPIOA->MODER &= ~(1<<1);

//	SYSCFG->EXTICR[0] |= SYSCFG_EXTICR1_EXTI0_PA;
//
//	EXTI->IMR |= (1<<0);
//	EXTI->RTSR |= (1<<0);
//
//	NVIC_SetPriority(EXTI0_IRQn, 1);
//	NVIC_EnableIRQ(EXTI0_IRQn);



}


//void EXTI0_IRQHandler(void){
//	if(EXTI->PR & (1<<0)){
//		EXTI->PR |= EXTI_PR_PR0;
//		GPIOD->ODR ^= GPIO_PIN_14;
//
//	}
//}





int button_get_state(void){
	if(GPIOA->IDR & (1<<0)){
		return 1;
	}
	else
		return 0;

}
