#include <Arduino.h>
#include <dv_every_interval.h>
#include "callback.h"

static DV_EveryInterval everyInterval(3000, &callBack);

void setup() {
  Serial.begin(115200);
  Serial.println("DV_EveryInterval test");
}

void loop() {
  everyInterval.update();
}

/*
output:
DV_EveryInterval test
3000 It's time to display this message
6000 It's time to display this message
9000 It's time to display this message
...
*/
