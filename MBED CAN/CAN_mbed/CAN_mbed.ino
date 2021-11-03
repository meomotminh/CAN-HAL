#include "mbed.h"
#include <ThreadDebug.h>

// For TRACE32 Debug
//UsbDebugCommInterface debugComm(&SerialUSB);
//ThreadDebug           threadDebug(&debugComm, DEBUG_BREAK_IN_SETUP);

using namespace mbed;

TIM_HandleTypeDef htimer6;

UART_HandleTypeDef huart2;
RTC_HandleTypeDef hrtc;
RTC_TimeTypeDef RTC_TimeRead;
RTC_DateTypeDef RTC_DateRead;
EXTI_HandleTypeDef hexti;
EXTI_ConfigTypeDef ExtiConfig;

bool alarm = false;

/************************************************************************/
/*                            TIMER SECTION                             */
/************************************************************************/


void TIMER6_Init(void){
  
  // enable TIM interface clock
  __HAL_RCC_TIM6_CLK_ENABLE();
  
  htimer6.Instance = TIM6; // Basic Timer
  htimer6.Init.Prescaler = 24;
  htimer6.Init.Period = 500;
  htimer6.Init.CounterMode = TIM_COUNTERMODE_UP;
  //htimer6.Init.ClockDivision = TIM_CLOCK_DIVISION_DIV1;

  
  

  // initialize the TIM low level resources 
  if (HAL_TIM_Base_Init(&htimer6) != HAL_OK){
    SerialUSB.println("HAL_TIM_Base_Init error!");
  } else {
    SerialUSB.println("HAL_TIM_Base_Init OK!");
  }

  
  // Activate TIM peripheral 
  if (HAL_TIM_Base_Start_IT(&htimer6) != HAL_OK){
    SerialUSB.println("HAL_TIM_Base_Start_IT error!");
  } else {
    SerialUSB.println("HAL_TIM_Base_Start_IT OK!");
  }

  if (USE_HAL_TIM_REGISTER_CALLBACKS){
    Serial.println("USE_HAL_TIM_REGISTER_CALLBACKS");
  } else {
    Serial.println("NO_USE_HAL_TIM_REGISTER_CALLBACKS");
  }
  

  // register callback 
  /*if (HAL_TIM_RegisterCallback(&htimer6, HAL_TIM_PERIOD_ELAPSED_CB_ID, &TIM6_DAC_IRQHandler) != HAL_OK){
    Serial.println("HAL_TIM_RegisterCallback error");
  } else {
    Serial.println("HAL_TIM_RegisterCallback OK");
  }*/
  
  // set TIMx priority
  //NVIC_SetVector(TIM6_IRQn, (uint32_t)&TIM6_DAC_IRQHandler);
  
  //NVIC_EnableIRQ(TIM6_IRQn);
  NVIC_SetVector(TIM6_DAC_IRQn, (uint32_t)&TIM6_DAC_IRQHandler);

  // enable TIMx global interrupt
  NVIC_EnableIRQ(TIM6_DAC_IRQn);

}

void TIM6_DAC_IRQHandler(void){
  Serial.println("1");
  HAL_TIM_IRQHandler(&htimer6);
}

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim){
  Serial.println("1");
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
      Serial.println("error");
    } else {
      Serial.println("ok");
    }
}

void HAL_UART_MspInit(UART_HandleTypeDef *huart){
    GPIO_InitTypeDef gpio_uart;

    __HAL_RCC_USART2_CLK_ENABLE();

    __HAL_RCC_GPIOA_CLK_ENABLE();

    gpio_uart.Pin = GPIO_PIN_2;
    gpio_uart.Mode = GPIO_MODE_AF_PP;
    gpio_uart.Pull = GPIO_PULLUP;
    gpio_uart.Speed = GPIO_SPEED_FREQ_LOW;

    gpio_uart.Pin = GPIO_PIN_3;
    HAL_GPIO_Init(GPIOA, &gpio_uart);

    HAL_NVIC_EnableIRQ(USART2_IRQn);
    HAL_NVIC_SetPriority(USART2_IRQn, 0, 0);

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

void RTC_CalendarConfig(void){
    RTC_TimeTypeDef     RTC_TimeInit;
    RTC_DateTypeDef     RTC_DateInit;

    RTC_TimeInit.Hours = 12;
    RTC_TimeInit.Minutes = 45;
    RTC_TimeInit.Seconds = 0;
    RTC_TimeInit.TimeFormat = RTC_HOURFORMAT12_PM;

    if (HAL_RTC_SetTime(&hrtc, &RTC_TimeInit, RTC_FORMAT_BIN) != HAL_OK){
       Serial.println("error"); 
    } else  {
      Serial.println("OK");
    }

    RTC_DateInit.Date = 12;
    RTC_DateInit.Month = RTC_MONTH_JUNE;
    RTC_DateInit.Year = 18;
    RTC_DateInit.WeekDay = RTC_WEEKDAY_TUESDAY;

    if (HAL_RTC_SetDate(&hrtc, &RTC_DateInit, RTC_FORMAT_BIN)!= HAL_OK){
      Serial.println("error");
    } else  {
      Serial.println("OK");
    }
    

}

void RTC_Alarm_IRQHandler(void){
  //Serial.println("error");  
    HAL_RTC_AlarmIRQHandler(&hrtc);
}

void HAL_RTC_AlarmAEventCallback(RTC_HandleTypeDef *hrtc){
  alarm = true;
}

void GPIO_Init(){
    __HAL_RCC_GPIOA_CLK_ENABLE();
    __HAL_RCC_GPIOC_CLK_ENABLE();


	GPIO_InitTypeDef ledgpio , buttongpio;

	ledgpio.Pin = GPIO_PIN_5;
	ledgpio.Mode = GPIO_MODE_OUTPUT_PP;
	ledgpio.Pull = GPIO_NOPULL;
	HAL_GPIO_Init(GPIOA,&ledgpio);

	buttongpio.Pin = GPIO_PIN_13;
	buttongpio.Mode = GPIO_MODE_IT_FALLING;
	buttongpio.Pull = GPIO_NOPULL;
	HAL_GPIO_Init(GPIOC,&buttongpio);

  
  //NVIC_SetPriority(EXTI15_10_IRQn,15,0);
	NVIC_EnableIRQ(EXTI15_10_IRQn);
}

void UART2_Init(){
    huart2.Instance = USART2;
	huart2.Init.BaudRate =115200;
	huart2.Init.WordLength = UART_WORDLENGTH_8B;
	huart2.Init.StopBits = UART_STOPBITS_1;
	huart2.Init.Parity = UART_PARITY_NONE;
	huart2.Init.HwFlowCtl = UART_HWCONTROL_NONE;
	huart2.Init.Mode = UART_MODE_TX;


	if ( HAL_UART_Init(&huart2) != HAL_OK )
	{
		//There is a problem
		//Error_handler();
	}
}

void EXTI15_10_IRQHandler(void){
    HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_13);
}

char* getDayofweek(uint8_t number)
{
	char *weekday[] = { "Monday", "TuesDay", "Wednesday","Thursday","Friday","Saturday","Sunday"};

	return weekday[number-1];
}

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin){
  
	
}

void RTC_AlarmConfig(uint8_t second){
   Serial.println("Come Here!");
   RTC_AlarmTypeDef AlarmA_Set;

   memset(&AlarmA_Set,0,sizeof(AlarmA_Set));

   //HAL_RTC_DeactivateAlarm(&hrtc,RTC_ALARM_A);

   //xx:45:09
   AlarmA_Set.Alarm = RTC_ALARM_A;
   AlarmA_Set.AlarmTime.Minutes = 45;
   AlarmA_Set.AlarmTime.Seconds = 10;
   AlarmA_Set.AlarmMask = RTC_ALARMMASK_DATEWEEKDAY | RTC_ALARMMASK_HOURS | RTC_ALARMMASK_MINUTES;
   AlarmA_Set.AlarmSubSecondMask = RTC_ALARMSUBSECONDMASK_NONE;
   if ( HAL_RTC_SetAlarm_IT(&hrtc, &AlarmA_Set, RTC_FORMAT_BIN) != HAL_OK)
   {
     //Error_handler();
     Serial.println("Error");
   } else {
     Serial.println("set alarm OK");
   }
  
}

void setup(){

  Serial.begin(9600);
  while (!Serial);
  
  HAL_Init();

  TIMER6_Init();

}

void loop(){
  

  /*
  HAL_RTC_GetTime(&hrtc,&RTC_TimeRead,RTC_FORMAT_BIN);

  HAL_RTC_GetDate(&hrtc,&RTC_DateRead,RTC_FORMAT_BIN);

  Serial.print(RTC_TimeRead.Hours);  
  Serial.print(RTC_TimeRead.Minutes);  
  Serial.println(RTC_TimeRead.Seconds);  
  */
  

  if (alarm){
    Serial.println("ALARM");
    alarm = false;
  } else {
    //Serial.println("--------");
  }
 

}
