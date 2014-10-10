#!/usr/bin/env python

# Mac Application for the Control of the Animatronic Prosthetic Hand

# Brighton College - brightoncollege.github.io
# Harry Beadle, Adrian Lam

# Requires pySerial http://pypi.python.org/pypi/pyserial
try:
    import serial
except ImportError:
    from os import system as consoleRun
    consoleRun("wget https://pypi.python.org/packages/source/p/pyserial/pyserial-2.7.tar.gz")
    consoleRun("tar -zxvf pyserial-2.7.tar.gz")
    consoleRun("cd pyserial-2.7")
    consoleRun("sudo python setup.py install")
    import serial

serialConnection = serial.Serial("/dev/rfcomm4", 9600)

# Gestures
gesturePoint   = ['z','a','z','z','z']
gesturePaper   = ['a','a','a','a','a']
gestureRock    = ['z','z','z','z','z']
gestureSissors = ['z','a','a','z','z']

def changeGesture(Gesture):
    serialConnection.write(b"S0%s" % (Gesture[0]))
    serialConnection.write(b"S1%s" % (Gesture[1]))
    serialConnection.write(b"S2%s" % (Gesture[2]))
    serialConnection.write(b"S3%s" % (Gesture[3]))
    serialConnection.write(b"S4%s" % (Gesture[4]))
    
def changeFinger(Finger, Angle):
    if type(Angle) is int:
        Angle = chr(map(Angle, 0, 180, ord(b"a"), ord(b"z")))
    serialConnection.write(b"S%i%s" % (Finger, Angle))

