#ifndef FDCAN_H
#define FDCAN_H

#include "mbed.h"
#include "UTILITY.h"  // for some utility variable






void Set_Freq(can_t , const can_pinmap_t *, int);

void Set_CAN_Pin(can_t *, PinName , PinName , int );

void Trd_internal_init(can_t *);

int my_can_write(can_t *, CAN_Message , int cc);

int my_can_read(can_t *, CAN_Message *, int );

int my_can_filter(can_t *, uint32_t , uint32_t , CANFormat , int32_t );

unsigned char my_can_rderror(can_t *);

unsigned char my_can_tderror(can_t *);

int my_can_mode(can_t *, CanMode );

void FDCAN1_IT0_IRQHandler(void);

void HAL_FDCAN_TxBufferCompleteCallback(FDCAN_HandleTypeDef *, uint32_t );

void HAL_FDCAN_RxFifo0Callback(FDCAN_HandleTypeDef *, uint32_t );

void HAL_FDCAN_TimeoutOccurredCallback(FDCAN_HandleTypeDef *);

void HAL_FDCAN_TimestampWraparoundCallback(FDCAN_HandleTypeDef *);

#endif