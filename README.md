## eSYS24 - Overview
<img src="Images/union_boards.PNG" alt="Both Boards" width="321" height="250" align="right"/>

Electronic System based on 2.4GHz communication.<br /> The Project is developed using the most popular GHz transceiver in the market, the [NRF24L01](https://www.mouser.com/datasheet/2/297/nRF24L01_Product_Specification_v2_0-9199.pdf),it enables us to have a fast link (**up to 2Mbps**) and without a PA/LNA we've a wirelles range, *open-air gap*, up to 100m. All these fetures are controlled by [STM32F103Cx](https://www.st.com/resource/en/datasheet/stm32f103c8.pdf).

### Hardware
eSWITCH24 and eCONTROL24 schematic is in [hardware](/hardware). You can download PCB [Transceiver](/hardware/Transceiver/PCB_Files) and [Receiver](/hardware/Receiver/PCB_Files) designs files to build your eSYSTEM fully. If you'll fabricate the boards, I recommend use the [JLC7628 Stackup](https://cart.jlcpcb.com/impedance?_ga=2.116811712.798095935.1647969093-664896489.1639745533) from JLCPCB.



### Firmware
Both Codes were written in the Arduino IDE. The Codes and the libs are available to download [here](/firmware).

The firmware was based in be usefull, it's not a *Rubik's cube*, the method to use is Plug N' Play, press a button to toggle the load, type a message and see it in the other side.

### Images
Some pictures are available in this file to create a Spoiler of the project. <br /><br /><br />


###### Note:
To test the codes and also de hardware I developed this prototype using a breadBoard and some jumpers. <br />
To simulate the load, and to fit it in the board, I used a "traffic lights" board. In the other side to send the commands I used two classical tactile switch with a green button.<br />
The codes were burned in the *PluePill board* using a STLINK-V2 and the STM32CubeProgrammer, the serial communication were tested using a CP2102 sticker pluged in ```HardwareSerial Serial1(PA10,PA9) //RXD, TXD```.<br />



![Prototype](/Images/prototype_BreaBoard.jpg)<br />


###### If you are interested in building your own *Electronic System based on 2.4GHz* based on this project, feel free to change the PCB and the Codes file with your own application. Just remember to give some credit.
