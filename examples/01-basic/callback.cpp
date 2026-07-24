#include <Arduino.h>
#include "callback.h"

void callBack() {
  Serial.print(millis());
  Serial.println(" It's time to display this message");
}