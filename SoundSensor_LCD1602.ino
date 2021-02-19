#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// LCD address and geometry and library initialization
const byte lcdAddr = 0x27;  // Address of I2C backpack
const byte lcdCols = 16;    // Number of character in a row
const byte lcdRows = 2;     // Number of lines
//const byte lcdAddr = 0x3F;  // Address of I2C backpack
//const byte lcdCols = 20;    // Number of character in a row
//const byte lcdRows = 4;     // Number of lines

LiquidCrystal_I2C lcd(lcdAddr, lcdCols, lcdRows);

#define SoundSensor 9
#define Buzzer 10
boolean SoundValue;


void setup() 
 {
  
  Serial.begin(115200);
  pinMode(Buzzer,OUTPUT);
  pinMode(SoundSensor,INPUT);

  lcd.init();
  lcd.backlight();


  //lcd.begin (16,2); //Initialize the LCD
  lcd.setCursor(0,0);
  lcd.print("SOUND SENSOR");
  lcd.setCursor(0,1);
  lcd.print("USING LCD1602");
  delay(2000);
  
  }

void loop() 
{

 lcd.clear(); 
 SoundValue = digitalRead(SoundSensor);
 Serial.println(SoundValue);
 
 if(SoundValue == LOW)
 {
  Serial.println("Sound Detected!!!");
  lcd.setCursor(0,0);
  lcd.print("Sound Detected!!");
  digitalWrite(Buzzer,HIGH);
  delay(1000);
  digitalWrite(Buzzer,LOW);
  delay(1000);
 }
 else{
  Serial.println("Quiet Zone");
  digitalWrite(Buzzer,LOW);
  lcd.setCursor(0,0);
  lcd.print("Quiet Zone");
  
 }
 delay(500);
}
