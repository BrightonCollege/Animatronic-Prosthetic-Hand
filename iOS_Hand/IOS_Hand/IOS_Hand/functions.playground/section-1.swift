// swift code for original hand fucntions

import UIKit

//fuction which connects to bluetooth to change finger position
func changePostition(Finger: Angle)
{
    bluetoothSend(Channel)
    bluetoothSend(Finger)
    bluetoothSend(Angle)
}

//fuction which enables user to interact playing game 'rock, paper, scissors'
func doGesture(Gesture)
{
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

//fuction which returns hand to inital position
func initPosition()
{
    changePostition(Thumb_Finger, 0)
    changePostition(First_finger, 0)
    changePostition(Middle_Finger, 0)
    changePostition(Ring_Finger, 0)
    changePostition(Pinky_Finger, 0)
}


