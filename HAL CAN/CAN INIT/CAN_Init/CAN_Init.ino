#include "mbed.h"
#include <ThreadDebug.h>
#include "loiTruck_SDO.h"
#include "Scenario.h"
#include "FDCAN.h"
#include "RTC.h"
#include "SRAM.h"
#include "TIMER.h"
#include "UTILITY.h"




// For TRACE32 Debug
//USBSerial SerialUSB1(false, "DebugPort");
//UsbDebugCommInterface debugComm(&SerialUSB1);
//ThreadDebug           threadDebug(&debugComm, DEBUG_BREAK_IN_SETUP);

using namespace mbed;







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
