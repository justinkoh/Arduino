const double pi = 3.141593;
const long INTERVAL = 3800;
long timeNow = 0;
int i = -127;

// taylor sin is a general purpose sin function
// EEbug sin is the one we want
double taylorSin(float x);
int EEEBugSin(int x);

void setup() {
  // Initialize Serial port
  Serial.begin(9600);

  // Set pin 5 as an output pin
  pinMode(5, OUTPUT);

}

void loop() {

  // do nothing while the time is less than this var
  while( micros() < timeNow );

  // add an interval of time to wait/delay for
  timeNow += INTERVAL;
  
  // PWM write the value to the pin
  analogWrite(5, EEEBugSin(i));
//  Serial.println(EEEBugSin(i));

  // increment i
  i++;
  if(i > 127){
    i = -128;
  }

}


// Define functions
double taylorSin(float x){
    double acc = 0;
    double fact, exp;
    int sign = 1;

    for (int i=0; i<5; i++){
        if(i == 0){
            fact = 1;
            exp = x;
        } else {
            fact *= 2*i*(2*i +1);
            exp *= x*x;
            sign *= -1;
        }
        acc += ( sign / fact * exp );
    }
    return acc;
}

// use the built in sin function instead
int EEEBugSin(int x){
  return 127 * sin(pi/128 * x) + 128;
//  return 127 * taylorSin(pi/128 * (float)x) + 128;
}
