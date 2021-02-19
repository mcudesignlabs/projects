/* Created By: Rally Uminga
 * Arduino Uno with ST7735 color TFT (128x160 pixel) 
 * using Rain Sensor  
 * IECEP RIZAL PROJECT
 */
 
#include <Adafruit_GFX.h>      // include Adafruit graphics library
#include <Adafruit_ST7735.h>   // include Adafruit ST7735 TFT library

#define TFT_RST   8      // TFT RST pin is connected to arduino pin 8
#define TFT_CS    9      // TFT CS  pin is connected to arduino pin 9
#define TFT_DC    10     // TFT DC  pin is connected to arduino pin 10

// initialize ST7735 TFT library
Adafruit_ST7735 tft = Adafruit_ST7735(TFT_CS, TFT_DC, TFT_RST);

#define rainfall  7
#define buzzer    6
boolean value;
 
void setup(void)
{
  pinMode(buzzer,OUTPUT);
  pinMode(rainfall,INPUT);
  
  tft.initR(INITR_BLACKTAB);     // initialize a ST7735S chip, black tab
  tft.fillScreen(ST7735_BLACK);  // fill screen with black color
  tft.drawFastHLine(0, 50,  tft.width(), ST7735_WHITE);   // draw horizontal white line at position (0, 50)
 
  tft.setTextColor(ST7735_RED, ST7735_BLACK);  // set text color to white and black background
  tft.setTextSize(1);                 // text size = 1
  tft.setCursor(4, 16);               // move cursor to position (4, 16) pixel
  tft.print("  IECEP ST7735 TFT");
  tft.setCursor(19, 33);              // move cursor to position (19, 33) pixel
  tft.print("  RAIN SENSOR");
  tft.drawFastHLine(0, 102,  tft.width(), ST7735_GREEN);  // draw horizontal white line at position (0, 102)
  tft.setTextSize(1);                 // text size = 2
  tft.setTextColor(ST7735_BLUE, ST7735_BLACK);     // set text color to red and black background
  tft.setCursor(25, 61);              // move cursor to position (25, 61) pixel
  tft.print("DIGITAL VALUE =");
  tft.setTextColor(ST7735_YELLOW, ST7735_BLACK);  // set text color to green and black background
  tft.setCursor(34, 113);              // move cursor to position (34, 113) pixel
  tft.print(" STATUS =");
   
}
 
// main loop
void loop()
{
  value = digitalRead(rainfall);
  digitalWrite(buzzer,LOW);
  if(value ==  LOW) 
  {
    tft.setTextColor(ST7735_CYAN, ST7735_BLACK);  // set text color to yellow and black background
    tft.setTextSize(2); 
    tft.setCursor(56, 78);
    tft.print(value);
    tft.setTextSize(1); 
    tft.setCursor(13, 130);
    tft.print("RAIN DETECTED!!!");
   
    digitalWrite(buzzer,HIGH);
    delay(500);
    digitalWrite(buzzer,LOW);
    delay(500);
    
  }
     
  else
  {
    
    tft.setTextColor(ST7735_CYAN, ST7735_BLACK); 
    tft.setTextSize(2); 
    tft.setCursor(56, 78);
    tft.print(value);
    tft.setTextColor(0xFD00, ST7735_BLACK);  // set text color to orange and black background
    tft.setTextSize(1);
    tft.setCursor(13, 130);
    tft.print("    NO RAIN     ");
    digitalWrite(buzzer,LOW);

  }
    
  delay(500);    // wait a half second*/
 
}
 
// end of code.
