#include <Arduino.h>
#include <dv_every_interval.h>

struct Counter {
  uint8_t id;
  uint16_t count;
};

static void onTick(void* ctx) {
  Counter* c = static_cast<Counter*>(ctx);
  c->count++;
  Serial.print("Counter #");
  Serial.print(c->id);
  Serial.print(" -> ");
  Serial.println(c->count);
}

static Counter counterA = {1, 0};
static Counter counterB = {2, 0};

static DV_EveryInterval timerA;
static DV_EveryInterval timerB;

void setup() {
  Serial.begin(115200);
  Serial.println("DV_EveryInterval contextual callback demo");

  timerA.setInterval(1000).setCallback(onTick, &counterA);
  timerB.setInterval(2500).setCallback(onTick, &counterB);
}

void loop() {
  timerA.update();
  timerB.update();
}

/*
output:
DV_EveryInterval contextual callback demo
Counter #1 -> 1
Counter #1 -> 2
Counter #2 -> 1
Counter #1 -> 3
...
*/
