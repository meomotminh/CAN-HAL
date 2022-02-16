/* ------------------------------- RTC Section ------------------------------ */
#include "RTC.h"










bool RTC_AlarmConfig(LOITRUCK* loiTruck){
   //Serial.println("Come Here!");
   /*
   RTC_AlarmTypeDef AlarmA_Set;

   memset(&AlarmA_Set,0,sizeof(AlarmA_Set));

   //HAL_RTC_DeactivateAlarm(&hrtc,RTC_ALARM_A);

   //xx:45:09
   AlarmA_Set.Alarm = RTC_ALARM_A;
   AlarmA_Set.AlarmTime.Minutes = 45;
   

   if (!loiTruck->triggered){
     AlarmA_Set.AlarmTime.Seconds = loiTruck->current_Scenario->_input_timestamp;
   } else {
     //AlarmA_Set.AlarmTime.Seconds = loiTruck->current_Scenario->_input_timestamp + loiTruck->current_Scenario->_duration;
     AlarmA_Set.AlarmTime.Seconds = loiTruck->current_Scenario->_duration;
   }
      
   AlarmA_Set.AlarmMask = RTC_ALARMMASK_DATEWEEKDAY | RTC_ALARMMASK_HOURS | RTC_ALARMMASK_MINUTES;
   AlarmA_Set.AlarmSubSecondMask = RTC_ALARMSUBSECONDMASK_NONE;
   if ( HAL_RTC_SetAlarm_IT(&loiTruck->hrtc, &AlarmA_Set, RTC_FORMAT_BIN) != HAL_OK)
   {
     return false;
   } else {
     return true;
   }
   */
  
}

/* -------------------------------------------------------------------------- */
