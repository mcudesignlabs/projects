//  Example 4.2 - LED_Button2.ino
//  Turning an LED in pin 8 on and off using a button switch in pin 2

// Arduino pins being used
int pin_LED8 = 8;
int pin_Button2 = 2;
 
// Variables new and old button states
boolean oldButton8State = HIGH;
boolean newButton8State = HIGH;
 
void setup() 
{
    pinMode(pin_LED8, OUTPUT);  
    digitalWrite(pin_LED8,LOW); 
    pinMode(pin_Button2, INPUT); 
}
 
void loop()
{
    newButton8State = digitalRead(pin_Button2);
 
    if ( newButton8State != oldButton8State ) 
    {
       if ( newButton8State == LOW ) 
       {
        digitalWrite(pin_LED8, HIGH); 
       }
       else             
       { 
        digitalWrite(pin_LED8, LOW);  
       }
 
       oldButton8State = newButton8State;
    }   
}
