#include <MsTimer2.h>
#include "DynamicDriver.h"

//DynamicDriver::Vcc vcc = {7, 6, 3, 4, 5, 8, 2, 9};  //pin assing
//DynamicDriver led(vcc, 13, 12, 11, 10);

DynamicDriver led({7, 6, 3, 4, 5, 8, 2, 9}, 13, 12, 11, 10);

void setup() {
  Serial.begin(115200);
  MsTimer2::set(2, []() {  //lamda func
    led.show(millis() / 100., 1);
  });
  MsTimer2::start();
}

void loop() {
}
