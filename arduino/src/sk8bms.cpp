#include <Arduino.h>
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

int availableMemory() {
    int size = 2048; // Use 2048 with ATmega328
    byte *buf;

    while ((buf = (byte *) malloc(--size)) == NULL)
        ;

    free(buf);

    return size;
}

void setup()
{
    Serial.begin(9600);
    while(!Serial);

    Serial.println("setup");

    display = new OLEDDisplay();
    hardware = new ArduinoHardware();
    rotary = new Rotary(hardware, 1, 4, 0);
    mux = new Mux(hardware, 8, 9, 10, 11, 12);
    sensor = new VoltageSensor(hardware, A5);
    controller = new Controller(hardware, display, rotary, mux, sensor);

    controller->setup();

    analogReference(EXTERNAL);

    attachInterrupt(digitalPinToInterrupt(rotary->getSW()), rotaryClicked, FALLING);
    attachInterrupt(digitalPinToInterrupt(rotary->getCLK()), rotaryRotated, FALLING);

    Serial.println("leaving setup");
    Serial.print("availableMemory(): ");
    Serial.println(availableMemory());
}

void loop()
{
    Serial.println("loop start");
    controller->tick(millis());
}

uint8_t x;