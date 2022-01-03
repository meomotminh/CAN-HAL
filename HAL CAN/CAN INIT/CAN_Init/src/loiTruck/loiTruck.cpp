#include "loiTruck.h"

LOITRUCK::LOITRUCK(){
    // do nothing    
}

void LOITRUCK::SDO_process_function(){
    
    //sprintf(this->buffer_string[this->buffer_count++],"enter process function");
    // hang until copy received data into local object
    while (HAL_FDCAN_GetRxMessage(&this->my_can.CanHandle, FDCAN_RX_FIFO0, &this->RxHeader, this->RxData) != HAL_OK){
    ////Serial.println("HAL_FDCAN_GetRxMessage error");
      
    }

    
    
    
    // process command_ID and COB_ID    
    bool upload = false;    
    uint32_t COB_ID = (this->RxData[2] << 16) | (this->RxData[1] << 8) | this->RxData[3];
    String COB_ID_str = String(COB_ID);
    int COB_ID_int = COB_ID_str.toInt();

    //sprintf(this->buffer_string[this->buffer_count++],"RxData[0]: %x",RxData[0]);
    /**
     * @brief UPLOAD?
     * 
     */
    //Serial.println(this->RxData[0],HEX);
    if (this->RxData[0] == 0x40){
        this->state = CO_SDO_ST_UPLOAD_INITIATE_REQ;
    } else if (this->RxData[0] & 0xF0 == 0x20){
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
      this->found_SDO.address = first_SDO_address;
      break;
    case 0x200001:
      this->found_SDO.address = res_2000_01_address;
      break;
    case 0x200003:
      this->found_SDO.address = res_2000_03_address;
      break;  
    case 0x200202:
      this->found_SDO.address = res_2002_02_address;
      break;
    case 0x400708:
      this->found_SDO.address = res_4007_08_address;
      break;
    case 0x400702:
      this->found_SDO.address = res_4007_02_address;
      break;    
    case 0x400701:
      this->found_SDO.address = res_4007_01_address;
      break;
    case 0x400700:
      this->found_SDO.address = res_4007_00_address;
      break;
    case 0x400004:
      this->found_SDO.address = res_4000_04_address;
      break;
    case 0x400003:
      this->found_SDO.address = res_4000_03_address;
      break;
    case 0x400002:
      this->found_SDO.address = res_4000_02_address;
      break;
    case 0x400001:
      this->found_SDO.address = res_4000_01_address;
      break;
    case 0x240007:
      this->found_SDO.address = res_2400_07_address;
      break;
    case 0x240107:
      this->found_SDO.address = res_2401_07_address;
      break;
    case 0x240207:
      this->found_SDO.address = res_2402_07_address;
      break;
    case 0x240304:
      this->found_SDO.address = res_2403_04_address;
      break;
    case 0x240404:
      this->found_SDO.address = res_2404_04_address;
      break;
    case 0x240504:
      this->found_SDO.address = res_2405_04_address;
      break;
    case 0x240303:
      this->found_SDO.address = res_2403_03_address;
      break;
    case 0x240403:
      this->found_SDO.address = res_2404_03_address;
      break;
    case 0x240503:
      this->found_SDO.address = res_2405_03_address;
      break;
    case 0x240407:
      this->found_SDO.address = res_2404_07_address;
      break;
    case 0x240307:
      this->found_SDO.address = res_2403_07_address;
      break;
    case 0x240302:
      this->found_SDO.address = res_2403_02_address;
      break;
    case 0x240102:
      this->found_SDO.address = res_2401_02_address;
      break;
    case 0x240402:
      this->found_SDO.address = res_2404_02_address;
      break;
    case 0x246002:
      this->found_SDO.address = res_2460_02_address;
      break;
    case 0x240507:
      this->found_SDO.address = res_2405_07_address;
      break;
    case 0x240202:
      this->found_SDO.address = res_2402_02_address;
      break;
    case 0x240502:
      this->found_SDO.address = res_2405_02_address;
      break;
    case 0x241102:
      this->found_SDO.address = res_2411_02_address;
      break;
    case 0x200103:
      this->found_SDO.address = res_2001_03_address;
      break;
    case 0x200102:
      this->found_SDO.address = res_2001_02_address;
      break;
    case 0x246102:
      this->found_SDO.address = res_2461_02_address;
      break;
    case 0x241402:
      this->found_SDO.address = res_2414_02_address;
      break;
    case 0x292302:
      this->found_SDO.address = res_2923_02_address;
      break;
    case 0x241302:
      this->found_SDO.address = res_2413_02_address;
      break;
    case 0x202001:
      this->found_SDO.address = res_2020_01_address;
      break;
    case 0x200201:
      this->found_SDO.address = res_2002_01_address;
      break;
    case 0x210606:
      this->found_SDO.address = res_2106_06_address;
      break;
    case 0x210402:
      this->found_SDO.address = res_2104_02_address;
      break;
    case 0x210302:
      this->found_SDO.address = res_2103_02_address;
      break;
    case 0x210306:
      this->found_SDO.address = res_2103_06_address;
      break;
    case 0x220106:
      this->found_SDO.address = res_2201_06_address;
      break;
    case 0x220102:
      this->found_SDO.address = res_2201_02_address;
      break;
    case 0x210106:
      this->found_SDO.address = res_2101_06_address;
      break;
    case 0x210102:
      this->found_SDO.address = res_2101_02_address;
      break;
    case 0x200101:
      this->found_SDO.address = res_2001_01_address;
      break;
    case 0x220006:
      this->found_SDO.address = res_2200_06_address;
      break;
    case 0x220002:
      this->found_SDO.address = res_2200_02_address;
      break;
    case 0x210006:
      this->found_SDO.address = res_2100_06_address;
      break;
    case 0x210206:
      this->found_SDO.address = res_2102_06_address;
      break;
    case 0x210202:
      this->found_SDO.address = res_2102_02_address;
      break;
    case 0x210002:
      this->found_SDO.address = res_2100_02_address;
      break;
    case 0x202002:
      this->found_SDO.address = res_2020_02_address;
      break;
    case 0x200204: // segmented
      {
        this->found_SDO.address = Truck_ID_address;
        this->found_SDO.segmented = true;
        struct SDO* tmp = find_value(&this->my_SDO_List, 0x200204);
        if (tmp == NULL){
          Serial.println("NULL");
        } else {
          Serial.println(tmp->segmented_string);
        }
        
        this->found_SDO.segmented_string = tmp->segmented_string;       
        break;
      }
      
    default:
    {
      struct SDO* tmp = find_value(&this->my_SDO_List, COB_ID);
      if (tmp != NULL){
        this->found_SDO.address = tmp->address;          
      }      
      break;
    }
      
    }

    

    // base on state to call next function
    switch (this->state)
    {
    case CO_SDO_ST_DOWNLOAD_INITIATE_REQ:
        {          
        
          sprintf(this->buffer_string[this->buffer_count++],"download state");
          memcpy(&this->found_SDO.address, &this->RxData[4], 4);
          this->Download_function();        
          break;          
        }
        
    case CO_SDO_ST_UPLOAD_INITIATE_REQ:
        {
          if (this->found_SDO.segmented){
            
            sprintf(this->buffer_string[this->buffer_count++],"upload segmented state");            
            if (this->state != CO_SDO_ST_UPLOAD_INITIATE_RSP){
              this->state = CO_SDO_ST_UPLOAD_INITIATE_RSP;              
            }             
            this->Upload_segmented_function();
          } else {
            sprintf(this->buffer_string[this->buffer_count++],"upload expedited state");            
            
            this->Upload_expedited_function();
          }
          break;
        }

    case CO_SDO_ST_UPLOAD_SEGMENT_REQ:
        {                 
          sprintf(this->buffer_string[this->buffer_count++],"upload segmented continuous state");            
          this->state = CO_SDO_ST_UPLOAD_SEGMENT_RSP;  
          this->Upload_segmented_function();               
          break;
        }    
    default:
        break; 
        
        
    }

    

}


void LOITRUCK::Download_function(){
  
  this->state = CO_SDO_ST_DOWNLOAD_INITIATE_RSP;

  // clear Tx buffer
  memset(this->TxData, 0 , sizeof(this->TxData));
  
  // update TxData
  this->TxData[0] = 0x60;
  this->TxData[1] = this->RxData[1];
  this->TxData[2] = this->RxData[2];
  this->TxData[3] = this->RxData[3];


  this->CAN_send();


}

void LOITRUCK::Upload_expedited_function(){
  this->state = CO_SDO_ST_UPLOAD_INITIATE_RSP;

  // clear Tx buffer
  memset(this->TxData, 0 , sizeof(this->TxData));

  // update TxData
  this->TxData[0] = (uint8_t)(0x43 | ((4-4)<<2));
  this->TxData[1] = (uint8_t)this->RxData[1];
  this->TxData[2] = (uint8_t)(this->RxData[2]);
  this->TxData[3] = this->RxData[3];
  memcpy(&this->TxData[4], (uint8_t *)this->found_SDO.address,4);

  this->CAN_send();
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
        this->TxData[0] == 0x7;
      }
      
      String to_send = this->found_SDO.segmented_string;
      to_send = to_send.substring(5 - this->segment_remain,5 - this->segment_remain + 7);
      sprintf(this->buffer_string[this->buffer_count++], "Segmented string:%s",this->found_SDO.segmented_string);
      this->segment_remain--;
      
      to_send.getBytes(&this->TxData[1], to_send.length()+1);

      break;
    }
  
  default:
    break;
  }

  // reset segmented
  this->found_SDO.segmented = false;
  
  this->CAN_send();

  // clear last sent message
  while (HAL_FDCAN_GetRxMessage(&this->my_can.CanHandle, FDCAN_RX_FIFO0, &this->RxHeader, this->RxData) != HAL_OK){
       
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
  if (!this->ignore){
    HAL_Delay(this->delay);
    
  
    if (HAL_FDCAN_AddMessageToTxFifoQ(&(this->my_can.CanHandle), &this->TxHeader, this->TxData) != HAL_OK){      
    } else {
    }    
    
  }


  sprintf(this->buffer_string[this->buffer_count++],"P:\t%x\t%x\t%x\t%x\t%x\t%x\t%x\t%x",this->TxHeader.Identifier,this->TxData[0],this->TxData[1],this->TxData[2],this->TxData[3],this->TxData[4],this->TxData[5],this->TxData[6],this->TxData[7]);
  sprintf(this->buffer_string[this->buffer_count++],"E:\t%x\t%x\t%x\t%x\t%x\t%x\t%x\t%x",expect_SDO[this->test_SDO_process_count-1].id,expect_SDO[this->test_SDO_process_count-1].data[0],expect_SDO[this->test_SDO_process_count-1].data[1],expect_SDO[this->test_SDO_process_count-1].data[2],expect_SDO[this->test_SDO_process_count-1].data[3],expect_SDO[this->test_SDO_process_count-1].data[4],expect_SDO[this->test_SDO_process_count-1].data[5],expect_SDO[this->test_SDO_process_count-1].data[6],expect_SDO[this->test_SDO_process_count-1].data[7]);  

  if (this->compare_with_expect()){
    sprintf(this->buffer_string[this->buffer_count++],"PASSED");
  } else {
    sprintf(this->buffer_string[this->buffer_count++],"FAILED");
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
      }    
  }

  if (last->COB_ID == value){
    return last;
  } else {
    return NULL;
  }

  return last;

}

bool LOITRUCK::compare_with_expect(){
  return this->msg_to_send == expect_SDO[this->test_SDO_process_count - 1];
}
