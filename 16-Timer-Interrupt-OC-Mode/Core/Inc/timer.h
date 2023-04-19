/*
 * timer.h
 *
 *  Created on: Apr 19, 2023
 *      Author: Bilal Habes Akcam
 */

#ifndef INC_TIMER_H_
#define INC_TIMER_H_

#include "stm32f4xx_hal.h"


void timerInit(void);
void timerEnable(void);
void timerDisable(void);
void timerOC_Init(void);
void timerSetPeriod(uint32_t);
void timerInterruptEnable(void);
uint32_t timerGetCounterVal(void);



#endif /* INC_TIMER_H_ */
