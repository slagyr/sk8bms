#include <Arduino.h>
//#include "common.h"
//#include <Controller.h>
//#include "OLEDDisplay.h"
//#include "ArduinoHardware.h"
////#include "EEPROMConfig.h"
//
//OLEDDisplay *display;
//ArduinoHardware *hardware;
//Rotary *rotary;
//Controller *controller;
//Mux *mux;
//VoltageSensor *sensor;


//void rotaryRotated() { rotary->handleRotation(); }
//
//void rotaryClicked() { rotary->handleClick(); }
//
//void setup()
//{
//    Serial.begin(9600);
//    while(!Serial);
//
//    Serial.println("setup");
//
//    display = new OLEDDisplay();
//    hardware = new ArduinoHardware();
//    rotary = new Rotary(hardware, 2, 4, 3);
//    mux = new Mux(hardware, 5, 6, 7, 8, 9);
//    sensor = new VoltageSensor(hardware, A3);
//    controller = new Controller(hardware, display, rotary, mux, sensor);
//
//    Serial.println("objects created");
//
//    controller->setup();
//
//    Serial.println("setup complete");
//
//    analogReference(EXTERNAL);
//
//    attachInterrupt(digitalPinToInterrupt(rotary->getSW()), rotaryClicked, FALLING);
//    attachInterrupt(digitalPinToInterrupt(rotary->getCLK()), rotaryRotated, FALLING);
//
//    Serial.println("leaving setup");
//    Serial.print("availableMemory(): ");
//    Serial.println(availableMemory());
//}
//
//void loop()
//{
//    controller->tick(millis());
//}

#include "I2cOledComm.h"
#include "splash.h"
#include <oled/Oled.h>
#include <oled/OledFonts.h>

I2cOledComm *comm;
Oled *oled;

void setup() {


    Serial.begin(9600);
    while(!Serial);

    Serial.println("SETUP");

    comm = new I2cOledComm();
    oled = new Oled(comm);
    oled->setup();

//    int i = 0;
//    for(int row = 0; row < 64; row++){
//        for(int col = 0; col < 16; col++){
//            uint8_t b = ada[i++];
////            Serial.print(b & 0b10000000 == 0b10000000 ? "*" : " ");
////            Serial.print(b & 0b01000000 == 0b01000000 ? "*" : " ");
////            Serial.print(b & 0b00100000 == 0b00100000 ? "*" : " ");
////            Serial.print(b & 0b00010000 == 0b00010000 ? "*" : " ");
////            Serial.print(b & 0b00001000 == 0b00001000 ? "*" : " ");
////            Serial.print(b & 0b00000100 == 0b00000100 ? "*" : " ");
////            Serial.print(b & 0b00000010 == 0b00000010 ? "*" : " ");
////            Serial.print(b & 0b00000001 == 0b00000001 ? "*" : " ");
//            Serial.print((b & ( 1 << 1 )) >> 1 ? "*" : " ");
//            Serial.print((b & ( 1 << 2 )) >> 2 ? "*" : " ");
//            Serial.print((b & ( 1 << 3 )) >> 3 ? "*" : " ");
//            Serial.print((b & ( 1 << 4 )) >> 4 ? "*" : " ");
//            Serial.print((b & ( 1 << 5 )) >> 5 ? "*" : " ");
//            Serial.print((b & ( 1 << 6 )) >> 6 ? "*" : " ");
//            Serial.print((b & ( 1 << 7 )) >> 7 ? "*" : " ");
//            Serial.print((b & ( 1 << 8 )) >> 8 ? "*" : " ");
//        }
//        Serial.println("");
//    }
}

void loop() {
    oled->drawBitmap(0, 0, 128, 64, splashBMP);
//    oled->drawBitmap(0, 0, 128, 64, ada);


//    comm->beginTransmission();
//    int bytes = 128 * 64 / 8;
//    for(int i = 0; i < bytes; i++) {
//        comm->includeByte(pgm_read_byte(splashBMP + i));
//    }
//    comm->endTransmission();

    delay(3000);
    oled->clearScreen();
    delay(1000);

//    comm->beginTransmission();
//    int bytesInScreen = 128 * 64 / 16;
//    for(int i = 0; i < bytesInScreen; i++) {
//        comm->includeByte(0x00);
//        comm->includeByte(0xFF);
//    }
//    comm->endTransmission();
//
//    delay(3000);
//    oled->clearScreen();
//    delay(1000);

    oled->setFont(oled_font5x7);
    oled->writeString(0, 0, "Four score and seven");
    oled->writeString(50, 1, "years ago...");
    oled->writeString(0, 2, "ABCDEFGHIJKLMNOP");
    oled->setFont(oled_font6x8);
    oled->writeString(0, 3, "ABCDEFGHIJKLMNOP");
    oled->setFont(oled_font8x8);
    oled->writeString(0, 4, "ABCDEFGHIJKLMNOP");
    oled->setFont(oled_font5x7);
    oled->writeString(0, 5, "abcdefghijklmnop");
    oled->setFont(oled_font6x8);
    oled->writeString(0, 6, "abcdefghijklmnop");
    oled->setFont(oled_font8x8);
    oled->writeString(0, 7, "abcdefghijklmnop");

    delay(6000);
    oled->clearScreen();
    delay(1000);

}