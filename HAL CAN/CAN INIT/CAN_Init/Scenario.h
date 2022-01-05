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



enum OUTPUT_TYPE {
    OUT_TIME_STAMP,  // delay: 0
    OUT_CAN_MESSAGE, // predefinded: 1
    OUT_FUNCTION,    // function: 2
    OUT_IGNORE,         // ignore: 3
    OUT_RESET,        // reset to normal: 4
};

typedef class My_Function {
public:
    double _a;
    double _b;
    double _c;
    double _d;
    uint32_t _SDO_value;
    bool _sin;

    // constructor
    My_Function(double a, double b, double c, double d, uint32_t value, bool sin){
      _a = a;
      _b = b;
      _c = c;
      _d = d;
      _SDO_value = value;
      _sin = sin;
    }

    My_Function(){}
    
};

typedef class Scenario {

public:
        
    OUTPUT_TYPE _output_type;

    // input
    CANMessage *_input_CAN_message;
    uint32_t _start_time;

    // output
    CANMessage *_output_CAN_message;
    uint32_t _delay_time; // for delay
    My_Function *_output_function; // for manipulating parameter    
    
    Scenario* _next;


    // Constructor
    Scenario(OUTPUT_TYPE out, CAN_Message *input_CAN, uint32_t start_time,
    CANMessage *output_CAN, uint32_t delay_time, My_Function *output_func, Scenario* next){                
        _output_type = out;
        _input_CAN_message = input_CAN;  // Start CAN
        _start_time = start_time;   // start time
        _output_CAN_message = output_CAN; // predefined CAN
        _delay_time = delay_time; // delay time
        _output_function = output_func;  // manipulate func
        _next = next;        
    }
};


static My_Function function_sinc(0.0, 0.0, 10.0, 20.0, 0x400001, true);

static My_Function function_linear_2(0.0, 0.0, -2.0, 40.0, 0x400001, false);

static My_Function function_linear_1(0.0, 0.0, 1.0, 1.0, 0x400001, false); 
                                  // a*(t)³ + b*(t)² + c*(t) +d 

/* ---------------------------- DEFINE SCRENARIO ---------------------------- */

#define use_Scenario true

//static Scenario Scenario_3(OUT_FUNCTION, NULL, 10, NULL, 0, &function_sinc, 30, NULL);

//static Scenario Scenario_2(OUT_FUNCTION, NULL, 10, NULL, 0, &function_linear_2, 30, &Scenario_3);

//static Scenario Scenario_1(OUT_FUNCTION, NULL, 30, NULL, 0, &function_linear_1, 30, &Scenario_2);

static Scenario Scenario_4(OUT_RESET, NULL, 20, NULL, 0, nullptr, NULL);

static Scenario Scenario_3(OUT_IGNORE, NULL, 15, NULL, 0, nullptr, &Scenario_4);

static Scenario Scenario_2(OUT_RESET, NULL, 10, NULL, 0, nullptr, &Scenario_3);

static Scenario Scenario_1(OUT_IGNORE, NULL, 5, NULL, 0, nullptr, &Scenario_2);





#endif
