#include <Arduino.h>
#include "dv_foreach_interval.h"

DV_ForeachInterval::DV_ForeachInterval() {}

DV_ForeachInterval::DV_ForeachInterval(unsigned long interval)
  : _interval(interval) {}

DV_ForeachInterval::DV_ForeachInterval(unsigned long interval, void (*callback)())
  : _interval(interval), _callback(callback) {}

DV_ForeachInterval &DV_ForeachInterval::setCallback(void (*callback)()) {
  _callback = callback;

  return *this;
}

DV_ForeachInterval &DV_ForeachInterval::setInterval(unsigned long interval) {
  _interval = interval;

  return *this;
}

void DV_ForeachInterval::update() {
  if (!_isInitialized) {
    _nextExecutionTime = millis() + _interval;
    _isInitialized = true;
    return;
  }

  long unsigned currentTime = millis();
  if (currentTime >= _nextExecutionTime) {
    _nextExecutionTime = currentTime + _interval;
    if (_callback) { _callback(); }
  }
}
