// swift code for original hand fucntions

import UIKit

//fuction which connects to bluetooth to change finger position
func changePostition(Finger: Angle)
{
    bluetoothSend(Channel)
    bluetoothSend(Finger)
    bluetoothSend(Angle)
}

//fuction which enables user to send gestures
func doGesture(Gesture)
{
    switch Gesture.lowercaseString {
    
    case "rock":
        changePostition(Thumb_Finger, 180)
        changePostition(First_Finger, 180)
        changePostition(Middle_Finger,180)
        changePostition(Ring_Finger, 180)
        changePostition(Pinky_Finger, 180)
    case "paper":
        changePostition(Thumb_finger, 0)
        changePostition(First_Finger, 0)
        changePostition(Middle_finger, 0)
        changePostition(Ring_Finger, 0)
        changePostition(Pinky_Finger, 0)
    case "scissors":
        changePostition(Thumb_Finger, 180)
        changePostition(First_Finger, 0)
        changePostition(Middle_Finger, 0)
        changePostition(Ring_Finger, 180)
        changePostition(Pinky_Finger, 180)
    default:
        //Handle Error
        pass
    }
}

//fuction which returns hand to inital position
func initPosition()
{
    changePostition(Thumb_Finger, 0)
    changePostition(First_finger, 0)
    changePostition(Middle_Finger, 0)
    changePostition(Ring_Finger, 0)
    changePostition(Pinky_Finger, 0)
}


