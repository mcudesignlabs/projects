/***********************************************************************
 * Interfacing Arduino with ST7789 TFT display (240x240 pixel)
 *   and DHT11 digital humidity & temperature sensor.
 * Ex. ST7789_DHT11.ino
 ***********************************************************************/
#include <Adafruit_GFX.h>     // Adafruit core graphics library
#include <Adafruit_ST7789.h>  // Adafruit hardware-specific library for ST7789
#include <DHT.h>              // Adafruit DHT library code
 
// ST7789 TFT module connections
#define TFT_CS    10  // define chip select pin
#define TFT_DC     9  // define data/command pin
#define TFT_RST    8  // define reset pin, or set to -1 and connect to Arduino RESET pin
// initialize Adafruit ST7789 TFT library with hardware SPI module
// MOSI(SDA) ---> Arduino digital pin 11
// SCK (SCL) ---> Arduino digital pin 13
Adafruit_ST7789 tft = Adafruit_ST7789(TFT_CS, TFT_DC, TFT_RST);
 
#define DHTPIN  A2           // DHT11 data pin is connected to Arduino analog pin 2
#define DHTTYPE DHT11        // DHT11 sensor is used
DHT dht11(DHTPIN, DHTTYPE);  // initialize DHT library
 
void setup(void) {
  
  // initialize the ST7789 display (240x240 pixel)
  // if the display has CS pin try with SPI_MODE0
  tft.init(240, 240, SPI_MODE2);
 
  // if the screen is flipped, remove this command
  tft.setRotation(2);
  // fill the screen with black color
  tft.fillScreen(ST77XX_BLACK);
 
tft.setTextWrap(false);                        // turn off text wrap option
  tft.setTextColor(ST77XX_GREEN, ST77XX_BLACK);  // set text color to green and black background
  tft.setTextSize(3);           // text size = 3
  tft.setCursor(15, 40);        // move cursor to position (15, 27) pixel
  tft.print("TEMPERATURE:");
  tft.setTextColor(ST77XX_YELLOW, ST77XX_BLACK);  // set text color to yellow and black background
  tft.setCursor(43, 140);    // move cursor to position (15, 27) pixel
  tft.print("HUMIDITY:");
  tft.setTextSize(4);        // text size = 4
 
  // initialize DHT11 sensor
  dht11.begin();
 
}
 
char _buffer[7];
// main loop
void loop() {
 
  delay(1000);    // wait a second
 
  // read humidity in rH%
  int Humi = dht11.readHumidity() * 10;
  // read temperature in degrees Celsius
  int Temp = dht11.readTemperature() * 10;
 
  // print temperature (in °C)
  tft.setTextColor(ST77XX_RED, ST77XX_BLACK);  // set text color to red with black background
  if(Temp < 0)    // if temperature < 0
    sprintf(_buffer, "-%02u.%1u", (abs(Temp)/10)%100, abs(Temp) % 10);
  else            // temperature >= 0
    sprintf(_buffer, " %02u.%1u", (Temp/10)%100, Temp % 10);

  tft.setCursor(26, 71);
  tft.print(_buffer);
  tft.drawCircle(161, 77, 4, ST77XX_RED);  // print degree symbol ( ° )
  tft.drawCircle(161, 77, 5, ST77XX_RED);
  tft.setCursor(170, 71);
  tft.print("C");
 
  // print humidity (in %)
  tft.setTextColor(ST77XX_CYAN, ST77XX_BLACK);  // set text color to cyan and black background
  sprintf(_buffer, "%02u.%1u %%", (Humi/10)%100, Humi % 10);
  tft.setCursor(50, 171);
  tft.print(_buffer);
 
}
 
// end of code.
