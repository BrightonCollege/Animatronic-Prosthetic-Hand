// Brighton College Micro-electronic Engineering

// Animatonic Prosthetic Hand

// //
//
// File to be transfured to the Arduino.
// Collects Bluetooth input and outputs to the servos
//
// //

#include <Servo.h>

// Servo Setup
Servo Thumb_Finger_Servo;
Servo Index_Finger_Servo;
Servo Middle_Finger_Servo;
Servo Ring_Finger_Servo;
Servo Pinky_Finger_Servo;


// Communication Constants and Variables
const int Start_Byte = 83; // "S"
const int Thumb_Finger_Byte = 48; // "0"
const int Index_Finger_Byte = 49; // "1"
const int Middle_Finger_Byte = 50; // "2"
const int Ring_Finger_Byte = 51; // "3"
const int Pinky_Finger_Byte = 52; // "4"
const int Baud = 9600;
int RX_Finger_Byte = 0;
int RX_Angle_Byte = 0;

void setup() {
  // Attach Servos
  // Remember they can only be attached on PWM pins, marked with a "~"
  Thumb_Finger_Servo.attach(3);
  Index_Finger_Servo.attach(5);
  Middle_Finger_Servo.attach(6);
  Ring_Finger_Servo.attach(10);
  Pinky_Finger_Servo.attach(11);
  
  // Setup Bluetooth serial line
  Serial.begin(Baud); // Baud = 9600 bps
  
  // Initalise Servo Positions
  Thumb_Finger_Servo.write(1);
  Index_Finger_Servo.write(1);
  Middle_Finger_Servo.write(1);
  Ring_Finger_Servo.write(1);
  Pinky_Finger_Servo.write(1);
}

void loop() {
  // Only run if there is data in the buffer
  if (Serial.available() > 0) {
    // Only run if there is a connection signal
    if (Serial.read() == Start_Byte) {
      Serial.println("Message Receved");
      delay(500);
      // Read
      RX_Finger_Byte = Serial.read();
      delay(500);
      RX_Angle_Byte = Serial.read();
      Serial.println(RX_Finger_Byte);
      Serial.println(RX_Angle_Byte);
      Serial.println("Angle Byte in Degrees:");
      Serial.println(Angle(RX_Angle_Byte));
      // Verification
      // Selection
      if (RX_Finger_Byte == Thumb_Finger_Byte) {
        Thumb_Finger_Servo.write(Angle(RX_Angle_Byte));
        Serial.println("Thumb Moved");
        
      } else if (RX_Finger_Byte == Index_Finger_Byte) {
        Index_Finger_Servo.write(Angle(RX_Angle_Byte));
        Serial.println("Index Moved");
        
      } else if (RX_Finger_Byte == Middle_Finger_Byte) {
        Middle_Finger_Servo.write(Angle(RX_Angle_Byte));
        Serial.println("Middle Moved");
        
      } else if (RX_Finger_Byte == Ring_Finger_Byte) {
        Ring_Finger_Servo.write(Angle(RX_Angle_Byte));
        Serial.println("Ring Moved");
        
      } else if (RX_Finger_Byte == Pinky_Finger_Byte) {
        Pinky_Finger_Servo.write(Angle(RX_Angle_Byte));
        Serial.println("Pinky Moved");
      }
    }
  }
}

int Angle(int Byte) {
  int Angle = map(Byte, 97, 122, 1, 179);
  return Angle;
}
