//  Example 4.8 - LED_Button8.ino
//
//  Example of using a button switch as a toggle switch to turn a blinking LED on or off
//  now using functions
//
//  Pins
//  D8-LED
//  D2-push button
//  
 
// Define the pins being used
int pin_LED8 = 8;
int pin_Button2 = 2;
 
 
// variables to hold the new and old switch states
boolean oldSwitchState = HIGH;
 
// variables to hold the times
unsigned long timeNow = 0;
unsigned long timePrev = 0;
unsigned int timeWait = 100;
 
// variables used to control the LED
boolean flashingLEDisON = false;
boolean LEDstatus = LOW;
boolean keyPressed = false;
 
void setup() 
{
   
 
    pinMode(pin_LED8, OUTPUT);  
    digitalWrite(pin_LED8,LOW); 
 
    pinMode(pin_Button2, INPUT); 
}
 
void loop()
{
    keyPressed = checkButtonSwitch();
    if ( keyPressed )
    {   
        keyPressed = false;
        startAndStop();
    }
    if ( flashingLEDisON == true )  { blinkTheLED();   }
}
 
boolean checkButtonSwitch()
{
    boolean key = false;
 
    boolean newSwitchState1 = digitalRead(pin_Button2);      delay(1);
    boolean newSwitchState2 = digitalRead(pin_Button2);      delay(1);
    boolean newSwitchState3 = digitalRead(pin_Button2);
 
    if (  (newSwitchState1==newSwitchState2) && (newSwitchState1==newSwitchState3) )
    {
        if ( newSwitchState1 != oldSwitchState ) 
        {
            if ( newSwitchState1 == LOW ) { key = true; } else { key =  false; }
            oldSwitchState = newSwitchState1;
        }   
    }
    return key;
}
 
void startAndStop( )
{
     // turn on or turn off the blinking LED
     if ( flashingLEDisON == false)  
     { 
         flashingLEDisON = true; 
     } 
     else                            
     {   
         flashingLEDisON = false;               
         // the LED may be on so we turn it off just is case
         LEDstatus = LOW;  
         digitalWrite(pin_LED8, LEDstatus);
     }
}
 
 
void blinkTheLED()
{
    timeNow = millis();
    if (timeNow-timePrev >= timeWait )    
    {   
          timePrev = timeNow;   
          if (LEDstatus == LOW) { LEDstatus = HIGH; } else { LEDstatus = LOW; }   
          digitalWrite(pin_LED8, LEDstatus);
    }
}
