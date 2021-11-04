#ifndef LOITRUCK_H
#define LOITRUCK_H

static class loiTruck {
/* ------------------------------- GLOBAL VAR ------------------------------- */
    can_t my_can; // mbed CAN object
    char counter = 0; 
    CAN_Message msg; // mbed CAN message object
    FDCAN_RxHeaderTypeDef RxHeader; // HAL RxHeader object
    FDCAN_TxHeaderTypeDef TxHeader; // HAL TxHeader object
    uint8_t RxData[8]; // Buffer to save RxData
    uint8_t TxData[8]; // Buffer to save TxData
    FDCAN_ErrorCountersTypeDef error_counter; // Error Counter

/* -------------------------------- FOR SRAM -------------------------------- */
    SRAM_HandleTypeDef hsram;
    FMC_NORSRAM_TimingTypeDef timing;
    FMC_NORSRAM_TimingTypeDef Extiming;
    uint32_t aTxBuffer[16];
    uint32_t aRxBuffer[16];
    uint16_t uwIndex;
    uint32_t Hash_Int = 0x00000F0F;
    SDO* my_SDO_List = NULL;

/* --------------------------------- FOR RTC -------------------------------- */
    RTC_HandleTypeDef hrtc;
    RTC_TimeTypeDef RTC_TimeRead;
    RTC_DateTypeDef RTC_DateRead;
    EXTI_HandleTypeDef hexti;
    EXTI_ConfigTypeDef ExtiConfig;
    bool alarm = false;

/* -------------------------------- FOR TIMER ------------------------------- */
    TIM_HandleTypeDef htimer6;
    bool timer6 = false;

/* ------------------------------- FOR TESTING ------------------------------ */
    bool Rx_Fifo0_full = false;
    bool receiveMsg = false;
    bool timeout = false;
    bool interrupt = false;
    uint32_t Rx_IT_Number = 0;
    bool timestamp = false;
    bool found_parameter = false;
    bool sendMsg = false;
    bool fake_heart_beat = false;

/* ------------------------------ FOR SEGMENTED ----------------------------- */
    uint8_t segment_count = 0;
    bool segmented = false;
    uint8_t add_count = 0;
    uint8_t rest_count = 0;
    uint32_t rest_char = 0;
    uint16_t bit_swap = 0;

/* ------------------------------ FOR SCENARIO ------------------------------ */

    //My_Function function_linear(0.0,0.0,1.0,1.0); 
    //Scenario Scenario_1(IN_TIME_STAMP, OUT_NONE, NULL, 10, NULL, 0, &function_linear, 10);

/* ------------------------------- CONSTRUCTOR ------------------------------ */
    loiTruck(){
        /* ----------------------------- create SDO List ---------------------------- */
        my_SDO_List = 
    }



}

#endif