#ifndef CAN_H
#define CAN_H

#include "Arduino.h"  // for uint32_t
#include "../loiTruck/loiTruck.h"
#include "../SRAM/SRAM.h"       // for my_SDO_list object
#include "../../Scenario.h"
#include "../RTC/RTC.h"


uint16_t prepare_ID(uint16_t );

static uint32_t BufferCmp32b(uint32_t* , uint32_t* , uint16_t );

bool check_COB_ID_range(uint32_t);

uint8_t prepare_Command_ID(bool end_msg, LOITRUCK* loiTruck);

uint8_t write_parameter(LOITRUCK* loiTruck);

uint8_t read_parameter(LOITRUCK* loiTruck);

struct SDO* find_value(struct SDO**, uint32_t);

void append_Linked_List(struct SDO**, struct SDO*);

void display_Linked_List(LOITRUCK* loiTruck);

static void Fill_Buffer(uint32_t *, uint32_t , uint16_t );

bool find_Scenario(LOITRUCK* loiTruck);

bool setup_Scenario(LOITRUCK* loiTruck);

#endif
