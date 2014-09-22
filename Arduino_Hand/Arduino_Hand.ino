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
/*int RX_Finger_Byte = 0;
int RX_Angle_Byte = 0;*/ // moved to loop() as scope does not need to be global

void setup() {
  // Attach Servos
  // Remember they can only be attached on PWM pins, marked with a "~"
  /*thumb_servo.attach(3);
  index_servo.attach(5);
  middle_servo.attach(6);
  ring_servo.attach(10);
  pinky_servo.attach(11);*/
  const int PINS[] = { 3, 5, 6, 10, 11 };
  int i;
  for(i=0; i<5; i++) {
    fingers_servo[i].attach(PINS[i]);
  }
  
  // Setup Bluetooth serial line
  Serial.begin(BAUD); // Baud = 9600 bps
  
  // Initalise Servo Positions
  for(i=0; i<5; i++) {
    fingers_servo[i].write(1);
  } // Question: can this loop be merged to the previous loop?
  
  /*Thumb_Finger_Servo.write(1);
  Index_Finger_Servo.write(1);
  Middle_Finger_Servo.write(1);
  Ring_Finger_Servo.write(1);
  Pinky_Finger_Servo.write(1);*/
}

void loop() {
  int start_byte;
  int RX_finger_byte = 0;
  int RX_angle_byte = 0;
  /*************************************************************************
   * Question: any significance in using capitals for RX?                  *
   * If not, should change to lower case to conform to coding style.       *
   *************************************************************************/
  // Only run if there is data in the buffer
  if (Serial.available() >= 3) {
    start_byte = Serial.read();
    RX_finger_byte = Serial.read();
    RX_angle_byte = Serial.read();
    
    if(start_byte != START_BYTE) { // looks confusing, TODO: rename start_byte
      // TODO: handle error!
      return;
    }
    
    // Note: a good way to clear the input buffer is to define an end_byte
    // '\n' should be sufficient for this usage
    
    // TODO: Verification
    
    // TODO: What if someone accidentally entered two bytes and pressed enter?
    
    /*switch(RX_finger_byte) {
      case thumb_byte:
        thumb_servo.write(angle(RX_angle_byte));
        Serial.println("Thumb Moved");
        break;
      case index_byte:
        index_servo.write(angle(RX_angle_byte));
        Serial.println("Index Moved");
        break;
      case middle_byte:
        middle_servo.write(angle(RX_angle_byte));
        Serial.println("Middle Moved");
        break;
      case ring_byte:
        ring_servo.write(angle(RX_angle_byte));
        Serial.println("Ring Moved");
        break;
      case pinky_byte:
        Pinky_Finger_Servo.write(angle(RX_angle_byte));
        Serial.print("Pinky Moved ");
        Serial.println(RX_angle_byte);
        break;
    }*/
    
    int idx = RX_finger_byte - '0'; // convert char to the int it represents
    // '0'=thumb, '1'=index, ... , '4'=pinky
    if(0<idx || idx>4) {
      // TODO: handle error!
      return;
    }
    
    fingers_servo[idx].write(angle(RX_angle_byte));
    Serial.print(FINGERS_NAME[idx]);
    Serial.print(" moved ");
    Serial.println(RX_angle_byte);
    
    // TODO: send success/failure message?
    // alternative approach:
    // send exit success here, failure in "TODO: handle error!"
    
  }
}

/*int Angle(int Byte) {
  int Angle = map(Byte, 97, 122, 1, 179);
  return Angle;
}*/ // moved to top as #define, should reduce runtime resources cosumption
