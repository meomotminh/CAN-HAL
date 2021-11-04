#ifndef SRAM_H
#define SRAM_H

#include "mbed.h"
#include "loiTruck_SDO.h"
#include "UTILITY.h" // for append_linked_list function




uint8_t write_SDO_to_SRAM(void);

void init_SDO_object(void);

#endif
