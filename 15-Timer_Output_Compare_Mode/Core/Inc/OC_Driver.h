/*
 * OC_Driver.h
 *
 *  Created on: Dec 18, 2022
 *      Author: BILAL HABES AKCAM
 */

#ifndef INC_OC_DRIVER_H_
#define INC_OC_DRIVER_H_

#include "stm32f4xx_hal.h"
#include <stdint.h>

void OC_gpioInit(void);
void OC_timerInit(void);
void OC_timerEnable(void);
void OC_timerDisable(void);
void OC_timerCompareValue(uint32_t);






#endif /* INC_OC_DRIVER_H_ */
