// Brighton College Micro-electronic Engineering

// Animatonic Prosthetic Hand

// //
//
// File to be transferred to the Arduino.
// Collects Bluetooth input and outputs to the servos
//
// //

#include <Servo.h>
#define angle(ch) map(ch, 'a', 'z', 1, 165) // Angle adjustment required

#define DEBUG 1
#define DEBUG_PRINT(msg)       \
    if(DEBUG) {                \
      Serial.print("DEBUG: "); \
      Serial.println(msg);     \
    } else // consumes semicolon, not a bug

// Servo Setup
Servo fingers_servo[5];
const char FINGERS_NAME[][7] = { "Thumb", "Index", "Middle", "Ring", "Pinky" };

// Communication Constants
const byte START_BYTE  = 'S';
const int BAUD         = 9600;

void setup() {
  // Attach and Initalise Servos
  const int PINS[] = { 3, 5, 6, 10, 11 };
  int i;
  for(i=0; i<5; i++) {
    fingers_servo[i].attach(PINS[i]);
    fingers_servo[i].write(1);
  }
  // Setup Bluetooth serial line
  Serial.begin(BAUD);
}

void loop() {
  byte finger_byte = 0;
  byte angle_byte = 0;
  
  while(Serial.read() != START_BYTE); // Wait for the start byte
<<<<<<< HEAD

  unsigned long start_time_ms = millis();
  unsigned long input_timeout_ms = 1000;
  
  while(Serial.available() < 2) {
    if(millis() - start_time_ms >= input_timeout_ms) {
      // Timeout
      DEBUG_PRINT("Timeout!")
      Serial.write("t")
      return;
    }
  }
  
  finger_byte = Serial.read();
=======
  char input[3] = { 0, 0, 0 };
  if(Serial.readBytes(input, 2) < 2) {
    // TODO: handle input timeout error
    return;
  }
  finger_byte = input[0];
  angle_byte = input[1];
>>>>>>> FETCH_HEAD
  DEBUG_PRINT(finger_byte);
  DEBUG_PRINT(angle_byte);
  
  int idx = finger_byte - '0'; // convert char to the int it represents
<<<<<<< HEAD
=======
  // '0'=thumb, '1'=index, ... , '4'=pinky

>>>>>>> FETCH_HEAD
  DEBUG_PRINT(idx)
  if(0 < idx || idx > 4) {
    // Finger is out of range
    DEBUG_PRINT("finger_byte out of range!")
    Serial.write("f")
    return;
  }

  if(angle_byte < 'a' || angle_byte > 'z') {
    // Angle is out of range
    DEBUG_PRINT("angle_byte out of range!")
    Serial.write("a")
    return;
  }
  
  fingers_servo[idx].write(angle(angle_byte));
  Serial.print(FINGERS_NAME[idx]);
  Serial.print(" moved to ");
  Serial.println(angle(angle_byte));
}

