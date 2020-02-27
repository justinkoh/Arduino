#include <Servo.h>

Servo leftServo;
Servo rightServo;

int pos = 90;

void setup() {
  Serial.begin(9600);

  leftServo.attach(6);
  rightServo.attach(5);

  leftServo.write(90);
  rightServo.write(90);
  
}

void loop() {

  for (pos = 0; pos <= 180; pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    leftServo.write(pos);
    rightServo.write(pos);
    delay(15);                       // waits 15ms for the servo to reach the position
  }
  for (pos = 180; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
    leftServo.write(pos);
    rightServo.write(pos);
    delay(15);                       // waits 15ms for the servo to reach the position
  }
//
//  Serial.println(pos);
//  delay(10);
  

}
