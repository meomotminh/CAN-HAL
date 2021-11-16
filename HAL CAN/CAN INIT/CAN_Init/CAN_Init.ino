#include "Arduino.h"
#include "mbed.h"
#include <ThreadDebug.h>
#include "RPC_internal.h"  // for RPC call

#include "src/loiTruck/loiTruck.h"
#include "src/FDCAN/FDCAN.h"
#include "src/SRAM/SRAM.h"
#include "src/TIMER/TIMER.h"
#include "src/UTILITY/UTILITY.h"




using namespace mbed;




/* -------------------------------------------------------------------------- */
/*                                 CODE FOR M7                                */
/* -------------------------------------------------------------------------- */

#ifdef CORE_CM7

/* ---------------------------- For TRACE32 Debug --------------------------- */
//USBSerial SerialUSB1(false, "DebugPort");
//UsbDebugCommInterface debugComm(&SerialUSB1);
//ThreadDebug           threadDebug(&debugComm, DEBUG_BREAK_IN_SETUP);

using namespace rtos;

Thread send_fake_heart_beat;


LOITRUCK loiTruck = LOITRUCK(); // only loiTruck on M7


void send_fake(){
  /* ---------------------- Send Fake Heart Beat message ---------------------- */
    while (true){
      // send fake heart beat
      if (!loiTruck.receiveMsg){          
        //loiTruck.fake_heart_beat = true;
        
        if (my_can_write(&loiTruck.my_can, fake[0],0,&loiTruck)){

        } else {
          //Error_Handler();
          //Serial.println("Error");
        } 

        //loiTruck.fake_heart_beat = false;
        }
        
      HAL_Delay(100);
     }

     

}

/* ------------------------------ RTC CALLBACK ------------------------------ */

void HAL_RTC_AlarmAEventCallback(RTC_HandleTypeDef *hrtc){
  /* ----- when alarm ring, enable timer interrupt and set alarm 5s later ----- */
  loiTruck.alarm = true;
  //Serial.println("err");

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
      Serial.println("M7: HAL_RCC_OscConfig error!");
    } else {
      Serial.println("M7: HAL_RCC_OscConfig OK!");
    }

    /* -------------------------- select LSE as RTCCLK -------------------------- */
    RCC_RTCPeriClkInit.PeriphClockSelection = RCC_PERIPHCLK_RTC;
    RCC_RTCPeriClkInit.RTCClockSelection = RCC_RTCCLKSOURCE_LSE;

    if (HAL_RCCEx_PeriphCLKConfig(&RCC_RTCPeriClkInit) != HAL_OK){
      Serial.println("M7: HAL_RCCEx_PeriphCLKConfig error!");
    } else {
      Serial.println("M7: HAL_RCCEx_PeriphCLKConfig OK!");
    }

    /* ---------------------------- Enable RTC Clock ---------------------------- */
    __HAL_RCC_RTC_ENABLE();
    
    
    // enable EXTI Line 17 for RTC alarm
    loiTruck.hexti.Line = EXTI_LINE_17;
    loiTruck.ExtiConfig.Line = EXTI_LINE_17;
    loiTruck.ExtiConfig.Mode = EXTI_MODE_INTERRUPT;
    loiTruck.ExtiConfig.Trigger = EXTI_TRIGGER_RISING;
    
    if (HAL_EXTI_SetConfigLine(&loiTruck.hexti, &loiTruck.ExtiConfig) != HAL_OK){
      Serial.println("M7: HAL_EXTI_SetConfigLine error!");
    } else {
      Serial.println("M7: HAL_EXTI_SetConfigLine OK!");
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
    Serial.println("HAL_FDCAN_ConfigGlobalFilter error!");
  } else {
    Serial.println("HAL_FDCAN_ConfigGlobalFilter OK!");
  }

  
  if (HAL_FDCAN_ConfigFilter(&obj->CanHandle, &sFilterConfig) != HAL_OK){
    Serial.println("HAL_FDCAN_ConfigFilter error");
  } else {
    Serial.println("HAL_FDCAN_ConfigFilter OK");
  }
  */

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
    Serial.println("HAL_FDCAN_Start success!");
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
  //if ((RxFifo0ITs & FDCAN_IT_RX_FIFO0_NEW_MESSAGE) != RESET){

    loiTruck.receiveMsg = true;
    
    // DO SOMETHING
  //}
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
  
    // Initialize RPC lib, also boot M4 core
    RPC1.begin();
    
        
    Serial.begin(115200);
    while(!Serial);
    

    randomSeed(analogRead(A0)); // Initializes the pseudo-random number generator

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

    /* ------------------------------- RTC Config ------------------------------- */
    HAL_RTC_MspInit();
    RTC_Init(&loiTruck);    
    RTC_CalendarConfig(&loiTruck);
    
    
    
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

    //send_fake_heart_beat.start(send_fake); // Start an independent thread to send fake heart beat
    
    /* -------------------------------- Scenario -------------------------------- */
    if (find_Scenario(&loiTruck)){
      Serial.println("M7: Found First Scenario");
      if (RTC_AlarmConfig(&loiTruck)){ // set alarm for start of scenario
        Serial.println("M7: Alarm Config OK");
      } else {
        Serial.println("M7: Alarm Config error");
      }                    
    }
}


void loop() {
  /* --------------- put your main code here, to run repeatedly: -------------- */
  // Send fake heart beat
  /* ---------------------- Send Fake Heart Beat message ---------------------- */
  if (loiTruck.timestamp){

    
    //Serial.println("TimeStamp trigger!");
    loiTruck.fake_heart_beat = true;
    //Serial.print("Size of fake: "); Serial.println(sizeof(fake));
    
    
    
    for (int i = 0; i < 24; i++){        
      
      if (my_can_write(&loiTruck.my_can, fake[i],0,&loiTruck)){

      } else {
          //Error_Handler();
          Serial.println("Error");
      } 

    }
    loiTruck.fake_heart_beat = false; 
    loiTruck.timestamp = false;

  }
  
  

  /* -------------------------------------------------------------------------- */
  /* ----------------------------- Read and Reply ----------------------------- */
  /* -------------------------------------------------------------------------- */

  if (loiTruck.receiveMsg){

     //Serial.println("Receive mess");
    
    
    
    if (HAL_FDCAN_GetRxMessage(&loiTruck.my_can.CanHandle, FDCAN_RX_FIFO0, &loiTruck.RxHeader, loiTruck.RxData) != HAL_OK){
        //Serial.println("Error Handler");
        Error_Handler();
      
    } else {      
    

    
    /*
    Serial.println("*****************************");
    Serial.print("R :\t"); Serial.print(loiTruck.RxHeader.Identifier,HEX); Serial.print(" ");

    
    
    for (uint8_t i = 0; i < (loiTruck.RxHeader.DataLength >> 16); i++){
      Serial.print(" ");
      Serial.print(loiTruck.RxData[i], HEX); 
    }

    Serial.println(); 
    */   
      // READ COMMAND
      if ((((loiTruck.RxData[0] & 0xF0) == 0x40) | ((loiTruck.RxData[0] & 0xF0) == 0x60) | loiTruck.segmented)){        
          
          if (read_parameter(&loiTruck)){
              loiTruck.TxHeader.Identifier = prepare_ID(loiTruck.RxHeader.Identifier);
              if (my_can_write(&loiTruck.my_can, CANMessage(loiTruck.TxHeader.Identifier,loiTruck.TxData,8), 8, &loiTruck)){
              
              } else {
                Error_Handler();
              }            
          }
          
      // WRITE COMMAND                                                            
      } else if ((loiTruck.RxData[0] & 0xF0) == 0x20) {
        
        //Serial.println("Write Command!");
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

  

  
  /*
  if (loiTruck.Rx_Fifo0_full){
    Serial.println("FIFO full");
    loiTruck.Rx_Fifo0_full = false;
    
  }

  if (loiTruck.timeout){
    //Serial.println("Timeout occur!");
    loiTruck.timeout = false;
  }
  */
  
  
  /* -------------------------------------------------------------------------- */
  /* ---------------------------------- xxxx ---------------------------------- */
  /* -------------------------------------------------------------------------- */
 
  /* -------------------------------------------------------------------------- */
  /* ----------------------------- Print out Alarm ---------------------------- */
  /* -------------------------------------------------------------------------- */
  
  

  // nested to ensure call only 1
  if (loiTruck.alarm){
  
  if ((loiTruck.triggered) && (!loiTruck.finish_Scenario)){
    // signal R7 start of Scenario
    Serial.println("-------------------------------------");
    Serial.println("|        Start of Scenario          |");

    
      
        

    // set Scenario var
    switch (convert_Scenario_To_Code(loiTruck.current_Scenario))
    {
    case 1: // delay
      loiTruck.delay = loiTruck.current_Scenario->_output_timestamp;
      break;
    case 2: // predefined CAN
      // not yet
      break;
    case 3: // function
      {
      // calculate sample rate
      loiTruck.sample_rate = (int)((loiTruck.current_Scenario->_duration * 1000)/250); // to ensure buffer_index < 256
      
      struct SDO* found = find_value(&loiTruck.my_SDO_List, loiTruck.current_Scenario->_output_function->_SDO_value);

      Serial.print("Sample Rate:"); Serial.println(loiTruck.sample_rate);
      Serial.print("Manipulate Address:"); Serial.println(found->address, HEX);
      
      double temp_a = loiTruck.current_Scenario->_output_function->_a;
      double temp_b = loiTruck.current_Scenario->_output_function->_b;
      double temp_c = loiTruck.current_Scenario->_output_function->_c;
      double temp_d = loiTruck.current_Scenario->_output_function->_d;
      
      // calculate buffer
      if (!loiTruck.current_Scenario->_output_function->_sin){
        for (int i = 0; i < 256; i++){
        loiTruck.mani_buffer[i] = (int) (temp_a * (i * loiTruck.sample_rate) * (i * loiTruck.sample_rate) * (i * loiTruck.sample_rate) + \
                                        temp_b * (i * loiTruck.sample_rate) * (i * loiTruck.sample_rate) + \          
                                        temp_c * (i * loiTruck.sample_rate) + \
                                        temp_d);
        }  
      } else {
        for (int i = 0; i < 256; i++){
        loiTruck.mani_buffer[i] = (int) (temp_a * sin(i * loiTruck.sample_rate) * sin(i * loiTruck.sample_rate) * sin(i * loiTruck.sample_rate) + \
                                        temp_b * sin(i * loiTruck.sample_rate) * sin(i * loiTruck.sample_rate) + \          
                                        temp_c * sin(i * loiTruck.sample_rate) + \
                                        temp_d);
        }  
      }
      
       // Call M4
       //RPC1.call("updateData",5,0); // for example only
      
      
            
        
      }
      break;
    case 4: // ignore
      loiTruck.ignore = true;
      break;
    default:
      break;
    }

    RPC1.call("updateData",4, 0);

    //RTC_AlarmConfig(&loiTruck); // set next alarm

  } else if ((loiTruck.triggered) && (loiTruck.finish_Scenario)){
    // signal R7 end of Scenario

    // reset loiTruck Scenario var
      
      loiTruck.finish_Scenario = false;
      loiTruck.ignore = false;
      loiTruck.delay = 0;
      loiTruck.send_predefined_CAN = false;
      //loiTruck.manipulate_var = false;      
      loiTruck.sample_rate = 0;
      loiTruck.last_millis = 0;
      
    
    Serial.println("|         Stop of Scenario          |");
    Serial.println("-------------------------------------");    
    //RPC1.call("updateData",5, loiTruck.delay);    
    loiTruck.triggered = false;  
    
    // reset Scenario var


    // find next Scenario
    if (find_Scenario(&loiTruck)){
      Serial.println("Found Next Scenario");
      RTC_CalendarConfig(&loiTruck);
      RTC_AlarmConfig(&loiTruck);
        
      
      loiTruck.buffer_index = 0;
    }
  }
    loiTruck.alarm = false;
  } 
    
  // call fucntion if needed
  if ((loiTruck.triggered) && (!loiTruck.finish_Scenario) && (!loiTruck.alarm)){
      //Serial.println("Manipulate");
      // call func
      if ((millis() - loiTruck.last_millis) >= loiTruck.sample_rate){
        // update last_millis
        //Serial.println((millis() - loiTruck.last_millis));
        loiTruck.last_millis = millis();
        // call manipulate function
        if (loiTruck.buffer_index < 256){
          manipulate_SDO_on_SRAM(*(loiTruck.current_Scenario->_output_function), loiTruck.buffer_index++, &loiTruck);  
          
        } 
        
      }
   }
  
  
  /* -------------------------------------------------------------------------- */
  /*
  if (loiTruck.timer6){
    Serial.println("Timer");
    loiTruck.timer6 = false;
  } else {
    
  }
  */

   

  /* -------------------------------------------------------------------------- */
  /* ---------------------------------- xxxx ---------------------------------- */
  /* -------------------------------------------------------------------------- */

  
  String buffer = "";
  while (RPC1.available()){
    buffer += (char)RPC1.read();
  }

  if (buffer.length() > 0){
    Serial.println(buffer);
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
    
    //Serial.println("1");
    //RPC1.println("setup M4 is called");
    
}

void loop(){

  /* -------------------------------------------------------------------------- */
  /* --------------------------- Check next Scenario -------------------------- */
  /* -------------------------------------------------------------------------- */

  

  
  
}


#endif
