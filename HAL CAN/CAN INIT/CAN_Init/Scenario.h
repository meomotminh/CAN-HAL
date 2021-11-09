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
    MY_TIME_TRIGGER,
    MY_EVENT_TRIGGER
};



enum INPUT_TYPE {
    IN_TIME_STAMP,
    IN_CAN_MESSAGE,
}; 

enum OUTPUT_TYPE {
    OUT_TIME_STAMP,  // delay: 0
    OUT_CAN_MESSAGE, // predefinded: 1
    OUT_FUNCTION,    // function: 2
    OUT_NONE         // ignore: 3
};

typedef class My_Function {
public:
    double _a;
    double _b;
    double _c;
    double _d;
    uint32_t _SDO_value;

    // constructor
    My_Function(double a, double b, double c, double d, uint32_t value){
      _a = a;
      _b = b;
      _c = c;
      _d = d;
      _SDO_value = value;
    }

    My_Function(){}
    
};

typedef class Scenario {

public:
    
    INPUT_TYPE _input_type;
    OUTPUT_TYPE _output_type;

    // input
    CAN_Message *_input_CAN_message;
    uint32_t _input_timestamp;

    // output
    CAN_Message *_output_CAN_message;
    uint32_t _output_timestamp; // for delay
    My_Function *_output_function; // for manipulating parameter

    uint32_t _duration;
    
    Scenario* _next;


    // Constructor
    Scenario(INPUT_TYPE inp, OUTPUT_TYPE out, CAN_Message *input_CAN, uint32_t input_time,
    CAN_Message *output_CAN, uint32_t output_time, My_Function *output_func, uint32_t dur, Scenario* next){        
        _input_type = inp;
        _output_type = out;
        _input_CAN_message = input_CAN;
        _input_timestamp = input_time;
        _output_CAN_message = output_CAN;
        _output_timestamp = output_time;
        _output_function = output_func;
        _duration = dur;
        _next = next;        
    }
};


static My_Function function_linear(0.0, 0.0, 1.0, 1.0, 0x240207);  // SDO_value_240207 = 0.0(t)³ + 0.0(t)² + 1.0(t) + 1.0 

/* ---------------------------- DEFINE SCRENARIO ---------------------------- */
static Scenario Scenario_2(IN_TIME_STAMP, OUT_NONE, NULL, 10, NULL, 0, &function_linear, 10, NULL);

static Scenario Scenario_1(IN_TIME_STAMP, OUT_NONE, NULL, 10, NULL, 0, &function_linear, 10, &Scenario_2);







#endif
