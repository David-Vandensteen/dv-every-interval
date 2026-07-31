#include <Arduino.h>
#include <dv_every_interval.h>

DV_EveryInterval::DV_EveryInterval() {}

DV_EveryInterval::DV_EveryInterval(unsigned long interval)
  : _interval(interval) {}

DV_EveryInterval::DV_EveryInterval(unsigned long interval, void (*callback)())
  : _interval(interval), _callback(callback) {}

DV_EveryInterval &DV_EveryInterval::setCallback(void (*callback)()) {
  _callback = callback;
  _callbackCtx = nullptr;
  _context = nullptr;

  return *this;
}

DV_EveryInterval &DV_EveryInterval::setCallback(void (*callback)(void*), void* context) {
  _callbackCtx = callback;
  _context = context;
  _callback = nullptr;

  return *this;
}

DV_EveryInterval &DV_EveryInterval::setInterval(unsigned long interval) {
  _interval = interval;
  _nextExecutionTime = millis() + _interval;

  return *this;
}

void DV_EveryInterval::update() {
  if (_interval == 0) {
    if (_callbackCtx) { _callbackCtx(_context); }
    else if (_callback) { _callback(); }
    return;
  }

  if (!_isInitialized) {
    _nextExecutionTime = millis() + _interval;
    _isInitialized = true;
    return;
  }

  long unsigned currentTime = millis();
  if ((long)(currentTime - _nextExecutionTime) >= 0) {
    _nextExecutionTime += _interval;
    if (_callbackCtx) { _callbackCtx(_context); }
    else if (_callback) { _callback(); }
  }
}
