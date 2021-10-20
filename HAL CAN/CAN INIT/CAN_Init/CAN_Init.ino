#include "mbed.h"
#include <ThreadDebug.h>

// For TRACE32 Debug
//UsbDebugCommInterface debugComm(&SerialUSB);
//ThreadDebug           threadDebug(&debugComm, DEBUG_BREAK_IN_SETUP);

using namespace mbed;

// Global Var
can_t my_can;
char counter = 0;
CAN_Message msg;
bool receiveMsg = false;
bool Rx_Fifo0_full = false;
uint32_t Rx_IT_Number = 0;

HAL_StatusTypeDef hal_can_init(FDCAN_HandleTypeDef *hfdcan){
    return (HAL_FDCAN_Init(hfdcan));
}

void HAL_MspInit(void){
  // set up priority grouping of the arm cortex processor
  HAL_NVIC_SetPriorityGrouping(NVIC_PRIORITYGROUP_4);

  // enable required system exceptions
  SCB->SHCSR |= 0x7 << 16; // usage fault, memory fault and bus fault system exceptions

  // configure the priority for the system exceptions
  HAL_NVIC_SetPriority(MemoryManagement_IRQn, 0, 0);
  HAL_NVIC_SetPriority(BusFault_IRQn, 0, 0);
  HAL_NVIC_SetPriority(UsageFault_IRQn, 0, 0);

  
  //HAL_NVIC_SetPriority(FDCAN1_IT0_IRQn, 2, 0);
  //HAL_NVIC_EnableIRQ(FDCAN1_IT0_IRQn);
}


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
  obj->CanHandle.Init.AutoRetransmission = ENABLE;
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
  
  obj->CanHandle.Init.TxEventsNbr = 3;
  obj->CanHandle.Init.TxBuffersNbr = 0;
  obj->CanHandle.Init.TxFifoQueueElmtsNbr = 3;
  obj->CanHandle.Init.TxFifoQueueMode = FDCAN_TX_FIFO_OPERATION;
  obj->CanHandle.Init.TxElmtSize = FDCAN_DATA_BYTES_8;

  //Serial.print("Nominal Prescaler:"); Serial.println(nominalPrescaler);
  //Serial.print("ntq:"); Serial.println(ntq);
  //Serial.print("Nominal TimeSeg1:"); Serial.println(obj->CanHandle.Init.NominalTimeSeg1);
  //Serial.print("Nominal TimeSeg2:"); Serial.println(obj->CanHandle.Init.NominalTimeSeg2);
  //Serial.print("SyncJumpWidth:"); Serial.println(obj->CanHandle.Init.NominalSyncJumpWidth);

  Trd_internal_init(obj);
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
    //Serial.println("HAL_FDCAN_Init error\n");
  } else {
    //Serial.println("Init success!");
  }

 

  if (my_can_filter(obj, 0, 0, CANStandard, 0) == 0){
    //Serial.println("can_filter standard error!");
  }

  if (my_can_filter(obj, 0, 0, CANExtended, 0) == 0){
    //Serial.println("can_filter extended error!");
  }

  if (HAL_FDCAN_ConfigGlobalFilter(&obj->CanHandle, FDCAN_REJECT, FDCAN_REJECT, FDCAN_FILTER_REMOTE, FDCAN_FILTER_REMOTE) != HAL_OK){
    //Serial.println("HAL_FDCAN_ConfigGlobalFilter error");
  }


  // activate FDCAN interrupts  
  if (HAL_FDCAN_ActivateNotification(&obj->CanHandle, FDCAN_IT_RX_FIFO0_NEW_MESSAGE | FDCAN_IT_RX_FIFO0_FULL, 0xFFFF) != HAL_OK){
    Serial.println("HAL_FDCAN_ActivateNotification error");
  } else {
    Serial.println("HAL_FDCAN_ActivateNotification success!");
  }

  

  // FDCAN1 interrupt Init
  NVIC_SetVector(FDCAN1_IT0_IRQn, (uint32_t)&FDCAN1_IT0_IRQHandler);
  NVIC_EnableIRQ(FDCAN1_IT0_IRQn);


  if (HAL_FDCAN_Start(&obj->CanHandle) != HAL_OK){
    //Serial.println("HAL_FDCAN_Start error\n");
  } else {
    //Serial.println("Start success!");
  }

  

  //Serial.println("FDCAN1 interrupt success");

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

  if (HAL_FDCAN_AddMessageToTxFifoQ(&(obj->CanHandle), &TxHeader, msg.data) != HAL_OK){
    return 0;
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
    sFilterConfig.FilterType = FDCAN_FILTER_MASK;
    sFilterConfig.FilterConfig = FDCAN_FILTER_TO_RXFIFO0;
    sFilterConfig.FilterID1 = id;
    sFilterConfig.FilterID2 = mask;
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

  if (HAL_FDCAN_ConfigFilter(&obj->CanHandle, &sFilterConfig) != HAL_OK){
    return 0;
  }

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


/**
 * from can_irq of mbed OS target STM
 * **/
static void can_irq(CANName name, int id)
{
  FDCAN_HandleTypeDef CanHandle;
  CanHandle.Instance = (FDCAN_GlobalTypeDef *)name;

  if (__HAL_FDCAN_GET_IT_SOURCE(&CanHandle, FDCAN_IT_TX_COMPLETE)){
    if (__HAL_FDCAN_GET_FLAG(&CanHandle, FDCAN_FLAG_TX_COMPLETE)){
      __HAL_FDCAN_CLEAR_FLAG(&CanHandle, FDCAN_FLAG_TX_COMPLETE);
      //irq_handler(can_irq_contexts[id], IRQ_TX);
    }
  } // complete IRQ

  #if (defined FDCAN_IT_RX_BUFFER_NEW_MESSAGE)
    if (__HAL_FDCAN_GET_IT_SOURCE(&CanHandle, FDCAN_IT_RX_BUFFER_NEW_MESSAGE)){
      if (__HAL_FDCAN_GET_FLAG(&CanHandle, FDCAN_IT_RX_BUFFER_NEW_MESSAGE)){
        __HAL_FDCAN_CLEAR_FLAG(&CanHandle, FDCAN_IT_RX_BUFFER_NEW_MESSAGE);
        //irq_handler(can_irq_contexts[id], IRQ_RX);
      }
    }    
   // new message buffer
  #else 
    if (__HAL_FDCAN_GET_IT_SOURCE(&CanHandle, FDCAN_IT_RX_FIFO0_NEW_MESSAGE)){
      if (__HAL_FDCAN_GET_FLAG(&CanHandle, FDCAN_IT_RX_FIFO0_NEW_MESSAGE)){
        __HAL_FDCAN_CLEAR_FLAG(&CanHandle, FDCAN_IT_RX_FIFO0_NEW_MESSAGE);
        //irq_handler(can_irq_contexts[id], IRQ_RX);
      }
    }
  #endif // new message FIFO

  if (__HAL_FDCAN_GET_IT_SOURCE(&CanHandle, FDCAN_IT_ERROR_WARNING)){
    if (__HAL_FDCAN_GET_FLAG(&CanHandle, FDCAN_FLAG_ERROR_WARNING)){
      __HAL_FDCAN_CLEAR_FLAG(&CanHandle, FDCAN_FLAG_ERROR_WARNING);
      //irq_handler(can_irq_contexts[id], IRQ_ERROR);
    }
  }  // error warning

  if (__HAL_FDCAN_GET_IT_SOURCE(&CanHandle, FDCAN_IT_ERROR_PASSIVE)){
    if (__HAL_FDCAN_GET_FLAG(&CanHandle, FDCAN_FLAG_ERROR_PASSIVE)){
      __HAL_FDCAN_CLEAR_FLAG(&CanHandle, FDCAN_FLAG_ERROR_PASSIVE);
      //irq_handler(can_irq_contexts[id], IRQ_PASSIVE);
    }
  } // passive irq

  if (__HAL_FDCAN_GET_IT_SOURCE(&CanHandle, FDCAN_IT_BUS_OFF)){
    if (__HAL_FDCAN_GET_FLAG(&CanHandle, FDCAN_FLAG_BUS_OFF)){
      __HAL_FDCAN_CLEAR_FLAG(&CanHandle, FDCAN_FLAG_BUS_OFF);
      //irq_handler(can_irq_contexts[id], IRQ_BUS);
    }
  }
}

// **********Interrupt******************
void FDCAN1_IT0_IRQHandler(void){
  //Serial.println("Interrupt!");
  HAL_FDCAN_IRQHandler(&my_can.CanHandle);
}


void HAL_FDCAN_TxBufferCompleteCallback(FDCAN_HandleTypeDef *hfdcan, uint32_t BufferIndexes){
  
  Serial.println("Message Sent!");
}

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


void setup() {
  Serial.begin(9600);
  while (!Serial);

  #ifdef FDCAN1
    Serial.println("*********FDCAN1************");
  #endif

  #ifdef CAN_1
    Serial.println("*********CAN1************");
  #endif
  
  // Low level initialization
  HAL_Init();

  //asm volatile ("SVC #0x32\n\t");
  //HAL_MPU_Disable();
  
  // Config System Clock
  //SystemClock_Config();

  // UART config
  //UART_Config();
  
  // HSEM clock enable
  //__HAL_RCC_HSEM_CLK_ENABLE();

  
  // initiate can_t _can object  
  Set_CAN_Pin(&my_can, PB_8, PH_13, 250000);  

  // Set external Loop Back mode
  my_can_mode(&my_can, MODE_TEST_GLOBAL);

  //HAL_MPU_Enable(MPU_PRIVILEGED_DEFAULT);
  //Serial.println("-------------------------------------");
  //Serial.println("Start loop");
  //Serial.println("-------------------------------------");
}


void HAL_FDCAN_TxEventFifoCallback(FDCAN_HandleTypeDef *hfdcan, uint32_t TxEventFifoITs){
  //Serial.println("Sent message fifo");
}


void loop() {
  // put your main code here, to run repeatedly:
  if (my_can_write(&my_can, CANMessage(1337, &counter, 1), 1)){
    //Serial.print("Sent:"); Serial.println(counter);
    counter++;
  } else {
    //Serial.println("Error");
  }

  if (receiveMsg){
    Serial.println("Interrupt!!!");
    receiveMsg = false;
  }

  if (Rx_Fifo0_full){
    Serial.println("FIFO full");
    Rx_Fifo0_full = false;
    
  }

  //Serial.println(Rx_IT_Number);
  //if (my_can_read(&my_can, &msg, 0)){
    //Serial.print("Received:");Serial.println(msg.data[0]);
  //}
}
