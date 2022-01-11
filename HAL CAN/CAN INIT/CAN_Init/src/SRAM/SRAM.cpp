/* -------------------------------------------------------------------------- */
/*                                SRAM SECTION                                */
/* -------------------------------------------------------------------------- */
#include "SRAM.h"



/* ------------------------ Write SDO object to SRAM ------------------------ */


/* --------------------- Init SRAM to be able to access --------------------- */
void init_SDO_object(LOITRUCK* loiTruck){
  //uint32_t *temp = (uint32_t *)(BASE_ADD + 200000);
  //HAL_SRAM_Write_16b();
  
  loiTruck->hsram.Instance = FMC_NORSRAM_DEVICE; // Base address of : (up to 512KB) system data RAM accessible over over AXI   
  loiTruck->hsram.Extended = FMC_NORSRAM_EXTENDED_DEVICE;
  
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
  



  //write_SDO_to_SRAM(loiTruck);


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