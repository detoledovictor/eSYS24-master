# Overview
<img src="" alt="PCB 3D View" width="400" align="right"/>

eCONTROL24 hardware designed with a four layers FR4 PCB material. I need four layer to implement the RF Stackup and better power plains that gives me flexibility to control power consumption in various scenarios.

I placed RF paths on the top layer with impedance control for Sub-GHz and 2.4 GHz frequencies.

This PCB is originally designed with KiCAD version 6. All the libraries that required to build the PCB are included in [PCB files](/hardware/Receiver/PCB_Files).

## Layers
After routing wires for all components I placed polygons on each layer. In table below I show all the polygons and their purpose in our design.

| Layer       | Polygons Description |Image  |
| ----------- | ------------------- |-------|
| Top | Connected to GND.<br /> Multiple Polygons.<br /> Includes impedance control for RF paths and all others connections. | <img src="" alt="Top Layer Polygon" width="300" align="center"/>|
| Inner 1 | Connected to GND. | <img src="" alt="Inner Layer 1 Polygon" width="300" align="center"/>|
| Inner 2 | Connected to POWER LINES. | <img src="" alt="Inner Layer 2 Polygon" width="300" align="center"/>|
| Bottom | Connected to GND and to anothoer signal traces. | <img src="" alt="Bottom Layer Polygon" width="300" align="center"/>|

## How to Use
To use PCB files in this directory follow these steps:
- Install the latest version of the [KiCAD](https://www.kicad.org/download/)
- Download and extract [PCB files](/hardware/Receiver/PCB_Files)
- Open project in KiCAD
