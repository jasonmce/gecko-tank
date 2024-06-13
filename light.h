// From https://www.instructables.com/id/ESP8266-Light-Sensor/

#ifndef LightSensor_h
#define LightSensor_h

// Provides analogRead().
#include "Arduino.h"

class LightSensor {
  public:
    LightSensor();
    void sensorPin(int pin);
    int percent();
  private:
    int _pin;
};

#endif
