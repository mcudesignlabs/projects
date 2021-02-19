//  Example 4.1 LED_Button1.ino
// Arduino Pins to be used
int pin_LED8 = 8;                       // LED in pin 10
int pin_Button2 = 2;                    // Push Button in pin 2
 
void setup() 
{
    
    pinMode(pin_LED8, OUTPUT);          // Initialize pin 10 to output
    digitalWrite(pin_LED8,LOW);         // Initialize pin 10 LOW during start
    pinMode(pin_Button2, INPUT);        // Initialize pin 2 as digital input 
}
 
void loop()
{
    if ( digitalRead(pin_Button2) == LOW)// If push button was pressed
    {
       digitalWrite(pin_LED8, HIGH);     // LED pin 10 ON
    }
    else
    {
       digitalWrite(pin_LED8, LOW);      // If not pressed, pin 10 OFF
    }  
}
