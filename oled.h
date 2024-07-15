#include "SSD1306Wire.h" // legacy include: `#include "SSD1306.h"`


SSD1306Wire  display(0x3c, D3, D2);  //D2=SDK  D1=SCK  As per labeling on NodeMCU

void oled_setup() {
  delay(1000);
  Serial.println("");
  
  Serial.println("Initializing OLED Display");
  display.init();

  display.setFont(ArialMT_Plain_16);
  Serial.println("Done initializing OLED Display");

}

void drawFontFaceDemo() {
  // clear the display
  display.clear();
    // Font Demo1
    // create more fonts at http://oleddisplay.squix.ch/
    display.setTextAlignment(TEXT_ALIGN_LEFT);
    display.setFont(ArialMT_Plain_10);
    display.drawString(0, 0, "Hello world");
    display.setFont(ArialMT_Plain_16);
    display.drawString(0, 10, "Hello world");
    display.setFont(ArialMT_Plain_16);
    display.drawString(0, 26, "Hello world");
  // write the buffer to the display
  display.display();
}

void drawText(const char * title, const char * text, const char * text2 = "") {
  display.clear();
  display.setTextAlignment(TEXT_ALIGN_LEFT);
  display.setFont(ArialMT_Plain_16);  
  display.drawString(0, 0, title);
  display.setFont(ArialMT_Plain_16);
  display.drawString(0, 16, text);
  display.setFont(ArialMT_Plain_16);
  display.drawString(0, 32, text2);
  display.display();  
}  
