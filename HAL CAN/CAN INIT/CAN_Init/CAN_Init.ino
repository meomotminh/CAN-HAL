#include "Arduino.h"
#include "mbed.h"
#include <ThreadDebug.h>
#include "RPC_internal.h"  // for RPC call

#include "src/loiTruck/loiTruck.h"
#include "src/FDCAN/FDCAN.h"
#include "src/SRAM/SRAM.h"
#include "src/TIMER/TIMER.h"
#include "src/UTILITY/UTILITY.h"
#include "src/MY_TEST/test_worst_case.h"
#include "src/MY_TEST/test_SDO_process.h"

/* ------------------------------- CANOpenNode ------------------------------ */
//#include "src/CANopenNode/CANopen.h"
//#include "config.h"

extern "C" {
//#include "src/CANopenNode/301/CO_driver.h"
}

using namespace mbed;
using namespace rtos;
using namespace std::chrono;


// TEMP------------------------
boolean sendMsg = false;
boolean receiveMsg = false;
boolean timeStamp = false;
boolean timestampVal = 0;
boolean timerElapse = false;

uint16_t time_array;
int timeDiff = 0;
char buffer[40];




/* -------------------------------------------------------------------------- */
/*                                 CODE FOR M7                                */
/* -------------------------------------------------------------------------- */

#ifdef CORE_CM7

/* ---------------------------- For TRACE32 Debug --------------------------- */
//USBSerial SerialUSB1(false, "DebugPort");
//UsbDebugCommInterface debugComm(&SerialUSB1);
//ThreadDebug           threadDebug(&debugComm, DEBUG_BREAK_IN_SETUP);



Thread send_fake_heart_beat(osPriorityNormal);
Thread SDO_process(osPriorityHigh);

LOITRUCK loiTruck = LOITRUCK(); // only loiTruck on M7


/* ----------------------------- THREAD FUNCTION ---------------------------- */
void send_fake(){
  /* ---------------------- Send Fake Heart Beat message ---------------------- */            
    while (true){
      for (int i = 0; i < 24; i++){        
          my_can_write(&loiTruck.my_can, fake[i],0,&loiTruck);
      }
      ThisThread::sleep_for(1000);  
    }    
}

void SDO_process_thread(){
  while (true){
    if (loiTruck.new_SDO_received){
      loiTruck.SDO_process_function();
      loiTruck.new_SDO_received = true;
    }
  }
}


/* ------------------------------ RTC CALLBACK ------------------------------ */

void HAL_RTC_AlarmAEventCallback(RTC_HandleTypeDef *hrtc){
  /* ----- when alarm ring, enable timer interrupt and set alarm 5s later ----- */
  loiTruck.alarm = true;
  ////Serial.println("err");

  if (!loiTruck.triggered){
    /* --------------------------- 1st time triggered --------------------------- */
    
    //TIMER6_Init(&loiTruck);
    loiTruck.triggered = true;  // for logic in RTC_AlarmConfig function
    RTC_CalendarConfig(&loiTruck);
    RTC_AlarmConfig(&loiTruck); // alarm for end of scenario
        
  } else {
    /* ----------------------------- Deactive Alarm ----------------------------- */    
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
    //RCC_OscInitStruct.PLL.PLLState = RCC_PLL_NONE;

    if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK){
      //Serial.println("M7: HAL_RCC_OscConfig error!");
    } else {
      //Serial.println("M7: HAL_RCC_OscConfig OK!");
    }

    /* -------------------------- select LSE as RTCCLK -------------------------- */
    RCC_RTCPeriClkInit.PeriphClockSelection = RCC_PERIPHCLK_RTC;
    RCC_RTCPeriClkInit.RTCClockSelection = RCC_RTCCLKSOURCE_LSE;

    if (HAL_RCCEx_PeriphCLKConfig(&RCC_RTCPeriClkInit) != HAL_OK){
      //Serial.println("M7: HAL_RCCEx_PeriphCLKConfig error!");
    } else {
      //Serial.println("M7: HAL_RCCEx_PeriphCLKConfig OK!");
    }

    /* ---------------------------- Enable RTC Clock ---------------------------- */
    __HAL_RCC_RTC_ENABLE();
    
    
    // enable EXTI Line 17 for RTC alarm
    loiTruck.hexti.Line = EXTI_LINE_17;
    loiTruck.ExtiConfig.Line = EXTI_LINE_17;
    loiTruck.ExtiConfig.Mode = EXTI_MODE_INTERRUPT;
    loiTruck.ExtiConfig.Trigger = EXTI_TRIGGER_RISING;
    
    if (HAL_EXTI_SetConfigLine(&loiTruck.hexti, &loiTruck.ExtiConfig) != HAL_OK){
      //Serial.println("M7: HAL_EXTI_SetConfigLine error!");
    } else {
      //Serial.println("M7: HAL_EXTI_SetConfigLine OK!");
    }


    /* -------------------- enable RTC ALarm IRQ in the NVIC -------------------- */
    NVIC_SetVector(RTC_Alarm_IRQn, (uint32_t)&RTC_Alarm_IRQHandler);
    //NVIC_SetPriority(RTC_Alarm_IRQn,1,0);
    NVIC_EnableIRQ(RTC_Alarm_IRQn);   
}

void RTC_Alarm_IRQHandler(void){
    ////Serial.println("error");  
    HAL_RTC_AlarmIRQHandler(&loiTruck.hrtc);
}





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
  /*  
  if (HAL_FDCAN_ConfigGlobalFilter(&loiTruck->my_can.CanHandle, FDCAN_ACCEPT_IN_RX_FIFO0, FDCAN_ACCEPT_IN_RX_FIFO0, FDCAN_FILTER_REMOTE, FDCAN_FILTER_REMOTE) != HAL_OK){
    //Error_Handler();
    //Serial.println("HAL_FDCAN_ConfigGlobalFilter error!");
  } else {
    //Serial.println("HAL_FDCAN_ConfigGlobalFilter OK!");
  }

  
  if (HAL_FDCAN_ConfigFilter(&obj->CanHandle, &sFilterConfig) != HAL_OK){
    //Serial.println("HAL_FDCAN_ConfigFilter error");
  } else {
    //Serial.println("HAL_FDCAN_ConfigFilter OK");
  }
  */

  /* ---------------------------- Enable Interrupt ---------------------------- */
   
  if (HAL_FDCAN_ActivateNotification(&loiTruck->my_can.CanHandle, FDCAN_IT_RX_FIFO0_NEW_MESSAGE | FDCAN_IT_TIMEOUT_OCCURRED | FDCAN_IT_TIMESTAMP_WRAPAROUND | FDCAN_IT_TX_COMPLETE, 0xFFFF) != HAL_OK){
    //Error_Handler();
    //Serial.println("HAL_FDCAN_ActivateNotification error!");
  } else {
    //Serial.println("HAL_FDCAN_ActivateNotification OK!");
  }


  /* --------------------------- FINALLY START FDCAN -------------------------- */

  if (HAL_FDCAN_Start(&obj->CanHandle) != HAL_OK){
    //Serial.println("HAL_FDCAN_Start error\n");
  } else {
    //Serial.println("HAL_FDCAN_Start success!");
  }
  
  /* -------------------------- FDCAN1 interrupt Init ------------------------- */
  NVIC_SetVector(FDCAN1_IT0_IRQn, (uint32_t)&FDCAN1_IT0_IRQHandler);
  NVIC_EnableIRQ(FDCAN1_IT0_IRQn);


  ////Serial.println("FDCAN1 interrupt success");


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
  ////Serial.println("Interrupt!");
  //interrupt = true;
  HAL_FDCAN_IRQHandler(&loiTruck.my_can.CanHandle);
}


void HAL_FDCAN_TxBufferCompleteCallback(FDCAN_HandleTypeDef *hfdcan, uint32_t BufferIndexes){
  loiTruck.sendMsg = true;
  
  
}


void HAL_FDCAN_RxFifo0Callback(FDCAN_HandleTypeDef *hfdcan, uint32_t RxFifo0ITs){  
    // Do SDO process
   // loiTruck.SDO_process_function();     
}

void HAL_FDCAN_TimeoutOccurredCallback(FDCAN_HandleTypeDef *hfdcan){
  //timeout = true;
}


void HAL_FDCAN_TimestampWraparoundCallback(FDCAN_HandleTypeDef *hfdcan){
   loiTruck.timestamp = true;           

   
          
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

  ////Serial.print("TIM6 Clock: "); //Serial.println(uwTimClock);

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
    ////Serial.println("HAL_TIM_Base_Init error!");
  } else {    
    ////Serial.println("HAL_TIM_Base_Init OK!");
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
  loiTruck.passed_time_s++;
  sprintf(loiTruck.buffer_string[(loiTruck.buffer_count++) % 100],"time passed(s):%d\n:",loiTruck.passed_time_s);         
  
  loiTruck.State_process_function();
  
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
    //Serial.println("HAL_RCC_ClockConfig error!");
  } else {
    //Serial.println("HAL_RCC_ClockConfig OK!");
  }

  /* ------------------- Initializes the peripherals clocks ------------------- */

  PeriphClkInit.PeriphClockSelection = RCC_PERIPHCLK_FDCAN;
  PeriphClkInit.FdcanClockSelection = RCC_FDCANCLKSOURCE_PLL;
  
  if (HAL_RCCEx_PeriphCLKConfig(&PeriphClkInit) != HAL_OK){
    //Error_Handler();
    //Serial.println("HAL_RCCEx_PeriphCLKConfig error!");
  } else {
    //Serial.println("HAL_RCCEx_PeriphCLKConfig OK!");
  }
}





void Error_Handler(void){
  // DO SOMETHING 
}

/* ------------------------------- CANopenNode ------------------------------ */



void setup() {
  
    // Initialize RPC lib, also boot M4 core
    RPC1.begin();
    
        
    Serial.begin(115200);
    while(!Serial);
    

    randomSeed(analogRead(A0)); // Initializes the pseudo-random number generator

    /* ------------------------ Low level initialization ------------------------ */
    HAL_Init();

    // Start DWT Timer
    DWT_timer_start();

    /* --------------------------- Config System Clock -------------------------- */
    //SystemClock_Config();

    /* ----------------------------- Init SDO object ---------------------------- */
    init_SDO_object(&loiTruck);
    

    /* --------------------- Display SDO object linked list --------------------- */
    //display_Linked_List(&loiTruck);

    /* ----------------------- Configure FDCAN peripheral ----------------------- */
    //FDCAN_Config();


    /* ----------------------- initiate can_t _can object ----------------------- */
    Set_CAN_Pin(&loiTruck.my_can, PB_8, PH_13, 250000);  

    /* ----------------------- Set external Loop Back mode ---------------------- */
    my_can_mode(&loiTruck.my_can, MODE_TEST_LOCAL);
    loiTruck.my_can_mode = MODE_TEST_LOCAL;

    /* -------------------------- set filter and start -------------------------- */
    //int my_can_filter(can_t *obj, uint32_t id, uint32_t mask, CANFormat format, int32_t handle)
    my_can_filter(&loiTruck.my_can, 0x641, 0x7FF, CANStandard, 0, &loiTruck);

    /* ------------------------------- RTC Config ------------------------------- */
    HAL_RTC_MspInit();
    RTC_Init(&loiTruck);    
    RTC_CalendarConfig(&loiTruck);
    
    
    
    /* ----------------------- Check Address of FDCAN RAM ----------------------- */
    /*
    //Serial.println("-------------------------------------");
    //Serial.println("|           Check Address            |");
    //Serial.println("-------------------------------------");

    //Serial.print("Message RxFIFO0 Start Address:");  //Serial.println(loiTruck.my_can.CanHandle.msgRam.RxFIFO0SA,HEX);
    //Serial.print("Message RxFIFO1 Start Address:");  //Serial.println(loiTruck.my_can.CanHandle.msgRam.RxFIFO1SA,HEX);
    //Serial.print("Message Rx Buffer Start Address:");  //Serial.println(loiTruck.my_can.CanHandle.msgRam.RxBufferSA,HEX);
    //Serial.print("Message RAM End Address:");  //Serial.println(loiTruck.my_can.CanHandle.msgRam.EndAddress,HEX);


    //Serial.println("-------------------------------------");
    //Serial.println("|           Start loop              |");
    //Serial.println("-------------------------------------");
    */
    
    
    /* -------------------------------- Scenario -------------------------------- */
    if (find_Scenario(&loiTruck)){
      //Serial.println("M7: Found First Scenario");
      if (RTC_AlarmConfig(&loiTruck)){ // set alarm for start of scenario
        //Serial.println("M7: Alarm Config OK");
      } else {
        //Serial.println("M7: Alarm Config error");
      }                    
    }

    
    // Start Thread
    //send_fake_heart_beat.start(send_fake); // Start an independent thread to send fake heart beat
    //SDO_process.start(SDO_process_thread);   
}


void loop() {
  /* --------------- put your main code here, to run repeatedly: -------------- */
  
  /*
  while (loiTruck.test_SDO_process_count < 11){    
    int passed_cycle = test_SDO_process(&loiTruck);
    sprintf(loiTruck.buffer_string[(loiTruck.buffer_count++) % 100], "Passed Time:%.4f\n",(passed_cycle/400e6));        
  }
  */
 
  if (loiTruck.buffer_count >= 100){
    for (int i = 0; i<loiTruck.buffer_count; i++){
      Serial.print(loiTruck.buffer_string[i]);
    }       
    loiTruck.buffer_count = 0;
  }
 

}

#endif


/* -------------------------------------------------------------------------- */
/*                                 CODE FOR M4                                */
/* -------------------------------------------------------------------------- */

#ifdef CORE_CM4

/* ------------------------------ RPC PROCEDURE ----------------------------- */
// M4 will monitor Scenario and trigger function to update loiTruck run on M7
int updateData(int code_id, int _delay){  

  RPC1.println("M4 is called");
  
  delay(700);
}


void setup(){
    // initialize RPC lib
    RPC1.begin();
    RPC1.bind("updateData",updateData);
    Serial.begin(115200); // must have for RPC print
    //while(!Serial);
    
    
    
    randomSeed(analogRead(A0)); // Initializes the pseudo-random number generator
    
    //HAL_Init();
    
    ////Serial.println("1");
    //RPC1.println("setup M4 is called");
    
}

void loop(){

  /* -------------------------------------------------------------------------- */
  /* --------------------------- Check next Scenario -------------------------- */
  /* -------------------------------------------------------------------------- */

  

  
  
}


#endif
