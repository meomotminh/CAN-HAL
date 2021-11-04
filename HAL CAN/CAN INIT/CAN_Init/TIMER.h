#ifndef TIMER_H
#define TIMER_H

#include "mbed.h"
#include "RTC.h" // for alarm variable



void TIMER6_Init(void);

void TIM6_DAC_IRQHandler(void);

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *);

#endif