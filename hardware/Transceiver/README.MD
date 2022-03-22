# Overview
<img src="/Images/eswitch_3D.PNG" alt="PCB 3D View" width="400" align="right"/>

eSWITCH24 hardware designed with a four layers FR4 PCB material. We need four layer to implement the RF Stackup and better power plains that gives us flexibility to control power consumption in various scenarios.

I placed RF paths on the top layer with impedance control for Sub-GHz and 2.4 GHz frequencies.

This PCB is originally designed with Altium Designer version 21. All the libraries that required to build the PCB are included in [PCB files](../hardware/PCB_Files).

## Layers
After routing wires for all components I placed polygons on each layer. In table below I show all the polygons and their purpose in our design.

| Layer       | Polygons Description |Image  |
| ----------- | ------------------- |-------|
| Top | Connected to GND.<br /> Multiple Polygons.<br /> Includes impedance control for RF paths and all others connections. | <img src="/Images/eswitch_top.PNG" alt="Top Layer Polygon" width="300" align="center"/>|
| Inner 1 | Connected to GND. | <img src="/Images/eswitch_mid1.PNG" alt="Inner Layer 1 Polygon" width="300" align="center"/>|
| Inner 2 | Connected to POWER LINES. | <img src="/Images/eswitch_mid2.PNG" alt="Inner Layer 2 Polygon" width="300" align="center"/>|
| Bottom | Connected to GND. | <img src="/Images/eswitch_bottom.PNG" alt="Bottom Layer Polygon" width="300" align="center"/>|

## How to Use
To use PCB files in this directory follow these steps:
- Install the latest version of the [Altium Designer](https://www.altium.com/products/downloads)
- Download and extract [PCB files](../hardware/PCB_Files)
- Open project in Altium Designer
