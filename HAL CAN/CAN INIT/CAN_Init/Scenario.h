/**
  * @brief  FDCAN Trigger structure definition
  */
/*
typedef struct
{
  uint32_t TriggerIndex;  !< Specifies the trigger which will be configured.
                               This parameter must be a number between 0 and 63                                 

  uint32_t TimeMark;      !< Specifies the cycle time for which the trigger becomes active.
                               This parameter must be a number between 0 and 0xFFFF                             

  uint32_t RepeatFactor;  !< Specifies the trigger repeat factor.
                               This parameter can be a value of @ref FDCAN_TT_Repeat_Factor                     

  uint32_t StartCycle;    !< Specifies the index of the first cycle in which the trigger becomes active.
                               This parameter is ignored if RepeatFactor is set to FDCAN_TT_REPEAT_EVERY_CYCLE.
                               This parameter must be a number between 0 and RepeatFactor                       

  uint32_t TmEventInt;    !< Enable or disable the internal time mark event.
                               If enabled, FDCAN_TT_FLAG_TRIG_TIME_MARK flag is set when trigger memory element
                               becomes active.
                               This parameter can be a value of @ref FDCAN_TT_Time_Mark_Event_Internal          

  uint32_t TmEventExt;    !< Enable or disable the external time mark event.
                               If enabled, and if TTOCN.TTIE is set, a pulse is generated at fdcan1_tmp when
                               trigger memory element becomes active.
                               This parameter can be a value of @ref FDCAN_TT_Time_Mark_Event_External          

  uint32_t TriggerType;   !< Specifies the trigger type.
                               This parameter can be a value of @ref FDCAN_TT_Trigger_Type                      

  uint32_t FilterType;    !< Specifies the filter identifier type.
                               This parameter can be a value of @ref FDCAN_id_type                              

  uint32_t TxBufferIndex; !< Specifies the index of the Tx buffer for which the trigger is valid.
                               This parameter can be a value of @ref FDCAN_Tx_location.
                               This parameter is taken in consideration only if the trigger is configured for
                               transmission.                                                                    

  uint32_t FilterIndex;   !< Specifies the filter for which the trigger is valid.
                               This parameter is taken in consideration only if the trigger is configured for
                               reception.
                               This parameter must be a number between:
                                - 0 and 127, if FilterType is FDCAN_STANDARD_ID
                                - 0 and 63, if FilterType is FDCAN_EXTENDED_ID                                  

} FDCAN_TriggerTypeDef;
*/

#ifndef SCENARIO_H
#define SCENARIO_H

#include "mbed.h"


enum TRIGGER_TYPE {
    TIME_TRIGGER,
    EVENT_TRIGGER
}

enum INPUT_TYPE {
    TIME_STAMP,
    CAN_MESSAGE,
    NONE
} 

enum OUTPUT_TYPE {
    CAN_MESSAGE,
    NONE
}

typedef struct Scenario {

public:
    TRIGGER_TYPE _trigger_type;
    INPUT_TYPE _input_type;
    OUTPUT_TYPE _output_type;

    // input
    CANMessage _input_CAN_message;
    uint32_t _input_timestamp;

    // output
    CANMessage _output_CAN_message;
    
}




#endif