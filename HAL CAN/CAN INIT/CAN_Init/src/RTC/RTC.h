#ifndef RTC_H
#define RTC_H

#include "mbed.h"
#include <stm32h747xx.h>
#include "../TIMER/TIMER.h" // for timer6.init()
#include "../loiTruck/loiTruck.h"


//void RTC_Init(LOITRUCK* loiTruck);

//void RTC_CalendarConfig(LOITRUCK* loiTruck);


bool RTC_AlarmConfig(LOITRUCK* loiTruck);

#endif
