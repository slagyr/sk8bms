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
