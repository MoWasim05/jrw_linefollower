bool debugMode = false; //controls serial prints

//motor pins
#define PWMa D1
#define lFwd D2 //ain1

#define PWMb D8
#define rFwd D3 //ain2

//button
#define buttonPin D0 //toggles motors
bool lastButton = LOW; //tracking

//led
#define led D4 //active low (HIGH outputs off)

//system states
int buttonState = 0;
int ledState = LOW;

bool motorState = false;

// ir sensor pins (left, centre, right)
const int irPins[3] = {D5, D6, D7}; 

// sensor initialization
int irValDigital[3];
int sensorSum;
int sensorWeight;
int sensorBit;

int weightVal[3] = {10, 20, 30};
int bitWeight[3] = {1, 2, 4};

//PID variables
float linePosition;
float centerPosition = 20;
float error;
float derivative;
float previousError;
int baseSpeed = 150;
float kp = 15;
float kd = 5;

// motor speed parity
int adjustSpeed = 10;

void setup() {
  // control initialization
  pinMode(buttonPin, INPUT);
  pinMode(led, OUTPUT);

  for (int i = 0; i < 3; i++)
    pinMode(irPins[i], INPUT);

  // motor Setup
  pinMode(lFwd, OUTPUT); pinMode(PWMa, OUTPUT);
  pinMode(rFwd, OUTPUT); pinMode(PWMb, OUTPUT);

  Serial.begin(9600);
}

void loop() {
  buttonState = digitalRead(buttonPin);
  readLine(); 

  // Button Toggle Logic
  if (lastButton == LOW && buttonState == HIGH) {
    delay(10); 
    if (digitalRead(buttonPin) == HIGH) {
      motorState = !motorState; 
    }
  }
  lastButton = buttonState;

  // Motor Execution & LED Logic
  if (motorState == true) {
    
    // Junction Indicator Logic
    if (sensorSum == 3) {
      digitalWrite(led, LOW); // Turn LED ON when all 3 sensors see black
    } else {
      digitalWrite(led, HIGH); // Keep LED OFF during normal line following
    }

    // Execute PID
    PIDControl(baseSpeed, kp, kd); 
    
  } else {
    // System OFF state
    digitalWrite(led, HIGH); 
    stop(); 
  }
}