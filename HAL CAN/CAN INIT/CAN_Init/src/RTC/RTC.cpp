/* ------------------------------- RTC Section ------------------------------ */
#include "RTC.h"





void RTC_Init(LOITRUCK* loiTruck){
    loiTruck->hrtc.Instance = RTC;
    loiTruck->hrtc.Init.HourFormat = RTC_HOURFORMAT_24;
    loiTruck->hrtc.Init.AsynchPrediv = 0x7F; 
    loiTruck->hrtc.Init.SynchPrediv = 0xFF;
    loiTruck->hrtc.Init.OutPut = RTC_OUTPUT_DISABLE;
    loiTruck->hrtc.Init.OutPutPolarity = RTC_OUTPUT_POLARITY_LOW;
    loiTruck->hrtc.Init.OutPutType = RTC_OUTPUT_TYPE_OPENDRAIN;

    if (HAL_RTC_Init(&loiTruck->hrtc) != HAL_OK){
      Serial.println("HAL_RTC_Init error!");
    } else {
      Serial.println("HAL_RTC_Init OK!");
    }
}



void RTC_CalendarConfig(LOITRUCK* loiTruck){
    RTC_TimeTypeDef     RTC_TimeInit;
    RTC_DateTypeDef     RTC_DateInit;

    RTC_TimeInit.Hours = 12;
    RTC_TimeInit.Minutes = 45;
    RTC_TimeInit.Seconds = 0;
    RTC_TimeInit.TimeFormat = RTC_HOURFORMAT12_PM;

    if (HAL_RTC_SetTime(&loiTruck->hrtc, &RTC_TimeInit, RTC_FORMAT_BIN) != HAL_OK){
       Serial.println("HAL_RTC_SetTime error!"); 
    } else  {
      Serial.println("HAL_RTC_SetTime OK!");
    }

    RTC_DateInit.Date = 12;
    RTC_DateInit.Month = RTC_MONTH_JUNE;
    RTC_DateInit.Year = 18;
    RTC_DateInit.WeekDay = RTC_WEEKDAY_TUESDAY;

    if (HAL_RTC_SetDate(&loiTruck->hrtc, &RTC_DateInit, RTC_FORMAT_BIN)!= HAL_OK){
      Serial.println("HAL_RTC_SetDate error!");
    } else  {
      Serial.println("HAL_RTC_SetDate OK!");
    }
}






void RTC_AlarmConfig(LOITRUCK* loiTruck){
   //Serial.println("Come Here!");
   RTC_AlarmTypeDef AlarmA_Set;

   memset(&AlarmA_Set,0,sizeof(AlarmA_Set));

   //HAL_RTC_DeactivateAlarm(&hrtc,RTC_ALARM_A);

   //xx:45:09
   AlarmA_Set.Alarm = RTC_ALARM_A;
   AlarmA_Set.AlarmTime.Minutes = 45;
   

   if (loiTruck->triggered == false){
     AlarmA_Set.AlarmTime.Seconds = loiTruck->current_Scenario->_input_timestamp;
   } else {
     AlarmA_Set.AlarmTime.Seconds = loiTruck->current_Scenario->_input_timestamp + loiTruck->current_Scenario->_duration;
   }
      
   AlarmA_Set.AlarmMask = RTC_ALARMMASK_DATEWEEKDAY | RTC_ALARMMASK_HOURS | RTC_ALARMMASK_MINUTES;
   AlarmA_Set.AlarmSubSecondMask = RTC_ALARMSUBSECONDMASK_NONE;
   if ( HAL_RTC_SetAlarm_IT(&loiTruck->hrtc, &AlarmA_Set, RTC_FORMAT_BIN) != HAL_OK)
   {
     
   } else {
     
   }
  
}

/* -------------------------------------------------------------------------- */
