#ifndef CAN_H
#define CAN_H

#include "Arduino.h"  // for uint32_t
#include "FDCAN.h"    // for RxData variable
#include "loiTruck_SDO.h" // for SDO Object
#include "SRAM.h"       // for my_SDO_list object




uint16_t prepare_ID(uint16_t );

static uint32_t BufferCmp32b(uint32_t* , uint32_t* , uint16_t );

bool check_COB_ID_range(uint32_t);

uint8_t prepare_Command_ID(bool end_msg);

uint8_t write_parameter(struct SDO** linked_list,uint32_t* Tx_array, uint32_t* Rx_array, uint32_t RxIdentifier);

uint8_t read_parameter(struct SDO** linked_list,uint32_t* Tx_array, uint32_t* Rx_array, uint32_t RxIdentifier);

struct SDO* find_value(struct SDO**, uint32_t);

void append_Linked_List(struct SDO**, struct SDO*);

void display_Linked_List(void);

static void Fill_Buffer(uint32_t *, uint32_t , uint16_t );

#endif
