//This code is all about DS1302 RTC module using LCD 1602
//Download this code ArduinoRTClibrary.zip to the link https://github.com/chrisfryer78/ArduinoRTClibrary then add the .zip file to the Arduino Library
#include  <virtuabotixRTC.h>  //DS1302 Library
//Include LCD1602 library
#include <LiquidCrystal.h>

//Choose pinouts of LCD1602
const int RS = 3, EN = 4, D4 = 5, D5 = 6, D6 = 7, D7 = 8;
LiquidCrystal lcd(RS, EN, D4, D5, D6, D7);

//Wiring for DS1302 Module SCLK, I/O, CE Or CLK, DAT, Reset               
virtuabotixRTC myRTC(9, 10, 11); 

void setup() 
{
  Serial.begin(115200);
  lcd.begin (16,2); //Initialize the LCD
  lcd.setCursor(0,0);
  lcd.print("MARIC DS1302 RTC");
  lcd.setCursor(0,1);
  lcd.print("USING GIZDUINO");
  delay(1000);
  
  //Set the updated time 	
  myRTC.setDS1302Time(0, 3, 3, 5, 31, 7, 2020);  //Comment this code after setting the right time and date
}
                                                   

void loop() 
{
  lcd.clear(); 
  myRTC.updateTime();
  lcd.setCursor(4,0);
  lcd.print(myRTC.hours);
  lcd.print(":");
  lcd.print(myRTC.minutes);
  lcd.print(":");
  lcd.print(myRTC.seconds);
  lcd.setCursor(4,1);
  lcd.print(myRTC.dayofmonth);
  lcd.print("-");
  lcd.print(myRTC.month);
  lcd.print("-");
  lcd.print(myRTC.year);
  
  delay(1000);
}
