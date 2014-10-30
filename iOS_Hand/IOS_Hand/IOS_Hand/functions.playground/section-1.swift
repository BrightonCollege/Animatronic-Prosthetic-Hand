// Playground - noun: a place where people can play

import UIKit

//
func changePostition(Finger: angle)
{
    bluetoothSend(Channel)
    bluetoothSend(Finger)
    bluetoothSend(Angle)
}

func doGesture(gesture){
    Gesture = Gesture.lowercaseString
    
    if Gesture == "rock"
    {
        changePostition(Thumb_Finger, 180)
        changePostition(First_Finger, 180)
        changePostition(Middle_Finger,180)
        changePostition(Ring_Finger, 180)
        changePostition(Pinky_Finger, 180)
    }
    
    if Gesture == "paper"
    {
        changePostition(Thumb_finger, 0)
        changePostition(First_Finger, 0)
        changePostition(Middle_finger, 0)
        changePostition(Ring_Finger, 0)
        changePostition(Pinky_Finger, 0)
    }
    
    if Gesture == "scissors"
    {
        changePostition(Thumb_Finger, 180)
        changePostition(First_Finger, 0)
        changePostition(Middle_Finger, 0)
        changePostition(Ring_Finger, 180)
        changePostition(Pinky_Finger, 180)
    }
    
}


