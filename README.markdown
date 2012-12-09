#hackbox
####An Arduino project to read the lifebox pulse oximeter sensor signal  

Our project was reverse engineering the LifeBox Pulse Oximeter (http://www.lifebox.org/) to allow high resolution data to be exported to external devices.
We hacked an Arduino into the analogue connection between the sensor and the lifebox. This allows us to read the raw data from the light sensor, and in principal reconstruct the DVP curve (which is useful in diagnosis.)
The Arduino processes this data and then outputs the relevant readings to a PC over a serial connection.
This is useful because Pulse Oximeters are expensive, proprietary closed hardware devices which prohibit useful interoperability and export features - these would allow metastudies of collected data. The DVP curve can already distinguish between young and old persons, and can be used in determining arterial health. Who knows what other secrets it holds? Would individual patients benefit from their doctors being able to visualise this data more easily, for example at higher resolution on existing hardware?
In principal, this project shows that it is not as difficult to get data out of these devices - certainly not as difficult as the manufacturers claim.


####What you need:
- A lifebox pulse oximeter (http://www.lifebox.org/) ($250)
- An Arduino board (http://www.arduino.cc/) (ca. $25)
- Two 9-pin SUB-D connectors, some wire (< $10)



![Schematic](https://raw.github.com/funsim/hackbox/master/pics/schematic.png)

![Wiring](https://raw.github.com/funsim/hackbox/master/pics/wiring.jpg)

####Pins All

- COM 1	| Power	2.8V	Main power rail?
- COM 2 | Data			Led 1 Trigger
- COM 3 | Data			Led 2 Trigger
- COM 4 | Power	1.2V(?)
- COM 5 | Power	2V(?)		Light sensor calibration(?)
- COM 6 | GND
- COM 7 | GND
- COM 8 | Data			Sensor Output
- COM 9 | Data?	1.9		Light sensor calibration(?)

####Pins Used
For this project we only used the GND, the pulsed LED signalsi and light sensor.

