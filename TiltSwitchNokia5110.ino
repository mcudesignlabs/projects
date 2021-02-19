#include <SPI.h>               // include SPI library
#include <Adafruit_GFX.h>      // include adafruit graphics library
#include <Adafruit_PCD8544.h>  // include adafruit PCD8544 (Nokia 5110) library

const int Buzzer     = 8;
const int TiltSensor = 9;

// Nokia 5110 LCD module connections (CLK, DIN, D/C, CS, RST)
Adafruit_PCD8544 display = Adafruit_PCD8544(7, 6, 5, 4, 3);


void setup()
{
  pinMode(Buzzer, OUTPUT);
  pinMode(TiltSensor, INPUT);
  delay(500);  // wait 1 second
  digitalWrite(Buzzer, LOW);
  // initialize the display
  display.begin();
  
  // you can change the contrast around to adapt the display
  // for the best viewing!
  display.setContrast(60);
  display.clearDisplay();   // clear the screen and buffer
  display.drawFastHLine(0, 23, display.width(), BLACK);
  display.setTextSize(1);
  display.setTextColor(BLACK, WHITE);
  display.setCursor(6, 0);
  display.print("TILT SENSOR");
  display.setCursor(15, 28);
  display.print("STATUS:");
  display.setCursor(63, 28);
  display.print("OFF");
  display.display();

}

// main loop
void loop()
{
  

  if (digitalRead(TiltSensor) == 1)
  {
    
  digitalWrite(Buzzer, HIGH);   
  display.setCursor(63, 28);
  display.print("ON ");
  display.display();
  delay(300);                       
  digitalWrite(Buzzer, LOW);     
  delay(300);  
  
  }
  
  else
  {
    
  digitalWrite(Buzzer, LOW);   
  display.setCursor(63, 28);
  display.print("OFF");
  display.display();
  
  }

  delay(500);  // wait 0.5 second
  
}
// end of code.
