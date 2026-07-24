#ifndef DV_FOREACH_INTERVAL_H
#define DV_FOREACH_INTERVAL_H
#include <Arduino.h>

class DV_ForeachInterval {
  public:
    explicit DV_ForeachInterval();
    explicit DV_ForeachInterval(unsigned long interval);
    explicit DV_ForeachInterval(unsigned long interval, void (*callback)());
    DV_ForeachInterval &setCallback(void (*callback)());
    DV_ForeachInterval &setInterval(unsigned long interval);
    void update();

  private:
    unsigned long _interval = 0;
    unsigned long _nextExecutionTime = 0;
    bool _isInitialized = false;
    void (*_callback)() = nullptr;
};

#endif