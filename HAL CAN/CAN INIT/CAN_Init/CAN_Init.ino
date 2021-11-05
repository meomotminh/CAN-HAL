#include "mbed.h"
#include <ThreadDebug.h>
#include "src/loiTruck/loiTruck.h""
#include "src/FDCAN/FDCAN.h"
#include "src/RTC/RTC.h"
#include "src/SRAM/SRAM.h"
#include "src/TIMER/TIMER.h"
#include "src/UTILITY/UTILITY.h"
#include "Scenario.h"



// For TRACE32 Debug
//USBSerial SerialUSB1(false, "DebugPort");
//UsbDebugCommInterface debugComm(&SerialUSB1);
//ThreadDebug           threadDebug(&debugComm, DEBUG_BREAK_IN_SETUP);

using namespace mbed;



LOITRUCK loiTruck = LOITRUCK();





/* --------------------------- FDCAN CALLBACK --------------------------- */


/* ------------------ from can_filter of mbed OS Target STM ----------------- */
 
int my_can_filter(can_t *obj, uint32_t id, uint32_t mask, CANFormat format, int32_t handle, LOITRUCK* loiTruck){
  FDCAN_FilterTypeDef sFilterConfig = {0};

 
  
  if (format == CANStandard){
    sFilterConfig.IdType = FDCAN_STANDARD_ID;
    sFilterConfig.FilterIndex = handle;    
    sFilterConfig.FilterType = FDCAN_FILTER_RANGE; // FDCAN_FILTER_MASK
    sFilterConfig.FilterConfig = FDCAN_FILTER_TO_RXFIFO0;
    sFilterConfig.FilterID1 = 0x600;
    sFilterConfig.FilterID2 = 0x799;
  } else if (format == CANExtended){
    sFilterConfig.IdType = FDCAN_EXTENDED_ID;
    sFilterConfig.FilterIndex = handle;    
    sFilterConfig.FilterType = FDCAN_FILTER_MASK;
    sFilterConfig.FilterConfig = FDCAN_FILTER_TO_RXFIFO0;
    sFilterConfig.FilterID1 = id;
    sFilterConfig.FilterID2 = mask;
  } else {
    return 0;
  }
  
/* ----- Configure global filter: Filter all remote frames with STD and ----- */
/* -------- EXT ID Reject non matching frames with STD ID and EXT ID -------- */
    
  if (HAL_FDCAN_ConfigGlobalFilter(&loiTruck->my_can.CanHandle, FDCAN_ACCEPT_IN_RX_FIFO0, FDCAN_ACCEPT_IN_RX_FIFO0, FDCAN_FILTER_REMOTE, FDCAN_FILTER_REMOTE) != HAL_OK){
    //Error_Handler();
    Serial.println("HAL_FDCAN_ConfigGlobalFilter error!");
  } else {
    Serial.println("HAL_FDCAN_ConfigGlobalFilter OK!");
  }

  
  if (HAL_FDCAN_ConfigFilter(&obj->CanHandle, &sFilterConfig) != HAL_OK){
    Serial.println("HAL_FDCAN_ConfigFilter error");
  } else {
    Serial.println("HAL_FDCAN_ConfigFilter OK");
  }
  

  /* ---------------------------- Enable Interrupt ---------------------------- */
   
  if (HAL_FDCAN_ActivateNotification(&loiTruck->my_can.CanHandle, FDCAN_IT_RX_FIFO0_NEW_MESSAGE | FDCAN_IT_TIMEOUT_OCCURRED | FDCAN_IT_TIMESTAMP_WRAPAROUND | FDCAN_IT_TX_COMPLETE, 0xFFFF) != HAL_OK){
    //Error_Handler();
    Serial.println("HAL_FDCAN_ActivateNotification error!");
  } else {
    Serial.println("HAL_FDCAN_ActivateNotification OK!");
  }


  /* --------------------------- FINALLY START FDCAN -------------------------- */

  if (HAL_FDCAN_Start(&obj->CanHandle) != HAL_OK){
    Serial.println("HAL_FDCAN_Start error\n");
  } else {
    Serial.println("Start success!");
  }
  
  /* -------------------------- FDCAN1 interrupt Init ------------------------- */
  NVIC_SetVector(FDCAN1_IT0_IRQn, (uint32_t)&FDCAN1_IT0_IRQHandler);
  NVIC_EnableIRQ(FDCAN1_IT0_IRQn);


  //Serial.println("FDCAN1 interrupt success");


  /* ---------------------------- Prepare Tx Header --------------------------- */
  loiTruck->TxHeader.Identifier = 0x322;
  loiTruck->TxHeader.IdType = FDCAN_STANDARD_ID;
  loiTruck->TxHeader.TxFrameType = FDCAN_DATA_FRAME;
  loiTruck->TxHeader.DataLength = FDCAN_DLC_BYTES_8;
  loiTruck->TxHeader.ErrorStateIndicator = FDCAN_ESI_ACTIVE;
  loiTruck->TxHeader.BitRateSwitch = FDCAN_BRS_OFF;
  loiTruck->TxHeader.FDFormat = FDCAN_CLASSIC_CAN;
  loiTruck->TxHeader.TxEventFifoControl = FDCAN_STORE_TX_EVENTS;
  loiTruck->TxHeader.MessageMarker = 0;

  return 1;
}

void FDCAN1_IT0_IRQHandler(void){
  //Serial.println("Interrupt!");
  //interrupt = true;
  HAL_FDCAN_IRQHandler(&loiTruck.my_can.CanHandle);
}


void HAL_FDCAN_TxBufferCompleteCallback(FDCAN_HandleTypeDef *hfdcan, uint32_t BufferIndexes){
  loiTruck.sendMsg = true;
  

  //sendMsg = false;  
}


/*
void HAL_FDCAN_RxFifo0Callback(FDCAN_HandleTypeDef *hfdcan, uint32_t RxFifo0ITs){

 
   if (RxFifo0ITs == FDCAN_IT_RX_FIFO0_NEW_MESSAGE){  // = 1
      receiveMsg = true;
   } 

   if (RxFifo0ITs == (FDCAN_IT_RX_FIFO0_FULL + FDCAN_IT_RX_FIFO0_NEW_MESSAGE)){ // new message + full = 5
      Rx_Fifo0_full = true;
   }

   Rx_IT_Number = RxFifo0ITs;
   
   //counter = 0;
  //Serial.println("Receive new message!");
  
}
*/

void HAL_FDCAN_RxFifo0Callback(FDCAN_HandleTypeDef *hfdcan, uint32_t RxFifo0ITs){
  if ((RxFifo0ITs & FDCAN_IT_RX_FIFO0_NEW_MESSAGE) != RESET){

    loiTruck.receiveMsg = true;
    
    // DO SOMETHING
  }
}

void HAL_FDCAN_TimeoutOccurredCallback(FDCAN_HandleTypeDef *hfdcan){
  //timeout = true;
}


void HAL_FDCAN_TimestampWraparoundCallback(FDCAN_HandleTypeDef *hfdcan){
  loiTruck.timestamp = true;  
}



/* ------------------------------ RTC CALLBACK ------------------------------ */

void HAL_RTC_AlarmAEventCallback(RTC_HandleTypeDef *hrtc){
  /* ----- when alarm ring, enable timer interrupt and set alarm 5s later ----- */
  loiTruck.alarm = true;
  
  
  if (!loiTruck.triggered){
    /* --------------------------- 1st time triggered --------------------------- */
    
    TIMER6_Init(&loiTruck);
    loiTruck.triggered = true;  // for logic in RTC_AlarmConfig function
    RTC_AlarmConfig(&loiTruck);    
        
  } else {
    /* ----------------------------- Deactive Alarm ----------------------------- */
    loiTruck.triggered = false; 
    HAL_RTC_DeactivateAlarm(&loiTruck.hrtc, RTC_ALARM_A);
    loiTruck.finish_Scenario = true;

  }

  
}

void HAL_RTC_MspInit(void){
    RCC_OscInitTypeDef  RCC_OscInitStruct;
    RCC_PeriphCLKInitTypeDef RCC_RTCPeriClkInit;
    
    
    /* ------------------------------- turn on LSE ------------------------------ */
    RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_LSE;
    RCC_OscInitStruct.LSEState = RCC_LSE_ON;
    RCC_OscInitStruct.PLL.PLLState = RCC_PLL_NONE;

    if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK){

    }

    /* -------------------------- select LSE as RTCCLK -------------------------- */
    RCC_RTCPeriClkInit.PeriphClockSelection = RCC_PERIPHCLK_RTC;
    RCC_RTCPeriClkInit.RTCClockSelection = RCC_RTCCLKSOURCE_LSE;

    if (HAL_RCCEx_PeriphCLKConfig(&RCC_RTCPeriClkInit) != HAL_OK){

    }

    /* ---------------------------- Enable RTC Clock ---------------------------- */
    __HAL_RCC_RTC_ENABLE();
    
    
    // enable EXTI Line 17 for RTC alarm
    loiTruck.hexti.Line = EXTI_LINE_17;
    loiTruck.ExtiConfig.Line = EXTI_LINE_17;
    loiTruck.ExtiConfig.Mode = EXTI_MODE_INTERRUPT;
    loiTruck.ExtiConfig.Trigger = EXTI_TRIGGER_RISING;
    
    if (HAL_EXTI_SetConfigLine(&loiTruck.hexti, &loiTruck.ExtiConfig) != HAL_OK){
      Serial.println("HAL_EXTI_SetConfigLine error!");
    } else {
      Serial.println("HAL_EXTI_SetConfigLine OK!");
    }


    /* -------------------- enable RTC ALarm IRQ in the NVIC -------------------- */
    NVIC_SetVector(RTC_Alarm_IRQn, (uint32_t)&RTC_Alarm_IRQHandler);
    //NVIC_SetPriority(RTC_Alarm_IRQn,1,0);
    NVIC_EnableIRQ(RTC_Alarm_IRQn);   
}

void RTC_Alarm_IRQHandler(void){
  //Serial.println("error");  
    HAL_RTC_AlarmIRQHandler(&loiTruck.hrtc);
}


/* ----------------------------- TIMER CALLBACK ----------------------------- */

void TIMER6_Init(LOITRUCK* loiTruck){
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

  //Serial.print("TIM6 Clock: "); Serial.println(uwTimClock);

  /* -- compute the prescaler value to have TIM6 counter clock equal to 1 MHz - */
  uwPrescalerValue = (uint32_t) ((uwTimClock / 1000000U) - 1U);

  /* ----------------------------- initialize TIM6 ---------------------------- */
  loiTruck->htimer6.Instance = TIM6; // Basic Timer

  /*
    Initialize TIMx peripheral as follow
    Period = [(TIM6CLK / 1000) - 1]
    Prescaler = (uwTimclock / 1000000 - 1)
    ClockDivision = 0

  */
  loiTruck->htimer6.Init.Period = (1000000U / 1000U) - 1;
  loiTruck->htimer6.Init.Prescaler = uwPrescalerValue;
  loiTruck->htimer6.Init.CounterMode = TIM_COUNTERMODE_UP;
  
  /* ----------------- initialize the TIM low level resources ----------------- */
  if (HAL_TIM_Base_Init(&loiTruck->htimer6) != HAL_OK){
    //Serial.println("HAL_TIM_Base_Init error!");
  } else {    
    //Serial.println("HAL_TIM_Base_Init OK!");
  }

  
  /* ------------------------- Activate TIM peripheral ------------------------ */
  if (HAL_TIM_Base_Start_IT(&loiTruck->htimer6) != HAL_OK){
    
  } else {
    
  }

  NVIC_SetVector(TIM6_DAC_IRQn, (uint32_t)&TIM6_DAC_IRQHandler);
  HAL_NVIC_SetPriority(TIM6_DAC_IRQn, 14U, 0U);
  // enable TIMx global interrupt
  HAL_NVIC_EnableIRQ(TIM6_DAC_IRQn);

}

void TIM6_DAC_IRQHandler(void){
  
  HAL_TIM_IRQHandler(&loiTruck.htimer6);
}

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim){
  
  /* ----------------------- only trigger when alarm set ---------------------- */
  if (loiTruck.alarm){
    loiTruck.timer6 = true;
  } 
  
}









  /* --------------------------- Config System Clock -------------------------- */
  //from https://github.com/meomotminh/STM32CubeG4/blob/master/Projects/STM32G474E-EVAL/Examples/FDCAN/FDCAN_Classic_Frame_Networking/Src/main.c
 
void SystemClock_Config(void){
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};
  RCC_PeriphCLKInitTypeDef PeriphClkInit = {0};
  HAL_StatusTypeDef ret = HAL_OK;

  /* -------------------- Oscillator init seem not to work -------------------- */
    


  

  /* -------------- Initialize the CPU, AHB and APB buses clocks -------------- */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK | RCC_CLOCKTYPE_SYSCLK 
                                | RCC_CLOCKTYPE_PCLK1 | RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_2) != HAL_OK){
    //Error_Handler();
    Serial.println("HAL_RCC_ClockConfig error!");
  } else {
    Serial.println("HAL_RCC_ClockConfig OK!");
  }

  /* ------------------- Initializes the peripherals clocks ------------------- */

  PeriphClkInit.PeriphClockSelection = RCC_PERIPHCLK_FDCAN;
  PeriphClkInit.FdcanClockSelection = RCC_FDCANCLKSOURCE_PLL;
  
  if (HAL_RCCEx_PeriphCLKConfig(&PeriphClkInit) != HAL_OK){
    //Error_Handler();
    Serial.println("HAL_RCCEx_PeriphCLKConfig error!");
  } else {
    Serial.println("HAL_RCCEx_PeriphCLKConfig OK!");
  }
}





void Error_Handler(void){
  // DO SOMETHING 
}

void setup() {
  //Serial.begin(115200);
  Serial.begin(115200);
  while (!Serial);

  
  /* ------------------------ Low level initialization ------------------------ */
  HAL_Init();


  /* --------------------------- Config System Clock -------------------------- */
  //SystemClock_Config();

  /* ----------------------------- Init SDO object ---------------------------- */
  init_SDO_object(&loiTruck);

  /* --------------------- Display SDO object linked list --------------------- */
  display_Linked_List(&loiTruck);

  /* ----------------------- Configure FDCAN peripheral ----------------------- */
  //FDCAN_Config();
  
  
  /* ----------------------- initiate can_t _can object ----------------------- */
  Set_CAN_Pin(&loiTruck.my_can, PB_8, PH_13, 250000);  

  /* ----------------------- Set external Loop Back mode ---------------------- */
  my_can_mode(&loiTruck.my_can, MODE_NORMAL);
  
  /* -------------------------- set filter and start -------------------------- */
  //int my_can_filter(can_t *obj, uint32_t id, uint32_t mask, CANFormat format, int32_t handle)
  my_can_filter(&loiTruck.my_can, 0x641, 0x7FF, CANStandard, 0, &loiTruck);


  /* ----------------------- Check Address of FDCAN RAM ----------------------- */
  Serial.println("-------------------------------------");
  Serial.println("|           Check Address            |");
  Serial.println("-------------------------------------");

  Serial.print("Message RxFIFO0 Start Address:");  Serial.println(loiTruck.my_can.CanHandle.msgRam.RxFIFO0SA,HEX);
  Serial.print("Message RxFIFO1 Start Address:");  Serial.println(loiTruck.my_can.CanHandle.msgRam.RxFIFO1SA,HEX);
  Serial.print("Message Rx Buffer Start Address:");  Serial.println(loiTruck.my_can.CanHandle.msgRam.RxBufferSA,HEX);
  Serial.print("Message RAM End Address:");  Serial.println(loiTruck.my_can.CanHandle.msgRam.EndAddress,HEX);

  
  Serial.println("-------------------------------------");
  Serial.println("|           Start loop              |");
  Serial.println("-------------------------------------");

  //struct SDO* found1 = find_value(&my_SDO_List, 0x200204);
  //Serial.print("Find :");Serial.println(found1->value,HEX);  Serial.println(found1->address,HEX);Serial.println(ceil(found1->length / 8.0));


    HAL_RTC_MspInit();
    RTC_Init(&loiTruck);
    
    RTC_CalendarConfig(&loiTruck);
    //Serial.println("1");
    

  /* -------------------------------- Scenario -------------------------------- */
  if (find_Scenario(&loiTruck)){
    Serial.println("Found First Scenario");
    RTC_AlarmConfig(&loiTruck);
  }

      
    

}


void loop() {
  /* --------------- put your main code here, to run repeatedly: -------------- */

  if (HAL_FDCAN_IsRxBufferMessageAvailable(&loiTruck.my_can.CanHandle,0) == 1){
    Serial.println("Rx new message ");
  }
  
  if (loiTruck.receiveMsg){

     Serial.println("Receive mess");
    
    
    /* -------------------- Retrieve Rx message from Rx FIFO0 ------------------- */
    if (HAL_FDCAN_GetRxMessage(&loiTruck.my_can.CanHandle, FDCAN_RX_FIFO0, &loiTruck.RxHeader, loiTruck.RxData) != HAL_OK){
        Serial.println("Error Handler");
        Error_Handler();
      
    } else {      
    /* ------------------------------ check action ------------------------------ */

    /* -------------------------------- print out ------------------------------- */
    Serial.println("*****************************");
    Serial.print("R :\t"); Serial.print(loiTruck.RxHeader.Identifier,HEX); Serial.print(" ");

    
    
    for (uint8_t i = 0; i < (loiTruck.RxHeader.DataLength >> 16); i++){
      Serial.print(" ");
      Serial.print(loiTruck.RxData[i], HEX); 
    }

    Serial.println();  
        
      /* ------------------------------ READ COMMAND ------------------------------ */
      if ((((loiTruck.RxData[0] & 0xF0) == 0x40) | ((loiTruck.RxData[0] & 0xF0) == 0x60) | loiTruck.segmented)){        
          if (read_parameter(&loiTruck)){
              loiTruck.TxHeader.Identifier = prepare_ID(loiTruck.RxHeader.Identifier);
              if (my_can_write(&loiTruck.my_can, CANMessage(loiTruck.TxHeader.Identifier,loiTruck.TxData,8), 8, &loiTruck)){
              
              } else {
                Error_Handler();
              }            
          }
                                
          
                        
      } else if ((loiTruck.RxData[0] & 0xF0) == 0x20) {
        /* ------------------------------ WRITE COMMAND ----------------------------- */
        //Serial.println("");
        write_parameter(&loiTruck);  

        loiTruck.TxHeader.Identifier = prepare_ID(loiTruck.RxHeader.Identifier);
          if (my_can_write(&loiTruck.my_can, CANMessage(loiTruck.TxHeader.Identifier,loiTruck.TxData,8), 8, &loiTruck)){
      
          } else {
            Error_Handler();
          }  
      }

      
    }

     

  
    loiTruck.receiveMsg = false;
  }

  

  if (loiTruck.Rx_Fifo0_full){
    Serial.println("FIFO full");
    loiTruck.Rx_Fifo0_full = false;
    
  }

  if (loiTruck.timeout){
    //Serial.println("Timeout occur!");
    loiTruck.timeout = false;
  }

if (loiTruck.timestamp){
  int8_t fake_length = sizeof(fake);
  
  loiTruck.fake_heart_beat = true;
  /* ---------------------- Send Fake Heart Beat message ---------------------- */
  for (int i = 0; i < sizeof(fake); i++){        
    
    if (my_can_write(&loiTruck.my_can, fake[i],sizeof(fake[i]),&loiTruck)){
       
    } else {
        Error_Handler();
    } 
       
        
  }
  loiTruck.fake_heart_beat = false; 
  loiTruck.timestamp = false;
}

  if (loiTruck.segmented){
  }

  
  if (loiTruck.alarm){
    Serial.println("----------------ALARM--------------------");
    loiTruck.alarm = false;
  } 

  /*
  if (timer6){
    Serial.println("Timer");
    timer6 = false;
  } else {
    
  }
  */


  /* -------------------------- Check next Scenario ------------------------- */
  if (loiTruck.finish_Scenario){
    
    loiTruck.finish_Scenario = false;

    if (find_Scenario(&loiTruck)){
      Serial.println("Found Next Scenario");
      RTC_CalendarConfig(&loiTruck);
      RTC_AlarmConfig(&loiTruck);
    }
  }
  
}
