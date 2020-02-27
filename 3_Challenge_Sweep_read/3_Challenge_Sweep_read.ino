#include <Servo.h>

Servo leftServo;
Servo rightServo;

#define LEFT_LS A0
#define RIGHT_LS A1
int leftLS, rightLS, diff, pos;

void setup() {
  Serial.begin(9600);

  leftServo.attach(6);
  rightServo.attach(5);

  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(LEFT_LS, INPUT);
  pinMode(RIGHT_LS, INPUT);

//  leftServo.write(90);
//  rightServo.write(90);
  

}

void loop() {
  
  for (pos = 0; pos <= 180; pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    readLS();
    leftServo.write(pos);
    rightServo.write(pos);
    delay(15);                       // waits 15ms for the servo to reach the position
  }
  for (pos = 180; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
    readLS();
    leftServo.write(pos);
    rightServo.write(pos);
    delay(15);                       // waits 15ms for the servo to reach the position
  }
}

void readLS(){
  leftLS = analogRead(LEFT_LS);
  rightLS = analogRead(RIGHT_LS);
  //Write ADC values to serial
  Serial.print(rightLS);
  Serial.write(' ');
  Serial.println(leftLS);

  diff = leftLS-rightLS;
  if(diff>0){
    Serial.print("Left LS is brighter and the diff is ");
  } else if(diff < 0){
    Serial.print("Right LS is brighter and the diff is ");
  } else {
    Serial.print("Both sensors are equal and the diff is: ");
  }
  
  Serial.println(diff);
}
