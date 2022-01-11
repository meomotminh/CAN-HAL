#ifndef SCENARIO_H
#define SCENARIO_H

#include "mbed.h"


using namespace mbed;


// define test_SDO
const  uint8_t test_scenario_0[] = {0x40,0x02,0x20,0x4,0x0,0x0,0x0,0x0};
const  uint8_t test_scenario_1[] = {0x60,0x02,0x20,0x4,0x0,0x0,0x0,0x0};
const  uint8_t test_scenario_2[] = {0x70,0x02,0x20,0x4,0x0,0x0,0x0,0x0};
const  uint8_t test_scenario_3[] = {0x40,0x04,0x24,0x02,0x0,0x0,0x0,0x0};
const  uint8_t test_scenario_4[] = {0x2B,0x04,0x24,0x02,0x04,0x04,0x0,0x0};
const  uint8_t test_scenario_5[] = {0x40,0x04,0x24,0x01,0x0,0x00,0x0,0x0};
const  uint8_t test_scenario_6[] = {0x2F,0x42,0x53,0x02,0x02,0x00,0x0,0x0};
const  uint8_t test_scenario_7[] = {0x2b,0x04,0x24,0x01,0x89,0x29,0x00,0x00};
const  uint8_t test_scenario_8[] = {0x40,0x03,0x24,0x02,0x00,0x00,0x00,0x00};
static CANMessage fault[12] = {
                    CANMessage(0x601,test_scenario_0,8),//0 SDO ident string
                    CANMessage(0x601,test_scenario_1,8),//1 SDO ident string 
                    CANMessage(0x601,test_scenario_2,8),//2 SDO ident string
                    CANMessage(0x601,test_scenario_1,8),//3 SDO ident string                   
                    CANMessage(0x601,test_scenario_2,8),//4 SDO ident string                   
                    CANMessage(0x601,test_scenario_1,8),//5 SDO ident string
                    CANMessage(0x641,test_scenario_3,8),//6 SDO 240402
                    CANMessage(0x641,test_scenario_4,8),//7 Download SDO 240402
                    CANMessage(0x641,test_scenario_3,8),//8 SDO 240402
                    CANMessage(0x641,test_scenario_5,8),//9 SDO 240401
                    CANMessage(0x641,test_scenario_7,8),//10 Download SDO 240401
                    CANMessage(0x641,test_scenario_5,8),//11 SDO 240401                    
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

    uint32_t output(int val){
      if (this->_sin){
        return (sin(val*3*2)+1)*1000;
      } else {
        return int(_a*_a*_a*val + _b*_b*val + _c*val +_d);
      }
      
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
    Scenario(OUTPUT_TYPE out, CANMessage *input_CAN, uint32_t start_time,
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


static My_Function function_sinc(0.0, 0.0, 0, 0, 0x400001, true);

static My_Function function_linear_2(0.0, 0.0, -2.0, 40.0, 0x400001, false);

static My_Function function_linear_1(0.0, 0.0, 1.0, 1.0, 0x400001, false); 
                                  // a*(t)³ + b*(t)² + c*(t) +d 

/* ---------------------------- DEFINE SCRENARIO ---------------------------- */

#define use_Scenario false

//static Scenario Scenario_3(OUT_FUNCTION, NULL, 10, NULL, 0, &function_sinc, 30, NULL);

//static Scenario Scenario_2(OUT_FUNCTION, NULL, 10, NULL, 0, &function_linear_2, 30, &Scenario_3);

//static Scenario Scenario_1(OUT_FUNCTION, NULL, 30, NULL, 0, &function_linear_1, 30, &Scenario_2);

//static Scenario Scenario_4(OUT_RESET, NULL, 20, NULL, 0, nullptr, NULL);

//static Scenario Scenario_3(OUT_TIME_STAMP, NULL, 15, NULL, 0, nullptr, &Scenario_4);

//static Scenario Scenario_2(OUT_RESET, NULL, 10, NULL, 0, nullptr, &Scenario_3);

//static Scenario Scenario_1(OUT_IGNORE, NULL, 5, NULL, 0, nullptr, &Scenario_2);


// --------------test scenario 1-------------
//static Scenario Scenario_4(OUT_RESET, &fault[0], 20, NULL, 0, nullptr, nullptr);

//static Scenario Scenario_3(OUT_IGNORE, &fault[0], 15, NULL, 0, nullptr, &Scenario_4);

//static Scenario Scenario_2(OUT_TIME_STAMP, &fault[0], 10, NULL, 100, nullptr, &Scenario_3);

//static Scenario Scenario_1(OUT_TIME_STAMP, &fault[0], 5, NULL, 0, nullptr, &Scenario_2);


// --------------test scenario function-----------
static Scenario Scenario_1(OUT_FUNCTION, nullptr, 5, NULL, 0, &function_sinc, nullptr);


#endif
