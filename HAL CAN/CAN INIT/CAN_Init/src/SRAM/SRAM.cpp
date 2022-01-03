/* -------------------------------------------------------------------------- */
/*                                SRAM SECTION                                */
/* -------------------------------------------------------------------------- */
#include "SRAM.h"


/* ------------------------ Write SDO object to SRAM ------------------------ */
uint8_t write_SDO_to_SRAM(LOITRUCK* loiTruck){
  loiTruck->uwIndex = 0;
  
struct SDO* temp;
//struct SDO temp(0,0,0,NULL,0,false);


  //*(__IO uint32_t *)(SRAM_BANK_ADDR + WRITE_READ_ADDR + (4*first_SDO.index)) = first_SDO.to_save;
  
  // create SDO object and add to linked list
  temp = &first_SDO;
  //temp->address = SRAM_BANK_ADDR + WRITE_READ_ADDR + (4*temp->index);

  append_Linked_List(&loiTruck->my_SDO_List, temp);

  while (temp->next != NULL){
    
    temp = temp->next;
    //temp->address = SRAM_BANK_ADDR + WRITE_READ_ADDR + (4*temp->index);
    *(__IO uint32_t *)(temp->address) = temp->to_save;
    
    append_Linked_List(&loiTruck->my_SDO_List, temp);
  }

#ifdef Truck_ID
  
  String truck_id_temp = String(Truck_ID);

  //Serial.print("Truck ID:");  //Serial.println(truck_id_temp);
  // create object SDO Truck_ID of length 0x20 = 32 and segmented = true
  
  while (truck_id_temp.length() < 32){
    truck_id_temp += " ";
  }

  struct SDO last_SDO = *(get_last_SDO(&loiTruck->my_SDO_List));
  int temp_index = last_SDO.index + 1;
  
  struct SDO temp_ident_SDO = SDO(temp_index,0,0x200204,NULL,0x20,true,0);  
  temp_ident_SDO.set_segmented_string(truck_id_temp);
  last_SDO.next = &temp_ident_SDO;
  //Serial.println(temp_ident_SDO.segmented_string);

  append_Linked_List(&loiTruck->my_SDO_List, &temp_ident_SDO);
  
#endif

  

  return 1;
}

/* --------------------- Init SRAM to be able to access --------------------- */
void init_SDO_object(LOITRUCK* loiTruck){
  //uint32_t *temp = (uint32_t *)(BASE_ADD + 200000);
  //HAL_SRAM_Write_16b();
  loiTruck->hsram.Instance = FMC_NORSRAM_DEVICE; // Base address of : (up to 512KB) system data RAM accessible over over AXI   
  loiTruck->hsram.Extended = FMC_NORSRAM_EXTENDED_DEVICE;
  /* at stm32h7xx_ll_fmc.h */
  loiTruck->hsram.Init.NSBank = FMC_NORSRAM_BANK1;      
  loiTruck->hsram.Init.DataAddressMux = FMC_DATA_ADDRESS_MUX_DISABLE;
  loiTruck->hsram.Init.MemoryType = FMC_MEMORY_TYPE_SRAM;
  loiTruck->hsram.Init.MemoryDataWidth = FMC_NORSRAM_MEM_BUS_WIDTH_32; 
  loiTruck->hsram.Init.BurstAccessMode = FMC_BURST_ACCESS_MODE_DISABLE;
  loiTruck->hsram.Init.WaitSignalPolarity = FMC_WAIT_SIGNAL_POLARITY_LOW;
  loiTruck->hsram.Init.WaitSignalActive = FMC_WAIT_TIMING_BEFORE_WS;
  loiTruck->hsram.Init.WriteOperation = FMC_WRITE_OPERATION_ENABLE;
  loiTruck->hsram.Init.ExtendedMode = FMC_EXTENDED_MODE_DISABLE;
  loiTruck->hsram.Init.AsynchronousWait = FMC_ASYNCHRONOUS_WAIT_DISABLE;
  loiTruck->hsram.Init.WriteBurst = FMC_WRITE_BURST_DISABLE;
  loiTruck->hsram.Init.ContinuousClock = FMC_CONTINUOUS_CLOCK_SYNC_ONLY;
  loiTruck->hsram.Init.WriteFifo = FMC_WRITE_FIFO_ENABLE;
  loiTruck->hsram.Init.PageSize = FMC_PAGE_SIZE_NONE;

  loiTruck->timing.AddressSetupTime = 2;
  loiTruck->timing.AddressHoldTime = 15;
  loiTruck->timing.DataSetupTime = 2;
  loiTruck->timing.BusTurnAroundDuration = 1;
  loiTruck->timing.CLKDivision = 16;
  loiTruck->timing.DataLatency = 17;
  loiTruck->timing.AccessMode = FMC_ACCESS_MODE_A;



  if (HAL_SRAM_Init(&loiTruck->hsram, &loiTruck->timing, NULL) != HAL_OK){
    ////Serial.println("HAL_SRAM_Init error");
  } else {
    ////Serial.println("HAL_SRAM_Init OK");
  }


  write_SDO_to_SRAM(loiTruck);


}


void manipulate_SDO_on_SRAM(My_Function func, int index, LOITRUCK* loiTruck){
    struct SDO* found = find_value(&loiTruck->my_SDO_List, func._SDO_value);

    if (found != NULL){
      *(__IO uint32_t *)(found->address) = (((loiTruck->mani_buffer[index] & 0x00FF) << 24) | ((loiTruck->mani_buffer[index] && 0xFF00) << 16));    
      ////Serial.print("Address:");
      ////Serial.println(found->address, HEX);
      ////Serial.print("Vaue:");
      ////Serial.println(loiTruck->mani_buffer[index], HEX);
    }

    // read from SRAM
    //uint32_t read_from_SRAM = *(__IO uint32_t *)(found->address);
    ////Serial.print("new value:"); //Serial.println(read_from_SRAM, HEX);
}