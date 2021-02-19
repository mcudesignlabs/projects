//Example 2.6 - BlinkingLED.ino
//Author: Rally Uminga
//Description: Blinking LED in pin 13 of Arduino Uno

int LED13 = 13;                //D13 has built-in LED in Arduino Uno
            
void setup()    //All initialization put here 
{

pinMode(LED13, OUTPUT);        //Initialize pin 13 as output

}

void loop()     //The main program that is repeated all over again
{

digitalWrite(LED13, HIGH);  //Writing the pin 13 into output high
delay(1000);    //Delay 1000 millisecond of Arduino delay function
digitalWrite(LED13, LOW); //Writing the pin 13 into output low
delay(1000);    //Delay 1000 millisecond of Arduino delay function

}
