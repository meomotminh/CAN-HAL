#ifndef LOITRUCK_H
#define LOITRUCK_H

#include "mbed.h"
#include "../../Scenario.h"

using namespace mbed;

#define SRAM_BANK_ADDR      ((uint32_t) 0x30000000)     // SRAM1 Address | 0x10000000
#define WRITE_READ_ADDR     ((uint32_t) 0x0800)

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

// 50ms

// Declare SDO object value
// Segment STANDARD (0x2000 - 0x20FF)

/**
 * 0x2000 Komponenteninformation
 * **/






//#define Truck_ID            "ECE 225       2011" // must divide 4 or some " " will be added at the end
#define Truck_ID            "ECE225        2015" // must be even number of char
#define Truck_ID_indx       49          // +6 words ceil(22/4.0)

#define Truck_null_word     ((uint32_t)0x00000000U)          // save some extra space symbol

typedef struct SDO {
public:    
    uint32_t index;
    uint32_t address;
    uint32_t value;
    
    struct SDO* next;
    uint8_t length;
    bool segmented;

    uint32_t to_save;

    // Constructor
    SDO(uint32_t _index, uint32_t _address, uint32_t _value, struct SDO* _next, uint8_t _length, bool _segmented, uint32_t _to_save){            
        index = _index;
        address = _address;
        value = _value; // not value to be saved in SRAM but the 0x20002 value
        next = _next;
        length = _length;
        segmented = _segmented;
        to_save = _to_save;
    }
};


static SDO res_4007_08(55, 0x0, 0x400708, NULL, 0x4, false, 0x01000000);  // uint16 type

static SDO res_4007_02(54, 0x0, 0x400702, &res_4007_08, 0x4, false, 0x01000000);  // uint16 type

static SDO res_4007_01(53, 0x0, 0x400701, &res_4007_02, 0x4, false, 0x01000000);  // uint8 type

static SDO res_4007_00(52, 0x0, 0x400700, &res_4007_01, 0x4, false, 0x08000000);  // number of entries AC Betriebsgroessen

static SDO res_4000_04(51, 0x0, 0x400004, &res_4007_00, 0x4, false, 0x04000000);  // ist drehzahl 16 bit

static SDO res_4000_03(50, 0x0, 0x400003, &res_4000_04, 0x4, false, 0x02000000);  // ramp down

static SDO res_4000_02(49, 0x0, 0x400002, &res_4000_03, 0x4, false, 0x02000000);  // ramp up

static SDO res_4000_01(48, 0x0, 0x400001, &res_4000_02, 0x4, false, 0x01000000);  // soll drehzahl

static SDO res_2400_07(47, 0x0, 0x240007, &res_4000_01, 0x4, false, 0x00000000);  

static SDO res_2401_07(46, 0x0, 0x240107, &res_2400_07, 0x4, false, 0x00000000);

static SDO res_2402_07(45, 0x0, 0x240207, &res_2401_07, 0x4, false, 0x00000000);

static SDO res_2403_04(44, 0x0, 0x240304, &res_2402_07, 0x4, false, 0x00000000);

static SDO res_2404_04(43, 0x0, 0x240404, &res_2403_04, 0x4, false, 0x00000000);

static SDO res_2405_04(42, 0x0, 0x240504, &res_2404_04, 0x4, false, 0x00000000);

static SDO res_2403_03(41, 0x0, 0x240303, &res_2405_04, 0x4, false, 0x00000000);

static SDO res_2404_03(40, 0x0, 0x240403, &res_2403_03, 0x4, false, 0x00000000);

static SDO res_2405_03(39, 0x0, 0x240503, &res_2404_03, 0x4, false, 0x00000000);

static SDO res_2404_07(38, 0x0, 0x240407, &res_2405_03, 0x4, false, 0x00000000);

static SDO res_2403_07(37, 0x0, 0x240307, &res_2404_07, 0x4, false, 0x00000000);

static SDO res_2403_02(36, 0x0, 0x240302, &res_2403_07, 0x4, false, 0x00000000);

static SDO res_2401_02(35, 0x0, 0x240102, &res_2403_02, 0x4, false, 0x00000000);

static SDO res_2404_02(34, 0x0, 0x240402, &res_2401_02, 0x4, false, 0x00000000);

static SDO res_2460_02(33, 0x0, 0x246002, &res_2404_02, 0x4, false, 0x00000000);

static SDO res_2405_07(32, 0x0, 0x240507, &res_2460_02, 0x4, false, 0x00000000);

static SDO res_2402_02(31, 0x0, 0x240202, &res_2405_07, 0x4, false, 0x00000000);

static SDO res_2405_02(30, 0x0, 0x240502, &res_2402_02, 0x4, false, 0x00000000);

static SDO res_2411_02(29, 0x0, 0x241102, &res_2405_02, 0x4, false, 0x00000000);

static SDO res_2001_03(28, 0x0, 0x200103, &res_2411_02, 0x4, false, 0x00000000);

static SDO res_2001_02(27, 0x0, 0x200102, &res_2001_03, 0x4, false, 0x00000000);

static SDO res_2461_02(26, 0x0, 0x246102, &res_2001_02, 0x4, false, 0x00000000);

static SDO res_2414_02(25, 0x0, 0x241402, &res_2461_02, 0x4, false, 0x00000000);

static SDO res_2923_02(24, 0x0, 0x292302, &res_2414_02, 0x4, false, 0x00000000);

static SDO res_2413_02(23, 0x0, 0x241302, &res_2923_02, 0x4, false, 0x00000000);

static SDO res_2020_01(22, 0x0, 0x202001, &res_2413_02, 0x4, false, 0x49010000);

static SDO res_2002_01(21, 0x0, 0x200201, &res_2020_01, 0x4, false, 0x8e155301); 

static SDO res_2106_06(20, 0x0, 0x210606, &res_2002_01, 0x4, false, 0x82000000);

static SDO res_2104_02(19, 0x0, 0x210402, &res_2106_06, 0x4, false, 0x82000000);

static SDO res_2103_02(18, 0x0, 0x210302, &res_2104_02, 0x4, false, 0x96000000);

static SDO res_2103_06(17, 0x0, 0x210306, &res_2103_02, 0x4, false, 0x96000000);

static SDO res_2201_06(16, 0x0, 0x220106, &res_2103_06, 0x4, false, 0x19000000);

static SDO res_2201_02(15, 0x0, 0x220102, &res_2201_06, 0x4, false, 0x19000000);

static SDO res_2101_06(14, 0x0, 0x210106, &res_2201_02, 0x4, false, 0x32000000);

static SDO res_2101_02(13, 0x0, 0x210102, &res_2101_06, 0x4, false, 0x32000000);

static SDO res_2001_01(12, 0x0, 0x200101, &res_2101_02, 0x4, false, 0x05000000);

static SDO res_2200_06(11, 0x0, 0x220006, &res_2001_01, 0x4, false, 0x0F000000);

static SDO res_2200_02(10, 0x0, 0x220002, &res_2200_06, 0x4, false, 0x0F000000);

static SDO res_2100_06(9, 0x0,  0x210006, &res_2200_02, 0x4, false, 0x64000000);

static SDO res_2102_06(8, 0x0,  0x210206, &res_2100_06, 0x4, false, 0x32000000);

static SDO res_2102_02(7, 0x0,  0x210202, &res_2102_06, 0x4, false, 0x32000000);

static SDO res_2100_02(6, 0x0,  0x210002, &res_2102_02, 0x4, false, 0x2E740000);

static SDO res_2020_02(5, 0x0,  0x202002, &res_2100_02, 0x4, false, 0x2E740000);

static SDO res_2002_02(4, 0x0,  0x200202, &res_2020_02, 0x4, false, 0x00000002);

static SDO res_2000_03(3, 0x0,  0x200003, &res_2002_02, 0x4, false, 0x01682251);

static SDO res_2000_01(2, 0x0,  0x200001, &res_2000_03, 0x4, false, 0x62498551);

static SDO first_SDO(1, 0x0,    0x200000, &res_2000_01, 0x4, false, 0x09000000);

#define Truck_ID            "ECE225        2015" // must be even number of char
//#define Truck_ID              "ECE225        2011" // simpler truck
//#define Truck_ID              "EFGBAUREIHE2_32014" // other truck


class LOITRUCK {
public:
/* ------------------------------- GLOBAL VAR ------------------------------- */
    can_t my_can; // mbed CAN object
    char counter = 0; 
    CANMessage msg; // mbed CAN message object
    FDCAN_RxHeaderTypeDef RxHeader; // HAL RxHeader object
    FDCAN_TxHeaderTypeDef TxHeader; // HAL TxHeader object
    uint8_t RxData[8]; // Buffer to save RxData
    uint8_t TxData[8]; // Buffer to save TxData
    FDCAN_ErrorCountersTypeDef error_counter; // Error Counter

/* -------------------------------- FOR SRAM -------------------------------- */
    SRAM_HandleTypeDef hsram;
    FMC_NORSRAM_TimingTypeDef timing;
    FMC_NORSRAM_TimingTypeDef Extiming;
    uint32_t aTxBuffer[16];
    uint32_t aRxBuffer[16];
    uint16_t uwIndex;
    uint32_t Hash_Int = 0x00000F0F;
    SDO* my_SDO_List = NULL;

/* --------------------------------- FOR RTC -------------------------------- */
    RTC_HandleTypeDef hrtc;
    RTC_TimeTypeDef RTC_TimeRead;
    RTC_DateTypeDef RTC_DateRead;
    EXTI_HandleTypeDef hexti;
    EXTI_ConfigTypeDef ExtiConfig;
    bool alarm = false;

/* -------------------------------- FOR TIMER ------------------------------- */
    TIM_HandleTypeDef htimer6;
    bool timer6 = false;
    uint32_t passed_time_us = 0;

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

/* ------------------------------ FOR SEGMENTED ----------------------------- */
    uint8_t segment_count = 0;
    bool segmented = false;
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


/* ------------------------------- CONSTRUCTOR ------------------------------ */
    LOITRUCK();
};

#endif
