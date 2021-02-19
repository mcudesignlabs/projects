#define sensorPin A0
#define relayPin 3

// Variable to store the time when last event happened
unsigned long lastEvent = 0;
boolean relayState = false;    // Variable to store the state of relay

void setup() {
  pinMode(relayPin, OUTPUT);  // Set relay pin as an OUTPUT pin
  pinMode(sensorPin, INPUT);  // Set sensor pin as an INPUT
}

void loop() {
  // Read Sound sensor
  int sensorData = digitalRead(sensorPin);

  // If pin goes LOW, sound is detected
  if (sensorData == LOW) {

  if (millis() - lastEvent > 25) {
    relayState = !relayState;
    digitalWrite(relayPin, relayState ? HIGH : LOW);
  }

  lastEvent = millis();
  }
}
