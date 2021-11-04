/* ------------------------------- RTC Section ------------------------------ */
#include "RTC.h"


void RTC_Alarm_IRQHandler(void){
  //Serial.println("error");  
    HAL_RTC_AlarmIRQHandler(&hrtc);
}

void HAL_RTC_MspInit(){
    RCC_OscInitTypeDef  RCC_OscInitStruct;
    RCC_PeriphCLKInitTypeDef RCC_RTCPeriClkInit;
    
    // turn on LSE
    RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_LSE;
    RCC_OscInitStruct.LSEState = RCC_LSE_ON;
    RCC_OscInitStruct.PLL.PLLState = RCC_PLL_NONE;

    if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK){

    }

    // select LSE as RTCCLK
    RCC_RTCPeriClkInit.PeriphClockSelection = RCC_PERIPHCLK_RTC;
    RCC_RTCPeriClkInit.RTCClockSelection = RCC_RTCCLKSOURCE_LSE;

    if (HAL_RCCEx_PeriphCLKConfig(&RCC_RTCPeriClkInit) != HAL_OK){

    }

    // Enable RTC Clock
    __HAL_RCC_RTC_ENABLE();
    

    // enable EXTI Line 17 for RTC alarm
    hexti.Line = EXTI_LINE_17;
    ExtiConfig.Line = EXTI_LINE_17;
    ExtiConfig.Mode = EXTI_MODE_INTERRUPT;
    ExtiConfig.Trigger = EXTI_TRIGGER_RISING;
    
    if (HAL_EXTI_SetConfigLine(&hexti, &ExtiConfig) != HAL_OK){
      Serial.println("HAL_EXTI_SetConfigLine error!");
    } else {
      Serial.println("HAL_EXTI_SetConfigLine OK!");
    }


    // enable RTC ALarm IRQ in the NVIC
    NVIC_SetVector(RTC_Alarm_IRQn, (uint32_t)&RTC_Alarm_IRQHandler);
    //NVIC_SetPriority(RTC_Alarm_IRQn,1,0);
    NVIC_EnableIRQ(RTC_Alarm_IRQn);   
}


void RTC_Init(void){
    hrtc.Instance = RTC;
    hrtc.Init.HourFormat = RTC_HOURFORMAT_24;
    hrtc.Init.AsynchPrediv = 0x7F; 
    hrtc.Init.SynchPrediv = 0xFF;
    hrtc.Init.OutPut = RTC_OUTPUT_DISABLE;
    hrtc.Init.OutPutPolarity = RTC_OUTPUT_POLARITY_LOW;
    hrtc.Init.OutPutType = RTC_OUTPUT_TYPE_OPENDRAIN;

    if (HAL_RTC_Init(&hrtc) != HAL_OK){
      Serial.println("HAL_RTC_Init error!");
    } else {
      Serial.println("HAL_RTC_Init OK!");
    }
}



void RTC_CalendarConfig(void){
    RTC_TimeTypeDef     RTC_TimeInit;
    RTC_DateTypeDef     RTC_DateInit;

    RTC_TimeInit.Hours = 12;
    RTC_TimeInit.Minutes = 45;
    RTC_TimeInit.Seconds = 0;
    RTC_TimeInit.TimeFormat = RTC_HOURFORMAT12_PM;

    if (HAL_RTC_SetTime(&hrtc, &RTC_TimeInit, RTC_FORMAT_BIN) != HAL_OK){
       Serial.println("HAL_RTC_SetTime error!"); 
    } else  {
      Serial.println("HAL_RTC_SetTime OK!");
    }

    RTC_DateInit.Date = 12;
    RTC_DateInit.Month = RTC_MONTH_JUNE;
    RTC_DateInit.Year = 18;
    RTC_DateInit.WeekDay = RTC_WEEKDAY_TUESDAY;

    if (HAL_RTC_SetDate(&hrtc, &RTC_DateInit, RTC_FORMAT_BIN)!= HAL_OK){
      Serial.println("HAL_RTC_SetDate error!");
    } else  {
      Serial.println("HAL_RTC_SetDate OK!");
    }
}




void HAL_RTC_AlarmAEventCallback(RTC_HandleTypeDef *hrtc){
  // when alarm ring, enable timer interrupt and set alarm 5s later
  if (!alarm){
    // enable interrupt
    TIMER6_Init();
    RTC_AlarmConfig(12);
    alarm = true;
  } else {
    alarm = false;
  }
  
  
}

void RTC_AlarmConfig(uint8_t second){
   //Serial.println("Come Here!");
   RTC_AlarmTypeDef AlarmA_Set;

   memset(&AlarmA_Set,0,sizeof(AlarmA_Set));

   //HAL_RTC_DeactivateAlarm(&hrtc,RTC_ALARM_A);

   //xx:45:09
   AlarmA_Set.Alarm = RTC_ALARM_A;
   AlarmA_Set.AlarmTime.Minutes = 45;
   AlarmA_Set.AlarmTime.Seconds = second;
   AlarmA_Set.AlarmMask = RTC_ALARMMASK_DATEWEEKDAY | RTC_ALARMMASK_HOURS | RTC_ALARMMASK_MINUTES;
   AlarmA_Set.AlarmSubSecondMask = RTC_ALARMSUBSECONDMASK_NONE;
   if ( HAL_RTC_SetAlarm_IT(&hrtc, &AlarmA_Set, RTC_FORMAT_BIN) != HAL_OK)
   {
     //Error_handler();
     //Serial.println("Error");
   } else {
     //Serial.println("set alarm OK");
   }
  
}

/* -------------------------------------------------------------------------- */
