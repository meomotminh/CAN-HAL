#include "loiTruck.h"

LOITRUCK::LOITRUCK(){
    // do nothing    
}

void LOITRUCK::SDO_process_function(){
    
    
    if (this->state != CO_SDO_ST_IDLE){
      return;
    }

    // hang until copy received data into local object
    while (HAL_FDCAN_GetRxMessage(&this->my_can.CanHandle, FDCAN_RX_FIFO0, &this->RxHeader, this->RxData) != HAL_OK){      
    }

    //sprintf(this->buffer_string[(this->buffer_count++) % 100],"R:\t%x\t%x\t%x\t%x\t%x\t%x\t%x\t%x\n",this->RxHeader.Identifier,this->RxData[0],this->RxData[1],this->RxData[2],this->RxData[3],this->RxData[4],this->RxData[5],this->RxData[6],this->RxData[7]);
    
        
    // process command_ID and COB_ID    
    bool upload = false;    
    uint32_t COB_ID = (this->RxData[2] << 16) | (this->RxData[1] << 8) | this->RxData[3];
    String COB_ID_str = String(COB_ID);
    int COB_ID_int = COB_ID_str.toInt();
    uint32_t received_value = (this->RxData[4] << 16) | (this->RxData[5] << 8) | this->RxData[6];

    
    //sprintf(this->buffer_string[this->buffer_count++],"RxData[0]: %x",RxData[0]);
    

    
    if (this->RxData[0] & 0xF0 == 0x40){
        this->state = CO_SDO_ST_UPLOAD_INITIATE_REQ;
    } else if ((this->RxData[0] & 0xF0) == 0x20){
        //Serial.println(this->RxData[0] & 0xF0,HEX);
        this->state = CO_SDO_ST_DOWNLOAD_INITIATE_REQ;
    } else if (this->RxData[0] == 0x60 || this->RxData[0] == 0x70){
        this->state = CO_SDO_ST_UPLOAD_SEGMENT_REQ;
    }

    /**
     * @brief Find in CANopen OD
     * 
     */    
    switch (COB_ID_int)
    {
    case 0x200000:
      this->found_SDO = &res_2000_00;
      break;
    case 0x200001:
      this->found_SDO = &res_2000_01;
      break;
    case 0x200003:
      this->found_SDO = &res_2000_03;
      break;  
    case 0x200202:
      this->found_SDO = &res_2002_02;
      break;
    case 0x400708:
      this->found_SDO = &res_4007_08;
      break;
    case 0x400702:
      this->found_SDO = &res_4007_02;
      break;    
    case 0x400701:
      this->found_SDO = &res_4007_01;
      break;
    case 0x400700:
      this->found_SDO = &res_4007_00;
      break;
    case 0x400004:
      this->found_SDO = &res_4000_04;
      break;
    case 0x400003:
      this->found_SDO = &res_4000_03;
      break;
    case 0x400002:
      this->found_SDO = &res_4000_02;
      break;
    case 0x400001:
      this->found_SDO = &res_4000_01;
      break;
    case 0x240007:
      this->found_SDO = &res_2400_07;
      break;
    case 0x240107:
      this->found_SDO = &res_2401_07;
      break;
    case 0x240207:
      this->found_SDO = &res_2402_07;
      break;
    case 0x240304:
      this->found_SDO = &res_2403_04;
      break;
    case 0x240404:
      this->found_SDO = &res_2404_04;
      break;
    case 0x240504:
      this->found_SDO = &res_2405_04;
      break;
    case 0x240303:
      this->found_SDO = &res_2403_03;
      break;
    case 0x240403:
      this->found_SDO = &res_2404_03;
      break;
    case 0x240503:
      this->found_SDO = &res_2405_03;
      break;
    case 0x240407:
      this->found_SDO = &res_2404_07;
      break;
    case 0x240307:
      this->found_SDO = &res_2403_07;
      break;
    case 0x240302:
      this->found_SDO = &res_2403_02;
      break;
    case 0x240102:
      this->found_SDO = &res_2401_02;
      break;
    case 0x240402:
      this->found_SDO = &res_2404_02;
      break;
    case 0x246002:
      this->found_SDO = &res_2460_02;
      break;
    case 0x240507:
      this->found_SDO = &res_2405_07;
      break;
    case 0x240202:
      this->found_SDO = &res_2402_02;
      break;
    case 0x240502:
      this->found_SDO = &res_2405_02;
      break;
    case 0x241102:
      this->found_SDO = &res_2411_02;
      break;
    case 0x200103:
      this->found_SDO = &res_2001_03;
      break;
    case 0x200102:
      this->found_SDO = &res_2001_02;
      break;
    case 0x246102:
      this->found_SDO = &res_2461_02;
      break;
    case 0x241402:
      this->found_SDO = &res_2414_02;
      break;
    case 0x292302:
      this->found_SDO = &res_2923_02;
      break;
    case 0x241302:
      this->found_SDO = &res_2413_02;
      break;
    case 0x202001:
      this->found_SDO = &res_2020_01;
      break;
    case 0x200201:
      this->found_SDO = &res_2002_01;
      break;
    case 0x210606:
      this->found_SDO = &res_2106_06;
      break;
    case 0x210402:
      this->found_SDO = &res_2104_02;
      break;
    case 0x210302:
      this->found_SDO = &res_2103_02;
      break;
    case 0x210306:
      this->found_SDO = &res_2103_06;
      break;
    case 0x220106:
      this->found_SDO = &res_2201_06;
      break;
    case 0x220102:
      this->found_SDO = &res_2201_02;
      break;
    case 0x210106:
      this->found_SDO = &res_2101_06;
      break;
    case 0x210102:
      this->found_SDO = &res_2101_02;
      break;
    case 0x200101:
      this->found_SDO = &res_2001_01;
      break;
    case 0x220006:
      this->found_SDO = &res_2200_06;
      break;
    case 0x220002:
      this->found_SDO = &res_2200_02;
      break;
    case 0x210006:
      this->found_SDO = &res_2100_06;
      break;
    case 0x210206:
      this->found_SDO = &res_2102_06;
      break;
    case 0x210202:
      this->found_SDO = &res_2102_02;
      break;
    case 0x210002:
      this->found_SDO = &res_2100_02;
      break;
    case 0x202002:
      this->found_SDO = &res_2020_02;
      break;
    case 0x200204: // segmented
      {
        
        this->found_SDO = this->find_value(&this->my_SDO_List, COB_ID_int);
        //Serial.print("Hier_");Serial.println(this->found_SDO->segmented_string);        
        break;
      }
      
    default:
    {      
      //Serial.println("Come default");
      //this->display_Linked_List();
      this->found_SDO = this->find_value(&this->my_SDO_List, COB_ID_int);
      if (this->found_SDO == NULL){
        // create SDO object and add to linked list                           
        this->append_Linked_List(&this->my_SDO_List, COB_ID_int,received_value);
        this->found_SDO = find_value(&this->my_SDO_List, COB_ID_int);
        //Serial.print("new SDO:");Serial.println(this->found_SDO->COB_ID,HEX);
      } else {
        //Serial.println("already added");
      }
      break;
    }
      
    }
   

    // base on state to call next function
    switch (this->state)
    {
    case CO_SDO_ST_DOWNLOAD_INITIATE_REQ:
        {          
                  
          this->state = CO_SDO_ST_DOWNLOAD_INITIATE_RSP;
          // clear Tx buffer
          memset(this->TxData, 0 , sizeof(this->TxData));        
          if (this->found_SDO->SDO_default){
              *(__IO uint32_t *)(this->found_SDO->address) = received_value;              
          } else {              
              this->found_SDO->to_save = received_value;
          }
            
                    
          this->Download_function();        
          break;          
        }
        
    case CO_SDO_ST_UPLOAD_INITIATE_REQ:
        {
          this->state = CO_SDO_ST_UPLOAD_INITIATE_RSP;
          if (this->found_SDO->segmented){
                        
            if (this->state != CO_SDO_ST_UPLOAD_INITIATE_RSP){                     
              this->segment_remain = 5;       
            }             
            
            this->Upload_segmented_function();
          } else {                        
            this->Upload_expedited_function();
          }
          break;
        }

    case CO_SDO_ST_UPLOAD_SEGMENT_REQ:
        {                           
          this->state = CO_SDO_ST_UPLOAD_SEGMENT_RSP;  
          this->Upload_segmented_function();               
          break;
        }    
    default:
        break; 
        
        
    }

    

}


void LOITRUCK::Download_function(){
    
  // update TxData
  this->TxData[0] = 0x60;
  this->TxData[1] = this->RxData[1];
  this->TxData[2] = this->RxData[2];
  this->TxData[3] = this->RxData[3];

  this->CAN_send();
  
  // clear last sent message
  if (this->my_can_mode != MODE_NORMAL){
    while (HAL_FDCAN_GetRxMessage(&this->my_can.CanHandle, FDCAN_RX_FIFO0, &this->RxHeader, this->RxData) != HAL_OK){
       
    }
  }
  

}

/* --------------------- Append 1 node into linked list --------------------- */
void LOITRUCK::append_Linked_List(struct SDO** head_ref, uint32_t _COB_ID, uint32_t value){
  
  struct SDO *new_node = (struct SDO*) malloc(sizeof(struct SDO));
  
  struct SDO *last = *head_ref;

  new_node->index = (++this->last_linked_list_index);
  new_node->address = 0;
  new_node->COB_ID = _COB_ID;
  new_node->to_save = value;
  new_node->SDO_default = false;
  new_node->segmented = false;
    
  if (*head_ref == NULL){
    *head_ref = new_node;
    //Serial.println("NULL");
    return;
  }

  // else traverse till the last node
  while (last->next != NULL)
    last = last->next;

  // change the next of last node
  last->next = new_node;

  //Serial.println("Appended!");  
  return;
}

void LOITRUCK::Upload_expedited_function(){
  this->state = CO_SDO_ST_UPLOAD_INITIATE_RSP;
  uint32_t to_send = 0;
  // clear Tx buffer
  memset(this->TxData, 0 , sizeof(this->TxData));

  // update TxData
  this->TxData[0] = (uint8_t)(0x43 | ((4-4)<<2));
  this->TxData[1] = (uint8_t)this->RxData[1];
  this->TxData[2] = (uint8_t)(this->RxData[2]);
  this->TxData[3] = this->RxData[3];

  if (this->found_SDO->SDO_default){
    //Serial.println("Upload default SDO");
    //Serial.println(this->found_SDO->address,HEX);
    
    to_send = *(__IO uint32_t *)(this->found_SDO->address); 
    this->TxData[4] = to_send >> 16;
    this->TxData[5] = to_send >> 8;
    this->TxData[6] = to_send;
    
  } else {
    //Serial.println("Comeerere");
    this->TxData[4] = this->found_SDO->to_save >> 16;
    this->TxData[5] = this->found_SDO->to_save >> 8;
    this->TxData[6] = this->found_SDO->to_save;
    
  }
  

  this->CAN_send();

  // clear last sent message
  if (this->my_can_mode != MODE_NORMAL){
    while (HAL_FDCAN_GetRxMessage(&this->my_can.CanHandle, FDCAN_RX_FIFO0, &this->RxHeader, this->RxData) != HAL_OK){
       
    }
  }
}

void LOITRUCK::Upload_segmented_function(){
  
  
  // clear Tx buffer
  memset(this->TxData, 0 , sizeof(this->TxData));

  switch (this->state)
  {
  case CO_SDO_ST_UPLOAD_INITIATE_RSP:
    {
      this->TxData[0] = 0x41;
      this->TxData[1] = (uint8_t)this->RxData[1];
      this->TxData[2] = (uint8_t)(this->RxData[2]);
      this->TxData[3] = this->RxData[3];
      this->TxData[4] = 0x20;
      this->SDO_toggle = 0x00;
      break;
    }
  case CO_SDO_ST_UPLOAD_SEGMENT_RSP:
    {
      this->TxData[0] = this->SDO_toggle;
      this->SDO_toggle = (this->SDO_toggle == 0x00) ? 0x10 : 0x00;
      if (this->segment_remain == 1){
        this->TxData[0] = 0x7;
      } else {
        String to_send = this->found_SDO->segmented_string;
        to_send = to_send.substring((5 - this->segment_remain)*7,(5 - this->segment_remain)*7 + 7);              
        this->segment_remain--;      
        to_send.getBytes(&this->TxData[1], to_send.length()+1);
      }
      
      

      break;
    }
  
  default:
    break;
  }
  
  this->CAN_send();

  // clear last sent message
  if (this->my_can_mode != MODE_NORMAL){
    while (HAL_FDCAN_GetRxMessage(&this->my_can.CanHandle, FDCAN_RX_FIFO0, &this->RxHeader, this->RxData) != HAL_OK){
       
    }
  }
  
}

uint16_t LOITRUCK::prepare_ID(){
  uint16_t node_ID = this->RxHeader.Identifier & 0x07F;
  return (node_ID | 0x580);
}

void LOITRUCK::CAN_send(){
  this->TxHeader.Identifier = this->prepare_ID();
  this->TxHeader.IdType = FDCAN_STANDARD_ID;
  this->TxHeader.TxFrameType = FDCAN_DATA_FRAME;
  this->TxHeader.DataLength = 4 << 16;

  this->TxHeader.ErrorStateIndicator = FDCAN_ESI_ACTIVE;
  this->TxHeader.BitRateSwitch = FDCAN_BRS_OFF;
  this->TxHeader.FDFormat = FDCAN_CLASSIC_CAN;
  this->TxHeader.TxEventFifoControl = FDCAN_STORE_TX_EVENTS;
  this->TxHeader.MessageMarker = 0;

  // create a CANMessage for comparison
  this->msg_to_send = CANMessage(this->TxHeader.Identifier, this->TxData,8);

  // check if ignore or delay or send_predefined
  if (this->tool_state != TOOL_IGNORE){
    if (this->tool_state == TOOL_DELAY){
      HAL_Delay(this->current_Scenario->_delay_time);
    }
    
    if (this->tool_state == TOOL_PREDEFINED){
      if (CANMessage(this->RxHeader.Identifier, this->RxData, this->RxHeader.DataLength) == *(this->current_Scenario->_input_CAN_message)){
        this->TxHeader.Identifier = this->current_Scenario->_output_CAN_message.id;
        this->TxHeader.DataLength = this->current_Scenario->_output_CAN_message.len;
        memcpy(this->current_Scenario->_output_CAN_message.data, this->TxData, this->current_Scenario->_output_CAN_message.len);
      }
    }
  
    while (HAL_FDCAN_AddMessageToTxFifoQ(&(this->my_can.CanHandle), &this->TxHeader, this->TxData) != HAL_OK){      
    
    } else {
      // reset state
      this->state = CO_SDO_ST_OK;
      sprintf(this->buffer_string[(this->buffer_count++) % 100],"P:\t%x\t%x\t%x\t%x\t%x\t%x\t%x\t%x\n",this->TxHeader.Identifier,this->TxData[0],this->TxData[1],this->TxData[2],this->TxData[3],this->TxData[4],this->TxData[5],this->TxData[6],this->TxData[7]);
      sprintf(this->buffer_string[(this->buffer_count++) % 100],"E:\t%x\t%x\t%x\t%x\t%x\t%x\t%x\t%x\n",expect_SDO[this->test_SDO_process_count-1].id,expect_SDO[this->test_SDO_process_count-1].data[0],expect_SDO[this->test_SDO_process_count-1].data[1],expect_SDO[this->test_SDO_process_count-1].data[2],expect_SDO[this->test_SDO_process_count-1].data[3],expect_SDO[this->test_SDO_process_count-1].data[4],expect_SDO[this->test_SDO_process_count-1].data[5],expect_SDO[this->test_SDO_process_count-1].data[6],expect_SDO[this->test_SDO_process_count-1].data[7]);  

      if (this->compare_with_expect()){
        sprintf(this->buffer_string[(this->buffer_count++) % 100],"PASSED\n");
      } else {
        sprintf(this->buffer_string[(this->buffer_count++) % 100],"FAILED\n");
      }  
    }    
    
  }


  
}

/* ------------------------ Find value in Linked List ----------------------- */
struct SDO* LOITRUCK::find_value(struct SDO** head_ref, uint32_t value){
  struct SDO* last = *head_ref;

  if (*head_ref == NULL){
    return NULL;
  } 
    
  // traverse until the end
  while (last->next != NULL){
    if (last->COB_ID == value) 
      { 
        break;
      } else {
        last = last->next;    
        //Serial.println(last->COB_ID,HEX);
      }    
  }

  if (last->COB_ID == value){
    return last;
  } else {
    return NULL;
  }
}

bool LOITRUCK::compare_with_expect(){
  return this->msg_to_send == expect_SDO[this->test_SDO_process_count - 1];
}

void LOITRUCK::display_Linked_List(){
  //Serial.println("Called Displayed");
  //Serial.println(loiTruck->my_SDO_List == NULL);
  struct SDO *tmp;
  if (this->my_SDO_List == NULL){
    return;
  } else {    
    tmp = this->my_SDO_List;
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

void LOITRUCK::State_process_function(){
  Scenario* next_scenario = this->current_Scenario->_next;
  

  if (this->current_Scenario != NULL){
    // change to next Scenario
    if (next_scenario != NULL){
      if (next_scenario->_start_time == this->passed_time_s){
        this->current_Scenario = next_scenario;
      }
    }

    // trigger at start time
    if (this->current_Scenario->_start_time == this->passed_time_s){
       switch (this->current_Scenario->_output_type)
       {
       case OUT_TIME_STAMP:{ // Delay
         this->tool_state = TOOL_DELAY;
         sprintf(this->buffer_string[(this->buffer_count++) % 100],"In Delay Mode\n");         
         break;
       }

       case OUT_CAN_MESSAGE:{ // predefine
         this->tool_state = TOOL_PREDEFINED;
         sprintf(this->buffer_string[(this->buffer_count++) % 100],"In Predefined Mode\n");
         break;
       }

       case OUT_FUNCTION:{ // Delay
         this->tool_state = TOOL_FUNCTION;
         sprintf(this->buffer_string[(this->buffer_count++) % 100],"In Function Mode\n");
         break;
       }

       case OUT_IGNORE:{ // Delay
         this->tool_state = TOOL_IGNORE;         
         sprintf(this->buffer_string[(this->buffer_count++) % 100],"In Ignore Mode\n");
         break;
       }

       case OUT_RESET:{ // Delay
         this->tool_state = TOOL_DEFAULT;
         sprintf(this->buffer_string[(this->buffer_count++) % 100],"In Default Mode\n");
         this->state = CO_SDO_ST_IDLE;
         break;
       }                
       default:
         break;
       }
    }
  } else {
    this->current_Scenario = &Scenario_1;
  }
}