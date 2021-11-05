/* -------------------------------------------------------------------------- */
/*                                SRAM SECTION                                */
/* -------------------------------------------------------------------------- */
#include "SRAM.h"


/* ------------------------ Write SDO object to SRAM ------------------------ */
uint8_t write_SDO_to_SRAM(LOITRUCK* loiTruck){
  loiTruck->uwIndex = 0;
  
struct SDO temp(0,0,0,NULL,0,false);

  //Serial.println(CRC_Hash_Function(200000));
#ifdef res_2000_00 
  *(__IO uint32_t *)(SRAM_BANK_ADDR + WRITE_READ_ADDR + (4*res_2000_00_indx)) = res_2000_00;
  
  // create SDO object and add to linked list
  temp = SDO(res_2000_00_indx,SRAM_BANK_ADDR + WRITE_READ_ADDR + (4*res_2000_00_indx),0x200000,NULL,0x01,false);  
  append_Linked_List(&loiTruck->my_SDO_List, &temp);
#endif


#ifdef res_2000_01 
  *(__IO uint32_t *)(SRAM_BANK_ADDR + WRITE_READ_ADDR + (4*res_2000_01_indx)) = res_2000_01;
  //Serial.println(res_2000_01_indx);
  temp = SDO(res_2000_01_indx,SRAM_BANK_ADDR + WRITE_READ_ADDR + (4*res_2000_01_indx),0x200001,NULL,0x01,false);
  append_Linked_List(&loiTruck->my_SDO_List, &temp);

  //display_Linked_List();
#endif


#ifdef res_2000_03 
  *(__IO uint32_t *)(SRAM_BANK_ADDR + WRITE_READ_ADDR + (4*res_2000_03_indx)) = res_2000_03;
  //Serial.println(res_2000_03_indx);
  temp = SDO(res_2000_03_indx,SRAM_BANK_ADDR + WRITE_READ_ADDR + (4*res_2000_03_indx),0x200003,NULL,0x01,false);
  append_Linked_List(&loiTruck->my_SDO_List, &temp);

 
#endif

#ifdef res_2002_02 
  *(__IO uint32_t *)(SRAM_BANK_ADDR + WRITE_READ_ADDR + (4*res_2002_02_indx)) = res_2002_02;
  //Serial.println(res_2002_02_indx);
  temp = SDO(res_2002_02_indx,SRAM_BANK_ADDR + WRITE_READ_ADDR + (4*res_2002_02_indx),0x200202,NULL,0x01,false);
  append_Linked_List(&loiTruck->my_SDO_List, &temp);
#endif

#ifdef res_2020_02    
  *(__IO uint32_t *)(SRAM_BANK_ADDR + WRITE_READ_ADDR + (4*res_2020_02_indx)) = res_2020_02;
  //Serial.println(res_2020_02_indx);
  temp = SDO(res_2020_02_indx,SRAM_BANK_ADDR + WRITE_READ_ADDR + (4*res_2020_02_indx),0x202002,NULL,0x01,false);
  append_Linked_List(&loiTruck->my_SDO_List, &temp);
#endif

#ifdef res_2100_02
  *(__IO uint32_t *)(SRAM_BANK_ADDR + WRITE_READ_ADDR + (4*res_2100_02_indx)) = res_2100_02;
  //Serial.println(res_2100_02_indx);
  temp = SDO(res_2100_02_indx,SRAM_BANK_ADDR + WRITE_READ_ADDR + (4*res_2100_02_indx),0x210002,NULL,0x01,false);
  append_Linked_List(&loiTruck->my_SDO_List, &temp);
#endif

#ifdef res_2102_02
  *(__IO uint32_t *)(SRAM_BANK_ADDR + WRITE_READ_ADDR + (4*res_2102_02_indx)) = res_2102_02;
  //Serial.println(res_2102_02_indx);
  temp = SDO(res_2102_02_indx,SRAM_BANK_ADDR + WRITE_READ_ADDR + (4*res_2102_02_indx),0x210202,NULL,0x01,false);
  append_Linked_List(&loiTruck->my_SDO_List, &temp);
#endif

#ifdef res_2102_06
  *(__IO uint32_t *)(SRAM_BANK_ADDR + WRITE_READ_ADDR + (4*res_2102_06_indx)) = res_2102_06;
  //Serial.println(res_2102_06_indx);
  temp = SDO(res_2102_06_indx,SRAM_BANK_ADDR + WRITE_READ_ADDR + (4*res_2102_06_indx),0x210206,NULL,0x01,false);
  append_Linked_List(&loiTruck->my_SDO_List, &temp);
#endif

#ifdef res_2100_06
  *(__IO uint32_t *)(SRAM_BANK_ADDR + WRITE_READ_ADDR + (4*res_2000_03_indx)) = res_2000_03;
  //Serial.println(res_2000_03_indx);
  temp = SDO(res_2000_03_indx,SRAM_BANK_ADDR + WRITE_READ_ADDR + (4*res_2000_03_indx),0x200003,NULL,0x01,false);
  append_Linked_List(&loiTruck->my_SDO_List, &temp);
#endif

#ifdef res_2200_02
  *(__IO uint32_t *)(SRAM_BANK_ADDR + WRITE_READ_ADDR + (4*res_2200_02_indx)) = res_2200_02;
  //Serial.println(res_2200_02_indx);
  temp = SDO(res_2200_02_indx,SRAM_BANK_ADDR + WRITE_READ_ADDR + (4*res_2200_02_indx),0x220002,NULL,0x01,false);
  append_Linked_List(&loiTruck->my_SDO_List, &temp);
#endif

#ifdef res_2200_06
  *(__IO uint32_t *)(SRAM_BANK_ADDR + WRITE_READ_ADDR + (4*res_2200_06_indx)) = res_2200_06;
  //Serial.println(res_2200_06_indx);
  temp = SDO(res_2200_06_indx,SRAM_BANK_ADDR + WRITE_READ_ADDR + (4*res_2200_06_indx),0x220006,NULL,0x01,false);
  append_Linked_List(&loiTruck->my_SDO_List, &temp);
#endif

#ifdef res_2001_01
  *(__IO uint32_t *)(SRAM_BANK_ADDR + WRITE_READ_ADDR + (4*res_2001_01_indx)) = res_2001_01;
  //Serial.println(res_2001_01_indx);
  temp = SDO(res_2001_01_indx,SRAM_BANK_ADDR + WRITE_READ_ADDR + (4*res_2001_01_indx),0x200101,NULL,0x01,false);
  append_Linked_List(&loiTruck->my_SDO_List, &temp);
#endif

#ifdef res_2101_02
  *(__IO uint32_t *)(SRAM_BANK_ADDR + WRITE_READ_ADDR + (4*res_2101_02_indx)) = res_2101_02;
  //Serial.println(res_2101_02_indx); 
  temp = SDO(res_2101_02_indx,SRAM_BANK_ADDR + WRITE_READ_ADDR + (4*res_2101_02_indx),0x210102,NULL,0x01,false);
  append_Linked_List(&loiTruck->my_SDO_List, &temp);
#endif

#ifdef res_2101_06
  *(__IO uint32_t *)(SRAM_BANK_ADDR + WRITE_READ_ADDR + (4*res_2101_06_indx)) = res_2101_06;
  //Serial.println(res_2101_06_indx);
  temp = SDO(res_2101_06_indx,SRAM_BANK_ADDR + WRITE_READ_ADDR + (4*res_2101_06_indx),0x210106,NULL,0x01,false);
  append_Linked_List(&loiTruck->my_SDO_List, &temp);
#endif

#ifdef res_2201_02
  *(__IO uint32_t *)(SRAM_BANK_ADDR + WRITE_READ_ADDR + (4*res_2201_02_indx)) = res_2201_02;
  //Serial.println(res_2201_02_indx);
  temp = SDO(res_2201_02_indx,SRAM_BANK_ADDR + WRITE_READ_ADDR + (4*res_2201_02_indx),0x220102,NULL,0x01,false);
  append_Linked_List(&loiTruck->my_SDO_List, &temp);
#endif

#ifdef res_2201_06
  *(__IO uint32_t *)(SRAM_BANK_ADDR + WRITE_READ_ADDR + (4*res_2201_06_indx)) = res_2201_06;
  //Serial.println(res_2201_06_indx);
  temp = SDO(res_2201_06_indx,SRAM_BANK_ADDR + WRITE_READ_ADDR + (4*res_2201_06_indx),0x220106,NULL,0x01,false);
  append_Linked_List(&loiTruck->my_SDO_List, &temp);
#endif

#ifdef res_2103_06
  *(__IO uint32_t *)(SRAM_BANK_ADDR + WRITE_READ_ADDR + (4*res_2103_06_indx)) = res_2103_06;
  //Serial.println(res_2103_06_indx);
  temp = SDO(res_2103_06_indx,SRAM_BANK_ADDR + WRITE_READ_ADDR + (4*res_2103_06_indx),0x210306,NULL,0x01,false);
  append_Linked_List(&loiTruck->my_SDO_List, &temp);
#endif

#ifdef res_2103_02
  *(__IO uint32_t *)(SRAM_BANK_ADDR + WRITE_READ_ADDR + (4*res_2103_02_indx)) = res_2103_02;
  //Serial.println(res_2103_02_indx);
  temp = SDO(res_2103_02_indx,SRAM_BANK_ADDR + WRITE_READ_ADDR + (4*res_2103_02_indx),0x210302,NULL,0x01,false);
  append_Linked_List(&loiTruck->my_SDO_List, &temp);
#endif

#ifdef res_2104_02
  *(__IO uint32_t *)(SRAM_BANK_ADDR + WRITE_READ_ADDR + (4*res_2104_02_indx)) = res_2104_02;
  //Serial.println(res_2104_02_indx);
  temp = SDO(res_2104_02_indx,SRAM_BANK_ADDR + WRITE_READ_ADDR + (4*res_2104_02_indx),0x210402,NULL,0x01,false);
  append_Linked_List(&loiTruck->my_SDO_List, &temp);
#endif

#ifdef res_2106_06
  *(__IO uint32_t *)(SRAM_BANK_ADDR + WRITE_READ_ADDR + (4*res_2106_06_indx)) = res_2106_06;
  //Serial.println(res_2106_06_indx);
  temp = SDO(res_2106_06_indx,SRAM_BANK_ADDR + WRITE_READ_ADDR + (4*res_2106_06_indx),0x210606,NULL,0x01,false);
  append_Linked_List(&loiTruck->my_SDO_List, &temp);
#endif

#ifdef res_2002_01
  *(__IO uint32_t *)(SRAM_BANK_ADDR + WRITE_READ_ADDR + (4*res_2002_01_indx)) = res_2002_01;
  //Serial.println(res_2002_01_indx);
  temp = SDO(res_2002_01_indx,SRAM_BANK_ADDR + WRITE_READ_ADDR + (4*res_2002_01_indx),0x200201,NULL,0x01,false);
  append_Linked_List(&loiTruck->my_SDO_List, &temp);
#endif

#ifdef res_2020_01
  *(__IO uint32_t *)(SRAM_BANK_ADDR + WRITE_READ_ADDR + (4*res_2020_01_indx)) = res_2020_01;
  //Serial.println(res_2020_01_indx);
  temp = SDO(res_2020_01_indx,SRAM_BANK_ADDR + WRITE_READ_ADDR + (4*res_2020_01_indx),0x202001,NULL,0x01,false);
  append_Linked_List(&loiTruck->my_SDO_List, &temp);
#endif

#ifdef res_2413_02
  *(__IO uint32_t *)(SRAM_BANK_ADDR + WRITE_READ_ADDR + (4*res_2413_02_indx)) = res_2413_02;
  //Serial.println(res_2413_02_indx);
  temp = SDO(res_2413_02_indx,SRAM_BANK_ADDR + WRITE_READ_ADDR + (4*res_2413_02_indx),0x241302,NULL,0x01,false);
  append_Linked_List(&loiTruck->my_SDO_List, &temp);
#endif

#ifdef res_2923_02
  *(__IO uint32_t *)(SRAM_BANK_ADDR + WRITE_READ_ADDR + (4*res_2923_02_indx)) = res_2923_02;
  //Serial.println(res_2923_02_indx);
  temp = SDO(res_2923_02_indx,SRAM_BANK_ADDR + WRITE_READ_ADDR + (4*res_2923_02_indx),0x292302,NULL,0x01,false);
  append_Linked_List(&loiTruck->my_SDO_List, &temp);
#endif

#ifdef res_2414_02
  *(__IO uint32_t *)(SRAM_BANK_ADDR + WRITE_READ_ADDR + (4*res_2414_02_indx)) = res_2414_02;
  //Serial.println(res_2414_02_indx);
  temp = SDO(res_2414_02_indx,SRAM_BANK_ADDR + WRITE_READ_ADDR + (4*res_2414_02_indx),0x241402,NULL,0x01,false);
  append_Linked_List(&loiTruck->my_SDO_List, &temp);
#endif

#ifdef res_2461_02
  *(__IO uint32_t *)(SRAM_BANK_ADDR + WRITE_READ_ADDR + (4*res_2461_02_indx)) = res_2461_02;
  //Serial.println(res_2461_02_indx);
  temp = SDO(res_2461_02_indx,SRAM_BANK_ADDR + WRITE_READ_ADDR + (4*res_2461_02_indx),0x246102,NULL,0x01,false);
  append_Linked_List(&loiTruck->my_SDO_List, &temp);
#endif

#ifdef res_2001_02 
  *(__IO uint32_t *)(SRAM_BANK_ADDR + WRITE_READ_ADDR + (4*res_2001_02_indx)) = res_2001_02;
  //Serial.println(res_2001_02_indx);
  temp = SDO(res_2001_02_indx,SRAM_BANK_ADDR + WRITE_READ_ADDR + (4*res_2001_02_indx),0x200102,NULL,0x01,false);
  append_Linked_List(&loiTruck->my_SDO_List, &temp);
#endif

#ifdef res_2001_03    
  *(__IO uint32_t *)(SRAM_BANK_ADDR + WRITE_READ_ADDR + (4*res_2001_03_indx)) = res_2001_03;
  //Serial.println(res_2001_03_indx);
  temp = SDO(res_2001_03_indx,SRAM_BANK_ADDR + WRITE_READ_ADDR + (4*res_2001_03_indx),0x200103,NULL,0x01,false);
  append_Linked_List(&loiTruck->my_SDO_List, &temp);
#endif

#ifdef res_2411_02
  *(__IO uint32_t *)(SRAM_BANK_ADDR + WRITE_READ_ADDR + (4*res_2411_02_indx)) = res_2411_02;
  //Serial.println(res_2411_02_indx);
  temp = SDO(res_2411_02_indx,SRAM_BANK_ADDR + WRITE_READ_ADDR + (4*res_2411_02_indx),0x241102,NULL,0x01,false);
  append_Linked_List(&loiTruck->my_SDO_List, &temp);
#endif

#ifdef res_2405_02
  *(__IO uint32_t *)(SRAM_BANK_ADDR + WRITE_READ_ADDR + (4*res_2405_02_indx)) = res_2405_02;
  temp = SDO(res_2405_02_indx,SRAM_BANK_ADDR + WRITE_READ_ADDR + (4*res_2405_02_indx),0x240502,NULL,0x01,false);
  append_Linked_List(&loiTruck->my_SDO_List, &temp);
#endif

#ifdef res_2402_02
  *(__IO uint32_t *)(SRAM_BANK_ADDR + WRITE_READ_ADDR + (4*res_2402_02_indx)) = res_2402_02;
  //Serial.println(res_2402_02_indx);
  temp = SDO(res_2402_02_indx,SRAM_BANK_ADDR + WRITE_READ_ADDR + (4*res_2402_02_indx),0x240202,NULL,0x01,false);
  append_Linked_List(&loiTruck->my_SDO_List, &temp);
#endif

#ifdef res_2405_07
  *(__IO uint32_t *)(SRAM_BANK_ADDR + WRITE_READ_ADDR + (4*res_2405_07_indx)) = res_2405_07;
  //Serial.println(res_2405_07_indx);
  temp = SDO(res_2405_07_indx,SRAM_BANK_ADDR + WRITE_READ_ADDR + (4*res_2405_07_indx),0x240507,NULL,0x01,false);
  append_Linked_List(&loiTruck->my_SDO_List, &temp);
#endif

#ifdef res_2460_02
  *(__IO uint32_t *)(SRAM_BANK_ADDR + WRITE_READ_ADDR + (4*res_2460_02_indx)) = res_2460_02;
  //Serial.println(res_2460_02_indx);
  temp = SDO(res_2460_02_indx,SRAM_BANK_ADDR + WRITE_READ_ADDR + (4*res_2460_02_indx),0x246002,NULL,0x01,false);
  append_Linked_List(&loiTruck->my_SDO_List, &temp);
#endif

#ifdef res_2404_02
  *(__IO uint32_t *)(SRAM_BANK_ADDR + WRITE_READ_ADDR + (4*res_2404_02_indx)) = res_2404_02;
  //Serial.println(res_2404_02_indx);
  temp = SDO(res_2404_02_indx,SRAM_BANK_ADDR + WRITE_READ_ADDR + (4*res_2404_02_indx),0x240402,NULL,0x01,false);
  append_Linked_List(&loiTruck->my_SDO_List, &temp);
#endif

#ifdef res_2401_02
  *(__IO uint32_t *)(SRAM_BANK_ADDR + WRITE_READ_ADDR + (4*res_2401_02_indx)) = res_2401_02;
  //Serial.println(res_2401_02_indx);
  temp = SDO(res_2401_02_indx,SRAM_BANK_ADDR + WRITE_READ_ADDR + (4*res_2401_02_indx),0x240102,NULL,0x01,false);
  append_Linked_List(&loiTruck->my_SDO_List, &temp);
#endif

#ifdef res_2403_02 
  *(__IO uint32_t *)(SRAM_BANK_ADDR + WRITE_READ_ADDR + (4*res_2403_02_indx)) = res_2403_02;
  //Serial.println(res_2403_02_indx);
  temp = SDO(res_2403_02_indx,SRAM_BANK_ADDR + WRITE_READ_ADDR + (4*res_2403_02_indx),0x240302,NULL,0x01,false);
  append_Linked_List(&loiTruck->my_SDO_List, &temp);
#endif

#ifdef res_2400_02    
  *(__IO uint32_t *)(SRAM_BANK_ADDR + WRITE_READ_ADDR + (4*res_2400_02_indx)) = res_2400_02;
  //Serial.println(res_2400_02_indx);
  temp = SDO(res_2400_02_indx,SRAM_BANK_ADDR + WRITE_READ_ADDR + (4*res_2400_02_indx),0x240002,NULL,0x01,false);
  append_Linked_List(&loiTruck->my_SDO_List, &temp);
#endif

#ifdef res_2403_07
  *(__IO uint32_t *)(SRAM_BANK_ADDR + WRITE_READ_ADDR + (4*res_2403_07_indx)) = res_2403_07;
  //Serial.println(res_2403_07_indx);
  temp = SDO(res_2403_07_indx,SRAM_BANK_ADDR + WRITE_READ_ADDR + (4*res_2403_07_indx),0x240307,NULL,0x01,false);
  append_Linked_List(&loiTruck->my_SDO_List, &temp);
#endif

#ifdef res_2404_07 
  *(__IO uint32_t *)(SRAM_BANK_ADDR + WRITE_READ_ADDR + (4*res_2404_07_indx)) = res_2404_07;
  //Serial.println(res_2404_07_indx);
  temp = SDO(res_2404_07_indx,SRAM_BANK_ADDR + WRITE_READ_ADDR + (4*res_2404_07_indx),0x240407,NULL,0x01,false);
  append_Linked_List(&loiTruck->my_SDO_List, &temp);
#endif

#ifdef res_2405_03
  *(__IO uint32_t *)(SRAM_BANK_ADDR + WRITE_READ_ADDR + (4*res_2405_03_indx)) = res_2405_03;
  //Serial.println(res_2405_03_indx);
  temp = SDO(res_2405_03_indx,SRAM_BANK_ADDR + WRITE_READ_ADDR + (4*res_2405_03_indx),0x240503,NULL,0x01,false);
  append_Linked_List(&loiTruck->my_SDO_List, &temp);
#endif

#ifdef res_2404_03
  *(__IO uint32_t *)(SRAM_BANK_ADDR + WRITE_READ_ADDR + (4*res_2404_03_indx)) = res_2404_03;
  //Serial.println(res_2404_03_indx);
  temp = SDO(res_2404_03_indx,SRAM_BANK_ADDR + WRITE_READ_ADDR + (4*res_2404_03_indx),0x240403,NULL,0x01,false);
  append_Linked_List(&loiTruck->my_SDO_List, &temp);
#endif

#ifdef res_2403_03
  *(__IO uint32_t *)(SRAM_BANK_ADDR + WRITE_READ_ADDR + (4*res_2403_03_indx)) = res_2403_03;
  //Serial.println(res_2403_03_indx);
  temp = SDO(res_2403_03_indx,SRAM_BANK_ADDR + WRITE_READ_ADDR + (4*res_2403_03_indx),0x240303,NULL,0x01,false);
  append_Linked_List(&loiTruck->my_SDO_List, &temp);
#endif

#ifdef res_2405_04
  *(__IO uint32_t *)(SRAM_BANK_ADDR + WRITE_READ_ADDR + (4*res_2405_04_indx)) = res_2405_04;
  //Serial.println(res_2405_04_indx);
  temp = SDO(res_2405_04_indx,SRAM_BANK_ADDR + WRITE_READ_ADDR + (4*res_2405_04_indx),0x240504,NULL,0x01,false);
  append_Linked_List(&loiTruck->my_SDO_List, &temp);
#endif

#ifdef res_2404_04
  *(__IO uint32_t *)(SRAM_BANK_ADDR + WRITE_READ_ADDR + (4*res_2404_04_indx)) = res_2404_04;
  //Serial.println(res_2404_04_indx);
  temp = SDO(res_2404_04_indx,SRAM_BANK_ADDR + WRITE_READ_ADDR + (4*res_2404_04_indx),0x240404,NULL,0x01,false);
  append_Linked_List(&loiTruck->my_SDO_List, &temp);
#endif

#ifdef res_2403_04
  *(__IO uint32_t *)(SRAM_BANK_ADDR + WRITE_READ_ADDR + (4*res_2403_04_indx)) = res_2403_04;
  //Serial.println(res_2403_04_indx);
  temp = SDO(res_2403_04_indx,SRAM_BANK_ADDR + WRITE_READ_ADDR + (4*res_2403_04_indx),0x240304,NULL,0x01,false);
  append_Linked_List(&loiTruck->my_SDO_List, &temp);
#endif

#ifdef res_2402_07
  *(__IO uint32_t *)(SRAM_BANK_ADDR + WRITE_READ_ADDR + (4*res_2402_07_indx)) = res_2402_07;
  //Serial.println(res_2402_07_indx);
  temp = SDO(res_2402_07_indx,SRAM_BANK_ADDR + WRITE_READ_ADDR + (4*res_2402_07_indx),0x240207,NULL,0x01,false);
  append_Linked_List(&loiTruck->my_SDO_List, &temp);
#endif

#ifdef res_2401_07
  *(__IO uint32_t *)(SRAM_BANK_ADDR + WRITE_READ_ADDR + (4*res_2401_07_indx)) = res_2401_07;
  //Serial.println(res_2401_07_indx);
  temp = SDO(res_2401_07_indx,SRAM_BANK_ADDR + WRITE_READ_ADDR + (4*res_2401_07_indx),0x240107,NULL,0x01,false);
  append_Linked_List(&loiTruck->my_SDO_List, &temp);
#endif

#ifdef res_2400_07
  *(__IO uint32_t *)(SRAM_BANK_ADDR + WRITE_READ_ADDR + (4*res_2400_07_indx)) = res_2400_07;
  //Serial.println(res_2400_07_indx);
  temp = SDO(res_2400_07_indx,SRAM_BANK_ADDR + WRITE_READ_ADDR + (4*res_2400_07_indx),0x240007,NULL,0x01,false);
  append_Linked_List(&loiTruck->my_SDO_List, &temp);
#endif

#ifdef Truck_ID
  
  // create object SDO Truck_ID of length 0x20 = 32 and segmented = true
  temp = SDO(Truck_ID_indx,SRAM_BANK_ADDR + WRITE_READ_ADDR + (4*Truck_ID_indx),0x200204,NULL,0x20,true);
  String truck_id_temp = String(Truck_ID);
  //Serial.println("Hier");
  //Serial.println(ceil(temp.length / 4.0));
  
  for (uint8_t i = 0; i < ceil(temp.length / 4.0); i++){
    String temp_char = truck_id_temp.substring(i*4,i*4+4);  // get 4 letters
    Serial.print(i);Serial.print(":");
    Serial.println(temp_char);
    byte buf[temp_char.length() + 1];
    temp_char.getBytes(buf, temp_char.length() + 1);    
    uint32_t to_save = (buf[0] << 24) + (buf[1] << 16) + (buf[2] << 8) + buf[3];
    Serial.println(to_save, HEX);
    *(__IO uint32_t *)(SRAM_BANK_ADDR + WRITE_READ_ADDR + (4*(Truck_ID_indx + i))) = to_save;
  }
  uint8_t word_cnt = ceil(temp.length / 4.0);
  *(__IO uint32_t *)(SRAM_BANK_ADDR + WRITE_READ_ADDR + (4*(Truck_ID_indx + word_cnt))) = Truck_null_word;
    
  append_Linked_List(&loiTruck->my_SDO_List, &temp);
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
    Serial.println("HAL_SRAM_Init error");
  } else {
    Serial.println("HAL_SRAM_Init OK");
  }


  write_SDO_to_SRAM(loiTruck);


}
