#include "mbed.h"
#include <ThreadDebug.h>

// For TRACE32 Debug
//UsbDebugCommInterface debugComm(&SerialUSB);
//ThreadDebug           threadDebug(&debugComm, DEBUG_BREAK_IN_SETUP);

using namespace mbed;


int main(){
    printf("Hello World!");
    while(1);
}