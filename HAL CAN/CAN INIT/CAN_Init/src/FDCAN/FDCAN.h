#ifndef FDCAN_H
#define FDCAN_H

#include "mbed.h"
#include "../loiTruck/loiTruck.h"



void Set_Freq(can_t , const can_pinmap_t *, int);

void Set_CAN_Pin(can_t *, PinName , PinName , int );

void Trd_internal_init(can_t *);

int my_can_write(can_t *, CAN_Message , int cc, LOITRUCK* loiTruck);

int my_can_read(can_t *, CAN_Message *, int ,LOITRUCK* loiTruck);

unsigned char my_can_rderror(can_t *);

unsigned char my_can_tderror(can_t *);

int my_can_mode(can_t *, CanMode );


#endif