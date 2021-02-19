// Example 3.6 - LEDCandleEffect.ino
int LED_Pin1 = 9;                         // LED PWM1
int LED_Pin2 = 10;                        // LED PWM2
int LED_Pin3 = 11;                        // LED PWM3

void setup()
{
pinMode(LED_Pin1, OUTPUT);                // Initialize Pin 9 to Output
pinMode(LED_Pin2, OUTPUT);                // Initialize Pin 9 to Output
pinMode(LED_Pin3, OUTPUT);                // Initialize Pin 9 to Output
}

void loop()
{
analogWrite(LED_Pin1, random(120)+135);   // Randomize Pin 9 PWM
analogWrite(LED_Pin2, random(120)+135);   // Randomize Pin 10 PWM
analogWrite(LED_Pin3, random(120)+135);   // Randomize Pin 11 PWM
delay(random(100));                       // Randomize delay in ms
}
