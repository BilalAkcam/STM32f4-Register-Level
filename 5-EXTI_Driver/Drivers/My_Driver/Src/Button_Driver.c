/*
 * Button_Driver.c
 *
 *  Created on: Oct 13, 2022
 *      Author: Bilal Habes Akcam
 */


#include "stm32f4xx_hal.h"
#include "Button_Driver.h"



void Button_DriverInt_Init(){

	//***CLOCK AYARLARI***//

	__HAL_RCC_GPIOA_CLK_ENABLE();
	__HAL_RCC_SYSCFG_CLK_ENABLE();


	//***GPIO AYARLARI***//

	GPIOA->MODER &= ~(1<<0);
	GPIOA->MODER &= ~(1<<1);

	//***CONFIG AYARLARI***//

	SYSCFG->EXTICR[0] |= SYSCFG_EXTICR1_EXTI0_PA;


	//EXTI AYARLARI

	//***MASKE KALDIRILDI***//

	EXTI->IMR |= (1<<0);

	//***EXTI TRIGGER SETTINGS***//

	EXTI->RTSR |= EXTI_RTSR_TR0;


	//***NVIC AYARLARI***//

	NVIC_SetPriority(EXTI0_IRQn, 1);
	NVIC_EnableIRQ(EXTI0_IRQn);

}


	//KESME SERVIS FONKSIYONU

void EXTI0_IRQHandler(void){
if((EXTI->PR &EXTI_PR_PR0) == EXTI_PR_PR0){
	EXTI->PR |= EXTI_PR_PR0;
	GPIOD->ODR ^= GPIO_PIN_15;

}
}



int Button_Get_State(void){

	if(GPIOA->IDR & 1<<0){
		return 1;
	}
	else
		return 0;

}

