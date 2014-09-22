// Brighton College Micro-electronic Engineering

// Animatonic Prosthetic Hand

// //
//
// File to be transferred to the Arduino.
// Collects Bluetooth input and outputs to the servos
//
// //

#include <Servo.h>
#define angle(Byte) map(Byte, 'a', 'z', 1, 179) // TODO: rename "Byte" to not use uppercase (is a reserved word)


// Servo Setup
Servo fingers_servo[5];

const char FINGERS_NAME[][7] = { "Thumb", "Index", "Middle", "Ring", "Pinky" };
/* not sure if char[][] works but it should reduce resource consumption.
   if doesn't work, switch to String[].*/


// Communication Constants and Variables
const int START_BYTE  = 'S';
//const int END_BYTE = '\n';
const int BAUD        = 9600;

void setup() {
  // Attach Servos
  // Remember they can only be attached on PWM pins, marked with a "~"
  const int PINS[] = { 3, 5, 6, 10, 11 };
  int i;
  for(i=0; i<5; i++) {
    fingers_servo[i].attach(PINS[i]);
    fingers_servo[i].write(1);
  }
  // Setup Bluetooth serial line
  Serial.begin(BAUD); // Baud = 9600 bps
}

void loop() {
  int finger_byte = 0;
  int angle_byte = 0;
  
  // Feel free to change this back, thought it was neater...
  // Assumes the server knows what it's doing though
  
  while (Serial.read() != START_BYTE) {} // Wait for the start byte
  while (Serial.available() < 2) {} // Wait for the buffer to fill
  finger_byte = Serial.read();
  angle_byte = Serial.read();

  // Impliment an END_BYTE
  
  // TODO: Verification
  // finger_byte range 48 - 52
  // angle_byte range 97 - 122
  
  // TODO: What if someone accidentally entered two bytes and pressed enter?
  
  int idx = finger_byte - '0'; // convert char to the int it represents
  // '0'=thumb, '1'=index, ... , '4'=pinky
  if(0<idx || idx>4) {
    // TODO: handle error!
    return;
  }
  
  fingers_servo[idx].write(angle(angle_byte));
  Serial.print(FINGERS_NAME[idx]);
  Serial.print(" moved ");
  Serial.println(angle_byte);
  
  // TODO: send success/failure message?
  // alternative approach:
  // send exit success here, failure in "TODO: handle error!"
    
}
