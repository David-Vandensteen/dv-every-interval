#ifndef DV_EVERY_INTERVAL_H
#define DV_EVERY_INTERVAL_H
#include <Arduino.h>

class DV_EveryInterval {
  public:
    explicit DV_EveryInterval();
    explicit DV_EveryInterval(unsigned long interval);
    explicit DV_EveryInterval(unsigned long interval, void (*callback)());
    DV_EveryInterval &setCallback(void (*callback)());
    DV_EveryInterval &setInterval(unsigned long interval);
    void update();

  private:
    unsigned long _interval = 1;
    unsigned long _nextExecutionTime = 0;
    bool _isInitialized = false;
    void (*_callback)() = nullptr;
};

#endif