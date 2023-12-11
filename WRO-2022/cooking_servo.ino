#include <Servo.h>

Servo servo_pin_5;
int variablename= 0;


void setup() {
  servo_pin_5.attach(4);
  pinMode(12, INPUT);
  servo_pin_5.write( 165 );

}

void loop() {
  if (( digitalRead(12) == HIGH )) {
    for(variablename = 165; 
100<=20?variablename <= 60:variablename >= 60; 
100<=20?variablename = variablename + 10:variablename = variablename - 10)
    {
      servo_pin_5.write( variablename );
      delay( 25 );
    }
    delay( 2000 );
    for(variablename = 60; 
20<=100?variablename <= 165:variablename >= 165; 
20<=100?variablename = variablename + 10:variablename = variablename - 10)
    {
      servo_pin_5.write( variablename );
      delay( 25 );
    }
  }
  else {
    servo_pin_5.write( 165 );
  }
}
