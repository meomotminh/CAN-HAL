/* -------------------------------------------------------------------------- */
/*                               UTILITY SECTION                              */
/* -------------------------------------------------------------------------- */
#include "UTILITY.h"
#include "Arduino.h"


uint16_t prepare_ID(uint16_t ID_req){
  uint16_t node_ID = ID_req & 0x07F;
  return (node_ID | 0x580);
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


/* ------------ check if it is in concerning range 0x601 -> 0x67F ----------- */
bool check_COB_ID_range(uint32_t COB_ID)
{    
    //Serial.println(TxHeader.Identifier, HEX);
    if ((COB_ID) >= 0x601 && (COB_ID <= 0x67F))
    {
        return true;
    } else return false;
}

/* -------------------- function to calculate command ID -------------------- */
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

/* ----------------------------- Write Parameter ---------------------------- */
uint8_t write_parameter(void){
  uint32_t tmp = (RxData[2] << 16) + (RxData[1] << 8) + RxData[3];
  uint32_t value = (RxData[7] << 24) + (RxData[6] << 16) + (RxData[5] << 8) + RxData[4];
  struct SDO* found = find_value(&my_SDO_List, tmp);

  if ( found != NULL){
    *(__IO uint32_t *)(found->address) = value;
    TxData[0] = prepare_Command_ID(false);
    TxData[1] = RxData[1];
    TxData[2] = RxData[2];
    TxData[3] = RxData[3];
    TxData[4] = 0x00;
    TxData[5] = 0x00;
    TxData[6] = 0x00;
    TxData[7] = 0x00;
  } else {
    TxData[0] = prepare_Command_ID(false);
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



/* ----------------------------- Read Parameter ----------------------------- */
uint8_t read_parameter(struct SDO** linked_list,uint32_t* Tx_array, uint32_t* Rx_array, uint32_t RxIdentifier){
  uint32_t tmp = (Rx_array[2] << 16) + (RxData_array[1] << 8) + RxData[3];
  struct SDO* found = find_value(&linked_list, tmp);
  uint8_t reply = 0;
  
  //Serial.print("Value to find:");
  //Serial.println(tmp, HEX);
  
  //Serial.println(found->value, HEX);
  if (check_COB_ID_range(RxIdentifier)){
    reply = 1;
    Serial.println("In Range");
    if (found == NULL){
    Tx_array[0] = prepare_Command_ID(false);
    Tx_array[1] = RxData[1];
    Tx_array[2] = RxData[2];
    Tx_array[3] = RxData[3];
    Tx_array[4] = 0x00;
    Tx_array[5] = 0x00;
    Tx_array[6] = 0x00;
    Tx_array[7] = 0x00;
    found_parameter = false;

    
  } else {
    //Serial.println("Hier"); 
    // if segmented or not
    if (found->segmented){
      // first message
      if (segment_count == 0){
        segmented = true;   // Flag at the beginning
        add_count = 0;
        bit_swap = 0;
        rest_char = 0;

        Tx_array[0] = 0x41;   // to send data length
        Tx_array[1] = RxData[1];
        Tx_array[2] = RxData[2];
        Tx_array[3] = RxData[3];
        Tx_array[4] = found->length;  
        Tx_array[5] = 0x00;
        Tx_array[6] = 0x00;
        Tx_array[7] = 0x00;

        

        segment_count++;
      // normal message
      } else if ((segment_count <= (found->length / 7.0)) && ((RxData[0] == 0x60) | (RxData[0] == 0x70))) { // each message send 7 bytes data
        // get 2 word EFG_ 
        uint32_t read_from_SRAM_1st = *(__IO uint32_t *)(found->address + ((add_count++) * 4));
        uint32_t read_from_SRAM_2nd = *(__IO uint32_t *)(found->address + ((add_count++) * 4));
        
        rest_count++;
        
        // 7 
        // 1(rest) + 6
        // 2(rest) + 5
        // 3(rest) + 4
        // 4(rest) + 3

        switch (rest_count)
        {
        case 1:
          Tx_array[0] = bit_swap;  
          Tx_array[1] = read_from_SRAM_1st >> 24;
          Tx_array[2] = read_from_SRAM_1st >> 16;
          Tx_array[3] = read_from_SRAM_1st >> 8;
          Tx_array[4] = read_from_SRAM_1st;
          Tx_array[5] = read_from_SRAM_2nd >> 24;
          Tx_array[6] = read_from_SRAM_2nd >> 16;
          Tx_array[7] = read_from_SRAM_2nd >> 8;  
          rest_char = read_from_SRAM_2nd & 0x000000FF; // get the last byte
          break;
        case 2:
          Tx_array[0] = bit_swap;  
          Tx_array[1] = rest_char;
          Tx_array[2] = read_from_SRAM_1st >> 24;
          Tx_array[3] = read_from_SRAM_1st >> 16;
          Tx_array[4] = read_from_SRAM_1st >> 8;
          Tx_array[5] = read_from_SRAM_1st;
          Tx_array[6] = read_from_SRAM_2nd >> 24;
          Tx_array[7] = read_from_SRAM_2nd >> 16;  
          rest_char = read_from_SRAM_2nd & 0x0000FFFF; // get last 2 bytes
          break;
        case 3:
          Tx_array[0] = bit_swap;  
          Tx_array[1] = rest_char >> 8;
          Tx_array[2] = rest_char;
          Tx_array[3] = read_from_SRAM_1st >> 24;
          Tx_array[4] = read_from_SRAM_1st >> 16;
          Tx_array[5] = read_from_SRAM_1st >> 8;
          Tx_array[6] = read_from_SRAM_1st;
          Tx_array[7] = read_from_SRAM_2nd >> 24;  
          rest_char = read_from_SRAM_2nd & 0x00FFFFFF; // get last 3 bytes
          break;
        case 4:
          Tx_array[0] = bit_swap;  
          Tx_array[1] = rest_char >> 16;
          Tx_array[2] = rest_char >> 8;
          Tx_array[3] = rest_char;
          Tx_array[4] = read_from_SRAM_1st >> 24;
          Tx_array[5] = read_from_SRAM_1st >> 16;
          Tx_array[6] = read_from_SRAM_1st >> 8;
          Tx_array[7] = read_from_SRAM_1st;  
          rest_char = 0; // delay 1 addres
          add_count--;
          break;
        
        default:
          break;
        }
        
        
        bit_swap ^= 0x10;
        
        

        
        //Serial.println("*****SEGMENT****");

        segment_count++;       
      // terminate message
      } else if (segment_count > (found->length / 7.0)){
        Tx_array[0] = 0x07;   // terminate
        Tx_array[1] = 0x00;
        Tx_array[2] = 0x00;
        Tx_array[3] = 0x00;
        Tx_array[4] = 0x00;  
        Tx_array[5] = 0x00;
        Tx_array[6] = 0x00;
        Tx_array[7] = 0x00; 

        //Serial.println("*****FINAL SEGMENT****");
        segmented = false;        
        segment_count = 0;
        add_count = 0;
        rest_count = 0;
      }

    // Not segmented      
    } else {
        uint32_t read_from_SRAM_1st = *(__IO uint32_t *)(found->address);        

        Tx_array[0] = prepare_Command_ID(false);   
        Tx_array[1] = RxData[1];
        Tx_array[2] = RxData[2];
        Tx_array[3] = RxData[3];
        Tx_array[4] = read_from_SRAM_1st >> 24;
        Tx_array[5] = read_from_SRAM_1st >> 16;
        Tx_array[6] = read_from_SRAM_1st >> 8;
        Tx_array[7] = read_from_SRAM_1st;
    }

    
  }
  }
  
  

  //Serial.println("Hier");
  found_parameter = true;
  return reply;

}



/* ------------------------ Find value in Linked List ----------------------- */
struct SDO* find_value(struct SDO** head_ref, uint32_t value){
  struct SDO* last = *head_ref;

  if (*head_ref == NULL){
    return NULL;
  } 
    
  // traverse until the end
  while (last->next != NULL){
    if (last->value == value) 
      { 
        break;
      } else {
        last = last->next;    
      }    
  }

  if (last->value == value){
    return last;
  } else {
    return NULL;
  }

  return last;

}

/* --------------------- Append 1 node into linked list --------------------- */
void append_Linked_List(struct SDO** head_ref, struct SDO* temp_node){
  
  struct SDO *last = *head_ref;
  struct SDO* new_node = (struct SDO*) malloc(sizeof(struct SDO));

  

  // assign value
  new_node->index = temp_node->index;
  new_node->address = temp_node->address;
  new_node->value = temp_node->value;
  new_node->next = NULL;
  new_node->length = temp_node->length;
  new_node->segmented = temp_node->segmented;
    
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
  Serial.println("Called");
  Serial.println(my_SDO_List == NULL);
  struct SDO *tmp;
  if (my_SDO_List == NULL){
    return;
  } else {    
    tmp = my_SDO_List;
    while (tmp != NULL){
      Serial.println("****************");
      Serial.print("SDO index:"); Serial.println(tmp->index);
      Serial.print("SDO address:"); Serial.println(tmp->address, HEX);
      Serial.print("SDO value:"); Serial.println(tmp->value, HEX);

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

/* -------------------------------------------------------------------------- */
