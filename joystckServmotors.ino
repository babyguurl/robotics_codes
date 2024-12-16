#include <Servo.h>

// Define the pins
const int xPin = A0;  // Joystick X-axis
const int yPin = A1;  // Joystick Y-axis
const int buttonPin = A2;  // Joystick button

const int servoPins[] = {9, 10, 11, 12, 13, 14};  // Pins for the 6 servos
Servo servos[6];  // Create an array of servo objects

void setup() {
  for (int i = 0; i < 6; i++) {
    servos[i].attach(servoPins[i]);  // Attach each servo motor to the digital pin
  }
  pinMode(buttonPin, INPUT_PULLUP);  // Set the button pin as input with pull-up resistor
  Serial.begin(9600);  // Initialize serial communication
}

void loop() {
  int xValue = analogRead(xPin);  // Read the X-axis value
  int yValue = analogRead(yPin);  // Read the Y-axis value

  // Map the joystick values to servo positions
  int servoX = map(xValue, 0, 1023, 0, 180);  // Map X-axis to 0-180 degrees
  int servoY = map(yValue, 0, 1023, 0, 180);  // Map Y-axis to 0-180 degrees

  // Write the servo positions for the first two servos
  servos[0].write(servoX);  // Move the first servo based on X-axis
  servos[1].write(servoY);  // Move the second servo based on Y-axis

  // Set the other servos to specific positions or add your own logic
  servos[2].write(90);  // Move the third servo to 90 degrees
  servos[3].write(45);  // Move the fourth servo to 45 degrees
  servos[4].write(135);  // Move the fifth servo to 135 degrees
  servos[5].write(180);  // Move the sixth servo to 180 degrees

  // Check if the button is pressed
  if (digitalRead(buttonPin) == LOW) {
    for (int i = 0; i < 6; i++) {
      servos[i].write(90);  // Center all servos
    }
    delay(500);  // Wait for half a second
  }
}
