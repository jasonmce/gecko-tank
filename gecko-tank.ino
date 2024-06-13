/*
  Gecko tank monitor.

  Monitors one dht22 and an LDR (light dependent resistor).
  Updates oled temp and humidity display every second.
  Posts sensor values to Thingspeak every 5 minutes.

  Requirements:
  - NodeMCU V2.0
  - Thingspeak channel
  - dht22 sensor and extension cable to reach from the circuit to inside the terrarium.
  - LDR (light dependent resistor) and 10K ohm resistor

- NodeMcu Pinout
    D1 <-> DHT22
    D2 <-> oled SDA
    D2 <-> oled SCA
    A0 <-> light circuit

  Light circuit
    The following all connect in one row:
    Photocell, other end to v3.3 (measurement)
    10k resistor to GND (pulldown)
    Wire to A0 (signal)
*/

// Community libraries.
#include <ESP8266WiFi.h>
#include "ThingSpeak.h"

// Application header files
#include "communications.h"
#include "dht22.h"
#include "light.h"
#include "oled.h"

// Seconds between data posts to thingSpeak, this is 5 minutes.
unsigned long THINGSPEAK_POST_FREQUENCY_SECONDS = 300;
// For tracking loops between posts.
unsigned long thingspeakCountdown; 

// Global variables.
WiFiClient  client;
Dht dhtHotside;
LightSensor light;

/**
  Run once at the beginning of the application.

  Initialize the objects and variables, connect to serial monitor and wifi.
  */
void setup() {
  Serial.begin(115200);

  dhtHotside.sensorPin(D1);
  light.sensorPin(A0);

  ThingSpeak.begin(client);
  oled_setup();

  drawText("Connecting to Wifi", "");
  while (!connect_wifi()) {
    Serial.println("Failed to connect to wifi, retrying in 1 second");
    delay(1000);
  }

  thingspeakCountdown = THINGSPEAK_POST_FREQUENCY_SECONDS;
}

/**
  Main program loop.

  Gather data, update displays, maybe post data, and then delay for a second.
 */
void loop() {
  /* Gather and store all sensor values */
  // Reading temperature or humidity takes about 250 milliseconds!
  // Sensor readings may also be up to 2 seconds 'old' (its a very slow sensor)
  dhtHotside.takeMeasurements();
  float hotside_temp_f = dhtHotside.tempF();
  float hotside_humid_f = dhtHotside.humidity();
  float rssi = get_rssi();
  int lux = light.percent();

  /* Send data to the serial monitor */
  char serial_update[100];
  sprintf(serial_update,"Hotside=%0.1ff %0.1f%% lux=%d rssi=%0.1f", 
    hotside_temp_f,
    hotside_humid_f,
    lux,
    rssi
  );         
  Serial.println(serial_update);

  /* Send data to the oled */
  char temp_text[100];
  sprintf(temp_text, "%0.1ff %0.1f%%", hotside_temp_f, hotside_humid_f);
  char title[100];
  sprintf(title, "lux %d", lux);
  drawText(title, temp_text);

  // Send data to Thingspeak for storage when it is time.
  if (0 == thingspeakCountdown--) {
    ThingSpeak.setField(1, hotside_temp_f); 
    ThingSpeak.setField(2, hotside_humid_f); 
    ThingSpeak.setField(3, lux); 
    ThingSpeak.setField(4, rssi); 
    drawText("Transmitting...", "");
    thingspeakPostData();

    thingspeakCountdown = THINGSPEAK_POST_FREQUENCY_SECONDS;
  }
  
  delay(1000);
}
