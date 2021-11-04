/* ------------------------------ timer section ----------------------------- */
#include "TIMER.h"


void TIMER6_Init(void){
  RCC_ClkInitTypeDef clkconfig;
  uint32_t uwTimClock, uwAPB1Prescaler = 0U;
  uint32_t uwPrescalerValue = 0U;
  uint32_t pFLatency;

  // enable TIM interface clock
  __HAL_RCC_TIM6_CLK_ENABLE();
  
  // get clock configuration
  HAL_RCC_GetClockConfig(&clkconfig, &pFLatency);

  // get APB1 prescaler
  uwAPB1Prescaler = clkconfig.APB1CLKDivider;

  // compute TIM6 clock
  if (uwAPB1Prescaler == RCC_HCLK_DIV1){
    uwTimClock = HAL_RCC_GetPCLK1Freq();
  } else {
    uwTimClock = 2*HAL_RCC_GetPCLK1Freq();
  }

  //Serial.print("TIM6 Clock: "); Serial.println(uwTimClock);

  // compute the prescaler value to have TIM6 counter clock equal to 1 MHz
  uwPrescalerValue = (uint32_t) ((uwTimClock / 1000000U) - 1U);

  // initialize TIM6
  htimer6.Instance = TIM6; // Basic Timer

  /*
    Initialize TIMx peripheral as follow
    Period = [(TIM6CLK / 1000) - 1]
    Prescaler = (uwTimclock / 1000000 - 1)
    ClockDivision = 0

  */
  htimer6.Init.Period = (1000000U / 1000U) - 1;
  htimer6.Init.Prescaler = uwPrescalerValue;
  htimer6.Init.CounterMode = TIM_COUNTERMODE_UP;
  
  // initialize the TIM low level resources 
  if (HAL_TIM_Base_Init(&htimer6) != HAL_OK){
    //Serial.println("HAL_TIM_Base_Init error!");
  } else {    
    //Serial.println("HAL_TIM_Base_Init OK!");
  }

  
  // Activate TIM peripheral 
  if (HAL_TIM_Base_Start_IT(&htimer6) != HAL_OK){
    //Serial.println("HAL_TIM_Base_Start_IT error!");
  } else {
    //Serial.println("HAL_TIM_Base_Start_IT OK!");
  }

  NVIC_SetVector(TIM6_DAC_IRQn, (uint32_t)&TIM6_DAC_IRQHandler);
  HAL_NVIC_SetPriority(TIM6_DAC_IRQn, 14U, 0U);
  // enable TIMx global interrupt
  HAL_NVIC_EnableIRQ(TIM6_DAC_IRQn);

}

void TIM6_DAC_IRQHandler(void){
  //Serial.println("1");
  HAL_TIM_IRQHandler(&htimer6);
}

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim){
  //Serial.println("1");
  // only trigger when alarm set
  if (alarm){
    timer6 = true;
  } 
  
}

/* -------------------------------------------------------------------------- */