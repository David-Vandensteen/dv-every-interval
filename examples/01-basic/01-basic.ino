#include <Arduino.h>
#include "dv_foreach_interval.h"
#include "callback.h"

static DV_ForeachInterval foreachInterval(3000, &callBack);

void setup() {
  Serial.begin(115200);
  Serial.println("DV_ForeachInterval test");
}

void loop() {
  foreachInterval.update();
}

/*
output:
DV_ForeachInterval test
3000 It's time to display this message
6000 It's time to display this message
9000 It's time to display this message
...
*/
