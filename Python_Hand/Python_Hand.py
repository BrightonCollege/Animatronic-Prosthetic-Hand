#!/usr/bin/env python

# Command Line Application for the Control of the Animatronic Prosthetic Hand

# Brighton College - brightoncollege.github.io

# Requires pySerial http://pypi.python.org/pypi/pyserial
try:
    import serial
except ImportError:
    from os import system
    system("wget https://pypi.python.org/packages/source/p/pyserial/pyserial-2.7.tar.gz")
    system("tar -zxvf pyserial-2.7.tar.gz")
    system("cd pyserial-2.7")
    system("sudo python setup.py install")
    import serial

#import platform
#from os import system
#System = platform.system()
#class PlatformError(Exception):
#    def __init__(self, platform): self.platform = platform
#    def __str__(self): return repr(self.platform + " is not supported.")
#if System == "Linux":
#    system("bash PlatformScripts/ubuntu.sh")
#    serialConnection = serial.Serial("/dev/rfcomm4", 115600, timeout=1)
#if System == "Darwin":
#    #serialConnection = serial.Serial("/dev/tty.---", 115600, timeout=1)
#    raise PlatformError(System)
#else:
#    raise PlatformError("Unknown System: " + System)

## Set Baud to 9600
#serialConnection.write("$$$")
#if serialConnection.read(3) == "CMD":
#    serialConnection.write("U,9600,N")
#serialConnection.baudrate = 9600

# Import Gestures
class Gesture():
    def __init__(self, Name, Gesture):
        self.name = Name
        self.gesture = Gesture
Gestures = []
with open("../Assets/gestures.csv", 'r') as File:
    line_number = 0
    for Line in File:
        if line_number != 0:
            Line = Line.split(",")
            Gestures.append(Gesture(Line[0], Line[1:]))
        line_number += 1

#def writeGesture(Gesture):
#    for finger in range(0,4):
#        serialConnection.write(b"S%i%s" % (Finger, Gesture[Finger]))
#    
#def writeFinger(Finger, Angle):
#    if type(Angle) is int:
#        Angle = chr(map(Angle, 0, 180, ord(b"a"), ord(b"z")))
#    if type(Angle) is str:
#        Angle = Angle.lower()
#    serialConnection.write(b"S%i%s" % (Finger, Angle))

if __name__ == '__main__':
    # Print Welcome
    with open("guidata/welcome.txt", 'r') as File:
        for Line in File:
            Line = Line.replace("\n", "")
            print Line
        print ""
    while True:
        user_input = raw_input(">>> ").lower().split(" ")
        if user_input[0] == "--quit":
            quit()
        if user_input[0] == "--help":
            with open("guidata/help.txt", 'r') as File:
                for Line in File:
                    Line = Line.replace("\n", "")
                    print Line
        if user_input[0] == "list":
            try:
                if user_input[1]:
                    if user_input[1] == "gestures":
                        for gesture in Gestures:
                            if "-g" in user_input: suffix = "".join(gesture.gesture)
                            else: suffix = ""
                            print gesture.name, suffix
                    elif user_input[1] == "fingers":
                            for finger in range(0, 5):
                                print str(finger)
                    else:
                        print "[e] No valid type was given."
                        print "[e] `--help` for help."
            except:
                print "[e] Incorrect usage."
                print "[e] `--help` for help."