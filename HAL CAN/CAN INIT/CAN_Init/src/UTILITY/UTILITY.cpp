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
    ////Serial.println(TxHeader.Identifier, HEX);
    if ((COB_ID) >= 0x601 && (COB_ID <= 0x67F))
    {
        return true;
    } else return false;
}

/* -------------------- function to calculate command ID -------------------- */
uint8_t prepare_Command_ID(bool end_msg, LOITRUCK* loiTruck){
  uint8_t command_ID = loiTruck->RxData[0] & 0xF0;

      switch (command_ID) {
        case 0x20: // initiate domain download            
            {
              command_ID = 0x60;  // Server reply                        
              break;
            }
        case 0x00:  // download domain segment toggle = 0
            {
              command_ID |= 0x20;  // or to remain toggle bit
              break;
            }            
        case 0x40:  // initiate domain upload
            {
              if (loiTruck->RxData[2] == 0x24 && loiTruck->RxData[3] == 0x02)
              {
                command_ID |= 0x0B;    // follow Noris excel   
              } else {
                command_ID |= 0x03;  // n = 0; e = s = 1
              }
            
              break;        
            }
            
        case 0x60:  // upload domain segment with toggle bit = 0
            {
              if (end_msg) {command_ID = 0x01;} else {command_ID = 0x00;}
              break;
            }
            
        case 0x70:  // upload domain segment with toggle bit = 1
            {
              if (end_msg) {command_ID = 0x11;} else {command_ID = 0x10;}
              break;
            }
            
        case 0xc0:  // initiate block download
            {
              command_ID = 0xA0;
              break;
            }
            
        default : // Unknown            
            break;
        }    
    
    return command_ID;
}

/* ----------------------------- Write Parameter ---------------------------- */
uint8_t write_parameter(LOITRUCK* loiTruck){
  uint32_t tmp = (loiTruck->RxData[2] << 16) + (loiTruck->RxData[1] << 8) + loiTruck->RxData[3];
  uint32_t value = (loiTruck->RxData[7] << 24) + (loiTruck->RxData[6] << 16) + (loiTruck->RxData[5] << 8) + loiTruck->RxData[4];
  struct SDO* found = find_value(&loiTruck->my_SDO_List, tmp);

  if ( found != NULL){
    // save into SRAM
    //Serial.println("Write to SRAM");
    *(__IO uint32_t *)(found->address) = value;
    loiTruck->TxData[0] = prepare_Command_ID(false, loiTruck);
    loiTruck->TxData[1] = loiTruck->RxData[1];
    loiTruck->TxData[2] = loiTruck->RxData[2];
    loiTruck->TxData[3] = loiTruck->RxData[3];
    loiTruck->TxData[4] = 0x00;
    loiTruck->TxData[5] = 0x00;
    loiTruck->TxData[6] = 0x00;
    loiTruck->TxData[7] = 0x00;
  } else {
    // get last SDO item in the linked list
    struct SDO last_SDO = *(get_last_SDO(&loiTruck->my_SDO_List));
    struct SDO temp(0,0,0,NULL,0,false,0x0);

    // if not found then append new SDO into list
    
    if (loiTruck->RxData[2] < 0x50) // seed and key
    {
      temp = SDO(last_SDO.index + (last_SDO.length / 4),SRAM_BANK_ADDR + WRITE_READ_ADDR + ((last_SDO.index + (last_SDO.length / 4)) << 2),tmp,NULL,0x01,false,0x0);  
    

      append_Linked_List(&loiTruck->my_SDO_List, &temp);
    
      // Save into SRAM
      *(__IO uint32_t *)(temp.address) = value;
      //Serial.println("Write to SRAM");
    }
    

    loiTruck->TxData[0] = prepare_Command_ID(false, loiTruck);
    loiTruck->TxData[1] = loiTruck->RxData[1];
    loiTruck->TxData[2] = loiTruck->RxData[2];
    loiTruck->TxData[3] = loiTruck->RxData[3];
    loiTruck->TxData[4] = 0x00;
    loiTruck->TxData[5] = 0x00;
    loiTruck->TxData[6] = 0x00;
    loiTruck->TxData[7] = 0x00;
    return 0;
  }

  

  
  return 1;
}



/* ----------------------------- Read Parameter ----------------------------- */
uint8_t read_parameter(LOITRUCK* loiTruck){
  uint32_t tmp = (loiTruck->RxData[2] << 16) + (loiTruck->RxData[1] << 8) + loiTruck->RxData[3];
  struct SDO* found = find_value(&loiTruck->my_SDO_List, tmp);
  uint8_t reply = 0;
  
  ////Serial.print("Value to find:");
  ////Serial.println(tmp, HEX);
  
  ////Serial.println(found->value, HEX);
  if (check_COB_ID_range(loiTruck->RxHeader.Identifier)){
    reply = 1;
    ////Serial.println("In Range");
    if (found == NULL){
    loiTruck->TxData[0] = prepare_Command_ID(false, loiTruck);
    loiTruck->TxData[1] = loiTruck->RxData[1];
    loiTruck->TxData[2] = loiTruck->RxData[2];
    loiTruck->TxData[3] = loiTruck->RxData[3];
    loiTruck->TxData[4] = 0x00;
    loiTruck->TxData[5] = 0x00;
    loiTruck->TxData[6] = 0x00;
    loiTruck->TxData[7] = 0x00;
    loiTruck->found_parameter = false;

    
  } else {
    ////Serial.println("Hier"); 
    // if loiTruck->segmented or not
    if (found->segmented){
      // first message
      if ((loiTruck->segment_count == 0) || (loiTruck->RxData[0] == 0x40)){
        /*
        loiTruck->segmented = true;   // Flag at the beginning
        loiTruck->add_count = 0;
        loiTruck->bit_swap = 0;
        loiTruck->rest_char = 0;

        loiTruck->TxData[0] = 0x41;   // to send data length
        loiTruck->TxData[1] = loiTruck->RxData[1];
        loiTruck->TxData[2] = loiTruck->RxData[2];
        loiTruck->TxData[3] = loiTruck->RxData[3];
        loiTruck->TxData[4] = found->length;  
        loiTruck->TxData[5] = 0x00;
        loiTruck->TxData[6] = 0x00;
        loiTruck->TxData[7] = 0x00;

        
        */
        loiTruck->segment_count++;
      
      } else if ((loiTruck->segment_count <= (found->length / 7.0)) && ((loiTruck->RxData[0] == 0x60) || (loiTruck->RxData[0] == 0x70))) { // each message send 7 bytes data
        // get 2 word EFG_ 
        uint32_t read_from_SRAM_1st = *(__IO uint32_t *)(found->address + ((loiTruck->add_count++) * 4));
        uint32_t read_from_SRAM_2nd = *(__IO uint32_t *)(found->address + ((loiTruck->add_count++) * 4));
        
        loiTruck->rest_count++;
        
        // 7 
        // 1(rest) + 6
        // 2(rest) + 5
        // 3(rest) + 4
        // 4(rest) + 3

        //Serial.println(read_from_SRAM_1st, HEX);
        //Serial.println(read_from_SRAM_2nd, HEX);

        switch (loiTruck->rest_count)
        {
        case 1:          
          loiTruck->TxData[0] = loiTruck->bit_swap;  
          loiTruck->TxData[1] = read_from_SRAM_1st >> 24;
          loiTruck->TxData[2] = read_from_SRAM_1st >> 16;
          loiTruck->TxData[3] = read_from_SRAM_1st >> 8;
          loiTruck->TxData[4] = read_from_SRAM_1st;
          loiTruck->TxData[5] = read_from_SRAM_2nd >> 24;
          loiTruck->TxData[6] = read_from_SRAM_2nd >> 16;
          loiTruck->TxData[7] = read_from_SRAM_2nd >> 8;  
          loiTruck->rest_char = read_from_SRAM_2nd & 0x000000FF; // get the last byte
          break;
        case 2:
          loiTruck->TxData[0] = loiTruck->bit_swap;  
          loiTruck->TxData[1] = loiTruck->rest_char;
          loiTruck->TxData[2] = read_from_SRAM_1st >> 24;
          loiTruck->TxData[3] = read_from_SRAM_1st >> 16;
          loiTruck->TxData[4] = read_from_SRAM_1st >> 8;
          loiTruck->TxData[5] = read_from_SRAM_1st;
          loiTruck->TxData[6] = read_from_SRAM_2nd >> 24;
          loiTruck->TxData[7] = read_from_SRAM_2nd >> 16;  
          loiTruck->rest_char = read_from_SRAM_2nd & 0x0000FFFF; // get last 2 bytes
          break;
        case 3:
          loiTruck->TxData[0] = loiTruck->bit_swap;  
          loiTruck->TxData[1] = loiTruck->rest_char >> 8;
          loiTruck->TxData[2] = loiTruck->rest_char;
          loiTruck->TxData[3] = read_from_SRAM_1st >> 24;
          loiTruck->TxData[4] = read_from_SRAM_1st >> 16;
          loiTruck->TxData[5] = read_from_SRAM_1st >> 8;
          loiTruck->TxData[6] = read_from_SRAM_1st;
          loiTruck->TxData[7] = read_from_SRAM_2nd >> 24;  
          loiTruck->rest_char = read_from_SRAM_2nd & 0x00FFFFFF; // get last 3 bytes
          break;
        case 4:
          loiTruck->TxData[0] = loiTruck->bit_swap;  
          loiTruck->TxData[1] = loiTruck->rest_char >> 16;
          loiTruck->TxData[2] = loiTruck->rest_char >> 8;
          loiTruck->TxData[3] = loiTruck->rest_char;
          loiTruck->TxData[4] = read_from_SRAM_1st >> 24;
          loiTruck->TxData[5] = read_from_SRAM_1st >> 16;
          loiTruck->TxData[6] = read_from_SRAM_1st >> 8;
          loiTruck->TxData[7] = read_from_SRAM_1st;  
          loiTruck->rest_char = 0; // delay 1 addres
          loiTruck->add_count--;
          break;
        
        default:
          break;
        }
        
        
        loiTruck->bit_swap ^= 0x10;
        
        

        
        ////Serial.println("*****SEGMENT****");

        loiTruck->segment_count++;       
      // terminate message
      } else if (loiTruck->segment_count > (found->length / 7.0)){
        loiTruck->TxData[0] = 0x07;   // terminate
        loiTruck->TxData[1] = 0x00;
        loiTruck->TxData[2] = 0x00;
        loiTruck->TxData[3] = 0x00;
        loiTruck->TxData[4] = 0x00;  
        loiTruck->TxData[5] = 0x00;
        loiTruck->TxData[6] = 0x00;
        loiTruck->TxData[7] = 0x00; 

        ////Serial.println("*****FINAL SEGMENT****");
        /*
        loiTruck->segmented = false;        
        loiTruck->segment_count = 0;
        loiTruck->add_count = 0;
        loiTruck->rest_count = 0;
        loiTruck->rest_char = 0;
        */
      }

    // Not loiTruck->segmented      
    } else {
        /*
        loiTruck->segmented = false;        
        loiTruck->segment_count = 0;
        loiTruck->add_count = 0;
        loiTruck->rest_count = 0;
        loiTruck->rest_char = 0;

        uint32_t read_from_SRAM_1st = *(__IO uint32_t *)(found->address);        

        loiTruck->TxData[0] = prepare_Command_ID(false, loiTruck);   
        loiTruck->TxData[1] = loiTruck->RxData[1];
        loiTruck->TxData[2] = loiTruck->RxData[2];
        loiTruck->TxData[3] = loiTruck->RxData[3];
        loiTruck->TxData[4] = read_from_SRAM_1st >> 24;
        loiTruck->TxData[5] = read_from_SRAM_1st >> 16;
        loiTruck->TxData[6] = read_from_SRAM_1st >> 8;
        loiTruck->TxData[7] = read_from_SRAM_1st;
        */
    }

    // print out 0x400001 message
    if ((loiTruck->RxData[2] == 0x40) && (loiTruck->RxData[1] == 0x00) && (loiTruck->RxData[3] == 0x01)){
      //Serial.println("-----------TRUCKSCOPE SAMPLE 0x400001-------------");
    }
    
  }
  }
  
  

  ////Serial.println("Hier");
  loiTruck->found_parameter = true;
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
    Serial.println(last->COB_ID,HEX);
    if (last->COB_ID == value) 
      { 
        break;
      } else {
        last = last->next;    
      }    
  }

  if (last->COB_ID == value){
    return last;
  } else return NULL;

}

/* --------------------- Append 1 node into linked list --------------------- */
void append_Linked_List(struct SDO** head_ref, struct SDO* temp_node){
  
  struct SDO *last = *head_ref;
    
  if (*head_ref == NULL){
    *head_ref = temp_node;
    //Serial.println("NULL");
    return;
  }

  // else traverse till the last node
  while (last->next != NULL)
    last = last->next;

  // change the next of last node
  last->next = temp_node;

  //Serial.println("Appended!");
  
  return;
}

void display_Linked_List(LOITRUCK* loiTruck){
  //Serial.println("Called Displayed");
  //Serial.println(loiTruck->my_SDO_List == NULL);
  struct SDO *tmp;
  if (loiTruck->my_SDO_List == NULL){
    return;
  } else {    
    tmp = loiTruck->my_SDO_List;
    while (tmp != NULL){
      Serial.println("****************");
      Serial.print("SDO index:"); Serial.println(tmp->index);
      Serial.print("SDO address:"); Serial.println(tmp->address, HEX);
      Serial.print("SDO COB_ID:"); Serial.println(tmp->COB_ID, HEX);
      Serial.print("segmented_string:"); Serial.println(tmp->segmented_string);
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


bool find_Scenario(LOITRUCK* loiTruck){  
  bool result = false;
  
  
  if (use_Scenario)
  {
    /* ------------------------- check current Scenario ------------------------- */
    if (loiTruck->current_Scenario == NULL){
      /* ------------------------ first scenario Scenario_1 ----------------------- */
      if (&Scenario_1 != NULL) {
        loiTruck->current_Scenario = &Scenario_1;
        result = true;
      }
      else {
        ////Serial.println("Cannot find Scenario_1 object!");
        result = false;
      }


    } else {
      /* --------------------------- not first scenario --------------------------- */
      if (loiTruck->current_Scenario->_next == NULL){
        result = false;
      } else {
        loiTruck->current_Scenario = loiTruck->current_Scenario->_next;
        result = true;
      }    
    }
  }        

  return result;
}

bool setup_Scenario(LOITRUCK* loiTruck){
  if (loiTruck->current_Scenario == NULL){
    return false;
  } 

  /* ----------------------- classify base on input_type ---------------------- */
  if (loiTruck->current_Scenario->_input_type == IN_TIME_STAMP){
    /* -------------------------- trigger by timestamp -------------------------- */
    RTC_AlarmConfig(loiTruck);
  }


}


void print_CANMessage(CANMessage msg){
  //Serial.print(msg.id, HEX);
  //Serial.print("\t");
  
  for (uint8_t i = 0; i<msg.len; i++){    
    //Serial.print(msg.data[i], HEX);
    //Serial.print("\t");
  }

  //Serial.println();
  
}

// from RPC_m4 example
String currentCPU(void){
  if (HAL_GetCurrentCPUID() == CM7_CPUID){
    return "M7";
  } else {
    return "M4";
  };
}

uint8_t convert_Scenario_To_Code(Scenario* sce){
  ////Serial.print("Convert:"); //Serial.println(sce->_output_type + 1);
  return sce->_output_type + 1;    // index start at 0
}

struct SDO* get_last_SDO(struct SDO** list_SDO){

  struct SDO* last = *list_SDO;

  if (last == NULL){
    return NULL;
  } 
    
  // traverse until the end
  while (last->next != NULL){
       last = last->next;    
  }  

  return last;
}



/* -------------------------------------------------------------------------- */
