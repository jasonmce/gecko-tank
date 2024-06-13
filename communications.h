/************************************* 
 *  setup wifi communications Nodemcu
 *************************************/

#include "credentials.h"

bool connect_wifi()
{
  Serial.print("Attempting to connect to SSID: ");
  Serial.println(ssid);
  WiFi.begin(ssid, pass);

  // Loops for no more than 10 * (.25 + .25) = 10 seconds.
  int loop_count = 0;
  while((WiFi.status() != WL_CONNECTED) && (loop_count++ < 20)) {
    digitalWrite(LED_BUILTIN, LOW);  // Flutter the LED on while we try to connect. 
    Serial.print("*");
    delay(250);
    digitalWrite(LED_BUILTIN, HIGH);  // Flutter the LED on while we try to connect.
    delay(250);
  }
  if (loop_count >= 20) {
    Serial.println("\nFailed to connect, will try again later.");    
    return false;
  }
  
  Serial.println("\nConnected.");
  delay(1000);
  return true;
}

/* Wrapper for an object method */
long get_rssi() {
    return WiFi.RSSI();
}

/*********************************** 
 *  Send data to Thingspeak.
 ***********************************/
 void thingspeakPostData(){
  Serial.println("thingspeaksenddata started");        
  int result = ThingSpeak.writeFields(myChannelNumber, myWriteAPIKey);
  Serial.print("thingspeaksenddata completed, result was ");       
  Serial.println(result);       
}
