//  Example 4.4 - Led_Button4.ino
//  Using a button switch as a toggle switch to turn an LED on or off
//  with a simple debounce
 
// Define the pins being used
int pin_LED8 = 8;
int pin_Button2 = 2;
 
// new and old switch states
boolean oldButton2State = HIGH;
boolean newButton2State1 = HIGH;
boolean newButton2State2 = HIGH;
boolean newButton2State3 = HIGH;

// LED8 state
boolean LED8state = LOW;
 
void setup() 
{
    pinMode(pin_LED8, OUTPUT);  
    digitalWrite(pin_LED8,LOW); 
    pinMode(pin_Button2, INPUT); 
}
 
void loop()
{
    newButton2State1 = digitalRead(pin_Button2);
    delay(1);
    newButton2State2 = digitalRead(pin_Button2);
    delay(1);
    newButton2State3 = digitalRead(pin_Button2);
 
    // if all 3 values are the same we can continue
    if (  (newButton2State1==newButton2State2) && (newButton2State1==newButton2State3) )
    {
 
        if ( newButton2State1 != oldButton2State ) 
        {
 
           // has the button switch been closed?
           if ( newButton2State1 == LOW )
           {
               if ( LED8state == LOW ) 
               {  
                  digitalWrite(pin_LED8, HIGH);  
                  LED8state = HIGH; 
               }
               else                    
               { 
                  digitalWrite(pin_LED8, LOW);   
                  LED8state = LOW;  
               }
           }
           oldButton2State = newButton2State1;
        }  
    }
}
