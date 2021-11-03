#include "mbed.h"
#include <ThreadDebug.h>
#include "loiTruck_SDO.h"
#include "Scenario.h"


// For TRACE32 Debug
//USBSerial SerialUSB1(false, "DebugPort");
//UsbDebugCommInterface debugComm(&SerialUSB1);
//ThreadDebug           threadDebug(&debugComm, DEBUG_BREAK_IN_SETUP);

using namespace mbed;

/**********CAN GLOBAL VAR*************/
can_t my_can; // mbed CAN object
char counter = 0; 
CAN_Message msg; // mbed CAN message object
FDCAN_RxHeaderTypeDef RxHeader; // HAL RxHeader object
FDCAN_TxHeaderTypeDef TxHeader; // HAL TxHeader object
uint8_t RxData[8]; // Buffer to save RxData
uint8_t TxData[8]; // Buffer to save TxData
FDCAN_ErrorCountersTypeDef error_counter; // Error Counter

/********BOOL VAR FOR TESTING********/
bool receiveMsg = false;
bool Rx_Fifo0_full = false;
bool timeout = false;
bool interrupt = false;
uint32_t Rx_IT_Number = 0;
bool timestamp = false;
bool found_parameter = false;
bool sendMsg = false;
bool fake_heart_beat = false;

/**********SRAM GLOBAL VAR*************/
SRAM_HandleTypeDef hsram;
FMC_NORSRAM_TimingTypeDef timing;
FMC_NORSRAM_TimingTypeDef Extiming;
uint32_t aTxBuffer[16];
uint32_t aRxBuffer[16];
uint16_t uwIndex;
uint32_t Hash_Int = 0x00000F0F;
SDO* my_SDO_List = NULL;

/**********FOR SEGMENTED*************/
uint8_t segment_count = 0;
bool segmented = false;
uint8_t add_count = 0;
uint8_t rest_count = 0;
uint32_t rest_char = 0;
uint16_t bit_swap = 0;

/**********FOR RTC*************/
RTC_HandleTypeDef hrtc;
RTC_TimeTypeDef RTC_TimeRead;
RTC_DateTypeDef RTC_DateRead;
EXTI_HandleTypeDef hexti;
EXTI_ConfigTypeDef ExtiConfig;
bool alarm = false;

/**********FOR SCENARIO*************/
My_Function function_linear(0.0,0.0,1.0,1.0); 
Scenario Scenario_1(IN_TIME_STAMP, OUT_NONE, NULL, 10, NULL, 0, &function_linear, 10);

/**********FOR TIMER*************/
TIM_HandleTypeDef htimer6;
bool timer6 = false;

/************************************************************************/
/***********************      CODE AREA     *****************************/
/************************************************************************/


/************************************************************************/
/*                            TIMER SECTION                             */
/************************************************************************/


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


/************************************************************************/
/*                            RTC SECTION                               */
/************************************************************************/

void RTC_Init(void){
    hrtc.Instance = RTC;
    hrtc.Init.HourFormat = RTC_HOURFORMAT_24;
    hrtc.Init.AsynchPrediv = 0x7F; 
    hrtc.Init.SynchPrediv = 0xFF;
    hrtc.Init.OutPut = RTC_OUTPUT_DISABLE;
    hrtc.Init.OutPutPolarity = RTC_OUTPUT_POLARITY_LOW;
    hrtc.Init.OutPutType = RTC_OUTPUT_TYPE_OPENDRAIN;

    if (HAL_RTC_Init(&hrtc) != HAL_OK){
      Serial.println("HAL_RTC_Init error!");
    } else {
      Serial.println("HAL_RTC_Init OK!");
    }
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
       Serial.println("HAL_RTC_SetTime error!"); 
    } else  {
      Serial.println("HAL_RTC_SetTime OK!");
    }

    RTC_DateInit.Date = 12;
    RTC_DateInit.Month = RTC_MONTH_JUNE;
    RTC_DateInit.Year = 18;
    RTC_DateInit.WeekDay = RTC_WEEKDAY_TUESDAY;

    if (HAL_RTC_SetDate(&hrtc, &RTC_DateInit, RTC_FORMAT_BIN)!= HAL_OK){
      Serial.println("HAL_RTC_SetDate error!");
    } else  {
      Serial.println("HAL_RTC_SetDate OK!");
    }
}





void RTC_Alarm_IRQHandler(void){
  //Serial.println("error");  
    HAL_RTC_AlarmIRQHandler(&hrtc);
}

void HAL_RTC_AlarmAEventCallback(RTC_HandleTypeDef *hrtc){
  // when alarm ring, enable timer interrupt and set alarm 5s later
  if (!alarm){
    // enable interrupt
    TIMER6_Init();
    RTC_AlarmConfig(12);
    alarm = true;
  } else {
    alarm = false;
  }
  
  
}

void RTC_AlarmConfig(uint8_t second){
   //Serial.println("Come Here!");
   RTC_AlarmTypeDef AlarmA_Set;

   memset(&AlarmA_Set,0,sizeof(AlarmA_Set));

   //HAL_RTC_DeactivateAlarm(&hrtc,RTC_ALARM_A);

   //xx:45:09
   AlarmA_Set.Alarm = RTC_ALARM_A;
   AlarmA_Set.AlarmTime.Minutes = 45;
   AlarmA_Set.AlarmTime.Seconds = second;
   AlarmA_Set.AlarmMask = RTC_ALARMMASK_DATEWEEKDAY | RTC_ALARMMASK_HOURS | RTC_ALARMMASK_MINUTES;
   AlarmA_Set.AlarmSubSecondMask = RTC_ALARMSUBSECONDMASK_NONE;
   if ( HAL_RTC_SetAlarm_IT(&hrtc, &AlarmA_Set, RTC_FORMAT_BIN) != HAL_OK)
   {
     //Error_handler();
     //Serial.println("Error");
   } else {
     //Serial.println("set alarm OK");
   }
  
}


/************************************************************************/
/*                          UTILITY SECTION                             */
/************************************************************************/


// check if it is in concerning range 0x601 -> 0x67F
bool check_COB_ID_range(uint32_t COB_ID)
{    
    //Serial.println(TxHeader.Identifier, HEX);
    if ((COB_ID) >= 0x601 && (COB_ID <= 0x67F))
    {
        return true;
    } else return false;
}

/**
 * function to calculate command ID
 * **/
uint8_t prepare_Command_ID(bool end_msg){
  uint8_t command_ID = RxData[0] & 0xF0;

      switch (command_ID) {
        case 0x20: // initiate domain download            
            command_ID = 0x60;  // Server reply                        
            break;
        case 0x00:  // download domain segment toggle = 0
            command_ID |= 0x20;  // or to remain toggle bit
            break;
        case 0x40:  // initiate domain upload
            if (RxData[2] == 0x24 && RxData[3] == 0x02)
            {
                command_ID |= 0x0B;    // follow Noris excel   
            } else {
                command_ID |= 0x03;  // n = 0; e = s = 1
            }
            
            break;        
        case 0x60:  // upload domain segment with toggle bit = 0
            if (end_msg) {command_ID = 0x01;} else {command_ID = 0x00;}
            break;
        case 0x70:  // upload domain segment with toggle bit = 1
            if (end_msg) {command_ID = 0x11;} else {command_ID = 0x10;}
            break;
        case 0xc0:  // initiate block download
            command_ID = 0xA0;
            break;
        default : // Unknown
            command_ID = 0x00;
            break;
        }    
    
    return command_ID;
}

/**
 * Write Parameter
 * **/
uint8_t write_parameter(void){
  uint32_t tmp = (RxData[2] << 16) + (RxData[1] << 8) + RxData[3];
  uint32_t value = (RxData[7] << 24) + (RxData[6] << 16) + (RxData[5] << 8) + RxData[4];
  struct SDO* found = find_value(&my_SDO_List, tmp);

  if ( found != NULL){
    *(__IO uint32_t *)(found->address) = value;
    TxData[0] = prepare_Command_ID(false);
    TxData[1] = RxData[1];
    TxData[2] = RxData[2];
    TxData[3] = RxData[3];
    TxData[4] = 0x00;
    TxData[5] = 0x00;
    TxData[6] = 0x00;
    TxData[7] = 0x00;
  } else {
    TxData[0] = prepare_Command_ID(false);
    TxData[1] = RxData[1];
    TxData[2] = RxData[2];
    TxData[3] = RxData[3];
    TxData[4] = 0x00;
    TxData[5] = 0x00;
    TxData[6] = 0x00;
    TxData[7] = 0x00;
    return 0;
  }
  
  return 1;
}



/**
 * Read Parameter
 * */
uint8_t read_parameter(void){
  uint32_t tmp = (RxData[2] << 16) + (RxData[1] << 8) + RxData[3];
  struct SDO* found = find_value(&my_SDO_List, tmp);
  uint8_t reply = 0;
  
  //Serial.print("Value to find:");
  //Serial.println(tmp, HEX);
  
  //Serial.println(found->value, HEX);
  if (check_COB_ID_range(RxHeader.Identifier)){
    reply = 1;
    Serial.println("In Range");
    if (found == NULL){
    TxData[0] = prepare_Command_ID(false);
    TxData[1] = RxData[1];
    TxData[2] = RxData[2];
    TxData[3] = RxData[3];
    TxData[4] = 0x00;
    TxData[5] = 0x00;
    TxData[6] = 0x00;
    TxData[7] = 0x00;
    found_parameter = false;

    
  } else {
    //Serial.println("Hier"); 
    // if segmented or not
    if (found->segmented){
      // first message
      if (segment_count == 0){
        segmented = true;   // Flag at the beginning
        add_count = 0;
        bit_swap = 0;
        rest_char = 0;

        TxData[0] = 0x41;   // to send data length
        TxData[1] = RxData[1];
        TxData[2] = RxData[2];
        TxData[3] = RxData[3];
        TxData[4] = found->length;  
        TxData[5] = 0x00;
        TxData[6] = 0x00;
        TxData[7] = 0x00;

        

        segment_count++;
      // normal message
      } else if ((segment_count <= (found->length / 7.0)) && ((RxData[0] == 0x60) | (RxData[0] == 0x70))) { // each message send 7 bytes data
        // get 2 word EFG_ 
        uint32_t read_from_SRAM_1st = *(__IO uint32_t *)(found->address + ((add_count++) * 4));
        uint32_t read_from_SRAM_2nd = *(__IO uint32_t *)(found->address + ((add_count++) * 4));
        
        rest_count++;
        
        // 7 
        // 1(rest) + 6
        // 2(rest) + 5
        // 3(rest) + 4
        // 4(rest) + 3

        switch (rest_count)
        {
        case 1:
          TxData[0] = bit_swap;  
          TxData[1] = read_from_SRAM_1st >> 24;
          TxData[2] = read_from_SRAM_1st >> 16;
          TxData[3] = read_from_SRAM_1st >> 8;
          TxData[4] = read_from_SRAM_1st;
          TxData[5] = read_from_SRAM_2nd >> 24;
          TxData[6] = read_from_SRAM_2nd >> 16;
          TxData[7] = read_from_SRAM_2nd >> 8;  
          rest_char = read_from_SRAM_2nd & 0x000000FF; // get the last byte
          break;
        case 2:
          TxData[0] = bit_swap;  
          TxData[1] = rest_char;
          TxData[2] = read_from_SRAM_1st >> 24;
          TxData[3] = read_from_SRAM_1st >> 16;
          TxData[4] = read_from_SRAM_1st >> 8;
          TxData[5] = read_from_SRAM_1st;
          TxData[6] = read_from_SRAM_2nd >> 24;
          TxData[7] = read_from_SRAM_2nd >> 16;  
          rest_char = read_from_SRAM_2nd & 0x0000FFFF; // get last 2 bytes
          break;
        case 3:
          TxData[0] = bit_swap;  
          TxData[1] = rest_char >> 8;
          TxData[2] = rest_char;
          TxData[3] = read_from_SRAM_1st >> 24;
          TxData[4] = read_from_SRAM_1st >> 16;
          TxData[5] = read_from_SRAM_1st >> 8;
          TxData[6] = read_from_SRAM_1st;
          TxData[7] = read_from_SRAM_2nd >> 24;  
          rest_char = read_from_SRAM_2nd & 0x00FFFFFF; // get last 3 bytes
          break;
        case 4:
          TxData[0] = bit_swap;  
          TxData[1] = rest_char >> 16;
          TxData[2] = rest_char >> 8;
          TxData[3] = rest_char;
          TxData[4] = read_from_SRAM_1st >> 24;
          TxData[5] = read_from_SRAM_1st >> 16;
          TxData[6] = read_from_SRAM_1st >> 8;
          TxData[7] = read_from_SRAM_1st;  
          rest_char = 0; // delay 1 addres
          add_count--;
          break;
        
        default:
          break;
        }
        
        
        bit_swap ^= 0x10;
        
        

        
        //Serial.println("*****SEGMENT****");

        segment_count++;       
      // terminate message
      } else if (segment_count > (found->length / 7.0)){
        TxData[0] = 0x07;   // terminate
        TxData[1] = 0x00;
        TxData[2] = 0x00;
        TxData[3] = 0x00;
        TxData[4] = 0x00;  
        TxData[5] = 0x00;
        TxData[6] = 0x00;
        TxData[7] = 0x00; 

        //Serial.println("*****FINAL SEGMENT****");
        segmented = false;        
        segment_count = 0;
        add_count = 0;
        rest_count = 0;
      }

    // Not segmented      
    } else {
        uint32_t read_from_SRAM_1st = *(__IO uint32_t *)(found->address);        

        TxData[0] = prepare_Command_ID(false);   
        TxData[1] = RxData[1];
        TxData[2] = RxData[2];
        TxData[3] = RxData[3];
        TxData[4] = read_from_SRAM_1st >> 24;
        TxData[5] = read_from_SRAM_1st >> 16;
        TxData[6] = read_from_SRAM_1st >> 8;
        TxData[7] = read_from_SRAM_1st;
    }

    
  }
  }
  
  

  //Serial.println("Hier");
  found_parameter = true;
  return reply;

}


/**
 * Find value in Linked List
 * **/
struct SDO* find_value(struct SDO** head_ref, uint32_t value){
  struct SDO* last = *head_ref;

  if (*head_ref == NULL){
    return NULL;
  } 
    
  // traverse until the end
  while (last->next != NULL){
    if (last->value == value) 
      { 
        break;
      } else {
        last = last->next;    
      }    
  }

  if (last->value == value){
    return last;
  } else {
    return NULL;
  }

  return last;

}

/**
 * Append 1 node into linked list 
**/
void append_Linked_List(struct SDO** head_ref, struct SDO* temp_node){
  
  struct SDO *last = *head_ref;
  struct SDO* new_node = (struct SDO*) malloc(sizeof(struct SDO));

  // assign value
  new_node->index = temp_node->index;
  new_node->address = temp_node->address;
  new_node->value = temp_node->value;
  new_node->next = NULL;
  new_node->length = temp_node->length;
  new_node->segmented = temp_node->segmented;
    
  // if linked list is empty then make new node as head
  if (*head_ref == NULL){
    *head_ref = new_node;
    return;
  }

  // else traverse till the last node
  while (last->next != NULL)
    last = last->next;

  // change the next of last node
  last->next = new_node;
  return;
}

void display_Linked_List(void){
  struct SDO *tmp;
  if (my_SDO_List == NULL){
    return;
  } else {    
    tmp = my_SDO_List;
    while (tmp != NULL){
      Serial.println("****************");
      Serial.print("SDO index:"); Serial.println(tmp->index);
      Serial.print("SDO address:"); Serial.println(tmp->address, HEX);
      Serial.print("SDO value:"); Serial.println(tmp->value, HEX);

      tmp = tmp->next;
    }
  }
}

/* https://github.com/STMicroelectronics/STM32CubeG4/blob/master/Projects/STM32G474E-EVAL/Examples/FMC/FMC_SRAM/Src/main.c */
static void Fill_Buffer(uint32_t *pBuffer, uint32_t uwBufferLength, uint16_t uwOffset){
  uint16_t tmpIndex = 0;

  for (tmpIndex = 0; tmpIndex < uwBufferLength; tmpIndex++){
    pBuffer[tmpIndex] = tmpIndex + uwOffset;
  }
}

/************************************************************************/
/*                             SRAM SECTION                             */
/************************************************************************/

uint8_t write_SDO_to_SRAM(void){
  uwIndex = 0;
  
struct SDO temp(0,0,0,NULL,0,false);

  //Serial.println(CRC_Hash_Function(200000));
#ifdef res_2000_00 
  *(__IO uint32_t *)(SRAM_BANK_ADDR + WRITE_READ_ADDR + (4*res_2000_00_indx)) = res_2000_00;
  
  // create SDO object and add to linked list
  temp = SDO(res_2000_00_indx,SRAM_BANK_ADDR + WRITE_READ_ADDR + (4*res_2000_00_indx),0x200000,NULL,0x01,false);  
  append_Linked_List(&my_SDO_List, &temp);
#endif


#ifdef res_2000_01 
  *(__IO uint32_t *)(SRAM_BANK_ADDR + WRITE_READ_ADDR + (4*res_2000_01_indx)) = res_2000_01;
  //Serial.println(res_2000_01_indx);
  temp = SDO(res_2000_01_indx,SRAM_BANK_ADDR + WRITE_READ_ADDR + (4*res_2000_01_indx),0x200001,NULL,0x01,false);
  append_Linked_List(&my_SDO_List, &temp);

  //display_Linked_List();
#endif


#ifdef res_2000_03 
  *(__IO uint32_t *)(SRAM_BANK_ADDR + WRITE_READ_ADDR + (4*res_2000_03_indx)) = res_2000_03;
  //Serial.println(res_2000_03_indx);
  temp = SDO(res_2000_03_indx,SRAM_BANK_ADDR + WRITE_READ_ADDR + (4*res_2000_03_indx),0x200003,NULL,0x01,false);
  append_Linked_List(&my_SDO_List, &temp);

 
#endif

#ifdef res_2002_02 
  *(__IO uint32_t *)(SRAM_BANK_ADDR + WRITE_READ_ADDR + (4*res_2002_02_indx)) = res_2002_02;
  //Serial.println(res_2002_02_indx);
  temp = SDO(res_2002_02_indx,SRAM_BANK_ADDR + WRITE_READ_ADDR + (4*res_2002_02_indx),0x200202,NULL,0x01,false);
  append_Linked_List(&my_SDO_List, &temp);
#endif

#ifdef res_2020_02    
  *(__IO uint32_t *)(SRAM_BANK_ADDR + WRITE_READ_ADDR + (4*res_2020_02_indx)) = res_2020_02;
  //Serial.println(res_2020_02_indx);
  temp = SDO(res_2020_02_indx,SRAM_BANK_ADDR + WRITE_READ_ADDR + (4*res_2020_02_indx),0x202002,NULL,0x01,false);
  append_Linked_List(&my_SDO_List, &temp);
#endif

#ifdef res_2100_02
  *(__IO uint32_t *)(SRAM_BANK_ADDR + WRITE_READ_ADDR + (4*res_2100_02_indx)) = res_2100_02;
  //Serial.println(res_2100_02_indx);
  temp = SDO(res_2100_02_indx,SRAM_BANK_ADDR + WRITE_READ_ADDR + (4*res_2100_02_indx),0x210002,NULL,0x01,false);
  append_Linked_List(&my_SDO_List, &temp);
#endif

#ifdef res_2102_02
  *(__IO uint32_t *)(SRAM_BANK_ADDR + WRITE_READ_ADDR + (4*res_2102_02_indx)) = res_2102_02;
  //Serial.println(res_2102_02_indx);
  temp = SDO(res_2102_02_indx,SRAM_BANK_ADDR + WRITE_READ_ADDR + (4*res_2102_02_indx),0x210202,NULL,0x01,false);
  append_Linked_List(&my_SDO_List, &temp);
#endif

#ifdef res_2102_06
  *(__IO uint32_t *)(SRAM_BANK_ADDR + WRITE_READ_ADDR + (4*res_2102_06_indx)) = res_2102_06;
  //Serial.println(res_2102_06_indx);
  temp = SDO(res_2102_06_indx,SRAM_BANK_ADDR + WRITE_READ_ADDR + (4*res_2102_06_indx),0x210206,NULL,0x01,false);
  append_Linked_List(&my_SDO_List, &temp);
#endif

#ifdef res_2100_06
  *(__IO uint32_t *)(SRAM_BANK_ADDR + WRITE_READ_ADDR + (4*res_2000_03_indx)) = res_2000_03;
  //Serial.println(res_2000_03_indx);
  temp = SDO(res_2000_03_indx,SRAM_BANK_ADDR + WRITE_READ_ADDR + (4*res_2000_03_indx),0x200003,NULL,0x01,false);
  append_Linked_List(&my_SDO_List, &temp);
#endif

#ifdef res_2200_02
  *(__IO uint32_t *)(SRAM_BANK_ADDR + WRITE_READ_ADDR + (4*res_2200_02_indx)) = res_2200_02;
  //Serial.println(res_2200_02_indx);
  temp = SDO(res_2200_02_indx,SRAM_BANK_ADDR + WRITE_READ_ADDR + (4*res_2200_02_indx),0x220002,NULL,0x01,false);
  append_Linked_List(&my_SDO_List, &temp);
#endif

#ifdef res_2200_06
  *(__IO uint32_t *)(SRAM_BANK_ADDR + WRITE_READ_ADDR + (4*res_2200_06_indx)) = res_2200_06;
  //Serial.println(res_2200_06_indx);
  temp = SDO(res_2200_06_indx,SRAM_BANK_ADDR + WRITE_READ_ADDR + (4*res_2200_06_indx),0x220006,NULL,0x01,false);
  append_Linked_List(&my_SDO_List, &temp);
#endif

#ifdef res_2001_01
  *(__IO uint32_t *)(SRAM_BANK_ADDR + WRITE_READ_ADDR + (4*res_2001_01_indx)) = res_2001_01;
  //Serial.println(res_2001_01_indx);
  temp = SDO(res_2001_01_indx,SRAM_BANK_ADDR + WRITE_READ_ADDR + (4*res_2001_01_indx),0x200101,NULL,0x01,false);
  append_Linked_List(&my_SDO_List, &temp);
#endif

#ifdef res_2101_02
  *(__IO uint32_t *)(SRAM_BANK_ADDR + WRITE_READ_ADDR + (4*res_2101_02_indx)) = res_2101_02;
  //Serial.println(res_2101_02_indx); 
  temp = SDO(res_2101_02_indx,SRAM_BANK_ADDR + WRITE_READ_ADDR + (4*res_2101_02_indx),0x210102,NULL,0x01,false);
  append_Linked_List(&my_SDO_List, &temp);
#endif

#ifdef res_2101_06
  *(__IO uint32_t *)(SRAM_BANK_ADDR + WRITE_READ_ADDR + (4*res_2101_06_indx)) = res_2101_06;
  //Serial.println(res_2101_06_indx);
  temp = SDO(res_2101_06_indx,SRAM_BANK_ADDR + WRITE_READ_ADDR + (4*res_2101_06_indx),0x210106,NULL,0x01,false);
  append_Linked_List(&my_SDO_List, &temp);
#endif

#ifdef res_2201_02
  *(__IO uint32_t *)(SRAM_BANK_ADDR + WRITE_READ_ADDR + (4*res_2201_02_indx)) = res_2201_02;
  //Serial.println(res_2201_02_indx);
  temp = SDO(res_2201_02_indx,SRAM_BANK_ADDR + WRITE_READ_ADDR + (4*res_2201_02_indx),0x220102,NULL,0x01,false);
  append_Linked_List(&my_SDO_List, &temp);
#endif

#ifdef res_2201_06
  *(__IO uint32_t *)(SRAM_BANK_ADDR + WRITE_READ_ADDR + (4*res_2201_06_indx)) = res_2201_06;
  //Serial.println(res_2201_06_indx);
  temp = SDO(res_2201_06_indx,SRAM_BANK_ADDR + WRITE_READ_ADDR + (4*res_2201_06_indx),0x220106,NULL,0x01,false);
  append_Linked_List(&my_SDO_List, &temp);
#endif

#ifdef res_2103_06
  *(__IO uint32_t *)(SRAM_BANK_ADDR + WRITE_READ_ADDR + (4*res_2103_06_indx)) = res_2103_06;
  //Serial.println(res_2103_06_indx);
  temp = SDO(res_2103_06_indx,SRAM_BANK_ADDR + WRITE_READ_ADDR + (4*res_2103_06_indx),0x210306,NULL,0x01,false);
  append_Linked_List(&my_SDO_List, &temp);
#endif

#ifdef res_2103_02
  *(__IO uint32_t *)(SRAM_BANK_ADDR + WRITE_READ_ADDR + (4*res_2103_02_indx)) = res_2103_02;
  //Serial.println(res_2103_02_indx);
  temp = SDO(res_2103_02_indx,SRAM_BANK_ADDR + WRITE_READ_ADDR + (4*res_2103_02_indx),0x210302,NULL,0x01,false);
  append_Linked_List(&my_SDO_List, &temp);
#endif

#ifdef res_2104_02
  *(__IO uint32_t *)(SRAM_BANK_ADDR + WRITE_READ_ADDR + (4*res_2104_02_indx)) = res_2104_02;
  //Serial.println(res_2104_02_indx);
  temp = SDO(res_2104_02_indx,SRAM_BANK_ADDR + WRITE_READ_ADDR + (4*res_2104_02_indx),0x210402,NULL,0x01,false);
  append_Linked_List(&my_SDO_List, &temp);
#endif

#ifdef res_2106_06
  *(__IO uint32_t *)(SRAM_BANK_ADDR + WRITE_READ_ADDR + (4*res_2106_06_indx)) = res_2106_06;
  //Serial.println(res_2106_06_indx);
  temp = SDO(res_2106_06_indx,SRAM_BANK_ADDR + WRITE_READ_ADDR + (4*res_2106_06_indx),0x210606,NULL,0x01,false);
  append_Linked_List(&my_SDO_List, &temp);
#endif

#ifdef res_2002_01
  *(__IO uint32_t *)(SRAM_BANK_ADDR + WRITE_READ_ADDR + (4*res_2002_01_indx)) = res_2002_01;
  //Serial.println(res_2002_01_indx);
  temp = SDO(res_2002_01_indx,SRAM_BANK_ADDR + WRITE_READ_ADDR + (4*res_2002_01_indx),0x200201,NULL,0x01,false);
  append_Linked_List(&my_SDO_List, &temp);
#endif

#ifdef res_2020_01
  *(__IO uint32_t *)(SRAM_BANK_ADDR + WRITE_READ_ADDR + (4*res_2020_01_indx)) = res_2020_01;
  //Serial.println(res_2020_01_indx);
  temp = SDO(res_2020_01_indx,SRAM_BANK_ADDR + WRITE_READ_ADDR + (4*res_2020_01_indx),0x202001,NULL,0x01,false);
  append_Linked_List(&my_SDO_List, &temp);
#endif

#ifdef res_2413_02
  *(__IO uint32_t *)(SRAM_BANK_ADDR + WRITE_READ_ADDR + (4*res_2413_02_indx)) = res_2413_02;
  //Serial.println(res_2413_02_indx);
  temp = SDO(res_2413_02_indx,SRAM_BANK_ADDR + WRITE_READ_ADDR + (4*res_2413_02_indx),0x241302,NULL,0x01,false);
  append_Linked_List(&my_SDO_List, &temp);
#endif

#ifdef res_2923_02
  *(__IO uint32_t *)(SRAM_BANK_ADDR + WRITE_READ_ADDR + (4*res_2923_02_indx)) = res_2923_02;
  //Serial.println(res_2923_02_indx);
  temp = SDO(res_2923_02_indx,SRAM_BANK_ADDR + WRITE_READ_ADDR + (4*res_2923_02_indx),0x292302,NULL,0x01,false);
  append_Linked_List(&my_SDO_List, &temp);
#endif

#ifdef res_2414_02
  *(__IO uint32_t *)(SRAM_BANK_ADDR + WRITE_READ_ADDR + (4*res_2414_02_indx)) = res_2414_02;
  //Serial.println(res_2414_02_indx);
  temp = SDO(res_2414_02_indx,SRAM_BANK_ADDR + WRITE_READ_ADDR + (4*res_2414_02_indx),0x241402,NULL,0x01,false);
  append_Linked_List(&my_SDO_List, &temp);
#endif

#ifdef res_2461_02
  *(__IO uint32_t *)(SRAM_BANK_ADDR + WRITE_READ_ADDR + (4*res_2461_02_indx)) = res_2461_02;
  //Serial.println(res_2461_02_indx);
  temp = SDO(res_2461_02_indx,SRAM_BANK_ADDR + WRITE_READ_ADDR + (4*res_2461_02_indx),0x246102,NULL,0x01,false);
  append_Linked_List(&my_SDO_List, &temp);
#endif

#ifdef res_2001_02 
  *(__IO uint32_t *)(SRAM_BANK_ADDR + WRITE_READ_ADDR + (4*res_2001_02_indx)) = res_2001_02;
  //Serial.println(res_2001_02_indx);
  temp = SDO(res_2001_02_indx,SRAM_BANK_ADDR + WRITE_READ_ADDR + (4*res_2001_02_indx),0x200102,NULL,0x01,false);
  append_Linked_List(&my_SDO_List, &temp);
#endif

#ifdef res_2001_03    
  *(__IO uint32_t *)(SRAM_BANK_ADDR + WRITE_READ_ADDR + (4*res_2001_03_indx)) = res_2001_03;
  //Serial.println(res_2001_03_indx);
  temp = SDO(res_2001_03_indx,SRAM_BANK_ADDR + WRITE_READ_ADDR + (4*res_2001_03_indx),0x200103,NULL,0x01,false);
  append_Linked_List(&my_SDO_List, &temp);
#endif

#ifdef res_2411_02
  *(__IO uint32_t *)(SRAM_BANK_ADDR + WRITE_READ_ADDR + (4*res_2411_02_indx)) = res_2411_02;
  //Serial.println(res_2411_02_indx);
  temp = SDO(res_2411_02_indx,SRAM_BANK_ADDR + WRITE_READ_ADDR + (4*res_2411_02_indx),0x241102,NULL,0x01,false);
  append_Linked_List(&my_SDO_List, &temp);
#endif

#ifdef res_2405_02
  *(__IO uint32_t *)(SRAM_BANK_ADDR + WRITE_READ_ADDR + (4*res_2405_02_indx)) = res_2405_02;
  temp = SDO(res_2405_02_indx,SRAM_BANK_ADDR + WRITE_READ_ADDR + (4*res_2405_02_indx),0x240502,NULL,0x01,false);
  append_Linked_List(&my_SDO_List, &temp);
#endif

#ifdef res_2402_02
  *(__IO uint32_t *)(SRAM_BANK_ADDR + WRITE_READ_ADDR + (4*res_2402_02_indx)) = res_2402_02;
  //Serial.println(res_2402_02_indx);
  temp = SDO(res_2402_02_indx,SRAM_BANK_ADDR + WRITE_READ_ADDR + (4*res_2402_02_indx),0x240202,NULL,0x01,false);
  append_Linked_List(&my_SDO_List, &temp);
#endif

#ifdef res_2405_07
  *(__IO uint32_t *)(SRAM_BANK_ADDR + WRITE_READ_ADDR + (4*res_2405_07_indx)) = res_2405_07;
  //Serial.println(res_2405_07_indx);
  temp = SDO(res_2405_07_indx,SRAM_BANK_ADDR + WRITE_READ_ADDR + (4*res_2405_07_indx),0x240507,NULL,0x01,false);
  append_Linked_List(&my_SDO_List, &temp);
#endif

#ifdef res_2460_02
  *(__IO uint32_t *)(SRAM_BANK_ADDR + WRITE_READ_ADDR + (4*res_2460_02_indx)) = res_2460_02;
  //Serial.println(res_2460_02_indx);
  temp = SDO(res_2460_02_indx,SRAM_BANK_ADDR + WRITE_READ_ADDR + (4*res_2460_02_indx),0x246002,NULL,0x01,false);
  append_Linked_List(&my_SDO_List, &temp);
#endif

#ifdef res_2404_02
  *(__IO uint32_t *)(SRAM_BANK_ADDR + WRITE_READ_ADDR + (4*res_2404_02_indx)) = res_2404_02;
  //Serial.println(res_2404_02_indx);
  temp = SDO(res_2404_02_indx,SRAM_BANK_ADDR + WRITE_READ_ADDR + (4*res_2404_02_indx),0x240402,NULL,0x01,false);
  append_Linked_List(&my_SDO_List, &temp);
#endif

#ifdef res_2401_02
  *(__IO uint32_t *)(SRAM_BANK_ADDR + WRITE_READ_ADDR + (4*res_2401_02_indx)) = res_2401_02;
  //Serial.println(res_2401_02_indx);
  temp = SDO(res_2401_02_indx,SRAM_BANK_ADDR + WRITE_READ_ADDR + (4*res_2401_02_indx),0x240102,NULL,0x01,false);
  append_Linked_List(&my_SDO_List, &temp);
#endif

#ifdef res_2403_02 
  *(__IO uint32_t *)(SRAM_BANK_ADDR + WRITE_READ_ADDR + (4*res_2403_02_indx)) = res_2403_02;
  //Serial.println(res_2403_02_indx);
  temp = SDO(res_2403_02_indx,SRAM_BANK_ADDR + WRITE_READ_ADDR + (4*res_2403_02_indx),0x240302,NULL,0x01,false);
  append_Linked_List(&my_SDO_List, &temp);
#endif

#ifdef res_2400_02    
  *(__IO uint32_t *)(SRAM_BANK_ADDR + WRITE_READ_ADDR + (4*res_2400_02_indx)) = res_2400_02;
  //Serial.println(res_2400_02_indx);
  temp = SDO(res_2400_02_indx,SRAM_BANK_ADDR + WRITE_READ_ADDR + (4*res_2400_02_indx),0x240002,NULL,0x01,false);
  append_Linked_List(&my_SDO_List, &temp);
#endif

#ifdef res_2403_07
  *(__IO uint32_t *)(SRAM_BANK_ADDR + WRITE_READ_ADDR + (4*res_2403_07_indx)) = res_2403_07;
  //Serial.println(res_2403_07_indx);
  temp = SDO(res_2403_07_indx,SRAM_BANK_ADDR + WRITE_READ_ADDR + (4*res_2403_07_indx),0x240307,NULL,0x01,false);
  append_Linked_List(&my_SDO_List, &temp);
#endif

#ifdef res_2404_07 
  *(__IO uint32_t *)(SRAM_BANK_ADDR + WRITE_READ_ADDR + (4*res_2404_07_indx)) = res_2404_07;
  //Serial.println(res_2404_07_indx);
  temp = SDO(res_2404_07_indx,SRAM_BANK_ADDR + WRITE_READ_ADDR + (4*res_2404_07_indx),0x240407,NULL,0x01,false);
  append_Linked_List(&my_SDO_List, &temp);
#endif

#ifdef res_2405_03
  *(__IO uint32_t *)(SRAM_BANK_ADDR + WRITE_READ_ADDR + (4*res_2405_03_indx)) = res_2405_03;
  //Serial.println(res_2405_03_indx);
  temp = SDO(res_2405_03_indx,SRAM_BANK_ADDR + WRITE_READ_ADDR + (4*res_2405_03_indx),0x240503,NULL,0x01,false);
  append_Linked_List(&my_SDO_List, &temp);
#endif

#ifdef res_2404_03
  *(__IO uint32_t *)(SRAM_BANK_ADDR + WRITE_READ_ADDR + (4*res_2404_03_indx)) = res_2404_03;
  //Serial.println(res_2404_03_indx);
  temp = SDO(res_2404_03_indx,SRAM_BANK_ADDR + WRITE_READ_ADDR + (4*res_2404_03_indx),0x240403,NULL,0x01,false);
  append_Linked_List(&my_SDO_List, &temp);
#endif

#ifdef res_2403_03
  *(__IO uint32_t *)(SRAM_BANK_ADDR + WRITE_READ_ADDR + (4*res_2403_03_indx)) = res_2403_03;
  //Serial.println(res_2403_03_indx);
  temp = SDO(res_2403_03_indx,SRAM_BANK_ADDR + WRITE_READ_ADDR + (4*res_2403_03_indx),0x240303,NULL,0x01,false);
  append_Linked_List(&my_SDO_List, &temp);
#endif

#ifdef res_2405_04
  *(__IO uint32_t *)(SRAM_BANK_ADDR + WRITE_READ_ADDR + (4*res_2405_04_indx)) = res_2405_04;
  //Serial.println(res_2405_04_indx);
  temp = SDO(res_2405_04_indx,SRAM_BANK_ADDR + WRITE_READ_ADDR + (4*res_2405_04_indx),0x240504,NULL,0x01,false);
  append_Linked_List(&my_SDO_List, &temp);
#endif

#ifdef res_2404_04
  *(__IO uint32_t *)(SRAM_BANK_ADDR + WRITE_READ_ADDR + (4*res_2404_04_indx)) = res_2404_04;
  //Serial.println(res_2404_04_indx);
  temp = SDO(res_2404_04_indx,SRAM_BANK_ADDR + WRITE_READ_ADDR + (4*res_2404_04_indx),0x240404,NULL,0x01,false);
  append_Linked_List(&my_SDO_List, &temp);
#endif

#ifdef res_2403_04
  *(__IO uint32_t *)(SRAM_BANK_ADDR + WRITE_READ_ADDR + (4*res_2403_04_indx)) = res_2403_04;
  //Serial.println(res_2403_04_indx);
  temp = SDO(res_2403_04_indx,SRAM_BANK_ADDR + WRITE_READ_ADDR + (4*res_2403_04_indx),0x240304,NULL,0x01,false);
  append_Linked_List(&my_SDO_List, &temp);
#endif

#ifdef res_2402_07
  *(__IO uint32_t *)(SRAM_BANK_ADDR + WRITE_READ_ADDR + (4*res_2402_07_indx)) = res_2402_07;
  //Serial.println(res_2402_07_indx);
  temp = SDO(res_2402_07_indx,SRAM_BANK_ADDR + WRITE_READ_ADDR + (4*res_2402_07_indx),0x240207,NULL,0x01,false);
  append_Linked_List(&my_SDO_List, &temp);
#endif

#ifdef res_2401_07
  *(__IO uint32_t *)(SRAM_BANK_ADDR + WRITE_READ_ADDR + (4*res_2401_07_indx)) = res_2401_07;
  //Serial.println(res_2401_07_indx);
  temp = SDO(res_2401_07_indx,SRAM_BANK_ADDR + WRITE_READ_ADDR + (4*res_2401_07_indx),0x240107,NULL,0x01,false);
  append_Linked_List(&my_SDO_List, &temp);
#endif

#ifdef res_2400_07
  *(__IO uint32_t *)(SRAM_BANK_ADDR + WRITE_READ_ADDR + (4*res_2400_07_indx)) = res_2400_07;
  //Serial.println(res_2400_07_indx);
  temp = SDO(res_2400_07_indx,SRAM_BANK_ADDR + WRITE_READ_ADDR + (4*res_2400_07_indx),0x240007,NULL,0x01,false);
  append_Linked_List(&my_SDO_List, &temp);
#endif

#ifdef Truck_ID
  
  // create object SDO Truck_ID of length 0x20 = 32 and segmented = true
  temp = SDO(Truck_ID_indx,SRAM_BANK_ADDR + WRITE_READ_ADDR + (4*Truck_ID_indx),0x200204,NULL,0x20,true);
  String truck_id_temp = String(Truck_ID);
  //Serial.println("Hier");
  //Serial.println(ceil(temp.length / 4.0));
  
  for (uint8_t i = 0; i < ceil(temp.length / 4.0); i++){
    String temp_char = truck_id_temp.substring(i*4,i*4+4);  // get 4 letters
    Serial.print(i);Serial.print(":");
    Serial.println(temp_char);
    byte buf[temp_char.length() + 1];
    temp_char.getBytes(buf, temp_char.length() + 1);    
    uint32_t to_save = (buf[0] << 24) + (buf[1] << 16) + (buf[2] << 8) + buf[3];
    Serial.println(to_save, HEX);
    *(__IO uint32_t *)(SRAM_BANK_ADDR + WRITE_READ_ADDR + (4*(Truck_ID_indx + i))) = to_save;
  }
  uint8_t word_cnt = ceil(temp.length / 4.0);
  *(__IO uint32_t *)(SRAM_BANK_ADDR + WRITE_READ_ADDR + (4*(Truck_ID_indx + word_cnt))) = Truck_null_word;
  

  
  
  append_Linked_List(&my_SDO_List, &temp);
#endif

  

  return 1;
}

void init_SDO_object(void){
  //uint32_t *temp = (uint32_t *)(BASE_ADD + 200000);
  //HAL_SRAM_Write_16b();
  hsram.Instance = FMC_NORSRAM_DEVICE; // Base address of : (up to 512KB) system data RAM accessible over over AXI   
  hsram.Extended = FMC_NORSRAM_EXTENDED_DEVICE;
  /* at stm32h7xx_ll_fmc.h */
  hsram.Init.NSBank = FMC_NORSRAM_BANK1;      
  hsram.Init.DataAddressMux = FMC_DATA_ADDRESS_MUX_DISABLE;
  hsram.Init.MemoryType = FMC_MEMORY_TYPE_SRAM;
  hsram.Init.MemoryDataWidth = FMC_NORSRAM_MEM_BUS_WIDTH_32; 
  hsram.Init.BurstAccessMode = FMC_BURST_ACCESS_MODE_DISABLE;
  hsram.Init.WaitSignalPolarity = FMC_WAIT_SIGNAL_POLARITY_LOW;
  hsram.Init.WaitSignalActive = FMC_WAIT_TIMING_BEFORE_WS;
  hsram.Init.WriteOperation = FMC_WRITE_OPERATION_ENABLE;
  hsram.Init.ExtendedMode = FMC_EXTENDED_MODE_DISABLE;
  hsram.Init.AsynchronousWait = FMC_ASYNCHRONOUS_WAIT_DISABLE;
  hsram.Init.WriteBurst = FMC_WRITE_BURST_DISABLE;
  hsram.Init.ContinuousClock = FMC_CONTINUOUS_CLOCK_SYNC_ONLY;
  hsram.Init.WriteFifo = FMC_WRITE_FIFO_ENABLE;
  hsram.Init.PageSize = FMC_PAGE_SIZE_NONE;

  timing.AddressSetupTime = 2;
  timing.AddressHoldTime = 15;
  timing.DataSetupTime = 2;
  timing.BusTurnAroundDuration = 1;
  timing.CLKDivision = 16;
  timing.DataLatency = 17;
  timing.AccessMode = FMC_ACCESS_MODE_A;



  if (HAL_SRAM_Init(&hsram, &timing, NULL) != HAL_OK){
    Serial.println("HAL_SRAM_Init error");
  } else {
    Serial.println("HAL_SRAM_Init OK");
  }


  write_SDO_to_SRAM();


}


uint16_t prepare_ID(uint16_t ID_req){
  uint16_t node_ID = ID_req & 0x07F;
  return (node_ID | 0x580);
}



//uint8_t prepare_Data


/* from https://github.com/meomotminh/STM32CubeG4/blob/master/Projects/STM32G474E-EVAL/Examples/FDCAN/FDCAN_Com_IT/Src/main.c */
static uint32_t BufferCmp32b(uint32_t* pBuffer1, uint32_t* pBuffer2, uint16_t BufferLength){
  while (BufferLength--){
    if (*pBuffer1 != *pBuffer2)
    return 0;

    pBuffer1++;
    pBuffer2++;
  }

  return 1;
}

/************************************************************************/
/*                            FDCAN SECTION                             */
/************************************************************************/


void Set_Freq(can_t *obj, const can_pinmap_t *pinmap, int hz)
{

    MBED_ASSERT((int)pinmap->peripheral != NC);


    #if defined(__HAL_RCC_FDCAN1_CLK_ENABLE)
        __HAL_RCC_FDCAN1_CLK_ENABLE_();
    #else 
        __HAL_RCC_FDCAN_CLK_ENABLE();
    #endif

    
    if (pinmap->peripheral == CAN_1) {       
        obj->index = 0;
    }
    #if defined(FDCAN2_BASE)
    else if (pinmap->peripheral == CAN_2) {
        
        obj->index = 1;
    }
    #endif
    
    else {
        error("can_init wrong instance\n");
        return;
    }

    //Serial.println("Before Set Frequency!\n");
    
    // Set Frequency
    RCC_PeriphCLKInitTypeDef RCC_PeriphClkInit;
    #if (defined RCC_PERIPHCLK_FDCAN1)
        RCC_PeriphClkInit.PeriphClockSelection = RCC_PERIPHCLK_FDCAN1;
        RCC_PeriphClkInit.Fdcan1ClockSelection = RCC_FDCAN1CLKSOURCE_PLL1;
    #else 
        //Serial.println("Enter here!");
        RCC_PeriphClkInit.PeriphClockSelection = RCC_PERIPHCLK_FDCAN;
        RCC_PeriphClkInit.FdcanClockSelection = RCC_FDCANCLKSOURCE_PLL;
    #endif

    
    
   #if defined(DUAL_CORE) && (TARGET_STM32H7)
    while (LL_HSEM_1StepLock(HSEM, CFG_HW_RCC_SEMID)) {
    }
   #endif /* DUAL_CORE */
    if (HAL_RCCEx_PeriphCLKConfig(&RCC_PeriphClkInit) != HAL_OK) {
        //Serial.println("HAL_RCCEx_PeriphCLKConfig error\n");
    } else {
        //Serial.println("HAL_RCCEx_PeriphCLKConfig OK!");
    }
    #if defined(DUAL_CORE) && (TARGET_STM32H7)
    LL_HSEM_ReleaseLock(HSEM, CFG_HW_RCC_SEMID, HSEM_CR_COREID_CURRENT);
    #endif /* DUAL_CORE */


    // Config CAN pins
    pin_function(pinmap->rd_pin, pinmap->rd_function);
    pin_function(pinmap->td_pin, pinmap->td_function);

    // Add pull-ups
    pin_mode(pinmap->rd_pin, PullUp);
    pin_mode(pinmap->td_pin, PullUp);

    //digitalWrite(pinmap->td_pin, HIGH);         

    // Default Values
    obj->CanHandle.Instance = (FDCAN_GlobalTypeDef *)pinmap->peripheral;
      //Serial.println(obj);
      //Serial.print("Instance:"); Serial.println(pinmap->peripheral);
      
    

    #if (defined TARGET_STM32H7)
        PLL1_ClocksTypeDef pll1_clocks;
        HAL_RCCEx_GetPLL1ClockFreq(&pll1_clocks);
        //Serial.print("Hier Freq:"); Serial.println(pll1_clocks.PLL1_Q_Frequency);
        int ntq = pll1_clocks.PLL1_Q_Frequency / hz;  // 320

    #else
    #if (defined RCC_PERIPHCLK_FDCAN1)
        //Serial.println("Hier 2");  
        int ntq = HAL_RCCEx_GetPeriphCLKFreq(RCC_PERIPHCLK_FDCAN1) / hz;
    #else
        //Serial.println("Hier 2");  
        int ntq = HALL_RCCEx_GetPeriphCLKFreq(RCC_PERIPHCLK_FDCAN) / hz;
    #endif
    #endif

    //Serial.print("ntq:");  Serial.println(ntq);

    

    int nominalPrescaler = 1;
while (!IS_FDCAN_NOMINAL_TSEG1(ntq / nominalPrescaler)){ // > 1 && < 256
  nominalPrescaler++;   // = 2
  if (!IS_FDCAN_NOMINAL_PRESCALER(nominalPrescaler)){
    //Serial.println("Could not determine nominalPrescaler. Bad clock value\n");
  }
}
  
  ntq = ntq / nominalPrescaler; // = 320/2 = 160
  
  // Create CAN Handle init object
  obj->CanHandle.Init.FrameFormat = FDCAN_FRAME_CLASSIC;
  obj->CanHandle.Init.Mode = FDCAN_MODE_NORMAL;
  obj->CanHandle.Init.AutoRetransmission = DISABLE;
  obj->CanHandle.Init.TransmitPause = ENABLE;
  obj->CanHandle.Init.ProtocolException = DISABLE;
  
  obj->CanHandle.Init.NominalPrescaler = nominalPrescaler;
  obj->CanHandle.Init.NominalTimeSeg1 = ntq * 0.75;
  obj->CanHandle.Init.NominalTimeSeg2 = ntq - 1 - obj->CanHandle.Init.NominalTimeSeg1;
  obj->CanHandle.Init.NominalSyncJumpWidth = obj->CanHandle.Init.NominalTimeSeg2;
  // not used, only in FD CAN  
  obj->CanHandle.Init.DataPrescaler = 0x1;
  obj->CanHandle.Init.DataSyncJumpWidth = 0x1;
  obj->CanHandle.Init.DataTimeSeg1 = 0x1;
  obj->CanHandle.Init.DataTimeSeg2 = 0x1;
  
  // RAM offset
  obj->CanHandle.Init.MessageRAMOffset = 0;
  
   // fiCanHandle.lters
  obj->CanHandle.Init.StdFiltersNbr = 128;
  obj->CanHandle.Init.ExtFiltersNbr = 64;
  
  obj->CanHandle.Init.RxFifo0ElmtsNbr = 3;
  obj->CanHandle.Init.RxFifo1ElmtSize = FDCAN_DATA_BYTES_8;
  obj->CanHandle.Init.RxFifo1ElmtsNbr = 0;
  obj->CanHandle.Init.RxBuffersNbr = 0;
  obj->CanHandle.Init.RxFifo0ElmtSize = FDCAN_DATA_BYTES_8;
  obj->CanHandle.Init.RxBufferSize = FDCAN_DATA_BYTES_8;
  
  obj->CanHandle.Init.TxEventsNbr = 24;
  obj->CanHandle.Init.TxBuffersNbr = 0;
  obj->CanHandle.Init.TxFifoQueueElmtsNbr = 24;
  obj->CanHandle.Init.TxFifoQueueMode = FDCAN_TX_FIFO_OPERATION;
  obj->CanHandle.Init.TxElmtSize = FDCAN_DATA_BYTES_8;

  //Serial.print("Nominal Prescaler:"); Serial.println(nominalPrescaler);
  //Serial.print("ntq:"); Serial.println(ntq);
  //Serial.print("Nominal TimeSeg1:"); Serial.println(obj->CanHandle.Init.NominalTimeSeg1);
  //Serial.print("Nominal TimeSeg2:"); Serial.println(obj->CanHandle.Init.NominalTimeSeg2);
  //Serial.print("SyncJumpWidth:"); Serial.println(obj->CanHandle.Init.NominalSyncJumpWidth);

  //Trd_internal_init(obj);
}

void Set_CAN_Pin(can_t *obj, PinName rd, PinName td, int hz){
    CANName can_rd = (CANName)pinmap_peripheral(rd, PinMap_CAN_RD);
    CANName can_td = (CANName)pinmap_peripheral(td, PinMap_CAN_TD);
    int peripheral = (int)pinmap_merge(can_rd, can_td);

    int function_rd = (int)pinmap_find_function(rd, PinMap_CAN_RD);
    int function_td = (int)pinmap_find_function(td, PinMap_CAN_TD);

    const can_pinmap_t static_pinmap = {peripheral, rd, function_rd, td, function_td};

    Set_Freq(obj, &static_pinmap, hz);
}


void Trd_internal_init(can_t *obj){
  // call HAL init function
  if (HAL_FDCAN_Init(&obj->CanHandle) != HAL_OK){
    Serial.println("HAL_FDCAN_Init error\n");
  } else {
    Serial.println("Init success!");
  }


  /**
   * Config Timestamp & Enable Timestamp
   * **/
  /*
  if (HAL_FDCAN_ConfigTimestampCounter(&obj->CanHandle, FDCAN_TIMESTAMP_PRESC_1) != HAL_OK){
    Serial.println("HAL_FDCAN_ConfigTimestampCounter error");
  } else {
    Serial.println("HAL_FDCAN_ConfigTimestampCounter OK");
  }

  if (HAL_FDCAN_EnableTimestampCounter(&obj->CanHandle, FDCAN_TIMESTAMP_INTERNAL) != HAL_OK){
    Serial.println("HAL_FDCAN_EnableTimestampCounter error");
  } else {
    Serial.println("HAL_FDCAN_EnableTimestampCounter OK");
  }
  */

  /**
   * Config & Enable TT operation
   * **/
  FDCAN_TT_ConfigTypeDef TT_Config;
  TT_Config.OperationMode = FDCAN_TT_COMMUNICATION_LEVEL2;  // not external sync
  
  
  //TT_Config.GapEnable = FDCAN_STRICTLY_TT_OPERATION;  
  TT_Config.TimeMaster = FDCAN_TT_POTENTIAL_MASTER;  
  TT_Config.InitRefTrigOffset = 0;  
  TT_Config.EvtTrigPolarity = FDCAN_TT_EVT_TRIG_POL_RISING;
  TT_Config.BasicCyclesNbr = FDCAN_TT_CYCLES_PER_MATRIX_1;
  

  TT_Config.ExpTxTrigNbr = 1;
  TT_Config.TURNumerator = 0x1FFFF;       // Must set
  TT_Config.TURDenominator = 0x1;         // Must set
  TT_Config.TriggerMemoryNbr = 1;
  
  TT_Config.StopWatchTrigSel = FDCAN_TT_STOP_WATCH_TRIGGER_0; // TIM2
  TT_Config.EventTrigSel = FDCAN_TT_EVENT_TRIGGER_1;  // TIM3

  /*
  if (HAL_FDCAN_TT_ConfigOperation(&obj->CanHandle, &TT_Config) != HAL_OK){
    Serial.println("HAL_FDCAN_TT_ConfigOperation error");
  } else {
    Serial.println("HAL_FDCAN_TT_ConfigOperation OK");
  }*/

  /**
   * Config Reference message
   * **/
  /*
  if (HAL_FDCAN_TT_ConfigReferenceMessage(&obj->CanHandle, FDCAN_STANDARD_ID, 0x641, FDCAN_TT_REF_MESSAGE_NO_PAYLOAD) != HAL_OK){
    Serial.println("HAL_FDCAN_TT_ConfigReferenceMessage error");
  } else {
    Serial.println("HAL_FDCAN_TT_ConfigReferenceMessage OK");
  }*/

  /**
   * Config Trigger to send reference message
   * **/
  /*
  FDCAN_TriggerTypeDef sTriggerConfig;
  sTriggerConfig.TriggerIndex = 0;  // 0 - 63
  sTriggerConfig.TimeMark = 0xFF; // 0 - 0xFFFF
  sTriggerConfig.RepeatFactor = FDCAN_TT_REPEAT_EVERY_CYCLE; // FDCAN_TT_Repeat_Factor
  //sTriggerConfig.StartCycle = 
  sTriggerConfig.TmEventInt = FDCAN_TT_TM_GEN_INTERNAL_EVENT; // internal event is generated when trigger become active
  sTriggerConfig.TmEventExt = FDCAN_TT_TM_GEN_EXTERNAL_EVENT; // external event is generated when trigger become active
  sTriggerConfig.TriggerType = FDCAN_TT_TX_REF_TRIGGER; // transmit reference message in external event-synchronized time-triggered operation
  //sTriggerConfig.FilterType = FDCAN_STANDARD_ID;
  //sTriggerConfig.TxBufferIndex = 
  //sTriggerConfig.FilterIndex = 
  
  if (HAL_FDCAN_TT_ConfigTrigger(&obj->CanHandle, &sTriggerConfig) != HAL_OK){
    Serial.println("HAL_FDCAN_TT_ConfigTrigger error");
  } else {
    Serial.println("HAL_FDCAN_TT_ConfigTrigger OK");
  }*/


  /***
   * Config Timestamp counter
  ***/
  if (HAL_FDCAN_ConfigTimestampCounter(&obj->CanHandle, FDCAN_TIMESTAMP_PRESC_2) != HAL_OK){
    Serial.println("HAL_FDCAN_ConfigTimestampCounter error!");
  } else {
    Serial.println("HAL_FDCAN_ConfigTimestampCounter OK!");
  }
  /***
   * Enable Timestamp counter
  ***/
  if (HAL_FDCAN_EnableTimestampCounter(&obj->CanHandle, FDCAN_TIMESTAMP_INTERNAL) != HAL_OK){
    Serial.println("HAL_FDCAN_EnableTimestampCounter error!");
  } else {
    Serial.println("HAL_FDCAN_EnableTimestampCounter OK!");
  }
  
  

  /***
  * Config Timeout Counter
  **/
  if (HAL_FDCAN_ConfigTimeoutCounter(&obj->CanHandle, FDCAN_TIMEOUT_CONTINUOUS, 0xFFFF) != HAL_OK){
    Serial.println("HAL_FDCAN_ConfigTimeoutCounter error!");
  } else {
    Serial.println("HAL_FDCAN_ConfigTimeoutCounter OK!");
  }

  /**
  * Enable Timeout Counter
  **/
  if (HAL_FDCAN_EnableTimeoutCounter(&obj->CanHandle) != HAL_OK){
    Serial.println("HAL_FDCAN_EnableTimeoutCounter error!");
  } else {
    Serial.println("HAL_FDCAN_EnableTimeoutCounter OK!");
  }  

}

/**
 * from can_write of mbed OS Target STM
 * and SimpleCAN github
 * 
 * **/
int my_can_write(can_t *obj, CAN_Message msg, int cc){
/**
  typedef struct
  {
  uint32_t Identifier;          !< Specifies the identifier.
                                     This parameter must be a number between:
                                      - 0 and 0x7FF, if IdType is FDCAN_STANDARD_ID
                                      - 0 and 0x1FFFFFFF, if IdType is FDCAN_EXTENDED_ID               

  uint32_t IdType;              !< Specifies the identifier type for the message that will be
                                     transmitted.
                                     This parameter can be a value of @ref FDCAN_id_type               

  uint32_t TxFrameType;         !< Specifies the frame type of the message that will be transmitted.
                                     This parameter can be a value of @ref FDCAN_frame_type            

  uint32_t DataLength;          !< Specifies the length of the frame that will be transmitted.
                                      This parameter can be a value of @ref FDCAN_data_length_code    

  uint32_t ErrorStateIndicator; !< Specifies the error state indicator.
                                     This parameter can be a value of @ref FDCAN_error_state_indicator 

  uint32_t BitRateSwitch;       !< Specifies whether the Tx frame will be transmitted with or without
                                     bit rate switching.
                                     This parameter can be a value of @ref FDCAN_bit_rate_switching    

  uint32_t FDFormat;            !< Specifies whether the Tx frame will be transmitted in classic or
                                     FD format.
                                     This parameter can be a value of @ref FDCAN_format                

  uint32_t TxEventFifoControl;  !< Specifies the event FIFO control.
                                     This parameter can be a value of @ref FDCAN_EFC                   

  uint32_t MessageMarker;       !< Specifies the message marker to be copied into Tx Event FIFO
                                     element for identification of Tx message status.
                                     This parameter must be a number between 0 and 0xFF                

} FDCAN_TxHeaderTypeDef;    
  */
  FDCAN_TxHeaderTypeDef TxHeader = {0};

  UNUSED(cc);

  // Configure Tx buffer message
  TxHeader.Identifier = msg.id;
  if (msg.format == CANStandard){
    //Serial.println("Standard");
    TxHeader.IdType = FDCAN_STANDARD_ID;
  } else {
    TxHeader.IdType = FDCAN_EXTENDED_ID;
  }

  TxHeader.TxFrameType = FDCAN_DATA_FRAME;
  TxHeader.DataLength = msg.len << 16;
  
  TxHeader.ErrorStateIndicator = FDCAN_ESI_ACTIVE;
  TxHeader.BitRateSwitch = FDCAN_BRS_OFF;
  TxHeader.FDFormat = FDCAN_CLASSIC_CAN;
  TxHeader.TxEventFifoControl = FDCAN_STORE_TX_EVENTS;
  TxHeader.MessageMarker = 0;

  for (int i = 0; i < 8; i++) TxData[i] = msg.data[i];    // For print out later
  
  if (HAL_FDCAN_AddMessageToTxFifoQ(&(obj->CanHandle), &TxHeader, msg.data) != HAL_OK){
    // USING M4 to Serial print    
    
    
    
    return 0;
  }

  if (!fake_heart_beat){
      Serial.print("S :\t"); Serial.print(TxHeader.Identifier,HEX); Serial.print(" ");

        
      for (uint8_t i = 0; i < (TxHeader.DataLength >> 16); i++){
        Serial.print(" ");
        Serial.print(TxData[i], HEX); 
      }

      Serial.println();   
  }

  return 1;
}


/**
 *  from can_read of mbed OS Target STM
 * 
**/
int my_can_read(can_t *obj, CAN_Message *msg, int handle)
{
  UNUSED(handle);

  if (HAL_FDCAN_GetRxFifoFillLevel(&obj->CanHandle, FDCAN_RX_FIFO0) == 0){
    return 0; // no message arrived
  }

  FDCAN_RxHeaderTypeDef RxHeader = {0};
  if (HAL_FDCAN_GetRxMessage(&obj->CanHandle, FDCAN_RX_FIFO0, &RxHeader, msg->data) != HAL_OK){
    //Serial.println("HAL_FDCAN_GetRxMessage error");
    return 0;
  }
  
  if (RxHeader.IdType == FDCAN_STANDARD_ID){
    msg->format = CANStandard;
  } else {
    msg->format = CANExtended;
  }
  msg->id = RxHeader.Identifier;
  msg->type = (RxHeader.RxFrameType == FDCAN_DATA_FRAME) ? CANData : CANRemote;
  msg->len = RxHeader.DataLength >> 16;

  return 1;
}


/**
 * from can_filter of mbed OS Target STM
 * 
 * **/
int my_can_filter(can_t *obj, uint32_t id, uint32_t mask, CANFormat format, int32_t handle){
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
  
  /** Configure global filter: 
   *  Filter all remote frames with STD and EXT ID
   *  Reject non matching frames with STD ID and EXT ID
   * **/
  
  if (HAL_FDCAN_ConfigGlobalFilter(&my_can.CanHandle, FDCAN_ACCEPT_IN_RX_FIFO0, FDCAN_ACCEPT_IN_RX_FIFO0, FDCAN_FILTER_REMOTE, FDCAN_FILTER_REMOTE) != HAL_OK){
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
  

   /** Enable Interrupt
   * **/
  if (HAL_FDCAN_ActivateNotification(&my_can.CanHandle, FDCAN_IT_RX_FIFO0_NEW_MESSAGE | FDCAN_IT_TIMEOUT_OCCURRED | FDCAN_IT_TIMESTAMP_WRAPAROUND | FDCAN_IT_TX_COMPLETE, 0xFFFF) != HAL_OK){
    //Error_Handler();
    Serial.println("HAL_FDCAN_ActivateNotification error!");
  } else {
    Serial.println("HAL_FDCAN_ActivateNotification OK!");
  }


  
  /** Unregister Callback function ???
  **/
  
  

  // FINALLY START FDCAN

  if (HAL_FDCAN_Start(&obj->CanHandle) != HAL_OK){
    Serial.println("HAL_FDCAN_Start error\n");
  } else {
    Serial.println("Start success!");
  }
  
  // FDCAN1 interrupt Init
  NVIC_SetVector(FDCAN1_IT0_IRQn, (uint32_t)&FDCAN1_IT0_IRQHandler);
  NVIC_EnableIRQ(FDCAN1_IT0_IRQn);


  //Serial.println("FDCAN1 interrupt success");


  /* Prepare Tx Header */
  TxHeader.Identifier = 0x322;
  TxHeader.IdType = FDCAN_STANDARD_ID;
  TxHeader.TxFrameType = FDCAN_DATA_FRAME;
  TxHeader.DataLength = FDCAN_DLC_BYTES_8;
  TxHeader.ErrorStateIndicator = FDCAN_ESI_ACTIVE;
  TxHeader.BitRateSwitch = FDCAN_BRS_OFF;
  TxHeader.FDFormat = FDCAN_CLASSIC_CAN;
  TxHeader.TxEventFifoControl = FDCAN_STORE_TX_EVENTS;
  TxHeader.MessageMarker = 0;

  return 1;
}





/**
 *  from can_rderror of mbed OS Target STM
 * 
 * **/
unsigned char my_can_rderror(can_t *obj)
{
  FDCAN_ErrorCountersTypeDef ErrorCounters;

  HAL_FDCAN_GetErrorCounters(&obj->CanHandle, &ErrorCounters);

  return (unsigned char)ErrorCounters.RxErrorCnt;
}


/**
 * 
 * from can_tderror of mbed OS target STM
 * 
 * **/
unsigned char my_can_tderror(can_t *obj)
{
  FDCAN_ErrorCountersTypeDef ErrorCounters;

  HAL_FDCAN_GetErrorCounters(&obj->CanHandle, &ErrorCounters);

  return (unsigned char)ErrorCounters.TxErrorCnt;
}

/**
 * from can_mode of mbed OS target STM
 * 
 * **/
int my_can_mode(can_t *obj, CanMode mode)
{
  if (HAL_FDCAN_Stop(&obj->CanHandle) != HAL_OK){
    //Serial.println("HAL_FDCAN_Stop error");
  }

  switch (mode){
    case MODE_RESET:
      break;
    case MODE_NORMAL:
      obj->CanHandle.Init.Mode = FDCAN_MODE_NORMAL;
      break;
    case MODE_SILENT: // Bus Monitoring
      obj->CanHandle.Init.Mode = FDCAN_MODE_BUS_MONITORING;
      break;
    case MODE_TEST_GLOBAL: // External Loopback
    case MODE_TEST_LOCAL:
      obj->CanHandle.Init.Mode = FDCAN_MODE_EXTERNAL_LOOPBACK;
      break;
    case MODE_TEST_SILENT:
      obj->CanHandle.Init.Mode = FDCAN_MODE_INTERNAL_LOOPBACK;
      break;
    default:
      return 0;
  }

  Trd_internal_init(obj);
  
  return 1;
}



// **********Interrupt******************
void FDCAN1_IT0_IRQHandler(void){
  //Serial.println("Interrupt!");
  //interrupt = true;
  HAL_FDCAN_IRQHandler(&my_can.CanHandle);
}


void HAL_FDCAN_TxBufferCompleteCallback(FDCAN_HandleTypeDef *hfdcan, uint32_t BufferIndexes){
  sendMsg = true;
  

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

/**
 * Config System Clock
 * from https://github.com/meomotminh/STM32CubeG4/blob/master/Projects/STM32G474E-EVAL/Examples/FDCAN/FDCAN_Classic_Frame_Networking/Src/main.c
 * **/
void SystemClock_Config(void){
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};
  RCC_PeriphCLKInitTypeDef PeriphClkInit = {0};
  HAL_StatusTypeDef ret = HAL_OK;

  // Oscillator init seem not to work
    


  

  /** Initialize the CPU, AHB and APB buses clocks
   * **/
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

  /**
   * Initializes the peripherals clocks
   * **/
  PeriphClkInit.PeriphClockSelection = RCC_PERIPHCLK_FDCAN;
  PeriphClkInit.FdcanClockSelection = RCC_FDCANCLKSOURCE_PLL;
  
  if (HAL_RCCEx_PeriphCLKConfig(&PeriphClkInit) != HAL_OK){
    //Error_Handler();
    Serial.println("HAL_RCCEx_PeriphCLKConfig error!");
  } else {
    Serial.println("HAL_RCCEx_PeriphCLKConfig OK!");
  }
}



/**
 * Rx FIFO0 Callback
 * 
 * **/
void HAL_FDCAN_RxFifo0Callback(FDCAN_HandleTypeDef *hfdcan, uint32_t RxFifo0ITs){
  if ((RxFifo0ITs & FDCAN_IT_RX_FIFO0_NEW_MESSAGE) != RESET){

    receiveMsg = true;
    
    // DO SOMETHING
  }
}

void HAL_FDCAN_TimeoutOccurredCallback(FDCAN_HandleTypeDef *hfdcan){
  //timeout = true;
}


void HAL_FDCAN_TimestampWraparoundCallback(FDCAN_HandleTypeDef *hfdcan){
  timestamp = true;
  
  
}


void Error_Handler(void){
  // DO SOMETHING 
}

void setup() {
  //Serial.begin(115200);
  Serial.begin(115200);
  while (!Serial);

  
  // Low level initialization
  HAL_Init();


  // Config System Clock
  //SystemClock_Config();

  // Init SDO object
  init_SDO_object();

  // Display SDO object linked list
  display_Linked_List();

  // Configure FDCAN peripheral
  //FDCAN_Config();
  
  
  // initiate can_t _can object  
  Set_CAN_Pin(&my_can, PB_8, PH_13, 250000);  

  // Set external Loop Back mode
  my_can_mode(&my_can, MODE_NORMAL);
  
  // set filter and start
  //int my_can_filter(can_t *obj, uint32_t id, uint32_t mask, CANFormat format, int32_t handle)
  my_can_filter(&my_can, 0x641, 0x7FF, CANStandard, 0);

  
  



  // Check Address of FDCAN RAM 
  Serial.println("-------------------------------------");
  Serial.println("|           Check Address            |");
  Serial.println("-------------------------------------");

  Serial.print("Message RxFIFO0 Start Address:");  Serial.println(my_can.CanHandle.msgRam.RxFIFO0SA,HEX);
  Serial.print("Message RxFIFO1 Start Address:");  Serial.println(my_can.CanHandle.msgRam.RxFIFO1SA,HEX);
  Serial.print("Message Rx Buffer Start Address:");  Serial.println(my_can.CanHandle.msgRam.RxBufferSA,HEX);
  Serial.print("Message RAM End Address:");  Serial.println(my_can.CanHandle.msgRam.EndAddress,HEX);

  
  Serial.println("-------------------------------------");
  Serial.println("|           Start loop              |");
  Serial.println("-------------------------------------");

  //struct SDO* found1 = find_value(&my_SDO_List, 0x200204);
  //Serial.print("Find :");Serial.println(found1->value,HEX);  Serial.println(found1->address,HEX);Serial.println(ceil(found1->length / 8.0));


    HAL_RTC_MspInit();
    RTC_Init();

    RTC_CalendarConfig();
    //Serial.println("1");
    RTC_AlarmConfig(10);

    // Timer
    

}


void loop() {
  // put your main code here, to run repeatedly:

  if (HAL_FDCAN_IsRxBufferMessageAvailable(&my_can.CanHandle,0) == 1){
    Serial.println("Rx new message ");
  }
  
  if (receiveMsg){

     Serial.println("Receive mess");
    
    
    // Retrieve Rx message from Rx FIFO0 
    if (HAL_FDCAN_GetRxMessage(&my_can.CanHandle, FDCAN_RX_FIFO0, &RxHeader, RxData) != HAL_OK){
        Serial.println("Error Handler");
        Error_Handler();
      
    } else {      
      // check action 

      // print out    
    Serial.println("*****************************");
    Serial.print("R :\t"); Serial.print(RxHeader.Identifier,HEX); Serial.print(" ");

    
    
    for (uint8_t i = 0; i < (RxHeader.DataLength >> 16); i++){
      Serial.print(" ");
      Serial.print(RxData[i], HEX); 
    }

    Serial.println();  
        
        // READ COMMAND
      if ((((RxData[0] & 0xF0) == 0x40) | ((RxData[0] & 0xF0) == 0x60) | segmented)){        
          if (read_parameter()){
              TxHeader.Identifier = prepare_ID(RxHeader.Identifier);
              if (my_can_write(&my_can, CANMessage(TxHeader.Identifier,TxData,8), 8)){
              
              } else {
                Error_Handler();
              }            
          }
                                
          
                        
      } else if ((RxData[0] & 0xF0) == 0x20) {
        // WRITE COMMAND
        //Serial.println("");
        write_parameter();  

        TxHeader.Identifier = prepare_ID(RxHeader.Identifier);
          if (my_can_write(&my_can, CANMessage(TxHeader.Identifier,TxData,8), 8)){
      
          } else {
            Error_Handler();
          }  
      }

      
    }

     

  
    receiveMsg = false;
  }

  

  if (Rx_Fifo0_full){
    Serial.println("FIFO full");
    Rx_Fifo0_full = false;
    
  }

  if (timeout){
    //Serial.println("Timeout occur!");
    timeout = false;
  }

if (timestamp){
  int8_t fake_length = sizeof(fake);
  
  fake_heart_beat = true;
  // Send Fake Heart Beat message
  for (int i = 0; i < sizeof(fake); i++){        
    
    //memcpy(TxData, fake[i].data, fake[i].len);
    
    if (my_can_write(&my_can, fake[i],sizeof(fake[i]))){
       
    } else {
        Error_Handler();
    } 
       
        
  }
  fake_heart_beat = false; 
  timestamp = false;
}

  if (segmented){
    //Serial.print("Segmented ");
    //Serial.println(segment_count);
  }

  
  if (alarm){
    Serial.println("----------------ALARM--------------------");
    alarm = false;
  } else {
    //Serial.println("--------");
  }

  /*
  if (timer6){
    Serial.println("Timer");
    timer6 = false;
  } else {
    //Serial.println("--------");
  }
  */
  //HAL_Delay(1000);
}
