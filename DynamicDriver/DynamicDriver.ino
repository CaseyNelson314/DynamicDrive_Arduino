#include <MsTimer2.h>
#include "DynamicDriver.h"

DynamicDriver::Vcc vcc = {7, 6, 3, 4, 5, 8, 2, 9};  //set pin assing
DynamicDriver led(vcc, 13, 12, 11, 10);             //set vcc, gnd

//DynamicDriver led({7, 6, 3, 4, 5, 8, 2, 9}, 13, 12, 11, 10); //OK!

void setup() {
  Serial.begin(115200);
  
  MsTimer2::set(2, []() {  //set lamda func
    led.show(millis() / 100., 1);
  });
  MsTimer2::start();
  
}

void loop() {
  //other processes
  delay(10);
}
