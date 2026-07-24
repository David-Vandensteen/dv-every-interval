#include <Arduino.h>
#include <dv_every_interval.h>

DV_EveryInterval::DV_EveryInterval() {}

DV_EveryInterval::DV_EveryInterval(unsigned long interval)
  : _interval(interval) {}

DV_EveryInterval::DV_EveryInterval(unsigned long interval, void (*callback)())
  : _interval(interval), _callback(callback) {}

DV_EveryInterval &DV_EveryInterval::setCallback(void (*callback)()) {
  _callback = callback;

  return *this;
}

DV_EveryInterval &DV_EveryInterval::setInterval(unsigned long interval) {
  _interval = interval;
  _nextExecutionTime = millis() + _interval;

  return *this;
}

void DV_EveryInterval::update() {
  if (_interval == 0) {
    if (_callback) { _callback(); }
    return;
  }

  if (!_isInitialized) {
    _nextExecutionTime = millis() + _interval;
    _isInitialized = true;
    return;
  }

  long unsigned currentTime = millis();
  if (currentTime >= _nextExecutionTime) {
    _nextExecutionTime += _interval;
    if (_callback) { _callback(); }
  }
}
