#include "test_worst_case.h"

/**
 * @brief Add 1 element into Linked List and measure
 * 
 */
int test_worst_case(LOITRUCK *loiTruck){

    struct SDO last_SDO = *(get_last_SDO(&loiTruck->my_SDO_List));
    int temp_index = last_SDO.index + 1;
    uint32_t DWT_start = 0;
    uint32_t DWT_stop = 0;
    
    
        
    struct SDO temp_SDO(temp_index, 0,0,NULL,0,true,0);
    append_Linked_List(&loiTruck->my_SDO_List, &temp_SDO);

    // Get current DWT CYCCNT
    DWT_start = DWT_get_CYCCNT();

    struct SDO temp_SDO_2 = *(get_last_SDO(&loiTruck->my_SDO_List)); 

      
    // Get current DWT CYCCNT
    DWT_stop = DWT_get_CYCCNT();

    // add to the array
    return DWT_stop - DWT_start;        
}