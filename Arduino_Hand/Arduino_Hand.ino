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

const int Baud = 9600;
int FingerByte = 0;
int AngleByte = 0;

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
    // Setup Bluetooth serial line
    Serial.begin(Baud); // Baud = 9600 bps
}

void loop() {
    // Note: Could do with some verification of incoming data.
    // Only run if there is data in the buffer
    if (Serial.available() > 0){ 
        // Only run if there is the connection signal
        if (Serial.read() == 255) {
            IncomingByte = Serial.read();
            if (IncomingByte == Thumb_Finger) {
                Thumb_Finger_Servo.write(Serial.read());
            } else if (IncomingByte == First_Finger) {
                First_Finger_Servo.write(Serial.read());
            } else if (IncomingByte == Middle_Finger) {
                Middle_Finger_Servo.write(Serial.read());
            } else if (IncomingByte == Ring_Finger) {
                Ring_Finger_Servo.write(Serial.read());
            } else if (IncomingByte == Pinky_Finger) {
                Pinky_Finger_Servo.write(Serial.read());
            FingerByte = Serial.read();
            AngleByte = Serial.read();
            // Correction
            if (AngleByte == 0) {AngleByte = 1;}
            if (AngleByte == 180) {AngleByte = 179;}
            }
         }
    }
}
