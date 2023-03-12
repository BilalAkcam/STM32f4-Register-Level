/*
 * TimerDriver.h
 *
 *  Created on: Dec 16, 2023
 *      Author: BILAL HABES AKCAM
 */

#ifndef INC_TIMERDRIVER_H_
#define INC_TIMERDRIVER_H_

#include "stm32f4xx_hal.h"
#include <stdint.h>

void timerInit(void);
void timerEnable(void);
void timerDisable(void);
void timerAutoReload(uint32_t);




#endif /* INC_TIMERDRIVER_H_ */
