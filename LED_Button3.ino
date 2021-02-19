//  Example 4.3 - LED_Button3.ino
//  Button switch as a toggle switch to turn an LED on or off

 
// Define the pins being used
int pin_LED8 = 8;
int pin_Button8 = 2;
 
// Variables of new and old button states
boolean oldButton8State = HIGH;
boolean newButton8State = HIGH;
 
boolean LED8state = LOW;
 
void setup() 
{
    pinMode(pin_LED8, OUTPUT);  
    digitalWrite(pin_LED8,LOW); 
    pinMode(pin_Button8, INPUT); 
}
 
void loop()
{
    newButton8State = digitalRead(pin_Button8);
 
    if ( newButton8State != oldButton8State ) 
    {
       // if pin_Button8 pressed
       if ( newButton8State == LOW )
       {
           if ( LED8state == LOW ) 
           { digitalWrite(pin_LED8, HIGH);  
           LED8state = HIGH; 
           }
           else                    
           { digitalWrite(pin_LED8, LOW);   
           LED8state = LOW;  
           }
       }
       oldButton8State = newButton8State;
    }   
}
