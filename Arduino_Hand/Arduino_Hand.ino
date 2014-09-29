// Brighton College Micro-electronic Engineering

// Animatonic Prosthetic Hand

#include <Servo.h>
#include <SoftwareSerial.h>

#define angle(ch) map(ch, 'a', 'z', 1, 165)

#define DEBUG 1
#define DEBUG_PRINT(msg)       \
    if(DEBUG) {                \
      Serial.print("DEBUG: "); \
      Serial.println(msg);     \
    } else // consumes semicolon, not a bug

// Servo Setup
Servo fingers_servo[5];
const char FINGERS_NAME[][7] = { "Thumb", "Index", "Middle", "Ring", "Pinky" };

// Communication Setup
const byte START_BYTE = 'S';
int bluetoothTx = 11;
int bluetoothRx = 12;
SoftwareSerial bluetooth(bluetoothTx, bluetoothRx);

void setup() {
  // Attach and Initalise Servos
  const int PINS[] = { 3, 5, 6, 9, 10 };
  int i;
  for(i=0; i<5; i++) {
    fingers_servo[i].attach(PINS[i]);
    fingers_servo[i].write(1);
  }
  // Setup Bluetooth
  bluetooth.begin(115200);
  bluetooth.print("$");
  bluetooth.print("$");
  bluetooth.print("$");
  delay(100);
  bluetooth.println("U,9600,N"); // Set the baudrate to 9600
  bluetooth.begin(9600);
}

void loop() {
  byte finger_byte = 0;
  byte angle_byte = 0;
  
  while(bluetooth.read() != START_BYTE); // Wait for the start byte

  unsigned long start_time_ms = millis();
  unsigned long input_timeout_ms = 1000;
  
  while(bluetooth.available() < 2) {
    if(millis() - start_time_ms >= input_timeout_ms) {
      // Timeout
      Serial.write("t"); // Write error message
      return;
    }
  }

  char input[3] = { 0, 0, 0 };
  if(bluetooth.readBytes(input, 2) < 2) {
    // Buffer too small
    bluetooth.write("b"); // Write error message
    return;
  }
  
  finger_byte = input[0];
  angle_byte = input[1];
  
  int idx = finger_byte - '0'; // convert char to the int it represents

  if(0 < idx || idx > 4) {
    // Finger is out of range
    bluetooth.write("f"); // Write error message
    return;
  }

  if(angle_byte < 'a' || angle_byte > 'z') {
    // Angle is out of range
    bluetooth.write("a"); // Write error message
    return;
  }
  
  fingers_servo[idx].write(angle(angle_byte)); // Move Servo
}

