#ifndef RTC_H
#define RTC_H

#include "mbed.h"
#include <stm32h747xx.h>
#include "TIMER.h" // for timer6.init()




void RTC_Init(void);

void HAL_RTC_MspInit(void);

void RTC_CalendarConfig(void);

void HAL_RTC_AlarmAEventCallback(RTC_HandleTypeDef *);

void RTC_AlarmConfig(uint8_t );

#endif
