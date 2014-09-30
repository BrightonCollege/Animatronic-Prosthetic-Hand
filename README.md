Animatronic-Prosthetic-Hand
===========================

A project using Arduino to control a robotic hand though a bluetooth connection with a mobile device.

## Comunication Protocol ##

To send data to the arduino over bluetooth you send three bytes. They are all in ASCII.

- `S`: This initates the connection between the Arduino and the phone.
- `0 - 4`: This reprients the finger you want to control. `0` is the Thumb and `4` is the pinky.
- `a - z`: This is the position you want the finger to be in. `a` is relaxed and `z` is tensed.

## Todo List ##

- Create a dictionary with the commands for each gesture that the hand will make to ensure continuity accross platforms.
- Build hand

Bluetooth
---------
- Begin bluetooth code on apps.
- Make secure bluetooth connection to prevent DDoSSing

Bluetooth Todo List for apps:
-----------------------------
- Make stable connection between device and arduino.
- Send a hexacode digit to the arduino and make sure it recieves.
- Adapt UI to send the hexacode digits precisely and efficiently.
- Make sure the connection is private (Stop DDoSSing)
