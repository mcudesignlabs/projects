// Example 3.4 - PulsatingLED.ino
int LED_Pin = 3;                        // Pin 3 PWM output      
float sine_Val;                         // Sine values
int LED_Val;                            // LED vales


void setup() 
{
  
    pinMode(LED_Pin, OUTPUT);           // Initialize LED_Pin to output

}

void loop() 
{
    for (int x=0; x<180; x++)           // Iterate until 180 times
    {

    sine_Val = (sin(x*(3.1416/180)));   // Degrees to Radians for sine value
    LED_Val = int(sine_Val*255);        // 8-bit PWM value
    analogWrite(LED_Pin, LED_Val);      // PWM Output
    delay(10);                          // Delay 10ms
                       
    }
}
