#include <Servo.h>              //Servo library
 
Servo servo_test1;        //initialize a servo object for the connected servo 
Servo servo_test2;  
Servo servo_test3;  
Servo servo_test4;   
                
int angle = 0;    
 
void setup() 
{ 
  servo_test1.attach(11);      // attach the signal pin of servo to pin9 of arduino
  servo_test2.attach(10);
  servo_test3.attach(9);
  servo_test4.attach(6);
} 
  
void loop() 
{ 
  grip();
  up();
  waist1();
  down();
  grip();
  waist2();
  
}

void grip()
{
  for(angle = 0; angle < 180; angle += 1)    // command to move from 0 degrees to 180 degrees 
  {                                  
    servo_test1.write(angle);                 //command to rotate the servo to the specified angle
    delay(15);                       
  } 
 
  delay(1000);
  
  for(angle = 180; angle>=1; angle-=1)     // command to move from 180 degrees to 0 degrees 
  {                                
    servo_test1.write(angle);              //command to rotate the servo to the specified angle
    delay(15);                       
  } 

    delay(1000);

}

void waist1()
{
  for(angle = 0; angle < 180; angle += 1)    // command to move from 0 degrees to 180 degrees 
  {                                  
    servo_test3.write(angle);                 //command to rotate the servo to the specified angle
    delay(15);                       
  } 
 
  delay(1000);
  
}

void waist2()
{
for(angle = 180; angle>=1; angle-=1)     // command to move from 180 degrees to 0 degrees 
  {                                
    servo_test3.write(angle);              //command to rotate the servo to the specified angle
    delay(15);                       
  } 

    delay(1000);

}

void up()
{
  for(angle = 0; angle < 180; angle += 1)    // command to move from 0 degrees to 180 degrees 
  {                                  
    servo_test2.write(angle);                 //command to rotate the servo to the specified angle
    delay(15);                       
  } 
 
  delay(1000);
  
}

void down()
{
for(angle = 180; angle>=1; angle-=1)     // command to move from 180 degrees to 0 degrees 
  {                                
    servo_test2.write(angle);              //command to rotate the servo to the specified angle
    delay(15);                       
  } 

    delay(1000);

}
