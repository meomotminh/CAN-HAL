#include "test_worst_case.h"

/**
 * @brief Add 1 element into Linked List and measure
 * 
 */
int test_worst_case(LOITRUCK *loiTruck){    
    uint32_t DWT_start = 0;
    uint32_t DWT_stop = 0;
    
    loiTruck->append_Linked_List(&loiTruck->my_SDO_List, 0,0);


    // Get current DWT CYCCNT
    DWT->CYCCNT = 0;
    DWT_start = DWT_get_CYCCNT();

    struct SDO temp_SDO_2 = *(get_last_SDO(&loiTruck->my_SDO_List)); 

      
    // Get current DWT CYCCNT
    DWT_stop = DWT_get_CYCCNT();

    // add to the array
    return DWT_stop - DWT_start;        
}