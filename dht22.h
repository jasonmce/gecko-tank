// From https://desire.giesecke.tk/index.php/2018/01/30/esp32-dht11.
#include "DHTesp.h"

#ifdef ESP32
#pragma message(THIS EXAMPLE IS FOR ESP8266 ONLY!)
#error Select ESP8266 board.
#endif

class Dht: public DHTesp {
 protected:
   float moisture, temperature;

 public:
   Dht();
   void sensorPin(int sensor_pin);
   void takeMeasurements(int retries_left = 5);
   float cToF(float temp_c);
   float tempC();
   float tempF();
   float heatIndexC();
   float heatIndexF();
   float humidity();
   float dewpoint();
};
