#include <Adafruit_GFX.h>     // Adafruit core graphics library
#include <Adafruit_ST7789.h>  // Adafruit hardware-specific library for ST7789
 
// ST7789 TFT module connections
#define TFT_CS    10  // define chip select pin
#define TFT_DC     9  // define data/command pin
#define TFT_RST    8  // define reset pin, or set to -1 and connect to Arduino RESET pin
// initialize Adafruit ST7789 TFT library with hardware SPI module
// MOSI(SDA) ---> Arduino digital pin 11
// SCK (SCL) ---> Arduino digital pin 13
Adafruit_ST7789 tft = Adafruit_ST7789(TFT_CS, TFT_DC, TFT_RST);
 
const int trigPin = 7;
const int echoPin = 6;
long duration;
float distanceCm;
 
void setup(void) 
{

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  
  // initialize the ST7789 display (240x240 pixel)
  // if the display has CS pin try with SPI_MODE0
  tft.init(240, 240, SPI_MODE2);
 
  // if the screen is flipped, remove this command
  tft.setRotation(2);
  // fill the screen with black color
  tft.fillScreen(ST77XX_BLACK);
 
  tft.setTextWrap(false);                        // turn off text wrap option
  tft.setTextColor(ST77XX_BLUE, ST77XX_BLACK);  // set text color to green and black background
  tft.setTextSize(2);           // text size = 3
  tft.setCursor(15, 40);        // move cursor to position (15, 27) pixel
  tft.print("WATER LEVEL SENSOR");
  tft.setTextColor(ST77XX_GREEN, ST77XX_BLACK);  // set text color to yellow and black background
  tft.setCursor(83, 140);    // move cursor to position (15, 27) pixel
  tft.print("STATUS:");
  tft.setTextSize(4);        // text size = 4
 
}
 
char _buffer[9];

// main loop
void loop()
{
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distanceCm = (duration*0.034)/2;
  tft.setTextColor(ST77XX_RED, ST77XX_BLACK);  // set text color to red with black background
  sprintf(_buffer, "%3u.%1u", (int)distanceCm, (int)(distanceCm * 10 ) % 100 );
  tft.setCursor(16, 71);
  tft.print(_buffer);
  tft.setCursor(185, 71);
  tft.print("cm ");

 if (distanceCm < 4.0){

  tft.setTextColor(ST77XX_YELLOW, ST77XX_BLACK);  // set text color to cyan and black background
  tft.setCursor(60, 171);
  tft.print("FULL  ");
 
 }
 else
 {
  tft.setTextColor(ST77XX_CYAN, ST77XX_BLACK);  // set text color to cyan and black background
  tft.setCursor(60, 171);
  tft.print("REFILL");
 } 
  delay(500);
 
}// end of code.
