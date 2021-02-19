int SoundSensor = 8;

int clap = 0;
long range_start = 0;
long range = 0;
boolean status_lights = false;
void setup() {
pinMode(SoundSensor, INPUT);
pinMode(9,OUTPUT);
}
void loop() 
{
  int status_sensor = digitalRead(SoundSensor);
  if (status_sensor == 0)
  {
    if (clap == 0)
    {
      range_start = range = millis();
      clap++;
    }
    else if (clap > 0 && millis()-range >= 50)
    {
      range = millis();
      clap++;
    }
  }
if (millis()-range_start >= 400)
{
    if (clap == 2)
    {
      if (!status_lights)
      {
        status_lights = true;
        digitalWrite(9, HIGH);
      }
      else if (status_lights)
      {
        status_lights = false;
        digitalWrite(9, LOW);
      }
    }
    clap = 0;
}

}
