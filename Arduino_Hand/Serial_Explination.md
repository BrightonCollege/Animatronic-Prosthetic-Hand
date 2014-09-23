# Arduino
Serial connection is started with `Serial.begin(9600)`. `9600` is the baud in bits per second.

Now any incoming data will be stored in the buffer.

`Serial.avalible()` returns an `int` value of how many bytes of data are stored in the buffer.

`Serial.read()` reads the buffer byte by byte and returns an `int` value. It returns `-1` if no data is in the buffer.

# Everyone Else
The Arduino code needs to be notified when there is data about to be sent. All the data you will send will be in this format (ASCII):

- `S` Send this number to initiate the system
- `0-4` This selects the finger, referance the Data_Dictionary file in the planning directory.
- `a - z` This is the position you want the finger to be in. 0 is relaxed, 180 is clenched. `a` is relaxed and `z` is tensed.