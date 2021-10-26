#include "mbed.h"
#include <ThreadDebug.h>
#include "loiTruck_SDO.h"

// For TRACE32 Debug
//UsbDebugCommInterface debugComm(&SerialUSB);
//ThreadDebug           threadDebug(&debugComm, DEBUG_BREAK_IN_SETUP);

using namespace mbed;

/**********CAN GLOBAL VAR*************/
can_t my_can; // mbed CAN object
char counter = 0; 
CAN_Message msg; // mbed CAN message object
FDCAN_RxHeaderTypeDef RxHeader; // HAL RxHeader object
FDCAN_TxHeaderTypeDef TxHeader; // HAL TxHeader object
uint8_t RxData[8]; // Buffer to save RxData
uint8_t TxData[8]; // Buffer to save TxData

/********BOOL VAR FOR TESTING********/
bool receiveMsg = false;
bool Rx_Fifo0_full = false;
bool timeout = false;
bool interrupt = false;
uint32_t Rx_IT_Number = 0;
bool timestamp = false;

/**********SRAM GLOBAL VAR*************/
SRAM_HandleTypeDef hsram;
FMC_NORSRAM_TimingTypeDef timing;
FMC_NORSRAM_TimingTypeDef Extiming;
uint32_t aTxBuffer[16];
uint32_t aRxBuffer[16];
uint16_t uwIndex;
uint32_t Hash_Int = 0x00000F0F;
SDO* my_SDO_List = NULL;


HAL_StatusTypeDef hal_can_init(FDCAN_HandleTypeDef *hfdcan){
    return (HAL_FDCAN_Init(hfdcan));
}


static uint32_t CRC_Hash_Function(uint32_t toHash){
  uint32_t temp = toHash & 0xF8000000;  // get 5 bits
  toHash = toHash << 5;
  toHash = toHash ^ (temp >> 27);
  toHash = toHash ^ Hash_Int;
  return toHash;
}


/**
 * Write Parameter
 * **/
uint8_t write_parameter(void){
  uint32_t tmp = (RxData[2] << 16) + (RxData[1] << 8) + RxData[3];
  uint32_t value = (RxData[7] << 24) + (RxData[6] << 16) + (RxData[5] << 8) + RxData[4];
  struct SDO* found = find_value(&my_SDO_List, tmp);

  if ( found != NULL){
    *(__IO uint32_t *)(found->address) = value;
    TxData[0] = ??;
    TxData[1] = RxData[1];
    TxData[2] = RxData[2];
    TxData[3] = RxData[3];
    TxData[4] = 0x00;
    TxData[5] = 0x00;
    TxData[6] = 0x00;
    TxData[7] = 0x00;
  } else {
    TxData[0] = ??;
    TxData[1] = RxData[1];
    TxData[2] = RxData[2];
    TxData[3] = RxData[3];
    TxData[4] = 0x00;
    TxData[5] = 0x00;
    TxData[6] = 0x00;
    TxData[7] = 0x00;
    return 0;
  }
  
  return 1;
}



/**
 * Read Parameter
 * */
uint8_t SDO* read_parameter(void){
  uint32_t tmp = (RxData[2] << 16) + (RxData[1] << 8) + RxData[3];
  struct SDO* found = find_value(&my_SDO_List, tmp);

  if (found == NULL){
    TxData[0] = ??;
    TxData[1] = RxData[1];
    TxData[2] = RxData[2];
    TxData[3] = RxData[3];
    TxData[4] = 0x00;
    TxData[5] = 0x00;
    TxData[6] = 0x00;
    TxData[7] = 0x00;
    return 0;
  } else {
    uint32_t read_from_SRAM = *(__IO uint16_t *)(found->address);

    TxData[0] = ??;
    TxData[1] = RxData[1];
    TxData[2] = RxData[2];
    TxData[3] = RxData[3];
    TxData[4] = read_from_SRAM & 0xFF000000;
    TxData[5] = read_from_SRAM & 0x00FF0000;
    TxData[6] = read_from_SRAM & 0x0000FF00;
    TxData[7] = read_from_SRAM & 0x000000FF;
  }

  return 1;

}


/**
 * Find value in Linked List
 * **/
struct SDO* find_value(struct SDO** head_ref, uint32_t value){
  struct SDO *last = *head_ref;

  if (*last == NULL){
    return NULL;
  } 
    
  // traverse until the end
  while (last->next != NULL){
    if (last->value == value) 
      return last;
    last = last->next;
  }

  return NULL;
}

/**
 * Append 1 node into linked list 
**/
void append_Linked_List(struct SDO** head_ref, uint32_t index, uint32_t address, uint32_t value){
  // allocate new node
  struct SDO* new_node = (struct SDO*)malloc(sizeof(struct SDO));

  struct SDO *last = *head_ref;

  // put data
  new_node->index = index;
  new_node->address = address;
  new_node->value = value;
  new_node->next = NULL;

  // if linked list is empty then make new node as head
  if (*head_ref == NULL){
    *head_ref = new_node;
    return;
  }

  // else traverse till the last node
  while (last->next != NULL)
    last = last->next;

  // change the next of last node
  last->next = new_node;
  return;
}

void display_Linked_List(void){
  struct SDO *tmp;
  if (my_SDO_List == NULL){
    return;
  } else {    
    tmp = my_SDO_List;
    while (tmp != NULL){
      Serial.println("****************");
      Serial.print("SDO index:"); Serial.println(tmp->index);
      Serial.print("SDO address:"); Serial.println(tmp->address, HEX);
      Serial.print("SDO value:"); Serial.println(tmp->value);

      tmp = tmp->next;
    }
  }
}

/* https://github.com/STMicroelectronics/STM32CubeG4/blob/master/Projects/STM32G474E-EVAL/Examples/FMC/FMC_SRAM/Src/main.c */
static void Fill_Buffer(uint32_t *pBuffer, uint32_t uwBufferLength, uint16_t uwOffset){
  uint16_t tmpIndex = 0;

  for (tmpIndex = 0; tmpIndex < uwBufferLength; tmpIndex++){
    pBuffer[tmpIndex] = tmpIndex + uwOffset;
  }
}

uint8_t write_SDO_to_SRAM(void){
  uwIndex = 0;
  
  //Serial.println(CRC_Hash_Function(200000));
#ifdef res_2000_00 
  *(__IO uint32_t *)(SRAM_BANK_ADDR + WRITE_READ_ADDR + (4*res_2000_00_indx)) = res_2000_00;
  //Serial.println(res_2000_00_indx);
  // create SDO object and add to linked list
  append_Linked_List(&my_SDO_List, res_2000_00_indx, SRAM_BANK_ADDR + WRITE_READ_ADDR + (4*res_2000_00_indx),200000);
#endif


#ifdef res_2000_01 
  *(__IO uint32_t *)(SRAM_BANK_ADDR + WRITE_READ_ADDR + (4*res_2000_01_indx)) = res_2000_01;
  //Serial.println(res_2000_01_indx);
  append_Linked_List(&my_SDO_List, res_2000_01_indx, SRAM_BANK_ADDR + WRITE_READ_ADDR + (4*res_2000_01_indx),200001);
#endif


#ifdef res_2000_03 
  *(__IO uint32_t *)(SRAM_BANK_ADDR + WRITE_READ_ADDR + (4*res_2000_03_indx)) = res_2000_03;
  //Serial.println(res_2000_03_indx);
  append_Linked_List(&my_SDO_List, res_2000_03_indx, SRAM_BANK_ADDR + WRITE_READ_ADDR + (4*res_2000_03_indx),200003);
#endif

#ifdef res_2002_02 
  *(__IO uint32_t *)(SRAM_BANK_ADDR + WRITE_READ_ADDR + (4*res_2002_02_indx)) = res_2002_02;
  //Serial.println(res_2002_02_indx);
  append_Linked_List(&my_SDO_List, res_2002_02_indx, SRAM_BANK_ADDR + WRITE_READ_ADDR + (4*res_2002_02_indx),200202);
#endif

#ifdef res_2020_02    
  *(__IO uint32_t *)(SRAM_BANK_ADDR + WRITE_READ_ADDR + (4*res_2020_02_indx)) = res_2020_02;
  //Serial.println(res_2020_02_indx);
  append_Linked_List(&my_SDO_List, res_2020_02_indx, SRAM_BANK_ADDR + WRITE_READ_ADDR + (4*res_2020_02_indx),202002);
#endif

#ifdef res_2100_02
  *(__IO uint32_t *)(SRAM_BANK_ADDR + WRITE_READ_ADDR + (4*res_2100_02_indx)) = res_2100_02;
  //Serial.println(res_2100_02_indx);
  append_Linked_List(&my_SDO_List, res_2100_02_indx, SRAM_BANK_ADDR + WRITE_READ_ADDR + (4*res_2100_02_indx),210002);
#endif

#ifdef res_2102_02
  *(__IO uint32_t *)(SRAM_BANK_ADDR + WRITE_READ_ADDR + (4*res_2102_02_indx)) = res_2102_02;
  //Serial.println(res_2102_02_indx);
  append_Linked_List(&my_SDO_List, res_2102_02_indx, SRAM_BANK_ADDR + WRITE_READ_ADDR + (4*res_2102_02_indx),210202);
#endif

#ifdef res_2102_06
  *(__IO uint32_t *)(SRAM_BANK_ADDR + WRITE_READ_ADDR + (4*res_2102_06_indx)) = res_2102_06;
  //Serial.println(res_2102_06_indx);
  append_Linked_List(&my_SDO_List, res_2102_06_indx, SRAM_BANK_ADDR + WRITE_READ_ADDR + (4*res_2102_06_indx),210206);
#endif

#ifdef res_2100_06
  *(__IO uint32_t *)(SRAM_BANK_ADDR + WRITE_READ_ADDR + (4*res_2000_03_indx)) = res_2000_03;
  //Serial.println(res_2000_03_indx);
  append_Linked_List(&my_SDO_List, res_2000_03_indx, SRAM_BANK_ADDR + WRITE_READ_ADDR + (4*res_2000_03_indx),200003);
#endif

#ifdef res_2200_02
  *(__IO uint32_t *)(SRAM_BANK_ADDR + WRITE_READ_ADDR + (4*res_2200_02_indx)) = res_2200_02;
  //Serial.println(res_2200_02_indx);
  append_Linked_List(&my_SDO_List, res_2200_02_indx, SRAM_BANK_ADDR + WRITE_READ_ADDR + (4*res_2200_02_indx),220002);
#endif

#ifdef res_2200_06
  *(__IO uint32_t *)(SRAM_BANK_ADDR + WRITE_READ_ADDR + (4*res_2200_06_indx)) = res_2200_06;
  //Serial.println(res_2200_06_indx);
  append_Linked_List(&my_SDO_List, res_2200_06_indx, SRAM_BANK_ADDR + WRITE_READ_ADDR + (4*res_2200_06_indx),220006);
#endif

#ifdef res_2001_01
  *(__IO uint32_t *)(SRAM_BANK_ADDR + WRITE_READ_ADDR + (4*res_2001_01_indx)) = res_2001_01;
  //Serial.println(res_2001_01_indx);
  append_Linked_List(&my_SDO_List, res_2001_01_indx, SRAM_BANK_ADDR + WRITE_READ_ADDR + (4*res_2001_01_indx),200101);
#endif

#ifdef res_2101_02
  *(__IO uint32_t *)(SRAM_BANK_ADDR + WRITE_READ_ADDR + (4*res_2101_02_indx)) = res_2101_02;
  //Serial.println(res_2101_02_indx); 
  append_Linked_List(&my_SDO_List, res_2101_02_indx, SRAM_BANK_ADDR + WRITE_READ_ADDR + (4*res_2101_02_indx),210102);
#endif

#ifdef res_2101_06
  *(__IO uint32_t *)(SRAM_BANK_ADDR + WRITE_READ_ADDR + (4*res_2101_06_indx)) = res_2101_06;
  //Serial.println(res_2101_06_indx);
  append_Linked_List(&my_SDO_List, res_2101_06_indx, SRAM_BANK_ADDR + WRITE_READ_ADDR + (4*res_2101_06_indx),210106);
#endif

#ifdef res_2201_02
  *(__IO uint32_t *)(SRAM_BANK_ADDR + WRITE_READ_ADDR + (4*res_2201_02_indx)) = res_2201_02;
  //Serial.println(res_2201_02_indx);
  append_Linked_List(&my_SDO_List, res_2201_02_indx, SRAM_BANK_ADDR + WRITE_READ_ADDR + (4*res_2201_02_indx),220102);
#endif

#ifdef res_2201_06
  *(__IO uint32_t *)(SRAM_BANK_ADDR + WRITE_READ_ADDR + (4*res_2201_06_indx)) = res_2201_06;
  //Serial.println(res_2201_06_indx);
  append_Linked_List(&my_SDO_List, res_2201_06_indx, SRAM_BANK_ADDR + WRITE_READ_ADDR + (4*res_2201_06_indx),220106);
#endif

#ifdef res_2103_06
  *(__IO uint32_t *)(SRAM_BANK_ADDR + WRITE_READ_ADDR + (4*res_2103_06_indx)) = res_2103_06;
  //Serial.println(res_2103_06_indx);
  append_Linked_List(&my_SDO_List, res_2103_06_indx, SRAM_BANK_ADDR + WRITE_READ_ADDR + (4*res_2103_06_indx),210306);
#endif

#ifdef res_2103_02
  *(__IO uint32_t *)(SRAM_BANK_ADDR + WRITE_READ_ADDR + (4*res_2103_02_indx)) = res_2103_02;
  //Serial.println(res_2103_02_indx);
  append_Linked_List(&my_SDO_List, res_2103_02_indx, SRAM_BANK_ADDR + WRITE_READ_ADDR + (4*res_2103_02_indx),210302);
#endif

#ifdef res_2104_02
  *(__IO uint32_t *)(SRAM_BANK_ADDR + WRITE_READ_ADDR + (4*res_2104_02_indx)) = res_2104_02;
  //Serial.println(res_2104_02_indx);
  append_Linked_List(&my_SDO_List, res_2104_02_indx, SRAM_BANK_ADDR + WRITE_READ_ADDR + (4*res_2104_02_indx),210402);
#endif

#ifdef res_2106_06
  *(__IO uint32_t *)(SRAM_BANK_ADDR + WRITE_READ_ADDR + (4*res_2106_06_indx)) = res_2106_06;
  //Serial.println(res_2106_06_indx);
  append_Linked_List(&my_SDO_List, res_2106_06_indx, SRAM_BANK_ADDR + WRITE_READ_ADDR + (4*res_2106_06_indx),210606);
#endif

#ifdef res_2002_01
  *(__IO uint32_t *)(SRAM_BANK_ADDR + WRITE_READ_ADDR + (4*res_2002_01_indx)) = res_2002_01;
  //Serial.println(res_2002_01_indx);
  append_Linked_List(&my_SDO_List, res_2002_01_indx, SRAM_BANK_ADDR + WRITE_READ_ADDR + (4*res_2002_01_indx),200201);
#endif

#ifdef res_2020_01
  *(__IO uint32_t *)(SRAM_BANK_ADDR + WRITE_READ_ADDR + (4*res_2020_01_indx)) = res_2020_01;
  //Serial.println(res_2020_01_indx);
  append_Linked_List(&my_SDO_List, res_2020_01_indx, SRAM_BANK_ADDR + WRITE_READ_ADDR + (4*res_2020_01_indx),202001);
#endif

#ifdef res_2413_02
  *(__IO uint32_t *)(SRAM_BANK_ADDR + WRITE_READ_ADDR + (4*res_2413_02_indx)) = res_2413_02;
  //Serial.println(res_2413_02_indx);
  append_Linked_List(&my_SDO_List, res_2413_02_indx, SRAM_BANK_ADDR + WRITE_READ_ADDR + (4*res_2413_02_indx),241302);
#endif

#ifdef res_2923_02
  *(__IO uint32_t *)(SRAM_BANK_ADDR + WRITE_READ_ADDR + (4*res_2923_02_indx)) = res_2923_02;
  //Serial.println(res_2923_02_indx);
  append_Linked_List(&my_SDO_List, res_2923_02_indx, SRAM_BANK_ADDR + WRITE_READ_ADDR + (4*res_2923_02_indx),292302);
#endif

#ifdef res_2414_02
  *(__IO uint32_t *)(SRAM_BANK_ADDR + WRITE_READ_ADDR + (4*res_2414_02_indx)) = res_2414_02;
  //Serial.println(res_2414_02_indx);
  append_Linked_List(&my_SDO_List, res_2414_02_indx, SRAM_BANK_ADDR + WRITE_READ_ADDR + (4*res_2414_02_indx),241402);
#endif

#ifdef res_2461_02
  *(__IO uint32_t *)(SRAM_BANK_ADDR + WRITE_READ_ADDR + (4*res_2461_02_indx)) = res_2461_02;
  //Serial.println(res_2461_02_indx);
  append_Linked_List(&my_SDO_List, res_2461_02_indx, SRAM_BANK_ADDR + WRITE_READ_ADDR + (4*res_2461_02_indx),246102);
#endif

#ifdef res_2001_02 
  *(__IO uint32_t *)(SRAM_BANK_ADDR + WRITE_READ_ADDR + (4*res_2001_02_indx)) = res_2001_02;
  //Serial.println(res_2001_02_indx);
  append_Linked_List(&my_SDO_List, res_2001_02_indx, SRAM_BANK_ADDR + WRITE_READ_ADDR + (4*res_2001_02_indx),200102);
#endif

#ifdef res_2001_03    
  *(__IO uint32_t *)(SRAM_BANK_ADDR + WRITE_READ_ADDR + (4*res_2001_03_indx)) = res_2001_03;
  //Serial.println(res_2001_03_indx);
  append_Linked_List(&my_SDO_List, res_2001_03_indx, SRAM_BANK_ADDR + WRITE_READ_ADDR + (4*res_2001_03_indx),200103);
#endif

#ifdef res_2411_02
  *(__IO uint32_t *)(SRAM_BANK_ADDR + WRITE_READ_ADDR + (4*res_2411_02_indx)) = res_2411_02;
  //Serial.println(res_2411_02_indx);
  append_Linked_List(&my_SDO_List, res_2411_02_indx, SRAM_BANK_ADDR + WRITE_READ_ADDR + (4*res_2411_02_indx),241102);
#endif

#ifdef res_2405_02
  *(__IO uint32_t *)(SRAM_BANK_ADDR + WRITE_READ_ADDR + (4*res_2405_02_indx)) = res_2405_02;
  //Serial.println(res_2405_02_indx);
  append_Linked_List(&my_SDO_List, res_2405_02_indx, SRAM_BANK_ADDR + WRITE_READ_ADDR + (4*res_2405_02_indx),240502);
#endif

#ifdef res_2402_02
  *(__IO uint32_t *)(SRAM_BANK_ADDR + WRITE_READ_ADDR + (4*res_2402_02_indx)) = res_2402_02;
  //Serial.println(res_2402_02_indx);
  append_Linked_List(&my_SDO_List, res_2402_02_indx, SRAM_BANK_ADDR + WRITE_READ_ADDR + (4*res_2402_02_indx),240202);
#endif

#ifdef res_2405_07
  *(__IO uint32_t *)(SRAM_BANK_ADDR + WRITE_READ_ADDR + (4*res_2405_07_indx)) = res_2405_07;
  //Serial.println(res_2405_07_indx);
  append_Linked_List(&my_SDO_List, res_2405_07_indx, SRAM_BANK_ADDR + WRITE_READ_ADDR + (4*res_2405_07_indx),240507);
#endif

#ifdef res_2460_02
  *(__IO uint32_t *)(SRAM_BANK_ADDR + WRITE_READ_ADDR + (4*res_2460_02_indx)) = res_2460_02;
  //Serial.println(res_2460_02_indx);
  append_Linked_List(&my_SDO_List, res_2460_02_indx, SRAM_BANK_ADDR + WRITE_READ_ADDR + (4*res_2460_02_indx),246002);
#endif

#ifdef res_2404_02
  *(__IO uint32_t *)(SRAM_BANK_ADDR + WRITE_READ_ADDR + (4*res_2404_02_indx)) = res_2404_02;
  //Serial.println(res_2404_02_indx);
  append_Linked_List(&my_SDO_List, res_2404_02_indx, SRAM_BANK_ADDR + WRITE_READ_ADDR + (4*res_2404_02_indx),240402);
#endif

#ifdef res_2401_02
  *(__IO uint32_t *)(SRAM_BANK_ADDR + WRITE_READ_ADDR + (4*res_2401_02_indx)) = res_2401_02;
  //Serial.println(res_2401_02_indx);
  append_Linked_List(&my_SDO_List, res_2401_02_indx, SRAM_BANK_ADDR + WRITE_READ_ADDR + (4*res_2401_02_indx),240102);
#endif

#ifdef res_2403_02 
  *(__IO uint32_t *)(SRAM_BANK_ADDR + WRITE_READ_ADDR + (4*res_2403_02_indx)) = res_2403_02;
  //Serial.println(res_2403_02_indx);
  append_Linked_List(&my_SDO_List, res_2403_02_indx, SRAM_BANK_ADDR + WRITE_READ_ADDR + (4*res_2403_02_indx),240302);
#endif

#ifdef res_2400_02    
  *(__IO uint32_t *)(SRAM_BANK_ADDR + WRITE_READ_ADDR + (4*res_2400_02_indx)) = res_2400_02;
  //Serial.println(res_2400_02_indx);
  append_Linked_List(&my_SDO_List, res_2400_02_indx, SRAM_BANK_ADDR + WRITE_READ_ADDR + (4*res_2400_02_indx),240002);
#endif

#ifdef res_2403_07
  *(__IO uint32_t *)(SRAM_BANK_ADDR + WRITE_READ_ADDR + (4*res_2403_07_indx)) = res_2403_07;
  //Serial.println(res_2403_07_indx);
  append_Linked_List(&my_SDO_List, res_2403_07_indx, SRAM_BANK_ADDR + WRITE_READ_ADDR + (4*res_2403_07_indx),240307);
#endif

#ifdef res_2404_07 
  *(__IO uint32_t *)(SRAM_BANK_ADDR + WRITE_READ_ADDR + (4*res_2404_07_indx)) = res_2404_07;
  //Serial.println(res_2404_07_indx);
  append_Linked_List(&my_SDO_List, res_2404_07_indx, SRAM_BANK_ADDR + WRITE_READ_ADDR + (4*res_2404_07_indx),240407);
#endif

#ifdef res_2405_03
  *(__IO uint32_t *)(SRAM_BANK_ADDR + WRITE_READ_ADDR + (4*res_2405_03_indx)) = res_2405_03;
  //Serial.println(res_2405_03_indx);
  append_Linked_List(&my_SDO_List, res_2405_03_indx, SRAM_BANK_ADDR + WRITE_READ_ADDR + (4*res_2405_03_indx),240503);
#endif

#ifdef res_2404_03
  *(__IO uint32_t *)(SRAM_BANK_ADDR + WRITE_READ_ADDR + (4*res_2404_03_indx)) = res_2404_03;
  //Serial.println(res_2404_03_indx);
  append_Linked_List(&my_SDO_List, res_2404_03_indx, SRAM_BANK_ADDR + WRITE_READ_ADDR + (4*res_2404_03_indx),240403);
#endif

#ifdef res_2403_03
  *(__IO uint32_t *)(SRAM_BANK_ADDR + WRITE_READ_ADDR + (4*res_2403_03_indx)) = res_2403_03;
  //Serial.println(res_2403_03_indx);
  append_Linked_List(&my_SDO_List, res_2403_03_indx, SRAM_BANK_ADDR + WRITE_READ_ADDR + (4*res_2403_03_indx),240303);
#endif

#ifdef res_2405_04
  *(__IO uint32_t *)(SRAM_BANK_ADDR + WRITE_READ_ADDR + (4*res_2405_04_indx)) = res_2405_04;
  //Serial.println(res_2405_04_indx);
  append_Linked_List(&my_SDO_List, res_2405_04_indx, SRAM_BANK_ADDR + WRITE_READ_ADDR + (4*res_2405_04_indx),240504);
#endif

#ifdef res_2404_04
  *(__IO uint32_t *)(SRAM_BANK_ADDR + WRITE_READ_ADDR + (4*res_2404_04_indx)) = res_2404_04;
  //Serial.println(res_2404_04_indx);
  append_Linked_List(&my_SDO_List, res_2404_04_indx, SRAM_BANK_ADDR + WRITE_READ_ADDR + (4*res_2404_04_indx),240404);
#endif

#ifdef res_2403_04
  *(__IO uint32_t *)(SRAM_BANK_ADDR + WRITE_READ_ADDR + (4*res_2403_04_indx)) = res_2403_04;
  //Serial.println(res_2403_04_indx);
  append_Linked_List(&my_SDO_List, res_2403_04_indx, SRAM_BANK_ADDR + WRITE_READ_ADDR + (4*res_2403_04_indx),240304);
#endif

#ifdef res_2402_07
  *(__IO uint32_t *)(SRAM_BANK_ADDR + WRITE_READ_ADDR + (4*res_2402_07_indx)) = res_2402_07;
  //Serial.println(res_2402_07_indx);
  append_Linked_List(&my_SDO_List, res_2402_07_indx, SRAM_BANK_ADDR + WRITE_READ_ADDR + (4*res_2402_07_indx),240207);
#endif

#ifdef res_2401_07
  *(__IO uint32_t *)(SRAM_BANK_ADDR + WRITE_READ_ADDR + (4*res_2401_07_indx)) = res_2401_07;
  //Serial.println(res_2401_07_indx);
  append_Linked_List(&my_SDO_List, res_2401_07_indx, SRAM_BANK_ADDR + WRITE_READ_ADDR + (4*res_2401_07_indx),240107);
#endif

#ifdef res_2400_07
  *(__IO uint32_t *)(SRAM_BANK_ADDR + WRITE_READ_ADDR + (4*res_2400_07_indx)) = res_2400_07;
  //Serial.println(res_2400_07_indx);
  append_Linked_List(&my_SDO_List, res_2400_07_indx, SRAM_BANK_ADDR + WRITE_READ_ADDR + (4*res_2400_07_indx),240007);
#endif

  

  return 1;
}

void init_SDO_object(void){
  //uint32_t *temp = (uint32_t *)(BASE_ADD + 200000);
  //HAL_SRAM_Write_16b();
  hsram.Instance = FMC_NORSRAM_DEVICE; // Base address of : (up to 512KB) system data RAM accessible over over AXI   
  hsram.Extended = FMC_NORSRAM_EXTENDED_DEVICE;
  /* at stm32h7xx_ll_fmc.h */
  hsram.Init.NSBank = FMC_NORSRAM_BANK1;      
  hsram.Init.DataAddressMux = FMC_DATA_ADDRESS_MUX_DISABLE;
  hsram.Init.MemoryType = FMC_MEMORY_TYPE_SRAM;
  hsram.Init.MemoryDataWidth = FMC_NORSRAM_MEM_BUS_WIDTH_32; 
  hsram.Init.BurstAccessMode = FMC_BURST_ACCESS_MODE_DISABLE;
  hsram.Init.WaitSignalPolarity = FMC_WAIT_SIGNAL_POLARITY_LOW;
  hsram.Init.WaitSignalActive = FMC_WAIT_TIMING_BEFORE_WS;
  hsram.Init.WriteOperation = FMC_WRITE_OPERATION_ENABLE;
  hsram.Init.ExtendedMode = FMC_EXTENDED_MODE_DISABLE;
  hsram.Init.AsynchronousWait = FMC_ASYNCHRONOUS_WAIT_DISABLE;
  hsram.Init.WriteBurst = FMC_WRITE_BURST_DISABLE;
  hsram.Init.ContinuousClock = FMC_CONTINUOUS_CLOCK_SYNC_ONLY;
  hsram.Init.WriteFifo = FMC_WRITE_FIFO_ENABLE;
  hsram.Init.PageSize = FMC_PAGE_SIZE_NONE;

  timing.AddressSetupTime = 2;
  timing.AddressHoldTime = 15;
  timing.DataSetupTime = 2;
  timing.BusTurnAroundDuration = 1;
  timing.CLKDivision = 16;
  timing.DataLatency = 17;
  timing.AccessMode = FMC_ACCESS_MODE_A;



  if (HAL_SRAM_Init(&hsram, &timing, NULL) != HAL_OK){
    Serial.println("HAL_SRAM_Init error");
  } else {
    Serial.println("HAL_SRAM_Init OK");
  }


  write_SDO_to_SRAM();


}


uint8_t prepare_Answer(void){
  // check address
  /*
  uint32_t *temp_address = (uint32_t *) (BASE_ADD + (RxData[1] << 8) + (RxData[2] << 16) + (RxData[3]));
  uint32_t temp_data = *temp_address;

  switch (sizeof(temp_data))
  {
  case 4:
    TxData[4] = (temp_data) >> 24;
    TxData[5] = (temp_data & 0x00FF0000) >> 16;
    TxData[6] = (temp_data & 0x0000FF00) >> 8;
    TxData[7] = (temp_data & 0x000000FF);
    break;
  case 1:
    TxData[4] = (temp_data) >> 24;
    TxData[5] = 0x00;
    TxData[6] = 0x00;
    TxData[7] = 0x00;
    break;
  
  default:
    break;
  }
  */
   
}

uint16_t prepare_ID(uint16_t ID_req){
  uint16_t node_ID = ID_req & 0x07F;
  return (node_ID | 0x580);
}

uint8_t prepare_Command_ID(bool end_msg){
  uint8_t command_ID = RxData[0] & 0xF0;

      switch (command_ID) {
        case 0x20: // initiate domain download            
            command_ID = 0x60;  // Server reply                        
            break;
        case 0x00:  // download domain segment toggle = 0
            command_ID |= 0x20;  // or to remain toggle bit
            break;
        case 0x40:  // initiate domain upload
            if (RxData[2] == 0x24 && RxData[3] == 0x02)
            {
                command_ID |= 0x0B;    // follow Noris excel   
            } else {
                command_ID |= 0x03;  // n = 0; e = s = 1
            }
            
            break;        
        case 0x60:  // upload domain segment with toggle bit = 0
            if (end_msg) {command_ID = 0x01;} else {command_ID = 0x00;}
            break;
        case 0x70:  // upload domain segment with toggle bit = 1
            if (end_msg) {command_ID = 0x11;} else {command_ID = 0x10;}
            break;
        case 0xc0:  // initiate block download
            command_ID = 0xA0;
            break;
        default : // Unknown
            command_ID = 0x00;
            break;
        }    
    
    return command_ID;
}

//uint8_t prepare_Data


/* from https://github.com/meomotminh/STM32CubeG4/blob/master/Projects/STM32G474E-EVAL/Examples/FDCAN/FDCAN_Com_IT/Src/main.c */
static uint32_t BufferCmp32b(uint32_t* pBuffer1, uint32_t* pBuffer2, uint16_t BufferLength){
  while (BufferLength--){
    if (*pBuffer1 != *pBuffer2)
    return 0;

    pBuffer1++;
    pBuffer2++;
  }

  return 1;
}

void HAL_MspInit(void){
  // set up priority grouping of the arm cortex processor
  //HAL_NVIC_SetPriorityGrouping(NVIC_PRIORITYGROUP_4);

  // enable required system exceptions
  //SCB->SHCSR |= 0x7 << 16; // usage fault, memory fault and bus fault system exceptions

  // configure the priority for the system exceptions
  //HAL_NVIC_SetPriority(MemoryManagement_IRQn, 0, 0);
  //HAL_NVIC_SetPriority(BusFault_IRQn, 0, 0);
  //HAL_NVIC_SetPriority(UsageFault_IRQn, 0, 0);

  
  //HAL_NVIC_SetPriority(FDCAN1_IT0_IRQn, 2, 0);
  //HAL_NVIC_EnableIRQ(FDCAN1_IT0_IRQn);
}


void Set_Freq(can_t *obj, const can_pinmap_t *pinmap, int hz)
{

    MBED_ASSERT((int)pinmap->peripheral != NC);


    #if defined(__HAL_RCC_FDCAN1_CLK_ENABLE)
        __HAL_RCC_FDCAN1_CLK_ENABLE_();
    #else 
        __HAL_RCC_FDCAN_CLK_ENABLE();
    #endif

    
    if (pinmap->peripheral == CAN_1) {       
        obj->index = 0;
    }
    #if defined(FDCAN2_BASE)
    else if (pinmap->peripheral == CAN_2) {
        
        obj->index = 1;
    }
    #endif
    
    else {
        error("can_init wrong instance\n");
        return;
    }

    //Serial.println("Before Set Frequency!\n");
    
    // Set Frequency
    RCC_PeriphCLKInitTypeDef RCC_PeriphClkInit;
    #if (defined RCC_PERIPHCLK_FDCAN1)
        RCC_PeriphClkInit.PeriphClockSelection = RCC_PERIPHCLK_FDCAN1;
        RCC_PeriphClkInit.Fdcan1ClockSelection = RCC_FDCAN1CLKSOURCE_PLL1;
    #else 
        //Serial.println("Enter here!");
        RCC_PeriphClkInit.PeriphClockSelection = RCC_PERIPHCLK_FDCAN;
        RCC_PeriphClkInit.FdcanClockSelection = RCC_FDCANCLKSOURCE_PLL;
    #endif

    
    
   #if defined(DUAL_CORE) && (TARGET_STM32H7)
    while (LL_HSEM_1StepLock(HSEM, CFG_HW_RCC_SEMID)) {
    }
   #endif /* DUAL_CORE */
    if (HAL_RCCEx_PeriphCLKConfig(&RCC_PeriphClkInit) != HAL_OK) {
        //Serial.println("HAL_RCCEx_PeriphCLKConfig error\n");
    } else {
        //Serial.println("HAL_RCCEx_PeriphCLKConfig OK!");
    }
    #if defined(DUAL_CORE) && (TARGET_STM32H7)
    LL_HSEM_ReleaseLock(HSEM, CFG_HW_RCC_SEMID, HSEM_CR_COREID_CURRENT);
    #endif /* DUAL_CORE */


    // Config CAN pins
    pin_function(pinmap->rd_pin, pinmap->rd_function);
    pin_function(pinmap->td_pin, pinmap->td_function);

    // Add pull-ups
    pin_mode(pinmap->rd_pin, PullUp);
    pin_mode(pinmap->td_pin, PullUp);

    //digitalWrite(pinmap->td_pin, HIGH);         

    // Default Values
    obj->CanHandle.Instance = (FDCAN_GlobalTypeDef *)pinmap->peripheral;
      //Serial.println(obj);
      //Serial.print("Instance:"); Serial.println(pinmap->peripheral);
      
    

    #if (defined TARGET_STM32H7)
        PLL1_ClocksTypeDef pll1_clocks;
        HAL_RCCEx_GetPLL1ClockFreq(&pll1_clocks);
        //Serial.print("Hier Freq:"); Serial.println(pll1_clocks.PLL1_Q_Frequency);
        int ntq = pll1_clocks.PLL1_Q_Frequency / hz;  // 320

    #else
    #if (defined RCC_PERIPHCLK_FDCAN1)
        //Serial.println("Hier 2");  
        int ntq = HAL_RCCEx_GetPeriphCLKFreq(RCC_PERIPHCLK_FDCAN1) / hz;
    #else
        //Serial.println("Hier 2");  
        int ntq = HALL_RCCEx_GetPeriphCLKFreq(RCC_PERIPHCLK_FDCAN) / hz;
    #endif
    #endif

    //Serial.print("ntq:");  Serial.println(ntq);

    

    int nominalPrescaler = 1;
while (!IS_FDCAN_NOMINAL_TSEG1(ntq / nominalPrescaler)){ // > 1 && < 256
  nominalPrescaler++;   // = 2
  if (!IS_FDCAN_NOMINAL_PRESCALER(nominalPrescaler)){
    //Serial.println("Could not determine nominalPrescaler. Bad clock value\n");
  }
}
  
  ntq = ntq / nominalPrescaler; // = 320/2 = 160
  
  // Create CAN Handle init object
  obj->CanHandle.Init.FrameFormat = FDCAN_FRAME_CLASSIC;
  obj->CanHandle.Init.Mode = FDCAN_MODE_NORMAL;
  obj->CanHandle.Init.AutoRetransmission = ENABLE;
  obj->CanHandle.Init.TransmitPause = ENABLE;
  obj->CanHandle.Init.ProtocolException = DISABLE;
  
  obj->CanHandle.Init.NominalPrescaler = nominalPrescaler;
  obj->CanHandle.Init.NominalTimeSeg1 = ntq * 0.75;
  obj->CanHandle.Init.NominalTimeSeg2 = ntq - 1 - obj->CanHandle.Init.NominalTimeSeg1;
  obj->CanHandle.Init.NominalSyncJumpWidth = obj->CanHandle.Init.NominalTimeSeg2;
  // not used, only in FD CAN  
  obj->CanHandle.Init.DataPrescaler = 0x1;
  obj->CanHandle.Init.DataSyncJumpWidth = 0x1;
  obj->CanHandle.Init.DataTimeSeg1 = 0x1;
  obj->CanHandle.Init.DataTimeSeg2 = 0x1;
  
  // RAM offset
  obj->CanHandle.Init.MessageRAMOffset = 0;
  
   // fiCanHandle.lters
  obj->CanHandle.Init.StdFiltersNbr = 128;
  obj->CanHandle.Init.ExtFiltersNbr = 64;
  
  obj->CanHandle.Init.RxFifo0ElmtsNbr = 3;
  obj->CanHandle.Init.RxFifo1ElmtSize = FDCAN_DATA_BYTES_8;
  obj->CanHandle.Init.RxFifo1ElmtsNbr = 0;
  obj->CanHandle.Init.RxBuffersNbr = 0;
  obj->CanHandle.Init.RxFifo0ElmtSize = FDCAN_DATA_BYTES_8;
  obj->CanHandle.Init.RxBufferSize = FDCAN_DATA_BYTES_8;
  
  obj->CanHandle.Init.TxEventsNbr = 24;
  obj->CanHandle.Init.TxBuffersNbr = 0;
  obj->CanHandle.Init.TxFifoQueueElmtsNbr = 24;
  obj->CanHandle.Init.TxFifoQueueMode = FDCAN_TX_FIFO_OPERATION;
  obj->CanHandle.Init.TxElmtSize = FDCAN_DATA_BYTES_8;

  //Serial.print("Nominal Prescaler:"); Serial.println(nominalPrescaler);
  //Serial.print("ntq:"); Serial.println(ntq);
  //Serial.print("Nominal TimeSeg1:"); Serial.println(obj->CanHandle.Init.NominalTimeSeg1);
  //Serial.print("Nominal TimeSeg2:"); Serial.println(obj->CanHandle.Init.NominalTimeSeg2);
  //Serial.print("SyncJumpWidth:"); Serial.println(obj->CanHandle.Init.NominalSyncJumpWidth);

  //Trd_internal_init(obj);
}

void Set_CAN_Pin(can_t *obj, PinName rd, PinName td, int hz){
    CANName can_rd = (CANName)pinmap_peripheral(rd, PinMap_CAN_RD);
    CANName can_td = (CANName)pinmap_peripheral(td, PinMap_CAN_TD);
    int peripheral = (int)pinmap_merge(can_rd, can_td);

    int function_rd = (int)pinmap_find_function(rd, PinMap_CAN_RD);
    int function_td = (int)pinmap_find_function(td, PinMap_CAN_TD);

    const can_pinmap_t static_pinmap = {peripheral, rd, function_rd, td, function_td};

    Set_Freq(obj, &static_pinmap, hz);
}


void Trd_internal_init(can_t *obj){
  // call HAL init function
  if (HAL_FDCAN_Init(&obj->CanHandle) != HAL_OK){
    Serial.println("HAL_FDCAN_Init error\n");
  } else {
    Serial.println("Init success!");
  }


  /**
   * Config Timestamp & Enable Timestamp
   * **/
  /*
  if (HAL_FDCAN_ConfigTimestampCounter(&obj->CanHandle, FDCAN_TIMESTAMP_PRESC_1) != HAL_OK){
    Serial.println("HAL_FDCAN_ConfigTimestampCounter error");
  } else {
    Serial.println("HAL_FDCAN_ConfigTimestampCounter OK");
  }

  if (HAL_FDCAN_EnableTimestampCounter(&obj->CanHandle, FDCAN_TIMESTAMP_INTERNAL) != HAL_OK){
    Serial.println("HAL_FDCAN_EnableTimestampCounter error");
  } else {
    Serial.println("HAL_FDCAN_EnableTimestampCounter OK");
  }
  */

  /**
   * Config & Enable TT operation
   * **/
  FDCAN_TT_ConfigTypeDef TT_Config;
  TT_Config.OperationMode = FDCAN_TT_COMMUNICATION_LEVEL2;  // not external sync
  
  
  //TT_Config.GapEnable = FDCAN_STRICTLY_TT_OPERATION;  
  TT_Config.TimeMaster = FDCAN_TT_POTENTIAL_MASTER;  
  TT_Config.InitRefTrigOffset = 0;  
  TT_Config.EvtTrigPolarity = FDCAN_TT_EVT_TRIG_POL_RISING;
  TT_Config.BasicCyclesNbr = FDCAN_TT_CYCLES_PER_MATRIX_1;
  

  TT_Config.ExpTxTrigNbr = 1;
  TT_Config.TURNumerator = 0x1FFFF;       // Must set
  TT_Config.TURDenominator = 0x1;         // Must set
  TT_Config.TriggerMemoryNbr = 1;
  
  TT_Config.StopWatchTrigSel = FDCAN_TT_STOP_WATCH_TRIGGER_0; // TIM2
  TT_Config.EventTrigSel = FDCAN_TT_EVENT_TRIGGER_1;  // TIM3

  /*
  if (HAL_FDCAN_TT_ConfigOperation(&obj->CanHandle, &TT_Config) != HAL_OK){
    Serial.println("HAL_FDCAN_TT_ConfigOperation error");
  } else {
    Serial.println("HAL_FDCAN_TT_ConfigOperation OK");
  }*/

  /**
   * Config Reference message
   * **/
  /*
  if (HAL_FDCAN_TT_ConfigReferenceMessage(&obj->CanHandle, FDCAN_STANDARD_ID, 0x641, FDCAN_TT_REF_MESSAGE_NO_PAYLOAD) != HAL_OK){
    Serial.println("HAL_FDCAN_TT_ConfigReferenceMessage error");
  } else {
    Serial.println("HAL_FDCAN_TT_ConfigReferenceMessage OK");
  }*/

  /**
   * Config Trigger to send reference message
   * **/
  /*
  FDCAN_TriggerTypeDef sTriggerConfig;
  sTriggerConfig.TriggerIndex = 0;  // 0 - 63
  sTriggerConfig.TimeMark = 0xFF; // 0 - 0xFFFF
  sTriggerConfig.RepeatFactor = FDCAN_TT_REPEAT_EVERY_CYCLE; // FDCAN_TT_Repeat_Factor
  //sTriggerConfig.StartCycle = 
  sTriggerConfig.TmEventInt = FDCAN_TT_TM_GEN_INTERNAL_EVENT; // internal event is generated when trigger become active
  sTriggerConfig.TmEventExt = FDCAN_TT_TM_GEN_EXTERNAL_EVENT; // external event is generated when trigger become active
  sTriggerConfig.TriggerType = FDCAN_TT_TX_REF_TRIGGER; // transmit reference message in external event-synchronized time-triggered operation
  //sTriggerConfig.FilterType = FDCAN_STANDARD_ID;
  //sTriggerConfig.TxBufferIndex = 
  //sTriggerConfig.FilterIndex = 
  
  if (HAL_FDCAN_TT_ConfigTrigger(&obj->CanHandle, &sTriggerConfig) != HAL_OK){
    Serial.println("HAL_FDCAN_TT_ConfigTrigger error");
  } else {
    Serial.println("HAL_FDCAN_TT_ConfigTrigger OK");
  }*/


  /***
   * Config Timestamp counter
  ***/
  if (HAL_FDCAN_ConfigTimestampCounter(&obj->CanHandle, FDCAN_TIMESTAMP_PRESC_1) != HAL_OK){
    Serial.println("HAL_FDCAN_ConfigTimestampCounter error!");
  } else {
    Serial.println("HAL_FDCAN_ConfigTimestampCounter OK!");
  }
  /***
   * Enable Timestamp counter
  ***/
  if (HAL_FDCAN_EnableTimestampCounter(&obj->CanHandle, FDCAN_TIMESTAMP_INTERNAL) != HAL_OK){
    Serial.println("HAL_FDCAN_EnableTimestampCounter error!");
  } else {
    Serial.println("HAL_FDCAN_EnableTimestampCounter OK!");
  }
  
  

  /***
  * Config Timeout Counter
  **/
  if (HAL_FDCAN_ConfigTimeoutCounter(&obj->CanHandle, FDCAN_TIMEOUT_CONTINUOUS, 0xFFFF) != HAL_OK){
    Serial.println("HAL_FDCAN_ConfigTimeoutCounter error!");
  } else {
    Serial.println("HAL_FDCAN_ConfigTimeoutCounter OK!");
  }

  /**
  * Enable Timeout Counter
  **/
  if (HAL_FDCAN_EnableTimeoutCounter(&obj->CanHandle) != HAL_OK){
    Serial.println("HAL_FDCAN_EnableTimeoutCounter error!");
  } else {
    Serial.println("HAL_FDCAN_EnableTimeoutCounter OK!");
  }  

}

/**
 * from can_write of mbed OS Target STM
 * and SimpleCAN github
 * 
 * **/
int my_can_write(can_t *obj, CAN_Message msg, int cc){
/**
  typedef struct
  {
  uint32_t Identifier;          !< Specifies the identifier.
                                     This parameter must be a number between:
                                      - 0 and 0x7FF, if IdType is FDCAN_STANDARD_ID
                                      - 0 and 0x1FFFFFFF, if IdType is FDCAN_EXTENDED_ID               

  uint32_t IdType;              !< Specifies the identifier type for the message that will be
                                     transmitted.
                                     This parameter can be a value of @ref FDCAN_id_type               

  uint32_t TxFrameType;         !< Specifies the frame type of the message that will be transmitted.
                                     This parameter can be a value of @ref FDCAN_frame_type            

  uint32_t DataLength;          !< Specifies the length of the frame that will be transmitted.
                                      This parameter can be a value of @ref FDCAN_data_length_code    

  uint32_t ErrorStateIndicator; !< Specifies the error state indicator.
                                     This parameter can be a value of @ref FDCAN_error_state_indicator 

  uint32_t BitRateSwitch;       !< Specifies whether the Tx frame will be transmitted with or without
                                     bit rate switching.
                                     This parameter can be a value of @ref FDCAN_bit_rate_switching    

  uint32_t FDFormat;            !< Specifies whether the Tx frame will be transmitted in classic or
                                     FD format.
                                     This parameter can be a value of @ref FDCAN_format                

  uint32_t TxEventFifoControl;  !< Specifies the event FIFO control.
                                     This parameter can be a value of @ref FDCAN_EFC                   

  uint32_t MessageMarker;       !< Specifies the message marker to be copied into Tx Event FIFO
                                     element for identification of Tx message status.
                                     This parameter must be a number between 0 and 0xFF                

} FDCAN_TxHeaderTypeDef;    
  */
  FDCAN_TxHeaderTypeDef TxHeader = {0};

  UNUSED(cc);

  // Configure Tx buffer message
  TxHeader.Identifier = msg.id;
  if (msg.format == CANStandard){
    //Serial.println("Standard");
    TxHeader.IdType = FDCAN_STANDARD_ID;
  } else {
    TxHeader.IdType = FDCAN_EXTENDED_ID;
  }

  TxHeader.TxFrameType = FDCAN_DATA_FRAME;
  TxHeader.DataLength = msg.len << 16;
  
  TxHeader.ErrorStateIndicator = FDCAN_ESI_ACTIVE;
  TxHeader.BitRateSwitch = FDCAN_BRS_OFF;
  TxHeader.FDFormat = FDCAN_CLASSIC_CAN;
  TxHeader.TxEventFifoControl = FDCAN_STORE_TX_EVENTS;
  TxHeader.MessageMarker = 0;

  if (HAL_FDCAN_AddMessageToTxFifoQ(&(obj->CanHandle), &TxHeader, msg.data) != HAL_OK){
    return 0;
  }

  return 1;
}


/**
 *  from can_read of mbed OS Target STM
 * 
**/
int my_can_read(can_t *obj, CAN_Message *msg, int handle)
{
  UNUSED(handle);

  if (HAL_FDCAN_GetRxFifoFillLevel(&obj->CanHandle, FDCAN_RX_FIFO0) == 0){
    return 0; // no message arrived
  }

  FDCAN_RxHeaderTypeDef RxHeader = {0};
  if (HAL_FDCAN_GetRxMessage(&obj->CanHandle, FDCAN_RX_FIFO0, &RxHeader, msg->data) != HAL_OK){
    //Serial.println("HAL_FDCAN_GetRxMessage error");
    return 0;
  }
  
  if (RxHeader.IdType == FDCAN_STANDARD_ID){
    msg->format = CANStandard;
  } else {
    msg->format = CANExtended;
  }
  msg->id = RxHeader.Identifier;
  msg->type = (RxHeader.RxFrameType == FDCAN_DATA_FRAME) ? CANData : CANRemote;
  msg->len = RxHeader.DataLength >> 16;

  return 1;
}


/**
 * from can_filter of mbed OS Target STM
 * 
 * **/
int my_can_filter(can_t *obj, uint32_t id, uint32_t mask, CANFormat format, int32_t handle){
  FDCAN_FilterTypeDef sFilterConfig = {0};

 

  if (format == CANStandard){
    sFilterConfig.IdType = FDCAN_STANDARD_ID;
    sFilterConfig.FilterIndex = handle;    
    sFilterConfig.FilterType = FDCAN_FILTER_MASK;
    sFilterConfig.FilterConfig = FDCAN_FILTER_TO_RXFIFO0;
    sFilterConfig.FilterID1 = id;
    sFilterConfig.FilterID2 = mask;
  } else if (format == CANExtended){
    sFilterConfig.IdType = FDCAN_EXTENDED_ID;
    sFilterConfig.FilterIndex = handle;    
    sFilterConfig.FilterType = FDCAN_FILTER_MASK;
    sFilterConfig.FilterConfig = FDCAN_FILTER_TO_RXFIFO0;
    sFilterConfig.FilterID1 = id;
    sFilterConfig.FilterID2 = mask;
  } else {
    return 0;
  }

  /** Configure global filter: 
   *  Filter all remote frames with STD and EXT ID
   *  Reject non matching frames with STD ID and EXT ID
   * **/
  if (HAL_FDCAN_ConfigGlobalFilter(&my_can.CanHandle, FDCAN_REJECT, FDCAN_REJECT, FDCAN_FILTER_REMOTE, FDCAN_FILTER_REMOTE) != HAL_OK){
    //Error_Handler();
    Serial.println("HAL_FDCAN_ConfigGlobalFilter error!");
  } else {
    Serial.println("HAL_FDCAN_ConfigGlobalFilter OK!");
  }

  if (HAL_FDCAN_ConfigFilter(&obj->CanHandle, &sFilterConfig) != HAL_OK){
    Serial.println("HAL_FDCAN_ConfigFilter error");
  } else {
    Serial.println("HAL_FDCAN_ConfigFilter OK");
  }

   /** Enable Interrupt
   * **/
  if (HAL_FDCAN_ActivateNotification(&my_can.CanHandle, FDCAN_IT_RX_FIFO0_NEW_MESSAGE | FDCAN_IT_TIMEOUT_OCCURRED | FDCAN_IT_TIMESTAMP_WRAPAROUND, 0xFFFF) != HAL_OK){
    //Error_Handler();
    Serial.println("HAL_FDCAN_ActivateNotification error!");
  } else {
    Serial.println("HAL_FDCAN_ActivateNotification OK!");
  }


  
  /** Unregister Callback function ???
  **/
  
  

  // FINALLY START FDCAN

  if (HAL_FDCAN_Start(&obj->CanHandle) != HAL_OK){
    Serial.println("HAL_FDCAN_Start error\n");
  } else {
    Serial.println("Start success!");
  }
  
  // FDCAN1 interrupt Init
  NVIC_SetVector(FDCAN1_IT0_IRQn, (uint32_t)&FDCAN1_IT0_IRQHandler);
  NVIC_EnableIRQ(FDCAN1_IT0_IRQn);


  //Serial.println("FDCAN1 interrupt success");


  /* Prepare Tx Header */
  TxHeader.Identifier = 0x322;
  TxHeader.IdType = FDCAN_STANDARD_ID;
  TxHeader.TxFrameType = FDCAN_DATA_FRAME;
  TxHeader.DataLength = FDCAN_DLC_BYTES_8;
  TxHeader.ErrorStateIndicator = FDCAN_ESI_ACTIVE;
  TxHeader.BitRateSwitch = FDCAN_BRS_OFF;
  TxHeader.FDFormat = FDCAN_CLASSIC_CAN;
  TxHeader.TxEventFifoControl = FDCAN_STORE_TX_EVENTS;
  TxHeader.MessageMarker = 0;

  return 1;
}





/**
 *  from can_rderror of mbed OS Target STM
 * 
 * **/
unsigned char my_can_rderror(can_t *obj)
{
  FDCAN_ErrorCountersTypeDef ErrorCounters;

  HAL_FDCAN_GetErrorCounters(&obj->CanHandle, &ErrorCounters);

  return (unsigned char)ErrorCounters.RxErrorCnt;
}


/**
 * 
 * from can_tderror of mbed OS target STM
 * 
 * **/
unsigned char my_can_tderror(can_t *obj)
{
  FDCAN_ErrorCountersTypeDef ErrorCounters;

  HAL_FDCAN_GetErrorCounters(&obj->CanHandle, &ErrorCounters);

  return (unsigned char)ErrorCounters.TxErrorCnt;
}

/**
 * from can_mode of mbed OS target STM
 * 
 * **/
int my_can_mode(can_t *obj, CanMode mode)
{
  if (HAL_FDCAN_Stop(&obj->CanHandle) != HAL_OK){
    //Serial.println("HAL_FDCAN_Stop error");
  }

  switch (mode){
    case MODE_RESET:
      break;
    case MODE_NORMAL:
      obj->CanHandle.Init.Mode = FDCAN_MODE_NORMAL;
      break;
    case MODE_SILENT: // Bus Monitoring
      obj->CanHandle.Init.Mode = FDCAN_MODE_BUS_MONITORING;
      break;
    case MODE_TEST_GLOBAL: // External Loopback
    case MODE_TEST_LOCAL:
      obj->CanHandle.Init.Mode = FDCAN_MODE_EXTERNAL_LOOPBACK;
      break;
    case MODE_TEST_SILENT:
      obj->CanHandle.Init.Mode = FDCAN_MODE_INTERNAL_LOOPBACK;
      break;
    default:
      return 0;
  }

  Trd_internal_init(obj);
  
  return 1;
}



// **********Interrupt******************
void FDCAN1_IT0_IRQHandler(void){
  //Serial.println("Interrupt!");
  //interrupt = true;
  HAL_FDCAN_IRQHandler(&my_can.CanHandle);
}


void HAL_FDCAN_TxBufferCompleteCallback(FDCAN_HandleTypeDef *hfdcan, uint32_t BufferIndexes){
  
  Serial.println("Message Sent!");
}

/*
void HAL_FDCAN_RxFifo0Callback(FDCAN_HandleTypeDef *hfdcan, uint32_t RxFifo0ITs){

 
   if (RxFifo0ITs == FDCAN_IT_RX_FIFO0_NEW_MESSAGE){  // = 1
      receiveMsg = true;
   } 

   if (RxFifo0ITs == (FDCAN_IT_RX_FIFO0_FULL + FDCAN_IT_RX_FIFO0_NEW_MESSAGE)){ // new message + full = 5
      Rx_Fifo0_full = true;
   }

   Rx_IT_Number = RxFifo0ITs;
   
   //counter = 0;
  //Serial.println("Receive new message!");
  
}
*/

/**
 * Config System Clock
 * from https://github.com/meomotminh/STM32CubeG4/blob/master/Projects/STM32G474E-EVAL/Examples/FDCAN/FDCAN_Classic_Frame_Networking/Src/main.c
 * **/
void SystemClock_Config(void){
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};
  RCC_PeriphCLKInitTypeDef PeriphClkInit = {0};
  HAL_StatusTypeDef ret = HAL_OK;

  // Oscillator init seem not to work
    


  

  /** Initialize the CPU, AHB and APB buses clocks
   * **/
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK | RCC_CLOCKTYPE_SYSCLK 
                                | RCC_CLOCKTYPE_PCLK1 | RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_2) != HAL_OK){
    //Error_Handler();
    Serial.println("HAL_RCC_ClockConfig error!");
  } else {
    Serial.println("HAL_RCC_ClockConfig OK!");
  }

  /**
   * Initializes the peripherals clocks
   * **/
  PeriphClkInit.PeriphClockSelection = RCC_PERIPHCLK_FDCAN;
  PeriphClkInit.FdcanClockSelection = RCC_FDCANCLKSOURCE_PLL;
  
  if (HAL_RCCEx_PeriphCLKConfig(&PeriphClkInit) != HAL_OK){
    //Error_Handler();
    Serial.println("HAL_RCCEx_PeriphCLKConfig error!");
  } else {
    Serial.println("HAL_RCCEx_PeriphCLKConfig OK!");
  }
}



/**
 * Rx FIFO0 Callback
 * 
 * **/
void HAL_FDCAN_RxFifo0Callback(FDCAN_HandleTypeDef *hfdcan, uint32_t RxFifo0ITs){
  if ((RxFifo0ITs & FDCAN_IT_RX_FIFO0_NEW_MESSAGE) != RESET){
    /* Retrieve Rx message from Rx FIFO0 */
    if (HAL_FDCAN_GetRxMessage(hfdcan, FDCAN_RX_FIFO0, &RxHeader, RxData) != HAL_OK){
      Error_Handler();
      //Serial.println("HAL_FDCAN_GetRxMessage error!");
    } else {
      
      // check action 
        // READ
      if ((RxData[0] & 0xF0) == 0x40){        
        read_parameter();        
      } else if ((RxData[0] & 0xF0) == 0x60) {
        // WRITE
        write_parameter();  
      }

      if (my_can_write(&my_can, CANMessage(prepare_ID(RxHeader.Identifier),TxData,8), 8)){
      } else {
        Error_Handler();
      }
      
      
      //Serial.println("Received msg!");
      receiveMsg = true;
    }

    // DO SOMETHING
  }
}

void HAL_FDCAN_TimeoutOccurredCallback(FDCAN_HandleTypeDef *hfdcan){
  //timeout = true;
}


void HAL_FDCAN_TimestampWraparoundCallback(FDCAN_HandleTypeDef *hfdcan){
  timestamp = true;
  int8_t fake_length = sizeof(fake);

  for (int i = 0; i < sizeof(fake); i++){
    if (my_can_write(&my_can, fake[i],1)){
      
    } else  {
      Error_Handler();
    }
  }
  
}


void Error_Handler(void){
  // DO SOMETHING 
}

void setup() {
  Serial.begin(9600);
  while (!Serial);

  #ifdef FDCAN1
    Serial.println("*********FDCAN1************");
  #endif

  #ifdef USE_HAL_FDCAN_REGISTER_CALLBACKS 
    Serial.println("*****REGISTER-CALLBACK******");
  #endif 
  
  #ifdef CAN_1
    Serial.println("*********CAN1************");
  #endif
  
  // Low level initialization
  HAL_Init();
  
  
  // Config System Clock
  //SystemClock_Config();

  // Init SDO object
  init_SDO_object();

  // Display SDO object linked list
  display_Linked_List();

  // Configure FDCAN peripheral
  //FDCAN_Config();
  
  
  // initiate can_t _can object  
  Set_CAN_Pin(&my_can, PB_8, PH_13, 250000);  

  // Set external Loop Back mode
  my_can_mode(&my_can, MODE_TEST_GLOBAL);
  
  // set filter and start
  //int my_can_filter(can_t *obj, uint32_t id, uint32_t mask, CANFormat format, int32_t handle)
  my_can_filter(&my_can, 0x641, 0x7FF, CANStandard, 0);

  
  // Fill sample buffer
  //Fill_Buffer(aTxBuffer, 16, 0xC20F);

  
  /* Write data to SRAM memory */
  
  /*for (uwIndex = 0; uwIndex < 16; uwIndex++){
    *(__IO uint16_t *)(SRAM_BANK_ADDR + WRITE_READ_ADDR + 2*uwIndex) = aTxBuffer[uwIndex];
  }*/

  /* Read data from SRAM memory */
  /*for (uwIndex = 0; uwIndex < 16; uwIndex++){
    aRxBuffer[uwIndex] = *(__IO uint16_t *)(SRAM_BANK_ADDR + WRITE_READ_ADDR + 2*uwIndex);
  }*/

  /* Check data integrity */
  /*
   if (BufferCmp32b(aTxBuffer, aRxBuffer, 16)){
    Serial.println("PASSED!");
  } else {
    Serial.println("FAILED!");
  }*/
  

  // Check Address of FDCAN RAM 
  Serial.println("-------------------------------------");
  Serial.println("|           Check Address            |");
  Serial.println("-------------------------------------");

  Serial.print("Message RxFIFO0 Start Address:");  Serial.println(my_can.CanHandle.msgRam.RxFIFO0SA,HEX);
  Serial.print("Message RxFIFO1 Start Address:");  Serial.println(my_can.CanHandle.msgRam.RxFIFO1SA,HEX);
  Serial.print("Message Rx Buffer Start Address:");  Serial.println(my_can.CanHandle.msgRam.RxBufferSA,HEX);
  Serial.print("Message RAM End Address:");  Serial.println(my_can.CanHandle.msgRam.EndAddress,HEX);

  
  Serial.println("-------------------------------------");
  Serial.println("|           Start loop              |");
  Serial.println("-------------------------------------");
}

/**
 * Unused Interrupt
 * **/
void HAL_FDCAN_TxEventFifoCallback(FDCAN_HandleTypeDef *hfdcan, uint32_t TxEventFifoITs){
  //Serial.println("Sent message fifo");
}


void loop() {
  // put your main code here, to run repeatedly:
  TxData[0] = 0x40;
  TxData[1] = 0x20;
  TxData[2] = 0x01;
  TxData[3] = 0x00;
  TxData[4] = 0x00;
  TxData[5] = 0x00;
  TxData[6] = 0x00;
  TxData[7] = 0x00;
  if (my_can_write(&my_can, CANMessage(0x641, TxData, 8), 8)){
    //Serial.print("Sent:"); Serial.println(counter);
    //counter++;
  } else {
    Error_Handler();
  }
  
  if (interrupt){
    Serial.println("Interrupt");
    interrupt = false;
  }

  if (receiveMsg){
    //if (BufferCmp8b(TxData, RxData, 8)){
        if (my_can_read(&my_can, &msg, 0)){
          Serial.print("Received:");Serial.println(msg.data[0]);
        }
      //Serial.println("Correct!");
    //}
    
    receiveMsg = false;
  }

  if (Rx_Fifo0_full){
    Serial.println("FIFO full");
    Rx_Fifo0_full = false;
    
  }

  if (timeout){
    //Serial.println("Timeout occur!");
    timeout = false;
  }

  if (timestamp){
    //Serial.println("Timestamp wrap around");
    timestamp = false;
  }

  
}
