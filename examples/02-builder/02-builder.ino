#include <Arduino.h>
#include <dv_every_interval.h>

static DV_EveryInterval everyInterval;

void setup() {
  Serial.begin(115200);
  Serial.println("DV_EveryInterval test");

  everyInterval
    .setInterval(3000)
    .setCallback([]() {
      Serial.print(millis());
      Serial.println(" It's time to display this message");
  });
}

void loop() {
  everyInterval.update();
}