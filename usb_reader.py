import serial
import sys

# Read in the command line arguments
if len(sys.argv) < 2:
    print "Usage: usb_reader PORT [SPEED]"
    sys.exit(1)

port = sys.argv[1]
if len(sys.argv) >= 3:
    speed = sys.argv[2]
else:
    speed = 115200

# Read Arudinos output
ser = serial.Serial(port, speed)
while True:
    print ser.readline()
