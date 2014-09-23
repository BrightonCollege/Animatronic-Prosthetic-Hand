Animatronic-Prosthetic-Hand
===========================

A project using Arduino to control a robotic hand though a bluetooth connection with a mobile device.

## Comunication Protocol ##

To send data to the arduino over bluetooth you send three bytes. They are all in ASCII.

- `S`: This initates the connection between the Arduino and the phone.
- `0 - 4`: This reprients the finger you want to control. `0` is the Thumb and `4` is the pinky.
- `a - z`: This is the position you want the finger to be in. `a` is relaxed and `z` is tensed.

## TODO ##

- Create a dictionary with the commands for each gesture that the hand will make to ensure continuity accross platforms.
- Deside on a UI design for both iOS and Android.
- Begin development on the Apps
- Fix issues with the Arduino code, allthough there is a working version for  testing.
- Build hand
- Impliment Bluetooth to the hardware