# Overview
<img src="/Images/econtrol_3Da.PNG" alt="PCB 3D View" width="500" align="right"/>

eCONTROL24 hardware designed with a four layers FR4 PCB material. I need four layer to implement the RF Stackup and better power plains that gives me flexibility to control power consumption in various scenarios.

I placed RF paths on the top layer with impedance control for Sub-GHz and 2.4 GHz frequencies.

For simplify the manufacture, I selected for the great part of passive componnents 0603 package, it's more easy to hand soldering. Otherwise, I had to use 0402 passive componnets to the RF path and for the USB Bridge filter (**ONLY FOR OPTIMIZE SPACE**).<br />

To communicate PC USB with the MCU, I used the brigde [CP2102](https://www.silabs.com/documents/public/data-sheets/cp2102n-datasheet.pdf) it's more powerful and trustworthy than the CH341SER (used in the Arduino's board).<br />

Here we've a DC/DC converter, for this I used the [TPS564201](https://www.ti.com/lit/ds/symlink/tps564201.pdf?ts=1647973921264&ref_url=https%253A%252F%252Fwww.ti.com%252Fproduct%252FTPS564201%253FkeyMatch%253DTPS564201DDCR%2526tisearch%253Dsearch-everything%2526usecase%253DOPN)  Synchronous Step-Down Voltage Regulator <br />

As we need an external power supply, the polarity protection is necessary, so the [FDN340P](https://www.onsemi.com/pdf/datasheet/fdn340p-d.pdf) will help us in this part.

To show the data received via RF, an [oLED 0.96inch](https://www.vishay.com/docs/37902/oled128o064dbpp3n00000.pdf) will be soldered in the bottom, how it uses the I2C communication, only 2 pins of the MCU are used to show the data, and why not debug too?!

This PCB is originally designed with KiCAD version 6. All the files that required to build the PCB are included in [PCB files](/hardware/Receiver/PCB_Files).

## Layers
After routing wires for all components I placed polygons on each layer. In table below I show all the polygons and their purpose in our design.

| Layer       | Polygons Description |Image  |
| ----------- | ------------------- |-------|
| Top | Connected to GND.<br /> Multiple Polygons.<br /> Includes impedance control for RF paths.<br />and all others connections. | <img src="/Images/econtrol_top.PNG" alt="Top Layer Polygon" width="300" align="center"/>|
| Inner 1 | Connected to GND. | <img src="/Images/econtrol_mid1.PNG" alt="Inner Layer 1 Polygon" width="300" align="center"/>|
| Inner 2 | Connected to POWER LINES. | <img src="/Images/econtrol_mid2.PNG" alt="Inner Layer 2 Polygon" width="300" align="center"/>|
| Bottom | Connected to GND.<br />and to anothoer signal traces. | <img src="/Images/econtrol_bottom.PNG" alt="Bottom Layer Polygon" width="300" align="center"/>|

## How to Use
To use PCB files in this directory follow these steps:
- Install the latest version of the [KiCAD](https://www.kicad.org/download/)
- Download and extract [PCB files](/hardware/Receiver/PCB_Files)
- Open project in KiCAD
