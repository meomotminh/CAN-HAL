
#pragma once
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

#define  first_SDO_address   (SRAM_BANK_ADDR + WRITE_READ_ADDR + (4*(1)))

#define Truck_ID_address           (SRAM_BANK_ADDR + WRITE_READ_ADDR + (4*(56)))




// Define Object Dictionary Elements
static SDO res_4007_08(55, res_4007_08_address, 0x400708, NULL, 0x4, false, 0x01000000);  // uint16 type

static SDO res_4007_02(54, res_4007_02_address, 0x400702, &res_4007_08, 0x4, false, 0x01000000);  // uint16 type

static SDO res_4007_01(53, res_4007_01_address, 0x400701, &res_4007_02, 0x4, false, 0x01000000);  // uint8 type

static SDO res_4007_00(52, res_4007_00_address, 0x400700, &res_4007_01, 0x4, false, 0x08000000);  // number of entries AC Betriebsgroessen

static SDO res_4000_04(51, res_4000_04_address, 0x400004, &res_4007_00, 0x4, false, 0x04000000);  // ist drehzahl 16 bit

static SDO res_4000_03(50, res_4000_03_address, 0x400003, &res_4000_04, 0x4, false, 0x02000000);  // ramp down

static SDO res_4000_02(49, res_4000_02_address, 0x400002, &res_4000_03, 0x4, false, 0x02000000);  // ramp up

static SDO res_4000_01(48, res_4000_01_address, 0x400001, &res_4000_02, 0x4, false, 0x01000000);  // soll drehzahl

static SDO res_2400_07(47, res_2400_07_address, 0x240007, &res_4000_01, 0x4, false, 0x00000000);  

static SDO res_2401_07(46, res_2401_07_address, 0x240107, &res_2400_07, 0x4, false, 0x00000000);

static SDO res_2402_07(45, res_2402_07_address, 0x240207, &res_2401_07, 0x4, false, 0x00000000);

static SDO res_2403_04(44, res_2403_04_address, 0x240304, &res_2402_07, 0x4, false, 0x00000000);

static SDO res_2404_04(43, res_2404_04_address, 0x240404, &res_2403_04, 0x4, false, 0x00000000);

static SDO res_2405_04(42, res_2405_04_address, 0x240504, &res_2404_04, 0x4, false, 0x00000000);

static SDO res_2403_03(41, res_2403_03_address, 0x240303, &res_2405_04, 0x4, false, 0x00000000);

static SDO res_2404_03(40, res_2404_03_address, 0x240403, &res_2403_03, 0x4, false, 0x00000000);

static SDO res_2405_03(39, res_2405_03_address, 0x240503, &res_2404_03, 0x4, false, 0x00000000);

static SDO res_2404_07(38, res_2404_07_address, 0x240407, &res_2405_03, 0x4, false, 0x00000000);

static SDO res_2403_07(37, res_2403_07_address, 0x240307, &res_2404_07, 0x4, false, 0x00000000);

static SDO res_2403_02(36, res_2403_02_address, 0x240302, &res_2403_07, 0x4, false, 0x00000000);

static SDO res_2401_02(35, res_2401_02_address, 0x240102, &res_2403_02, 0x4, false, 0x00000000);

static SDO res_2404_02(34, res_2404_02_address, 0x240402, &res_2401_02, 0x4, false, 0x00000000);

static SDO res_2460_02(33, res_2460_02_address, 0x246002, &res_2404_02, 0x4, false, 0x00000000);

static SDO res_2405_07(32, res_2405_07_address, 0x240507, &res_2460_02, 0x4, false, 0x00000000);

static SDO res_2402_02(31, res_2402_02_address, 0x240202, &res_2405_07, 0x4, false, 0x00000000);

static SDO res_2405_02(30, res_2405_02_address, 0x240502, &res_2402_02, 0x4, false, 0x00000000);

static SDO res_2411_02(29, res_2411_02_address, 0x241102, &res_2405_02, 0x4, false, 0x00000000);

static SDO res_2001_03(28, res_2001_03_address, 0x200103, &res_2411_02, 0x4, false, 0x00000000);

static SDO res_2001_02(27, res_2001_02_address, 0x200102, &res_2001_03, 0x4, false, 0x00000000);

static SDO res_2461_02(26, res_2461_02_address, 0x246102, &res_2001_02, 0x4, false, 0x00000000);

static SDO res_2414_02(25, res_2414_02_address, 0x241402, &res_2461_02, 0x4, false, 0x00000000);

static SDO res_2923_02(24, res_2923_02_address, 0x292302, &res_2414_02, 0x4, false, 0x00000000);

static SDO res_2413_02(23, res_2413_02_address, 0x241302, &res_2923_02, 0x4, false, 0x00000000);

static SDO res_2020_01(22, res_2020_01_address, 0x202001, &res_2413_02, 0x4, false, 0x49010000);

static SDO res_2002_01(21, res_2002_01_address, 0x200201, &res_2020_01, 0x4, false, 0x8e155301); 

static SDO res_2106_06(20, res_2106_06_address, 0x210606, &res_2002_01, 0x4, false, 0x82000000);

static SDO res_2104_02(19, res_2104_02_address, 0x210402, &res_2106_06, 0x4, false, 0x82000000);

static SDO res_2103_02(18, res_2103_02_address, 0x210302, &res_2104_02, 0x4, false, 0x96000000);

static SDO res_2103_06(17, res_2103_06_address, 0x210306, &res_2103_02, 0x4, false, 0x96000000);

static SDO res_2201_06(16, res_2201_06_address, 0x220106, &res_2103_06, 0x4, false, 0x19000000);

static SDO res_2201_02(15, res_2201_02_address, 0x220102, &res_2201_06, 0x4, false, 0x19000000);

static SDO res_2101_06(14, res_2101_06_address, 0x210106, &res_2201_02, 0x4, false, 0x32000000);

static SDO res_2101_02(13, res_2101_02_address, 0x210102, &res_2101_06, 0x4, false, 0x32000000);

static SDO res_2001_01(12, res_2001_01_address, 0x200101, &res_2101_02, 0x4, false, 0x05000000);

static SDO res_2200_06(11, res_2200_06_address, 0x220006, &res_2001_01, 0x4, false, 0x0F000000);

static SDO res_2200_02(10, res_2200_02_address, 0x220002, &res_2200_06, 0x4, false, 0x0F000000);

static SDO res_2100_06(9, res_2100_06_address,  0x210006, &res_2200_02, 0x4, false, 0x64000000);

static SDO res_2102_06(8, res_2102_06_address,  0x210206, &res_2100_06, 0x4, false, 0x32000000);

static SDO res_2102_02(7, res_2102_02_address,  0x210202, &res_2102_06, 0x4, false, 0x32000000);

static SDO res_2100_02(6, res_2100_02_address,  0x210002, &res_2102_02, 0x4, false, 0x2E740000);

static SDO res_2020_02(5, res_2020_02_address,  0x202002, &res_2100_02, 0x4, false, 0x2E740000);

static SDO res_2002_02(4, res_2002_02_address,  0x200202, &res_2020_02, 0x4, false, 0x00000002);

static SDO res_2000_03(3, res_2000_03_address,  0x200003, &res_2002_02, 0x4, false, 0x01682251);

static SDO res_2000_01(2, res_2000_01_address,  0x200001, &res_2000_03, 0x4, false, 0x62498551);

static SDO first_SDO(1, first_SDO_address,    0x200000, &res_2000_01, 0x4, false, 0x09000000);

#define Truck_ID            "ECE225        2015" // must be even number of char
//#define Truck_ID              "ECE225        2011" // simpler truck
//#define Truck_ID              "EFGBAUREIHE2_32014" // other truck

typedef uint32_t OD_size_t;

/** Type (and size) of Object Dictionary attribute */
typedef uint8_t OD_attr_t;

/**
 * Return codes from OD access functions.
 *
 * @ref OD_getSDOabCode() can be used to retrieve corresponding SDO abort code.
 */
typedef enum {
/* !!!! WARNING !!!!
 * If changing these values, change also OD_getSDOabCode() function!
 */
    /** Read/write is only partial, make more calls */
    ODR_PARTIAL = -1,
    /** SDO abort 0x00000000 - Read/write successfully finished */
    ODR_OK = 0,
    /** SDO abort 0x05040005 - Out of memory */
    ODR_OUT_OF_MEM = 1,
    /** SDO abort 0x06010000 - Unsupported access to an object */
    ODR_UNSUPP_ACCESS = 2,
    /** SDO abort 0x06010001 - Attempt to read a write only object */
    ODR_WRITEONLY = 3,
    /** SDO abort 0x06010002 - Attempt to write a read only object */
    ODR_READONLY = 4,
    /** SDO abort 0x06020000 - Object does not exist in the object dict. */
    ODR_IDX_NOT_EXIST = 5,
    /** SDO abort 0x06040041 - Object cannot be mapped to the PDO */
    ODR_NO_MAP = 6,
    /** SDO abort 0x06040042 - PDO length exceeded */
    ODR_MAP_LEN = 7,
    /** SDO abort 0x06040043 - General parameter incompatibility reasons */
    ODR_PAR_INCOMPAT = 8,
    /** SDO abort 0x06040047 - General internal incompatibility in device */
    ODR_DEV_INCOMPAT = 9,
    /** SDO abort 0x06060000 - Access failed due to hardware error */
    ODR_HW = 10,
    /** SDO abort 0x06070010 - Data type does not match */
    ODR_TYPE_MISMATCH = 11,
    /** SDO abort 0x06070012 - Data type does not match, length too high */
    ODR_DATA_LONG = 12,
    /** SDO abort 0x06070013 - Data type does not match, length too short */
    ODR_DATA_SHORT = 13,
    /** SDO abort 0x06090011 - Sub index does not exist */
    ODR_SUB_NOT_EXIST = 14,
    /** SDO abort 0x06090030 - Invalid value for parameter (download only) */
    ODR_INVALID_VALUE = 15,
    /** SDO abort 0x06090031 - Value range of parameter written too high */
    ODR_VALUE_HIGH = 16,
    /** SDO abort 0x06090032 - Value range of parameter written too low */
    ODR_VALUE_LOW = 17,
    /** SDO abort 0x06090036 - Maximum value is less than minimum value */
    ODR_MAX_LESS_MIN = 18,
    /** SDO abort 0x060A0023 - Resource not available: SDO connection */
    ODR_NO_RESOURCE = 19,
    /** SDO abort 0x08000000 - General error */
    ODR_GENERAL = 20,
    /** SDO abort 0x08000020 - Data cannot be transferred or stored to app */
    ODR_DATA_TRANSF = 21,
    /** SDO abort 0x08000021 - Data can't be transferred (local control) */
    ODR_DATA_LOC_CTRL = 22,
    /** SDO abort 0x08000022 - Data can't be transf. (present device state) */
    ODR_DATA_DEV_STATE = 23,
    /** SDO abort 0x08000023 - Object dictionary not present */
    ODR_OD_MISSING = 23,
    /** SDO abort 0x08000024 - No data available */
    ODR_NO_DATA = 25,
    /** Last element, number of responses */
    ODR_COUNT = 26
} ODR_t;

/**
 * IO stream structure, used for read/write access to OD variable, part of
 * @ref OD_IO_t.
 */
typedef struct {
    /** Pointer to original data object, defined by Object Dictionary. Default
     * read/write functions operate on it. If memory for data object is not
     * specified by Object Dictionary, then dataOrig is NULL.
     */
    void *dataOrig;
    /** Pointer to object, passed by @ref OD_extension_init(). Can be used
     * inside read / write functions from IO extension.
     */
    void *object;
    /** Data length in bytes or 0, if length is not specified */
    OD_size_t dataLength;
    /** In case of large data, dataOffset indicates position of already
     * transferred data */
    OD_size_t dataOffset;
    /** Attribute bit-field of the OD sub-object, see @ref OD_attributes_t */
    OD_attr_t attribute;
    /** Sub index of the OD sub-object, informative */
    uint8_t subIndex;
} OD_stream_t;

typedef struct {
    // object Dictionary stream object
    OD_stream_t stream;

    // read function
    ODR_t (*read)(OD_stream_t *stream, void *buf, OD_size_t count, OD_size_t *countRead);

    // write function
    ODR_t (*write)(OD_stream_t *stream, const void *buf, OD_size_t count, OD_size_t *countWritten);
} OD_IO_t;

// return values from SDO server or client functions
typedef enum {
    // waiting in client local transfer
    CO_SDO_RT_waitingLocalTransfer = 6,
    // data buffer is full. SDO client, data must be read before next upload cycle begin
    CO_SDO_RT_uploadDataBufferFull = 5,
    // CAN transmit buffer is full
    CO_SDO_RT_transmittBufferFull = 4,
    // Block download is in progress, sending train of messages
    CO_SDO_RT_blockDownldInProgress = 3,
    // Block upload is in progress. receiving train of messages
    CO_SDO_RT_blockUploadInProgress = 2,
    // Waiting server or client response
    CO_SDO_RT_waitingResponse = 1,
    // Success, end of communication
    CO_SDO_RT_ok_communicationEnd = 0,
    // Error in arguments
    CO_SDO_RT_wrongArguments = -2,
    // Communication ended with client abort
    CO_SDO_RT_endedWithClientAbort = -9,
    // Communication ended with server abort
    CO_SDO_RT_endedWithServerAbort = -10,
} CO_SDO_return_t;

// SDO server object
typedef struct
{
    // From CO_SDOserver_init()
    CO_CANmodule_t *CANdevTx;
    // CAN transmit buffer inside CANdevTx for CAN tx message
    CO_CANtx_t *CANtxBuff;
    // From CO_SDOserver_init()
    OD_t *OD;
    // From CO_SDOserver_init()
    uint8_t nodeId;
    // if true, SDO channel is valid
    bool valid;
    // internal state of SDO server
    volatile CO_SDO_state_t state;
    // Object dictionary interface for current object
    OD_IO_t OD_IO;
    // index of current object in Object dictionary
    uint16_t index;
    // subindex of current object in Object dictionary
    uint8_t subIndex;
    // indicate if new SDO message received from CAN bus, not cleared until received msg is completely processed
    volatile void *CANrxNew;
    // 8 data bytes of received message
    uint8_t CANrxData[8];

    // size of data to be transferred
    OD_size_t sizeInd;
    // size of data actually transferred
    OD_size_t sizeTran;
    // Toggle bit in each segment of segmented transfer
    uint8_t toggle;
    // if true, data transfer is finished
    bool finished;
    // max timeout time bw request and response
    uint32_t SDOtimeoutTime_us;
    // Timeout timer for SDO communication
    uint32_t timeoutTimer;
    // interim data buffer for segmented or block transfer + byte for '\0'
    uint8_t buf[8 + 1];
    // offset of next free data byte available for write in buffer
    OD_size_t buffOffsetWr;
    // offset of first data available for read in buffer
    OD_size_t bufOffsetRd;

} CO_SDOserver_t;



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
    //uint16_t test_worst_case[100];
    int test_worst_case_count = 0;

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
    void SDO_process_function();
    void Upload_procedure();
    void Download_procedure();
    void Upload_expedited_function();
    void Upload_segmented_function();
};

#endif
