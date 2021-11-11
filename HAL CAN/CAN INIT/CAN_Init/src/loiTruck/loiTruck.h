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


// Declare SDO object value
// Segment STANDARD (0x2000 - 0x20FF)

/**
 * 0x2000 Komponenteninformation
 * **/


#define res_2000_00         0x09000000 // Subindex 0 : Number of entries 
#define res_2000_00_indx   1

#define res_2000_01         0x51854962
#define res_2000_01_indx    2

#define res_2000_03         0x51226801
#define res_2000_03_indx    3

#define res_2002_02         0x22222222
#define res_2002_02_indx    4

#define res_2020_02         0x2E740000
#define res_2020_02_indx    5

#define res_2100_02         0x64000000 // -------------------- BESCHLEUNIGUNG FAHRPROGRAM (SPEED UP 2100-------------------------
#define res_2100_02_indx    6

#define res_2102_02         0x32000000 // -------------------- BESCHLEUNIGUNG MITGÄNGER FAHRPROGRAM (SPEED UP SUBINDEX 2 2102------------------------
#define res_2102_02_indx    7

#define res_2102_06         0x32000000 // -------------------- BESCHLEUNIGUNG MITGÄNGER FAHRPROGRAM (SPEED UP SUBINDEX 2 2102-------------------------
#define res_2102_06_indx    8

#define res_2100_06         0x64000000 // -------------------- BESCHLEUNIGUNG FAHRPROGRAM (SPEED UP 2 2100???-------------------------
#define res_2100_06_indx    9

#define res_2200_02         0x0F000000 // -------------------- HOCHLAUFRAMPE HEBEN LASTTEIL 2200-------------------------
#define res_2200_02_indx    10

#define res_2200_06         0x0F000000 // -------------------- HOCHLAUFRAMPE HEBEN LASTTEIL 2200-------------------------
#define res_2200_06_indx    11

#define res_2001_01         0x05000000 // -------------------- LOGBUCH 2001-------------------------
#define res_2001_01_indx    12

#define res_2101_02         0x32000000 // -------------------- BESCHLEUNIGUNG MITFAHRER SUBINDEX 02 2101-------------------------
#define res_2101_02_indx    13

#define res_2101_06         0x32000000 // -------------------- BESCHLEUNIGUNG MITFAHRER SUBINDEX 06 2101-------------------------
#define res_2101_06_indx    14

#define res_2201_02         0x19000000 // -------------------- AUSLAUFRAMPE HEBEN LASTTEIL SUBINDEX 2 2201-------------------------
#define res_2201_02_indx    15

#define res_2201_06         0x19000000 // -------------------- AUSLAUFRAMPE HEBEN LASTTEIL SUB INDEX 6 2201-------------------------
#define res_2201_06_indx    16

#define res_2103_06         0x96000000 // -------------------- UNKNOWN 2103 SUBINX 06-------------------------
#define res_2103_06_indx    17

#define res_2103_02         0x96000000 // -------------------- UNKNOWN 2103 SUBINX 02-------------------------
#define res_2103_02_indx    18

#define res_2104_02         0x82000000 // -------------------- AUSROLLBREMSE MITFAHRER 2104 SUBINX 02-------------------------
#define res_2104_02_indx    19

#define res_2106_06         0x82000000 // -------------------- AUSROLLBREMSE MITFAHRER 2104 SUBINX 06-------------------------
#define res_2106_06_indx    20

#define res_2002_01         0x22222222 //---- Seri Nummer -----
#define res_2002_01_indx    21

#define res_2020_01         0x49010000 //---- betriebszeit -----
#define res_2020_01_indx    22

#define res_2413_02         0x00000000 //---- Lenkkorrektur ----
#define res_2413_02_indx    23

#define res_2923_02         0x00000000 //---- Bandagenentspannung ---
#define res_2923_02_indx    24

#define res_2414_02         0x00000000 //---- Lenkübersetzung ---
#define res_2414_02_indx    25

#define res_2461_02         0x00000000 //---- Status ---
#define res_2461_02_indx    26

#define res_2001_02         0x00000000 //---- Soll Indx Logbuch ---
#define res_2001_02_indx    27

#define res_2001_03         0x00000000 //---- Ist Indx Logbuch ---
#define res_2001_03_indx    28

#define res_2411_02         0x00000000 //---- Kennlinie ---
#define res_2411_02_indx    29

#define res_2405_02         0x00000000 //---- SollLenkwinkel Link ----
#define res_2405_02_indx    30

#define res_2402_02         0x00000000 //---- Istwertgeber Null ----
#define res_2402_02_indx    31

#define res_2405_07         0x00000000 //---- SollLenkwinkel Link Min value subindx 7 ---
#define res_2405_07_indx    32

#define res_2460_02         0x00000000 //---- Status Lenken ----------
#define res_2460_02_indx    33

#define res_2404_02         0x00000000 //---- SollLenkwinkel Recht ----
#define res_2404_02_indx    34

#define res_2401_02         0x00000000 //---- IstLenkwinkel Recht ----
#define res_2401_02_indx    35

#define res_2403_02         0x00000000 //---- SollLenkwinkel Null ----
#define res_2403_02_indx    36

#define res_2400_02         0x00000000 //---- IstLenkwinkel Null not teach---
#define res_2400_02_indx    37

#define res_2403_07         0x00000000 //---- Min IstLenkwinkel Null teach---
#define res_2403_07_indx    38

#define res_2404_07         0x00000000 //---- Min IstLenkwinkel Recht teach---
#define res_2404_07_indx    39

#define res_2405_03         0x00000000 //---- Min value lenken
#define res_2405_03_indx    40

#define res_2404_03         0x00000000 //---- Min value lenken
#define res_2404_03_indx    41

#define res_2403_03         0x00000000 //---- Min value lenken
#define res_2403_03_indx    42

#define res_2405_04         0x00000000 //---- Max value lenken
#define res_2405_04_indx    43

#define res_2404_04         0x00000000 //---- Max value lenken
#define res_2404_04_indx    44

#define res_2403_04         0x00000000 //---- Max value lenken
#define res_2403_04_indx    45

#define res_2402_07         0x00000000 //---- Ist Teach-In Link
#define res_2402_07_indx    46

#define res_2401_07         0x00000000 //---- Ist Teach-In Recht 
#define res_2401_07_indx    47

#define res_2400_07         0x00000000 //---- Ist Teach-In Null
#define res_2400_07_indx    48

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

    // Constructor
    SDO(uint32_t _index, uint32_t _address, uint32_t _value, struct SDO* _next, uint8_t _length, bool _segmented){            
        index = _index;
        address = _address;
        value = _value;
        next = _next;
        length = _length;
        segmented = _segmented;
    }
};



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
