#include "dht22.h"


// Number of times to re-poll the dht for temperature on error.
int temperature_retries = 5;

/**
 * Takes Digitial pin index to set up connection.
 */
Dht::Dht() {}

/**
 * Initialize the DHT22 sensor attached to sensor_pin.
 */
void Dht::sensorPin(int sensor_pin) {
  this->setup(sensor_pin, DHTesp::DHT22);
}

/**
 * Store the current values for future requests.
 * 
 * If non-number comes back, wait 1 second and retry, up to 5 times.
 */
void Dht::takeMeasurements(int retries_left) {
  Serial.println("Dht::takeMeasurements - Begin");

  this->moisture = this->getHumidity();
  this->temperature = this->getTemperature();

  if(!isnan(this->moisture) && !isnan(this->temperature)) {
    Serial.println("Dht::takeMeasurements - End");
    return;
  }

  if (retries_left-- > 0) {
    delay(1000);
    Serial.print("Dht::takeMeasurements - retrying, temp ");
    Serial.print(this->temperature);
    Serial.print(isnan(this->moisture));
    Serial.print(" humidity ");
    Serial.print(this->moisture);
    Serial.println(isnan(this->moisture));
    this->takeMeasurements(retries_left--);
  }
}

/**
 * Convert cenigrate to farenheit.
 */
float Dht::cToF(float temp_c) {
  Serial.print("Dht::cToF, converting temp ");
  Serial.print(temp_c);
  Serial.println("c");
  return (temp_c * 1.8) + 32;
}

float Dht::humidity() {
  return this->moisture;
}

float Dht::tempC() {
  return this->temperature;
}

float Dht::tempF() {
  Serial.println("Dht::tempF begin");
  float result = this->cToF(this->temperature);
  Serial.print("Dht::tempF, returning");
  Serial.println(result);  
  return result;
}
