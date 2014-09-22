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

/****************************************************************
 * Question: Use byte or uint8_t datatypes instead of int?      *
 ****************************************************************/

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
  }
}
