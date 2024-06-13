/*
 Credentials example file.

 Copy this file to credentials.h and substitute your actual values
 and then restart your Arduino IDE to load the file as an editor tab.

 The variables needed to connect to wifi and push to ThingSpeak.
 */
 
// Network used to post data to ThingSpeak.
char ssid[] = "YourWifiSSID";
char pass[] = "YourWifiPassword";

// Thingspeak credentials.
unsigned long myChannelNumber = 1059466;
// You can find this in your channel API Keys tab.
const char * myWriteAPIKey = "CHANNEL_WRITE_API_KEY";
