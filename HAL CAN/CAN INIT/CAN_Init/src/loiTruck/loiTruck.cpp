#include "loiTruck.h"

LOITRUCK::LOITRUCK(){
    // do nothing
    
}

void LOITRUCK::SDO_process_function(){
    // process command_ID and COB_ID
    if ((this.RxData[0] & 0xF0 == 0x40) | (this.RxData[0] & 0xF0 == 0x60) | this.segmented){
    // READ COMMAND
    uint32_t temp = 0;    
    uint32_t COB_ID = (this.RxData[2] << 16) | (this.RxData[1] << 8) | loiTruck.RxData[3];
    String str = String(COB_ID);
    int str_int = str.toInt();
}

void LOITRUCK::Upload_procedure(){

}

void LOITRUCK::Download_procedure(){

}

void LOITRUCK::Upload_expedited_function(){

}

void LOITRUCK::Upload_segmented_function(){

}