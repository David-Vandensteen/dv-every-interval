#include <Arduino.h>
#include "dv_foreach_interval.h"

static DV_ForeachInterval foreachInterval;

void setup() {
  Serial.begin(115200);
  Serial.println("DV_ForeachInterval test");

  foreachInterval
    .setInterval(3000)
    .setCallback([]() {
      Serial.print(millis());
      Serial.println(" It's time to display this message");
  });
}

void loop() {
  foreachInterval.update();
}