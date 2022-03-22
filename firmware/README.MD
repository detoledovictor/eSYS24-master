# Overview
I provide the firmware files for eSYS24 hardwares in this directory. This is a [Arduino IDE](https://www.arduino.cc/) project for ST [STM32F103Cx](https://www.st.com/resource/en/datasheet/stm32f103c8.pdf) microcontroller.

This is the full communication system where we have 2 codes, the first one to Send, Transceiver Code, the state of 2 buttons and the serial received data. The another one is the Receiver Code, it will toggle the relays state in accordance with the received data button, and will show in the oLED display the serial data received.

## How to Use
To use this follow these steps:
- Download this repository
- Download [Arduino IDE](https://www.arduino.cc/en/software) software
- Make sure to download STM32 boards package .[here](https://github.com/stm32duino/Arduino_Core_STM32) and install it
- Import the code in the IDE and have FUN.
