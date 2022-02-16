#pragma once
#ifndef LOITRUCK_H
#define LOITRUCK_H

#include "mbed.h"
#include "../../Scenario.h"

using namespace mbed;

#define SRAM_BANK_ADDR      ((uint32_t) 0x30000000)     // SRAM1 Address | 0x30000000 - 0x3001FFFF
#define WRITE_READ_ADDR     ((uint32_t) 0x10000)

#define ID 0x12 // define ID number


// define Fake heart beat
const  uint8_t temp0[] = {0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0};
const  uint8_t temp1[] = {0x0,0x46,0x0,0x0,0x0,0x0,0x0,0x0};
const  uint8_t temp2[] = {0x0,0x0,0x0,0x0,0x0,0x3D,0x0,0x0};
const  uint8_t temp3[] = {0x0,0x0,0x0,0x0,0x0,0x02,0x0,0x0};
const  uint8_t temp4[] = {0x3,0x0,0x0,0x0,0x0,0x00,0x0,0x0};
const  uint8_t temp5[] = {0x5,0x0,0x0,0x0,0x0,0x00,0x0,0x0};
const  uint8_t temp6[] = {0x49,0x01,0x2E,0x74,0x0,0x00,0x0,0x0};
const  uint8_t temp7[] = {0x23,0x40,0x53,0x01,0x7C,0x00,0x00,0x10};
const  uint8_t temp8[] = {0x23,0x40,0x53,0x01,0x00,0x00,0x00,0x00};

static CANMessage fake[24] = {
                    CANMessage(0x80,temp0,0),
                    CANMessage(0x20e,temp1,8),
                    CANMessage(0x30E,temp2,8),
                    CANMessage(0x21D,temp0,8),                    
                    CANMessage(0x31D,temp0,8),                    
                    CANMessage(0x18D,temp3,8),
                    CANMessage(0x70D,temp0,1),
                    CANMessage(0x203,temp4,8),
                    CANMessage(0x701,temp5,1),
                    CANMessage(0x80,temp0,0),
                    CANMessage(0x20E,temp1,8),
                    CANMessage(0x183,temp0,0),
                    CANMessage(0x30E,temp2,8),
                    CANMessage(0x21D,temp0,8),
                    CANMessage(0x18D,temp3,8),
                    CANMessage(0x31D,temp0,8),
                    CANMessage(0x704,temp5,1),
                    CANMessage(0x80,temp0,0),
                    CANMessage(0x181,temp6,8),
                    CANMessage(0x20E,temp1,8),
                    CANMessage(0x30E,temp2,8),
                    CANMessage(0x603,temp7,8),
                    CANMessage(0x583,temp8,8),
                    CANMessage(0x703,temp5,1)
};


// define test_SDO
const  uint8_t test0[] = {0x40,0x02,0x20,0x4,0x0,0x0,0x0,0x0};
const  uint8_t test1[] = {0x60,0x02,0x20,0x4,0x0,0x0,0x0,0x0};
const  uint8_t test2[] = {0x70,0x02,0x20,0x4,0x0,0x0,0x0,0x0};
const  uint8_t test3[] = {0x40,0x04,0x24,0x02,0x0,0x0,0x0,0x0};
const  uint8_t test4[] = {0x2B,0x04,0x24,0x02,0x04,0x04,0x0,0x0};
const  uint8_t test5[] = {0x40,0x04,0x24,0x01,0x0,0x00,0x0,0x0};
const  uint8_t test6[] = {0x2F,0x42,0x53,0x02,0x02,0x00,0x0,0x0};
const  uint8_t test7[] = {0x2b,0x04,0x24,0x01,0x89,0x29,0x00,0x00};
const  uint8_t test8[] = {0x40,0x03,0x24,0x02,0x00,0x00,0x00,0x00};
static CANMessage test_SDO[12] = {
                    CANMessage(0x601,test0,8),//0 SDO ident string
                    CANMessage(0x601,test1,8),//1 SDO ident string 
                    CANMessage(0x601,test2,8),//2 SDO ident string
                    CANMessage(0x601,test1,8),//3 SDO ident string                   
                    CANMessage(0x601,test2,8),//4 SDO ident string                   
                    CANMessage(0x601,test1,8),//5 SDO ident string
                    CANMessage(0x641,test3,8),//6 SDO 240402
                    CANMessage(0x641,test4,8),//7 Download SDO 240402
                    CANMessage(0x641,test3,8),//8 SDO 240402
                    CANMessage(0x641,test5,8),//9 SDO 240401
                    CANMessage(0x641,test7,8),//10 Download SDO 240401
                    CANMessage(0x641,test5,8),//11 SDO 240401                    
};

// define expect_SDO
const  uint8_t expect0[] = {0x41,0x02,0x20,0x4,0x20,0x0,0x0,0x0};
const  uint8_t expect1[] = {0x0,0x45,0x43,0x45,0x32,0x32,0x35,0x20};
const  uint8_t expect2[] = {0x10,0x20,0x20,0x20,0x20,0x20,0x20,0x20};
const  uint8_t expect3[] = {0x0,0x32,0x30,0x31,0x35,0x20,0x20,0x20};
const  uint8_t expect4[] = {0x10,0x20,0x20,0x20,0x20,0x20,0x20,0x20};
const  uint8_t expect5[] = {0x7,0x0,0x0,0x0,0x0,0x00,0x0,0x0};
const  uint8_t expect6[] = {0x43,0x04,0x24,0x02,0x0,0x0,0x0,0x0};
const  uint8_t expect7[] = {0x60,0x04,0x24,0x02,0x00,0x00,0x0,0x0};
const  uint8_t expect8[] = {0x43,0x04,0x24,0x2,0x4,0x4,0x0,0x0};
const  uint8_t expect9[] = {0x43,0x04,0x24,0x1,0x0,0x0,0x0,0x0};
const  uint8_t expect10[] = {0x60,0x04,0x24,0x1,0x0,0x0,0x0,0x0};
const  uint8_t expect11[] = {0x43,0x04,0x24,0x1,0x89,0x29,0x0,0x0};

static CANMessage expect_SDO[12] = {
                    CANMessage(0x581,expect0,8),//1
                    CANMessage(0x581,expect1,8),//2
                    CANMessage(0x581,expect2,8),//3
                    CANMessage(0x581,expect3,8),//4                 
                    CANMessage(0x581,expect4,8),//5                    
                    CANMessage(0x581,expect5,8),//6
                    CANMessage(0x5C1,expect6,8),//7
                    CANMessage(0x5C1,expect7,8),//8    
                    CANMessage(0x5C1,expect8,8),//9               
                    CANMessage(0x5C1,expect9,8),//10               
                    CANMessage(0x5C1,expect10,8),//11               
                    CANMessage(0x5C1,expect11,8),//12               
};

// 50ms

// Declare SDO object value
// Segment STANDARD (0x2000 - 0x20FF)

/**
 * 0x2000 Komponenteninformation
 * **/

#define Truck_null_word     ((uint32_t)0x00000000U)          // save some extra space symbol

typedef struct SDO {
public:    
    // do nothing
        uint32_t index = 0;
        uint32_t address = 0;
        uint32_t Object_index = 0;
    
        SDO *next = NULL;
        uint8_t length = 0;
        bool segmented = false;

        uint32_t to_save = 0;
        String segmented_string = "";
        bool SDO_default = false;

    // Constructor
    SDO(uint32_t _index, uint32_t _address, uint32_t _Object_index, struct SDO* _next, uint8_t _length, bool _segmented, uint32_t _to_save, bool _is_default){            
        //malloc(sizeof(struct SDO));
        index = _index;
        address = _address;
        Object_index = _Object_index; // not value to be saved in SRAM but the 0x20002 value
        next = _next;
        length = _length;
        segmented = _segmented;
        to_save = _to_save;
        SDO_default = _is_default;
    }

    // Constructor
    SDO(uint32_t _index, uint32_t _address, uint32_t _Object_index, struct SDO* _next, uint8_t _length, bool _segmented, uint32_t _to_save){            
        //malloc(sizeof(struct SDO));
        index = _index;
        address = _address;
        Object_index = _Object_index; // not value to be saved in SRAM but the 0x20002 value
        next = _next;
        length = _length;
        segmented = _segmented;
        to_save = _to_save;
        SDO_default = false;        
    }
    
    SDO(){
        // do nothing
        index = 0;
        address = 0;
        Object_index = 0;
        next = NULL;
        length = 0;
        segmented = false;
        to_save = 0;
        segmented_string = "";
        SDO_default = false;
    }

    void set_segmented_string(String temp){
        segmented_string = temp;
    }

    void set_next(SDO* ptr){
        next = ptr;
    }
};

// Define Address List
//int max_CANopen_index  = 55;

#define  res_4007_08_address (SRAM_BANK_ADDR + WRITE_READ_ADDR + (4*(55)))  // uint16 type

#define  res_4007_02_address (SRAM_BANK_ADDR + WRITE_READ_ADDR + (4*(54)))  // uint16 type

#define  res_4007_01_address (SRAM_BANK_ADDR + WRITE_READ_ADDR + (4*(53)))  // uint8 type

#define  res_4007_00_address (SRAM_BANK_ADDR + WRITE_READ_ADDR + (4*(52)))  // number of entries AC Betriebsgroessen

#define  res_4000_04_address (SRAM_BANK_ADDR + WRITE_READ_ADDR + (4*(51)))  // ist drehzahl 16 bit

#define  res_4000_03_address (SRAM_BANK_ADDR + WRITE_READ_ADDR + (4*(50)))  // ramp down

#define  res_4000_02_address (SRAM_BANK_ADDR + WRITE_READ_ADDR + (4*(49)))  // ramp up

#define  res_4000_01_address (SRAM_BANK_ADDR + WRITE_READ_ADDR + (4*(48)))  // soll drehzahl

#define  res_2400_07_address (SRAM_BANK_ADDR + WRITE_READ_ADDR + (4*(47)))  

#define  res_2401_07_address (SRAM_BANK_ADDR + WRITE_READ_ADDR + (4*(46)))

#define  res_2402_07_address (SRAM_BANK_ADDR + WRITE_READ_ADDR + (4*(45)))

#define  res_2403_04_address (SRAM_BANK_ADDR + WRITE_READ_ADDR + (4*(44)))

#define  res_2404_04_address (SRAM_BANK_ADDR + WRITE_READ_ADDR + (4*(43)))

#define  res_2405_04_address (SRAM_BANK_ADDR + WRITE_READ_ADDR + (4*(42)))

#define  res_2403_03_address (SRAM_BANK_ADDR + WRITE_READ_ADDR + (4*(41)))

#define  res_2404_03_address (SRAM_BANK_ADDR + WRITE_READ_ADDR + (4*(40)))

#define  res_2405_03_address (SRAM_BANK_ADDR + WRITE_READ_ADDR + (4*(39)))

#define  res_2404_07_address (SRAM_BANK_ADDR + WRITE_READ_ADDR + (4*(38)))

#define  res_2403_07_address (SRAM_BANK_ADDR + WRITE_READ_ADDR + (4*(37)))

#define  res_2403_02_address (SRAM_BANK_ADDR + WRITE_READ_ADDR + (4*(36)))

#define  res_2401_02_address (SRAM_BANK_ADDR + WRITE_READ_ADDR + (4*(35)))

#define  res_2404_02_address (SRAM_BANK_ADDR + WRITE_READ_ADDR + (4*(34)))

#define  res_2460_02_address (SRAM_BANK_ADDR + WRITE_READ_ADDR + (4*(33)))

#define  res_2405_07_address (SRAM_BANK_ADDR + WRITE_READ_ADDR + (4*(32)))

#define  res_2402_02_address (SRAM_BANK_ADDR + WRITE_READ_ADDR + (4*(31)))

#define  res_2405_02_address (SRAM_BANK_ADDR + WRITE_READ_ADDR + (4*(30)))

#define  res_2411_02_address (SRAM_BANK_ADDR + WRITE_READ_ADDR + (4*(29)))

#define  res_2001_03_address (SRAM_BANK_ADDR + WRITE_READ_ADDR + (4*(28)))

#define  res_2001_02_address (SRAM_BANK_ADDR + WRITE_READ_ADDR + (4*(27)))

#define  res_2461_02_address (SRAM_BANK_ADDR + WRITE_READ_ADDR + (4*(26)))

#define  res_2414_02_address (SRAM_BANK_ADDR + WRITE_READ_ADDR + (4*(25)))

#define  res_2923_02_address (SRAM_BANK_ADDR + WRITE_READ_ADDR + (4*(24)))

#define  res_2413_02_address (SRAM_BANK_ADDR + WRITE_READ_ADDR + (4*(23)))

#define  res_2020_01_address (SRAM_BANK_ADDR + WRITE_READ_ADDR + (4*(22)))

#define  res_2002_01_address (SRAM_BANK_ADDR + WRITE_READ_ADDR + (4*(21)))

#define  res_2106_06_address (SRAM_BANK_ADDR + WRITE_READ_ADDR + (4*(20)))

#define  res_2104_02_address (SRAM_BANK_ADDR + WRITE_READ_ADDR + (4*(19)))

#define  res_2103_02_address (SRAM_BANK_ADDR + WRITE_READ_ADDR + (4*(18)))

#define  res_2103_06_address (SRAM_BANK_ADDR + WRITE_READ_ADDR + (4*(17)))

#define  res_2201_06_address (SRAM_BANK_ADDR + WRITE_READ_ADDR + (4*(16)))

#define  res_2201_02_address (SRAM_BANK_ADDR + WRITE_READ_ADDR + (4*(15)))

#define  res_2101_06_address (SRAM_BANK_ADDR + WRITE_READ_ADDR + (4*(14)))

#define  res_2101_02_address (SRAM_BANK_ADDR + WRITE_READ_ADDR + (4*(13)))

#define  res_2001_01_address (SRAM_BANK_ADDR + WRITE_READ_ADDR + (4*(12)))

#define  res_2200_06_address (SRAM_BANK_ADDR + WRITE_READ_ADDR + (4*(11)))

#define  res_2200_02_address (SRAM_BANK_ADDR + WRITE_READ_ADDR + (4*(10)))

#define  res_2100_06_address (SRAM_BANK_ADDR + WRITE_READ_ADDR + (4*(9)))

#define  res_2102_06_address (SRAM_BANK_ADDR + WRITE_READ_ADDR + (4*(8)))

#define  res_2102_02_address (SRAM_BANK_ADDR + WRITE_READ_ADDR + (4*(7)))

#define  res_2100_02_address (SRAM_BANK_ADDR + WRITE_READ_ADDR + (4*(6)))

#define  res_2020_02_address (SRAM_BANK_ADDR + WRITE_READ_ADDR + (4*(5)))

#define  res_2002_02_address (SRAM_BANK_ADDR + WRITE_READ_ADDR + (4*(4)))

#define  res_2000_03_address (SRAM_BANK_ADDR + WRITE_READ_ADDR + (4*(3)))

#define  res_2000_01_address (SRAM_BANK_ADDR + WRITE_READ_ADDR + (4*(2)))

#define  res_2000_00_address   (SRAM_BANK_ADDR + WRITE_READ_ADDR + (4*(1)))

#define  first_SDO_address   (SRAM_BANK_ADDR + WRITE_READ_ADDR + (4*(0)))

#define Truck_ID_address           (SRAM_BANK_ADDR + WRITE_READ_ADDR + (4*(56)))




// Define Object Dictionary Elements




#define Truck_ID            "ECE225        2015" // must be even number of char
//#define Truck_ID              "ECE225        2011" // simpler truck
//#define Truck_ID              "EFGBAUREIHE2_32014" // other truck



typedef enum {
    CO_SDO_ST_IDLE = 0x00U,    

    CO_SDO_ST_DOWNLOAD_INITIATE_REQ = 0x11U,
    CO_SDO_ST_DOWNLOAD_INITIATE_RSP = 0x12U,    

    CO_SDO_ST_UPLOAD_INITIATE_REQ = 0x21U,
    CO_SDO_ST_UPLOAD_INITIATE_RSP = 0x22U,

    CO_SDO_ST_UPLOAD_SEGMENT_REQ = 0x23U,
    CO_SDO_ST_UPLOAD_SEGMENT_RSP = 0x24U,
} CO_SDO_state_t;

typedef enum {  
    TOOL_DEFAULT = 0x00U,
    TOOL_DELAY = 0x01U,
    TOOL_IGNORE = 0x02U,
    TOOL_PREDEFINED = 0x03U,  
    TOOL_FUNCTION = 0x04U,  
} Tool_state_t;

/**
 * SDO abort codes.
 *
 * Send with Abort SDO transfer message.
 *
 * The abort codes not listed here are reserved.
 */
typedef enum {
    /** 0x00000000, No abort */
    CO_SDO_AB_NONE                  = 0x00000000UL,
    /** 0x05030000, Toggle bit not altered */
    CO_SDO_AB_TOGGLE_BIT            = 0x05030000UL,
    /** 0x05040000, SDO protocol timed out */
    CO_SDO_AB_TIMEOUT               = 0x05040000UL,
    /** 0x05040001, Command specifier not valid or unknown */
    CO_SDO_AB_CMD                   = 0x05040001UL,
    /** 0x05040002, Invalid block size in block mode */
    CO_SDO_AB_BLOCK_SIZE            = 0x05040002UL,
    /** 0x05040003, Invalid sequence number in block mode */
    CO_SDO_AB_SEQ_NUM               = 0x05040003UL,
    /** 0x05040004, CRC error (block mode only) */
    CO_SDO_AB_CRC                   = 0x05040004UL,
    /** 0x05040005, Out of memory */
    CO_SDO_AB_OUT_OF_MEM            = 0x05040005UL,
    /** 0x06010000, Unsupported access to an object */
    CO_SDO_AB_UNSUPPORTED_ACCESS    = 0x06010000UL,
    /** 0x06010001, Attempt to read a write only object */
    CO_SDO_AB_WRITEONLY             = 0x06010001UL,
    /** 0x06010002, Attempt to write a read only object */
    CO_SDO_AB_READONLY              = 0x06010002UL,
    /** 0x06020000, Object does not exist in the object dictionary */
    CO_SDO_AB_NOT_EXIST             = 0x06020000UL,
    /** 0x06040041, Object cannot be mapped to the PDO */
    CO_SDO_AB_NO_MAP                = 0x06040041UL,
    /** 0x06040042, Number and length of object to be mapped exceeds PDO
     * length */
    CO_SDO_AB_MAP_LEN               = 0x06040042UL,
    /** 0x06040043, General parameter incompatibility reasons */
    CO_SDO_AB_PRAM_INCOMPAT         = 0x06040043UL,
    /** 0x06040047, General internal incompatibility in device */
    CO_SDO_AB_DEVICE_INCOMPAT       = 0x06040047UL,
    /** 0x06060000, Access failed due to hardware error */
    CO_SDO_AB_HW                    = 0x06060000UL,
    /** 0x06070010, Data type does not match, length of service parameter does
     * not match */
    CO_SDO_AB_TYPE_MISMATCH         = 0x06070010UL,
    /** 0x06070012, Data type does not match, length of service parameter too
     * high */
    CO_SDO_AB_DATA_LONG             = 0x06070012UL,
    /** 0x06070013, Data type does not match, length of service parameter too
     * short */
    CO_SDO_AB_DATA_SHORT            = 0x06070013UL,
    /** 0x06090011, Sub index does not exist */
    CO_SDO_AB_SUB_UNKNOWN           = 0x06090011UL,
    /** 0x06090030, Invalid value for parameter (download only). */
    CO_SDO_AB_INVALID_VALUE         = 0x06090030UL,
    /** 0x06090031, Value range of parameter written too high */
    CO_SDO_AB_VALUE_HIGH            = 0x06090031UL,
    /** 0x06090032, Value range of parameter written too low */
    CO_SDO_AB_VALUE_LOW             = 0x06090032UL,
    /** 0x06090036, Maximum value is less than minimum value. */
    CO_SDO_AB_MAX_LESS_MIN          = 0x06090036UL,
    /** 0x060A0023, Resource not available: SDO connection */
    CO_SDO_AB_NO_RESOURCE           = 0x060A0023UL,
    /** 0x08000000, General error */
    CO_SDO_AB_GENERAL               = 0x08000000UL,
    /** 0x08000020, Data cannot be transferred or stored to application */
    CO_SDO_AB_DATA_TRANSF           = 0x08000020UL,
    /** 0x08000021, Data cannot be transferred or stored to application because
     * of local control */
    CO_SDO_AB_DATA_LOC_CTRL         = 0x08000021UL,
    /** 0x08000022, Data cannot be transferred or stored to application because
     * of present device state */
    CO_SDO_AB_DATA_DEV_STATE        = 0x08000022UL,
    /** 0x08000023, Object dictionary not present or dynamic generation fails */
    CO_SDO_AB_DATA_OD               = 0x08000023UL,
    /** 0x08000024, No data available */
    CO_SDO_AB_NO_DATA               = 0x08000024UL
} CO_SDO_abortCode_t;

class LOITRUCK {
public:
/* ------------------------------- GLOBAL VAR ------------------------------- */
    can_t my_can; // mbed CAN object
    char counter = 0; 
    CANMessage msg_to_send; // mbed CAN message object
    FDCAN_RxHeaderTypeDef RxHeader; // HAL RxHeader object
    FDCAN_TxHeaderTypeDef TxHeader; // HAL TxHeader object
    uint8_t RxData[8]; // Buffer to save RxData
    uint8_t TxData[8]; // Buffer to save TxData
    FDCAN_ErrorCountersTypeDef error_counter; // Error Counter
    CO_SDO_state_t state = CO_SDO_ST_IDLE; // SDO state    
    Tool_state_t tool_state = TOOL_DEFAULT; // Tool state

    int dataSizeToWrite = 0;
    SDO* found_SDO;
    uint8_t SDO_toggle = 0;
    uint8_t segment_remain = 0;
    bool new_SDO_received = false;
    char buffer_string[100][100];    
    int buffer_count = 0;
    
    bool to_add = false;
    uint32_t to_add_Object_index = 0;
    uint32_t to_add_value = 0;

    CanMode my_can_mode;
    int last_linked_list_index = 0;



/* -------------------------------- FOR SRAM -------------------------------- */
    SRAM_HandleTypeDef hsram;
    FMC_NORSRAM_TimingTypeDef timing;
    FMC_NORSRAM_TimingTypeDef Extiming;
    uint32_t aTxBuffer[16];
    uint32_t aRxBuffer[16];
    uint16_t uwIndex;
    uint32_t Hash_Int = 0x00000F0F;
    SDO* my_SDO_List = NULL;
    SDO* my_last_SDO_element = NULL;

/* --------------------------------- FOR RTC -------------------------------- */
    RTC_HandleTypeDef hrtc;
    RTC_TimeTypeDef RTC_TimeRead;
    RTC_DateTypeDef RTC_DateRead;
    EXTI_HandleTypeDef hexti;
    EXTI_ConfigTypeDef ExtiConfig;
    bool alarm = false;
    int DWT_elapse = 0;

/* -------------------------------- FOR TIMER ------------------------------- */
    TIM_HandleTypeDef htimer6;
    bool timer6 = false;
    uint32_t passed_time_s = 0;
    
/* ------------------------------- FOR TESTING ------------------------------ */
    bool Rx_Fifo0_full = false;
    bool receiveMsg = false;
    bool timeout = false;
    bool interrupt = false;
    uint32_t Rx_IT_Number = 0;
    bool timestamp = false;
    bool found_parameter = false;
    bool sendMsg = false;
    bool fake_heart_beat;
    uint8_t fake_index = 1;
    //uint16_t test_worst_case[100];
    int test_worst_case_count = 0;
    int test_SDO_process_count = 0;
    uint32_t DWT_start = 0;
    uint32_t DWT_stop = 0;
    float sine_t = 0;

/* ------------------------------ FOR SEGMENTED ----------------------------- */
    uint8_t segment_count = 0;
    //bool segmented = false;
    uint8_t add_count = 0;
    uint8_t rest_count = 0;
    uint32_t rest_char = 0;
    uint16_t bit_swap = 0;

/* ------------------------------ FOR SCENARIO ------------------------------ */

    Scenario* current_Scenario = NULL;
    bool triggered = false;
    bool finish_Scenario = false;
    bool ignore = false;
    uint32_t delay = 0;
    bool send_predefined_CAN = false;
    //bool manipulate_var = false;
    uint32_t mani_buffer[256];
    int sample_rate = 0;
    int last_millis = 0;
    uint8_t buffer_index = 0;
    bool end_loop = false;
    bool value_changed = false;
    uint32_t temp_value_scenario = 0;


/* ------------------------------- CONSTRUCTOR ------------------------------ */
    LOITRUCK();
    void SDO_process_function();
    void State_process_function();
    void Download_function();
    void Upload_expedited_function();
    void Upload_segmented_function();
    void CAN_send();
    void my_can_write(can_t *obj, CANMessage msg); // for fault test
    uint16_t prepare_ID();
    struct SDO* find_value(struct SDO** head_ref, uint32_t value);
    bool compare_with_expect();
    //void append_Linked_List(struct SDO** head_ref, struct SDO* temp_node);                                    
    void append_Linked_List(struct SDO** head_ref, uint32_t _Object_index, uint32_t value);
    void display_Linked_List();
    void init_SDO_list();
};

#endif
