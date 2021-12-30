#ifndef TIMER_H
#define TIMER_H

#include "mbed.h"
#include "../loiTruck/loiTruck.h"


bool DWT_timer_start();
bool DWT_timer_stop();

uint32_t DWT_get_CYCCNT();

bool TIM6_timer_start();
bool TIM6_timer_stop();




#endif