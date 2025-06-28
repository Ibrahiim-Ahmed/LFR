#include <AFMotor.h>

// Motor definitions
AF_DCMotor leftMotor(1); // Motor on M1
AF_DCMotor rightMotor(2); // Motor on M2

// Sensor pins
const int sensorPins[] = {A0, A1, A2, A3, A4};
const int numSensors = 5;
int sensorValues[numSensors];

// PID control variables
float Kp = 1.2;  // Proportional gain
float Ki = 0.0;  // Integral gain
float Kd = 0.8;  // Derivative gain
float lastError = 0;
float integral = 0;

// Motor speed settings
int baseSpeed = 150;
int maxSpeed = 255;

void setup() {
  Serial.begin(9600);

  // Set motor speed
  leftMotor.setSpeed(baseSpeed);
  rightMotor.setSpeed(baseSpeed);

  // Initialize sensor pins as input
  for (int i = 0; i < numSensors; i++) {
    pinMode(sensorPins[i], INPUT);
  }
}

void loop() {
  // Read sensor values
  readSensors();

  // Calculate the position of the line
  int linePosition = getLinePosition();

  // Calculate the error
  float error = linePosition - (numSensors - 1) * 500 / 2;

  // Calculate PID terms
  integral += error;
  float derivative = error - lastError;
  float output = Kp * error + Ki * integral + Kd * derivative;
  lastError = error;

  // Calculate motor speeds
  int leftSpeed = constrain(baseSpeed + output, 0, maxSpeed);
  int rightSpeed = constrain(baseSpeed - output, 0, maxSpeed);

  // Set motor speeds
  setMotorSpeed(leftSpeed, rightSpeed);
}

void readSensors() {
  for (int i = 0; i < numSensors; i++) {
    sensorValues[i] = analogRead(sensorPins[i]);
  }
}

int getLinePosition() {
  int weightedSum = 0;
  int sum = 0;

  for (int i = 0; i < numSensors; i++) {
    int value = 1023 - sensorValues[i]; // Invert the reading if needed
    weightedSum += value * i * 1000;
    sum += value;
  }

  return sum == 0 ? (numSensors - 1) * 1000 / 2 : weightedSum / sum;
}

void setMotorSpeed(int leftSpeed, int rightSpeed) {
  leftMotor.setSpeed(leftSpeed);
  rightMotor.setSpeed(rightSpeed);

  if (leftSpeed > 0) {
    leftMotor.run(FORWARD);
  } else {
    leftMotor.run(BACKWARD);
  }

  if (rightSpeed > 0) {
    rightMotor.run(FORWARD);
  } else {
    rightMotor.run(BACKWARD);
  }
}
