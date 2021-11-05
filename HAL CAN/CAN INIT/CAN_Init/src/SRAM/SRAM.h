#ifndef SRAM_H
#define SRAM_H

#include "mbed.h"
#include "../UTILITY/UTILITY.h" // for append_linked_list function
#include "../loiTruck/loiTruck.h"




uint8_t write_SDO_to_SRAM(LOITRUCK* loiTruck);

void init_SDO_object(LOITRUCK* loiTruck);

#endif
