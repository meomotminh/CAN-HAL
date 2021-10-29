#include "mbed.h"
#include <ThreadDebug.h>

// For TRACE32 Debug
//UsbDebugCommInterface debugComm(&SerialUSB);
//ThreadDebug           threadDebug(&debugComm, DEBUG_BREAK_IN_SETUP);

using namespace mbed;

UART_HandleTypeDef huart2;
RTC_HandleTypeDef hrtc;
RTC_TimeTypeDef RTC_TimeRead;
RTC_DateTypeDef RTC_DateRead;

bool alarm = false;

void printmsg(char *format,...){
    char str[80];

    // extract the argument list using VA apis
    va_list args;
    va_start(args, format);
    vsprintf(str, format, args);

    HAL_UART_Transmit(&huart2, (uint8_t *)str, strlen(str), HAL_MAX_DELAY);
    va_end(args);
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
  Serial.println("error");  
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
   AlarmA_Set.AlarmMask = RTC_ALARMMASK_SECONDS;
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

    //GPIO_Init();

    //SystemClock_Config_HSE(SYS_CLOCK_FREQ_50_MHZ);

    //UART2_Init();

    HAL_RTC_MspInit();
    RTC_Init();

    RTC_CalendarConfig();
    //Serial.println("1");
    RTC_AlarmConfig(10);
    //Serial.println("2");
    //RTC_AlarmConfig(20);
    
    //RTC_AlarmConfig(30);
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
  } else {
    //Serial.println("--------");
  }
 

}
