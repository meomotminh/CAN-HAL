#include "test_SDO_process.h"

int test_SDO_process(LOITRUCK *loiTruck){    
    uint32_t DWT_start = 0;
    uint32_t DWT_stop = 0;
    
    // send a SDO message
    my_can_write(&loiTruck->my_can, test_SDO[loiTruck->test_SDO_process_count++],0,loiTruck);
    
    // Get current DWT CYCCNT
    DWT->CYCCNT = 0;
    DWT_start = DWT_get_CYCCNT();
    
    // process
    loiTruck->SDO_process_function();

    // Get current DWT CYCCNT
    DWT_stop = DWT_get_CYCCNT();
       
    
    // calculate time
    return DWT_stop - DWT_start;
}