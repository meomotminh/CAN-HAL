#include "mbed.h"
#include <ThreadDebug.h>

// For TRACE32 Debug
UsbDebugCommInterface debugComm(&SerialUSB);
ThreadDebug           threadDebug(&debugComm, DEBUG_BREAK_IN_SETUP);

using namespace mbed;


char counter = 0;

void setup(){
    Serial.begin(9600);
    CAN can1(PB_8, PH_13, 250000); // inner row
}

void loop(){
    CAN can1(PB_8, PH_13, 250000); // inner row
    if (can1.write(CANMessage(1337, &counter, 1))){
       Serial.print("Sent: ");Serial.println(counter); 
       counter++;
    }
}
