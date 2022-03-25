
/*******************************************************************************
  eSWITCH24
  Is part of the eSYS24, this module is the responsable for Transmit the data
  over the air and execute the functions pre defined here.
    (v1.0 - 23/03/22)

  Operational code from board <eSWITCH24> in which we have the control over 4
  the air of 02 Relays and the data string showed in an oLED 0.96" display.
  Here are embbeded the MCU <STM32F103> popularly called as bluepill MCU.

  For the bread board connections and for the final PCB design, the table bellow
  was used to link the NRF24L01 to STM32F103Cx:

  NRF24L01 -> STM32F103 PINOUT
  3.3  GND      3.3  GND
  CSN  CE       PA4  PB0
  MOSI SCK      PA7  PA5
  IRQ  MISO      X   PA6

  Developed by: Victor Nunes (24/03/22).

*******************************************************************************/

//Board Selection Verification
// ---------------------------------------------
#if !defined (STM32F1xx)
#error Este codigo deve ser usado com o STM32F103Cx
#endif
// ---------------------------------------------

//Libraries
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

//DEBUG habilitation
//Uncomment if necessary DEBUG
//#define DEBUG;

//PCB Control PINS
#define BTA PA1
#define BTB PA2

//Radio Control
RF24 radio(PB0, PA4); // CE, CSN -- SPI bus plus pins
const byte RFaddress[][6] = {"0x012"};

//Control Arrays
const int input_pins[] = {BTA, BTB};
const int input_size = sizeof(input_pins) / sizeof(input_pins[0]);

//System variables
volatile byte state_INT1 = LOW;
volatile byte state_INT2 = LOW;
int data[2];
String input = "";


void setup() {

//Controls Configuration Startup
  for ( int i = 0; i < input_size; i++) {
    pinMode(input_pins[i], INPUT_PULLUP);
  }
  Serial.begin(9600);

#ifdef DEBUG
  Serial.print(F("eSYS24 - Electronic System based on 2.4GHz communication \n"));
  Serial.print(F("eSWITCH24 - Board to send signal to activate loads over the air and send text message \n"));
  Serial.print(F("\t v1.0 - 23/03/22 \n"));
  Serial.print(F("\t DEBUG Mode Activated, here are all the messages:"));
  Serial.print("\n");
#endif

  radio.begin();
  radio.setDataRate( RF24_2MBPS );
  radio.openWritingPipe(RFaddress[0]);
  radio.setPALevel(RF24_PA_LOW);       // Set with RF24_PA_MIN (-18 dBm) || RF24_PA_LOW (-12 dBm) || RF24_PA_HIGH (-6 dBm) || RF24_PA_MAX (0dBm)
  radio.stopListening();

  attachInterrupt(BTA, estado1, FALLING);
  attachInterrupt(BTB, estado2, FALLING);

}
void loop() {

  if (state_INT1) {
    const char text[] = "CH_A: Switching State";
    data[1] = 0x007E;
    radio.write(&text, sizeof(text));
    radio.write(data, sizeof(data));

#ifdef DEBUG
    Serial.println("CH_A: Your Button State is LOW");
    Serial.println(data[1]);
#endif
    state_INT1 = !state_INT1;
    data[1] = 0;
  }

  if (state_INT2) {
    const char text[] = "CH_B: Switching State";
    data[0] = 0x007F;
    radio.write(&text, sizeof(text));
    radio.write(data, sizeof(data));

#ifdef DEBUG
    Serial.println("CH_B: Your Button State is LOW");
    Serial.println(data[0]);
#endif
    state_INT2 = !state_INT2;
    data[0] = 0;
  }

   if (Serial.available()) {
     input = Serial.readString();
     char CharBuffer[500];
     input.toCharArray(CharBuffer, 500);
     radio.write(&CharBuffer, sizeof(CharBuffer));

    #ifdef DEBUG
     Serial.println(CharBuffer);
    #endif
    }

  delay(10);
}

//INTERRUPÇÕES ------------------------------------------
void estado1() {
  delay(250);
  state_INT1 = !state_INT1;
}
void estado2() {
  delay(250);
  state_INT2 = !state_INT2;
}
