#include "Arduino.h"
#include "mbed.h"
#include <ThreadDebug.h>
#include "RPC_internal.h"  // for RPC call

#include "loiTruck.h"




/* ------------------------------ RTC CALLBACK ------------------------------ */

#ifdef CORE_CM7
void setup(){
  
  HAL_Init();
  RPC1.begin();
  Serial.begin(115200);
  while(!Serial);
  
  bootM4(); 
  randomSeed(analogRead(A0)); // Initializes the pseudo-random number generator

}

void loop(){
  //Serial.println("***********");
  String buffer = "";
    while (RPC1.available()) {
      //Serial.println("??");
      buffer += (char)RPC1.read(); // Fill the buffer with characters
    }

    if (buffer.length() > 0) {
      Serial.print(buffer);
    }  
}
#endif

/* -------------------------------------------------------------------------- */
/*                                 CODE FOR M4                                */
/* -------------------------------------------------------------------------- */

#ifdef CORE_CM4

#define RPC1 RPC1


LOITRUCK loiTruck = LOITRUCK();

/* ------------------------------ RTC CALLBACK ------------------------------ */


void RTC_Init(LOITRUCK* loiTruck){
    loiTruck->hrtc.Instance = RTC;
    loiTruck->hrtc.Init.HourFormat = RTC_HOURFORMAT_24;
    loiTruck->hrtc.Init.AsynchPrediv = 0x7F; 
    loiTruck->hrtc.Init.SynchPrediv = 0xFF;
    loiTruck->hrtc.Init.OutPut = RTC_OUTPUT_DISABLE;
    loiTruck->hrtc.Init.OutPutPolarity = RTC_OUTPUT_POLARITY_LOW;
    loiTruck->hrtc.Init.OutPutType = RTC_OUTPUT_TYPE_OPENDRAIN;

    if (HAL_RTC_Init(&loiTruck->hrtc) != HAL_OK){
      RPC1.println("HAL_RTC_Init error!");
    } else {
      RPC1.println("HAL_RTC_Init OK!");
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
       RPC1.println("HAL_RTC_SetTime error!"); 
    } else  {
       RPC1.println("HAL_RTC_SetTime OK!");
    }

    RTC_DateInit.Date = 12;
    RTC_DateInit.Month = RTC_MONTH_JUNE;
    RTC_DateInit.Year = 18;
    RTC_DateInit.WeekDay = RTC_WEEKDAY_TUESDAY;

    if (HAL_RTC_SetDate(&loiTruck->hrtc, &RTC_DateInit, RTC_FORMAT_BIN)!= HAL_OK){
       RPC1.println("HAL_RTC_SetDate error!");
    } else  {
       RPC1.println("HAL_RTC_SetDate OK!");
    }
}



bool RTC_AlarmConfig(LOITRUCK* loiTruck){
   //RPC1.println("Come Here!");
   RTC_AlarmTypeDef AlarmA_Set;

   memset(&AlarmA_Set,0,sizeof(AlarmA_Set));

   //HAL_RTC_DeactivateAlarm(&hrtc,RTC_ALARM_A);

   //xx:45:09
   AlarmA_Set.Alarm = RTC_ALARM_A;
   AlarmA_Set.AlarmTime.Minutes = 45;
   

   if (loiTruck->triggered == false){
     //AlarmA_Set.AlarmTime.Seconds = loiTruck->current_Scenario->_input_timestamp;
     AlarmA_Set.AlarmTime.Seconds = 10;
   } else {
     //AlarmA_Set.AlarmTime.Seconds = loiTruck->current_Scenario->_input_timestamp + loiTruck->current_Scenario->_duration;
     AlarmA_Set.AlarmTime.Seconds = 10;
   }
      
   AlarmA_Set.AlarmMask = RTC_ALARMMASK_DATEWEEKDAY | RTC_ALARMMASK_HOURS | RTC_ALARMMASK_MINUTES;
   AlarmA_Set.AlarmSubSecondMask = RTC_ALARMSUBSECONDMASK_NONE;
   if ( HAL_RTC_SetAlarm_IT(&loiTruck->hrtc, &AlarmA_Set, RTC_FORMAT_BIN) != HAL_OK)
   {
     return false;
   } else {
     return true;
   }
  
}

void HAL_RTC_AlarmAEventCallback(RTC_HandleTypeDef *hrtc){
  /* ----- when alarm ring, enable timer interrupt and set alarm 5s later ----- */
  loiTruck.alarm = true;
  RPC1.println("err");
  
  if (!loiTruck.triggered){
    /* --------------------------- 1st time triggered --------------------------- */
    
    //TIMER6_Init(&loiTruck);
    loiTruck.triggered = true;  // for logic in RTC_AlarmConfig function
    RTC_AlarmConfig(&loiTruck);    
        
  } else {
    /* ----------------------------- Deactive Alarm ----------------------------- */
    loiTruck.triggered = false; 
    //HAL_RTC_DeactivateAlarm(&loiTruck.hrtc, RTC_ALARM_A);
    loiTruck.finish_Scenario = true;
  }  
}

void HAL_RTC_MspInit(void){
    RCC_OscInitTypeDef  RCC_OscInitStruct;
    RCC_PeriphCLKInitTypeDef RCC_RTCPeriClkInit;
    
    
    /* ------------------------------- turn on LSE ------------------------------ */
    RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_LSE;
    RCC_OscInitStruct.LSEState = RCC_LSE_ON;
    //RCC_OscInitStruct.PLL.PLLState = RCC_PLL_NONE;

    if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK){
      RPC1.println("M4: HAL_RCC_OscConfig error!");
    }

    /* -------------------------- select LSE as RTCCLK -------------------------- */
    RCC_RTCPeriClkInit.PeriphClockSelection = RCC_PERIPHCLK_RTC;
    RCC_RTCPeriClkInit.RTCClockSelection = RCC_RTCCLKSOURCE_LSE;

    if (HAL_RCCEx_PeriphCLKConfig(&RCC_RTCPeriClkInit) != HAL_OK){
       RPC1.println("M4: HAL_RCCEx_PeriphCLKConfig error!");
    }

    /* ---------------------------- Enable RTC Clock ---------------------------- */
    __HAL_RCC_RTC_ENABLE();
    
    
    // enable EXTI Line 17 for RTC alarm
    loiTruck.hexti.Line = EXTI_LINE_17;
    loiTruck.ExtiConfig.Line = EXTI_LINE_17;
    loiTruck.ExtiConfig.Mode = EXTI_MODE_INTERRUPT;
    loiTruck.ExtiConfig.Trigger = EXTI_TRIGGER_RISING;
    
    if (HAL_EXTI_SetConfigLine(&loiTruck.hexti, &loiTruck.ExtiConfig) != HAL_OK){
      RPC1.println("M4: HAL_EXTI_SetConfigLine error!");
    } else {
      RPC1.println("M4: HAL_EXTI_SetConfigLine OK!");
    }


    /* -------------------- enable RTC ALarm IRQ in the NVIC -------------------- */
    NVIC_SetVector(RTC_Alarm_IRQn, (uint32_t)&RTC_Alarm_IRQHandler);
    //NVIC_SetPriority(RTC_Alarm_IRQn,1,0);
    NVIC_EnableIRQ(RTC_Alarm_IRQn);   
}

void RTC_Alarm_IRQHandler(void){
  //RPC1.println("error");  
    HAL_RTC_AlarmIRQHandler(&loiTruck.hrtc);
}

void setup(){
    // initialize RPC lib
    randomSeed(analogRead(A0)); // Initializes the pseudo-random number generator
    
    
    //HAL_Init();
    RPC1.begin();
    Serial.begin(115200);
    while(!Serial);
    
                 
    HAL_RTC_MspInit();
    RTC_Init(&loiTruck);
    
    RTC_CalendarConfig(&loiTruck);
    //RPC1.println("1");

    /* -------------------------------- Scenario -------------------------------- */
    
      RPC1.println("Found First Scenario");
      if (RTC_AlarmConfig(&loiTruck)){
        RPC1.println("RTC_AlarmConfig OK");
      } else {
        RPC1.println("RTC_AlarmConfig error");
      }
      // call RPC procedure on M7
      RPC1.println("Call from M4 through RPC procedure");

      RPC1.println("Fake Heart Beat:" + String(loiTruck.fake_heart_beat));
      

      
      //auto result = RPC1.call("updateData",4).as<int>();

      //RPC1.println("Result:" + String(result));

      
      //loiTruck.finish_Scenario = true;
               
}

void loop(){

  /* -------------------------------------------------------------------------- */
  /* --------------------------- Check next Scenario -------------------------- */
  /* -------------------------------------------------------------------------- */

  
  

  // call RPC procedure on M7
  if (loiTruck.alarm){
    RPC1.println("-----------Alarm-----------");
    loiTruck.alarm = false;
  }

  if (HAL_RTC_GetTime(&loiTruck.hrtc, &loiTruck.RTC_TimeRead, RTC_FORMAT_BIN) == HAL_OK){
    RPC1.println("Minute:" + String(loiTruck.RTC_TimeRead.Minutes) + " Second:" + String(loiTruck.RTC_TimeRead.Seconds));
  } else {
    RPC1.println("Error Get Time");
  }
  
  

  //RPC1.println("Hier:" + String(convert_Scenario_To_Code(loiTruck.current_Scenario)));
      
  //auto result = RPC1.call("updateData",4).as<int>();

  //RPC1.println("Result:" + String(result));
  
  
  delay(100);
}


#endif
