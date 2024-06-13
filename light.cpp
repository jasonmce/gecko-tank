#include "light.h"

LightSensor::LightSensor() {}

void LightSensor::sensorPin(int pin) {
  _pin = pin;
}

// Light value expressed in the range of 0 to 100.
int LightSensor::percent() {
  // Convert the analog reading (which goes from 0 - 1023) to a voltage (0 - 5V).
  return analogRead(_pin) * ((float)100 / 1023.0);
}
