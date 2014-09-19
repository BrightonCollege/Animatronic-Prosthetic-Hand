// Brighton College Micro-electronic Engineering

// Animatonic Prosthetic Hand

// //
//
// File to be transfured to the Arduino.
// Collects Bluetooth input and outputs to the servos
//
// //

#include <Servo.h>

// Initalise Servo Objects
Servo Thumb_Finger_Servo;
Servo First_Finger_Servo;
Servo Middle_Finger_Servo;
Servo Ring_Finger_Servo;
Servo Pinky_Finger_Servo;

int IncomingByte = 0;

int Thumb_Finger = 0;
int First_Finger = 1;
int Middle_Finger = 2;
int Ring_Finger = 3;
int Pinky_Finger = 4;

void setup() {
    // Attach servos
    // Remember that Servos MUST be attched to pwm pins (marked with a ~)
    Thumb_Finger_Servo.attach(3);
    First_Finger_Servo.attach(5);
    Middle_Finger_Servo.attach(6);
    Ring_Finger_Servo.attach(10);
    Pinky_Finger_Servo.attach(11);
}

void loop() {

}
