
/*******************************************************************************
  eCONTROL24
  Is part of the eSYS24, this module is the responsable for Receive the data
  transmited over the air and execute the functions pre defined here.
    (v1.0 - 23/03/22)

  Operational code from board <eCONTROL24> in which we have the control over 4
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

//Libraries ---------------------------------
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
// ---------------------------------------------

//DEBUG habilitation
//Uncomment if necessary DEBUG
//#define DEBUG;

//PCB Control PINS
#define RLA PA1
#define RLB PA2

//oLED Control
#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

//Radio Control
RF24 radio(PB0, PA1); // CE, CSN -- SPI bus plus pins
const byte RFaddress[][6] = {"0x012"};

//System variables
int reader[2];
int bta_state = 0;
int btb_state = 0;

//Control Arrays
const int output_pins[] = {RLA, RLB};
const int output_size = sizeof(output_pins) / sizeof(output_pins[0]);

char text[500] = "";
String StrBuffer = "";

void setup() {

  //Controls Configuration Startup
  for ( int i = 0; i < output_size; i++) {
    pinMode(output_pins[i], OUTPUT);
  }

  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { // Address 0x3C for 128x64
    Serial.println(F("SSD1306 allocation failed"));
    for (;;) {
      toggle(RLA);
      delay(100);
    }
  }

  radio.begin();
  radio.setDataRate( RF24_2MBPS );
  radio.openReadingPipe(0, RFaddress[0]);
  radio.setPALevel(RF24_PA_MAX);       // Set with RF24_PA_MIN (-18 dBm) || RF24_PA_LOW (-12 dBm) || RF24_PA_HIGH (-6 dBm) || RF24_PA_MAX (0dBm)
  radio.startListening();

#ifdef DEBUG
  Serial.begin(9600);
  Serial.print(F("eSYS24 - Electronic System based on 2.4GHz communication \n"));
  Serial.print(F("eCONTROL24 - Board to actuate loads over the air and show text message \n"));
  Serial.print(F("\t v1.0 - 23/03/22 \n"));
  Serial.print("\t");
  Serial.print("DEBUG Mode Activated, here are all the messages:");
  Serial.print("\n");
#endif

  display.clearDisplay();
  toPrint(1, 0, 0, "eSYS24 - Board Model:     eCONTROL24");
  toPrint(1, 0, 30, "Menssagem :");

}
void loop() {

  newPrint();

  if (radio.available()) {
    radio.read(&text, sizeof(text));
    radio.read(&reader, sizeof(reader));

    if (reader[1] == 0x007E) {
      toggle(RLA);
      newPrint();
#ifdef DEBUG
      Serial.print("message received:\t");
      Serial.println(text);
      Serial.print("cmd to BTA received:\t");
      Serial.println(reader[1]);
#endif
      delay(100);
    }

    if (reader[0] == 0x007F) {
      toggle(RLB);
      newPrint();
#ifdef DEBUG
      Serial.print("message received:\t");
      Serial.println(text);
      Serial.print("cmd to BTB received:\t");
      Serial.println(reader[0]);
#endif
      delay(100);
    }
    display.clearDisplay();
    delay(10);
    toPrint (1, 0, 40, text);
    delay(500);
  }

  else {

   // Serial.println("Radio failure detected, restarting radio");
  }

  delay(5);
}

void newPrint() {
  display.clearDisplay();
  toPrint(1, 0, 0, "eSYS24 - Board Model:     eCONTROL24");
  toPrint(1, 0, 30, "Menssagem :");
  toPrint(1, 0, 40, "");
  StrBuffer += String(text);
  char CharBuffer[50];
  StrBuffer.toCharArray(CharBuffer, 50);
  toPrint(1, 0, 40, CharBuffer);
  StrBuffer = "";

}

void toPrint(int text, int x, int y, const char * c) {
  display.setTextSize(text);
  display.setTextColor(WHITE);
  display.setCursor(x, y);
  display.println(c);
  display.display();
}

void toggle(int pin) {
  digitalWrite(pin, !digitalRead(pin));
}
