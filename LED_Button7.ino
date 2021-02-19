//  Example 4.7 - LED_Button7.ino
//
//  Example of using a button switch as a toggle switch to turn a blinking LED on or off
//
//  Pins
//  D8 - LED
//  D2 - Push Button
//  
 
// Define the pins being used
int pin_LED8 = 8;
int pin_Button2 = 2;
 
 
// variables to hold the new and old switch states
boolean oldSwitchState = HIGH;
boolean newSwitchState1 = HIGH;
boolean newSwitchState2 = HIGH;
boolean newSwitchState3 = HIGH;
 
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
    newSwitchState1 = digitalRead(pin_Button2);      delay(1);
    newSwitchState2 = digitalRead(pin_Button2);      delay(1);
    newSwitchState3 = digitalRead(pin_Button2);
 
    if (  (newSwitchState1==newSwitchState2) && (newSwitchState1==newSwitchState3) )
    {
        if ( newSwitchState1 != oldSwitchState ) 
        {
            if ( newSwitchState1 == LOW ) { keyPressed = true; } else { keyPressed =  false; }
            oldSwitchState = newSwitchState1;
        }   
    }
 
if ( keyPressed )
    {   
         // turn on or turn off the blinking LED
         if ( flashingLEDisON == false)  
         {   
             flashingLEDisON = true;  
         } 
         else                            
         { 
              flashingLEDisON = false; 
              // the LED may be on so to be safe we turn it off. If you wished you could check LEDstatus
              LEDstatus = LOW;  digitalWrite(pin_LED8, LEDstatus);
         }
         keyPressed = false;
    }
 
 
    // if the blinking LED is on. See if it is time to blink it
    if ( flashingLEDisON == true )
    {
        timeNow = millis();
        if (timeNow-timePrev >= timeWait )    
        {   
              timePrev = timeNow;   
              if (LEDstatus == LOW) { LEDstatus = HIGH; } else { LEDstatus = LOW; }   
              digitalWrite(pin_LED8, LEDstatus);
        }
    }
}

 
