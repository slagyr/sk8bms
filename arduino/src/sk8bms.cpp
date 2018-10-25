#include <Arduino.h>
#include "common.h"
#include <Controller.h>
#include "OLEDDisplay.h"
#include "ArduinoHardware.h"
//#include "EEPROMConfig.h"

OLEDDisplay *display;
ArduinoHardware *hardware;
Rotary *rotary;
Controller *controller;
Mux *mux;
VoltageSensor *sensor;


void rotaryRotated() { rotary->handleRotation(); }

void rotaryClicked() { rotary->handleClick(); }

void setup()
{
    Serial.begin(9600);
    while(!Serial);

    Serial.println("setup");

    display = new OLEDDisplay();
    hardware = new ArduinoHardware();
    rotary = new Rotary(hardware, 2, 4, 3);
    mux = new Mux(hardware, 5, 6, 7, 8, 9);
    sensor = new VoltageSensor(hardware, A3);
    controller = new Controller(hardware, display, rotary, mux, sensor);

    Serial.println("objects created");

    controller->setup();

    Serial.println("setup complete");

    analogReference(EXTERNAL);

    attachInterrupt(digitalPinToInterrupt(rotary->getSW()), rotaryClicked, FALLING);
    attachInterrupt(digitalPinToInterrupt(rotary->getCLK()), rotaryRotated, FALLING);

    Serial.println("leaving setup");
    Serial.print("availableMemory(): ");
    Serial.println(availableMemory());
}

void loop()
{
    controller->tick(millis());
}

//#include "I2cOledComm.h"
//#include "splash.h"
//#include "Canvas.h"
//#include <oled/Oled.h>
//#include <oled/OledFonts.h>
//
//I2cOledComm *comm;
//Oled *oled;
//
//Canvas *canvas;
//
//void setup() {
//
//
//    Serial.begin(9600);
//    while(!Serial);
//
//    Serial.println("SETUP");
//
//    comm = new I2cOledComm();
//    oled = new Oled(comm);
//    oled->setup();
//
//    canvas = new Canvas(64, 32);
//    canvas->drawCircle(32, 16, 15, 1);
//    canvas->drawLine(0, 0, 64, 32, 1);
//    canvas->drawLine(0, 32, 64, 0, 1);
//    canvas->drawLine(32, 0, 32, 32, 1);
//    canvas->drawLine(0, 16, 64, 16, 1);
//}
//
//void loop() {
//    oled->drawBitmap(0, 0, 128, 64, splashBMP);
//
//    delay(3000);
//    oled->clearScreen();
//    delay(1000);
//
//    oled->setFont(oled_font5x7);
//    oled->writeString(0, 0, "Four score and seven");
//    oled->writeString(50, 1, "years ago...");
//    oled->writeString(0, 2, "ABCDEFGHIJKLMNOP");
//    oled->setFont(oled_font6x8);
//    oled->writeString(0, 3, "ABCDEFGHIJKLMNOP");
//    oled->setFont(oled_font8x8);
//    oled->writeString(0, 4, "ABCDEFGHIJKLMNOP");
//    oled->setFont(oled_font5x7);
//    oled->writeString(0, 5, "abcdefghijklmnop");
//    oled->setFont(oled_font6x8);
//    oled->writeString(0, 6, "abcdefghijklmnop");
//    oled->setFont(oled_font8x8);
//    oled->writeString(0, 7, "abcdefghijklmnop");
//
//    delay(3000);
//    oled->clearScreen();
//    delay(1000);
//
//    oled->drawCanvas(0, 0, 64, 32, canvas->getBuffer());
//    oled->drawCanvas(32, 2, 64, 32, canvas->getBuffer());
//    oled->drawCanvas(64, 4, 64, 32, canvas->getBuffer());
//
//    delay(3000);
//    oled->clearScreen();
//    delay(1000);
//
//}