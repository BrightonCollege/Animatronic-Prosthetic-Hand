#!/usr/bin/env python

def changePosition(Finger, Angle):
    bluetoothSend(Channel)
    bluetoothSend(Finger)
    bluetoothSend(Angle)

def doGesture(Gesture):
    Gesture = Gesture.lower()
    if Gesture == "rock":
        changePosition(Thumb_Finger, 180)
        changePosition(First_Finger, 180)
        changePosition(Middle_Finger, 180)
        changePosition(Ring_Finger, 180)
        changePosition(Pinky_Finger, 180)
    if Gesture == "paper":
        changePosition(Thumb_Finger, 0)
        changePosition(First_Finger, 0)
        changePosition(Middle_Finger, 0)
        changePosition(Ring_Finger, 0)
        changePosition(Pinky_Finger, 0)
    if Gesture == "scissors":
        changePosition(Thumb_Finger, 180)
        changePosition(First_Finger, 0)
        changePosition(Middle_Finger, 0)
        changePosition(Ring_Finger, 180)
        changePosition(Pinky_Finger, 180)

def initPosition():
    changePosition(Thumb_Finger, 0)
    changePosition(First_Finger, 0)
    changePosition(Middle_Finger, 0)
    changePosition(Ring_Finger, 0)
    changePosition(Pinky_Finger, 0)
