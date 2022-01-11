/* ------------------------------ timer section ----------------------------- */
#include "../../extern_loiTruck.h"

/**
 * @brief Enable Debug section + reset DWT counter
 * 
 */
bool DWT_timer_start()
{
    // Source: https://github.com/meomotminh/mbed-os/blob/master/cmsis/CMSIS_5/CMSIS/TARGET_CORTEX_M/Include/core_cm23.h
    
    /* Disable TRC */
    CoreDebug->DEMCR &= ~CoreDebug_DEMCR_TRCENA_Msk; // ~0x01000000;
    
    /* Enable TRC */
    CoreDebug->DEMCR |=  CoreDebug_DEMCR_TRCENA_Msk; // 0x01000000;
    
    
        // Disable Clock cycle counter
    DWT->CTRL &= ~DWT_CTRL_CYCCNTENA_Msk;
    // Enable Clock cycle counter
    DWT->CTRL |= DWT_CTRL_CYCCNTENA_Msk;

    // Reset clock cycle counter value
    DWT->CYCCNT = 0;
    //time_passed_us = 0;

    // wait 3 "NOP" instruction
    while (!DWT->CYCCNT){
      __asm volatile (
        "nop\n\t"
        "nop\n\t"
        "nop\n\t"
      );

      ////Serial.println(DWT->CYCCNT);
    }
        
        
    

    
    if (DWT->CYCCNT){
        ////Serial.println("Started");
        return 1; // value != 0 mean success
    } else {
        ////Serial.println("NOT Started");
        return 0;
    }


}

/**
 * @brief Read out DWT value and update LoiTruck time pass variable
 * 
 *
 * Calculation :
 * 
 * Clock Frequency = 400 MHz
 * 1 tick = 1/(400 * 10⁶) = 25*10^(-4)*10^(-6) = 25*10^(-10)s = 25*10^(-4) us
 * 32 bit -> FFFF FFFF = 4294967295 = 2^(32) - 1
 * overflow after 25*10^(-10)*4294967295 = 10,737 = 11s
 * 
 * 400e6 / e6 = 400
 * us = 400 000
 * 
 */
bool DWT_timer_stop()
{
    // read out DWT counter
    //loiTruck.passed_time_s = (DWT->CYCCNT * 25 / 10000);

    // Disable Clock cycle counter
    //DWT->CTRL &= ~DWT_CTRL_CYCCNTENA_Msk;    
}


/**
 * @brief return DWT_CYCCNT
 * 
 */
uint32_t DWT_get_CYCCNT(){
  return DWT->CYCCNT;
}



/**
 * @brief reset TIM6 counter
 * 
 */
void TIM6_timer_start()
{
  TIM_HandleTypeDef htimer6;
  RCC_ClkInitTypeDef clkconfig;
  uint32_t uwTimClock, uwAPB1Prescaler = 0U;
  uint32_t uwPrescalerValue = 0U;
  uint32_t pFLatency;

    /* ----------------------- enable TIM interface clock ----------------------- */
  __HAL_RCC_TIM6_CLK_ENABLE();

  
  /* ------------------------- get clock configuration ------------------------ */
  HAL_RCC_GetClockConfig(&clkconfig, &pFLatency);

  /* --------------------------- get APB1 prescaler --------------------------- */
  uwAPB1Prescaler = clkconfig.APB1CLKDivider;

  /* --------------------------- compute TIM6 clock --------------------------- */
  if (uwAPB1Prescaler == RCC_HCLK_DIV1){
    uwTimClock = HAL_RCC_GetPCLK1Freq();
  } else {
    uwTimClock = 2*HAL_RCC_GetPCLK1Freq();
  }

  ////Serial.print("TIM6 Clock: "); //Serial.println(uwTimClock);

  /* -- compute the prescaler value to have TIM6 counter clock equal to 1 MHz - */
  uwPrescalerValue = (uint32_t) ((uwTimClock / 1000000U) - 1U);

  /* ----------------------------- initialize TIM6 ---------------------------- */
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
  
  /* ----------------- initialize the TIM low level resources ----------------- */
  if (HAL_TIM_Base_Init(&htimer6) != HAL_OK){
    ////Serial.println("HAL_TIM_Base_Init error!");
  } else {    
    ////Serial.println("HAL_TIM_Base_Init OK!");
  }

  
  /* ------------------------- Activate TIM peripheral ------------------------ */
  if (HAL_TIM_Base_Start_IT(&htimer6) != HAL_OK){
    
  } else {
    
  }

}

/**
 * @brief Read out TIM6 counter
 * 
 */
void TIM6_timer_stop()
{

}




/* -------------------------------------------------------------------------- */
