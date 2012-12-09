from pylab import *
import time
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

ion()

tstart = time.time()               # for profiling
x = range(1000)
y = range(1000)
line, = plot(y)
while True: 
    l = ser.readline()
    try:
        l = [float(i) for i in l.split()]
        if len(l) != 3:
            continue
        y = y[1:] + [l[-1]] 
        line.set_ydata(y)  # update the data
        draw()                         # redraw the canvas
    except:
        pass

ioff()
show()
