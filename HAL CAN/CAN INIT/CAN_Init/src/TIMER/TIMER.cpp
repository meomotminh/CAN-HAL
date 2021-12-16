/* ------------------------------ timer section ----------------------------- */
#include "../../extern_loiTruck.h"

/**
 * @brief Enable Debug section + reset DWT counter
 * 
 */
bool DWT_timer_start()
{
    // Source: https://github.com/meomotminh/mbed-os/blob/master/cmsis/CMSIS_5/CMSIS/TARGET_CORTEX_M/Include/core_cm23.h
    // Disable Clock cycle counter
    DWT->CTRL &= ~DWT_CTRL_CYCCNTENA_Msk;
    // Enable Clock cycle counter
    DWT->CTRL |= DWT_CTRL_CYCCNTENA_Msk;

    // Reset clock cycle counter value
    DWT->CYCCNT = 0;
    loiTruck.passed_time_us = 0;

    // wait 3 "NOP" instruction
    __asm volatile (
        "nop\n\t"
        "nop\n\t"
        "nop\n\t"    
    );

    if (DWT->CYCCNT){
        return 1; // value != 0 mean success
    } else {
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
    loiTruck.passed_time_us = (DWT->CYCCNT * 25 / 10000);

    // Disable Clock cycle counter
    DWT->CTRL &= ~DWT_CTRL_CYCCNTENA_Msk;    
}





/**
 * @brief reset TIM6 counter
 * 
 */
void TIM6_timer_start()
{

}

/**
 * @brief Read out TIM6 counter
 * 
 */
void TIM6_timer_stop()
{

}




/* -------------------------------------------------------------------------- */
