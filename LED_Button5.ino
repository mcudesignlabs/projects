//  Example 4.5 - LED_Button5.ino
//
//  Example of using a single button switch to set multiple states or conditions
//
//  D10-green LED
//  D9-yellow LED
//  D8-red LED
//  D2-push button 
//  
//  state holds the current status.
//  0 = all off.
//  1 = green LED
//  2 = yellow LED
//  3 = red LED
 
// Define the pins being used
int pin_LED10green = 10;
int pin_LED9yellow = 9;
int pin_LED8red = 8;
 
int pin_Button2 = 2;
 
// new and old switch states
boolean oldButtonState = HIGH;
boolean newButtonState1 = HIGH;
boolean newButtonState2 = HIGH;
boolean newButtonState3 = HIGH;
 
byte state = 0;
 
void setup() 
{
    
    pinMode(pin_LED10green, OUTPUT);    digitalWrite(pin_LED10green,LOW); 
    pinMode(pin_LED9yellow, OUTPUT);   digitalWrite(pin_LED9yellow,LOW); 
    pinMode(pin_LED8red, OUTPUT);      digitalWrite(pin_LED8red,LOW); 
    pinMode(pin_Button2, INPUT); 
}
 
void loop()
{
    newButtonState1 = digitalRead(pin_Button2);
    delay(1);
    newButtonState2 = digitalRead(pin_Button2);
    delay(1);
    newButtonState3 = digitalRead(pin_Button2);
 
    // if all 3 values are the same we can continue
    if (  (newButtonState1==newButtonState2) && (newButtonState1==newButtonState3) )
    {
 
        if ( newButtonState1 != oldButtonState ) 
        {
 
           // has the button switch been closed?
           if ( newButtonState1 == LOW )
           {
                // increase the value of state
                state++;
                if (state > 3) { state = 0; }
 
// turn all LEDs off. Doing it this way means we do not need to care about the individual LEDs
                // simply turn them all off and then turn on the correct one. 
                digitalWrite(pin_LED10green, LOW);
                digitalWrite(pin_LED9yellow, LOW);
                digitalWrite(pin_LED8red, LOW);
 
                // Turn on the next LED
                // Because the value of state does not change while we are testing it we don't need to use else if
                if (state==1) { digitalWrite(pin_LED10green, HIGH);  }
                if (state==2) { digitalWrite(pin_LED9yellow, HIGH);  }
                if (state==3) { digitalWrite(pin_LED8red, HIGH);  }
 
           }
           oldButtonState = newButtonState1;
        }  
    }
}


 
