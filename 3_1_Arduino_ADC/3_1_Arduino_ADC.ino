#define LEFT_LS A0
#define RIGHT_LS A1
int leftLS, rightLS, diff;

void setup() {
  //Initialise pin modes and serial
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(LEFT_LS, INPUT);
  pinMode(RIGHT_LS, INPUT);
  Serial.begin(9600);
}
void loop() {
  //Read both input voltages
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
  
  delay(1000);
}
