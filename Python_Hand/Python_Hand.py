#!/usr/bin/env python

# Mac Application for the Control of the Animatronic Prosthetic Hand

# Brighton College - brightoncollege.github.io
# Harry Beadle, Adrian Lam

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

import platform
from os import system
System = platform.system()
class PlatformError(Exception):
    def __init__(self, platform): self.platform = platform
    def __str__(self): return repr(self.platform + " is not supported.")
if System == "Linux":
    system("bash ")
    serialConnection = serial.Serial("/dev/rfcomm4", 115600, timeout=1)
if System == "Darwin":
    #serialConnection = serial.Serial("/dev/tty.---", 115600, timeout=1)
    raise PlatformError(System)
else:
    raise PlatformError("Unknown System: " + System)

# Set Baud to 9600
serialConnection.write("$$$")
if serialConnection.read(3) == "CMD":
    serialConnection.write("U,9600,N")
serialConnection.baudrate = 9600

# Gestures
gesturePoint   = ['z','a','z','z','z']
gesturePaper   = ['a','a','a','a','a']
gestureRock    = ['z','z','z','z','z']
gestureSissors = ['z','a','a','z','z']
gestureGrasp   = ['z','z','z','z','z']
gestureObscene = ['z','z','a','z','z']
gestureShake   = ['m','m','m','m','m']
gestureRocker  = ['z','a','z','z','a']

def writeGesture(Gesture):
    for finger in range(0,4):
        serialConnection.write(b"S%i%s" % (Finger, Gesture[Finger]))
    
def writeFinger(Finger, Angle):
    if type(Angle) is int:
        Angle = chr(map(Angle, 0, 180, ord(b"a"), ord(b"z")))
    if type(Angle) is str:
        Angle = Angle.lower()
    serialConnection.write(b"S%i%s" % (Finger, Angle))
    
if __name__ == '__main__':
    ## run
    pass