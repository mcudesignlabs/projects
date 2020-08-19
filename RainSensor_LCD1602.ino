// include the library code:
#include <LiquidCrystal.h>

#define rainfall 9
#define buzzer 10
boolean value;

// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
const int RS = 3, EN = 4, D4 = 5, D5 = 6, D6 = 7, D7 = 8;
LiquidCrystal lcd(RS, EN, D4, D5, D6, D7);

void setup() 
 {
  
  Serial.begin(115200);
  pinMode(buzzer,OUTPUT);
  pinMode(rainfall,INPUT);

  lcd.begin (16,2); //Initialize the LCD
  lcd.setCursor(0,0);
  lcd.print("MARIC RAINSENSOR");
  lcd.setCursor(0,1);
  lcd.print("USING GIZDUINO");
  delay(3000);
  
  }

void loop() {

 lcd.clear(); 
 value = digitalRead(rainfall);
 Serial.println(value);
 
 if(value == LOW){
  Serial.println("Rain Detected!!!");
 
  lcd.setCursor(0,0);
  lcd.print("Rain Detected!!!");

  digitalWrite(buzzer,HIGH);
  delay(1000);
  digitalWrite(buzzer,LOW);
  delay(1000);
 }
 else{
  Serial.println("No Rain Detected");
  digitalWrite(buzzer,LOW);
 
  lcd.setCursor(0,0);
  lcd.print("No Rain");
  
 }
 delay(500);
}
