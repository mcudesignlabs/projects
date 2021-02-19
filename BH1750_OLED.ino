#include <Wire.h>              // include Arduino wire library (required for I2C devices)
#include <Adafruit_GFX.h>      // include Adafruit graphics library
#include <Adafruit_SSD1306.h>  // include Adafruit SSD1306 OLED display driver
#include <BH1750.h>

//#define OLED_RESET  4    // define display reset pin
Adafruit_SSD1306 display(-1);  // initialize Adafruit display library
 

BH1750 lightMeter; 

 
void setup(void)
{
 
  // initialize the SSD1306 OLED display with I2C address = 0x3C
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  Wire.begin();
  lightMeter.begin();
 
  // clear the display buffer.
  display.clearDisplay();
  display.setTextSize(1);   // text size = 1
  display.setTextColor(WHITE, BLACK);  // set text color to white and black background
  display.setTextWrap(false);           // disable text wrap
  display.setCursor(29, 0);
  display.print("BH1750 TEST");
  display.setCursor(0, 16);
  display.print("Light:");
  display.setCursor(80, 16);
  display.print("lx");
  display.display();        // update the display
 
}
 
char _buffer[12];
 
void loop()
{    
  float lux = lightMeter.readLightLevel();
  sprintf(_buffer, " %02u.%02u ", (int)lux, (int)(lux * 100) % 100 );
  display.setCursor(37, 16);
  display.print(_buffer);
  display.display();      // update the display
  delay(1000);            // wait a second
 
}
