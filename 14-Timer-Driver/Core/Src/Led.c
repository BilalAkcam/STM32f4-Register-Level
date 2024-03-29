/*
 * Led.c
 *
 *  Created on: Jan 19, 2023
 *      Author: Bilal Habes Akcam
 */



#include "Led.h"


void ledInit(void){

	RCC->AHB1ENR |= (1<<3);

	GPIOD->MODER |= (1<<28);
	GPIOD->MODER &= ~(1<<29);

	GPIOD->OTYPER &= ~(1<<14);

	GPIOD->OSPEEDR |= (1<<28);
	GPIOD->OSPEEDR &= ~(1<<29);

	GPIOD->PUPDR &= ~(1<<28);
	GPIOD->PUPDR &= ~(1<<29);

}


void ledOn(void){

	GPIOD->ODR |= (1<<14);

}


void ledOff(void){

	GPIOD->ODR &= ~(1<<14);
}

