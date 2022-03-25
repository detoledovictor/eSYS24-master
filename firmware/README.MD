# Overview
I provide the firmware files for eSYS24 hardwares in this directory. This is a [Arduino IDE](https://www.arduino.cc/) project for ST [STM32F103Cx](https://www.st.com/resource/en/datasheet/stm32f103c8.pdf) microcontroller.

This is the full communication system where we have 2 codes, the first one to Send, [Transceiver Code](/firmware/eSWTICH24-v00), the state of 2 buttons and the serial received data. The another one is the [Receiver Code](/firmware/eCONTROL24-v00), it will toggle the relays state in accordance with the received data button, and will show in the oLED display the serial data received.

###### Note1:
> *In the beginning was the Word, and the Word was with Code LOL!* **(it's a JOKE)**<br />
One of the parameters, the principal, of this project was send 500kB file from one to other devices. Is it impossible?  **NO!** We only need to take some careful... why?! Because NRF24L01 can send only 32Byte per message, so if you wanna send a large message you'll need break it in a little pieces.
As we can see the dataRate of transmission can be seted in the line code
```radio.setDataRate( RF24_2MBPS );```.
With this,send several messages, with 32kBytes, will not take some time.

###### Note2:
> The libs are essentials for this project, to make oLED works fine in the SMT32F103 I need the [Adafruit_SSD1306](https://github.com/adafruit/Adafruit_SSD1306) and the [Adafruit-GFX](https://github.com/adafruit/Adafruit-GFX-Library) on v1.7.2 *yes, I need downgrade the version.* <br />
> For the radio works properly, I need to use the [TMRh20](https://github.com/nRF24/RF24) RF24 lib. All the libs are available to download inside the codes files.

###### Note3:
> The codes are developed and test in a controled ambient, so... ***it works on my machine*** ```¯\_(ツ)_/¯```  **(it's a JOKE TOO)** <br />
> Like it's a v00 code, unfortunately, it isn't bugs free, if you download it and realise some bug tell me and let's together resolve it.


## How to Use
To use this follow these steps:
- Download this repository.
- Download [Arduino IDE](https://www.arduino.cc/en/software) software.
- Make sure to download STM32 boards package .[here](https://github.com/stm32duino/Arduino_Core_STM32) and install it.
- Import the code in the IDE and have FUN.
