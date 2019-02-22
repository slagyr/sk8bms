#include <Arduino.h>
//#include <avr/pgmspace.h>
//#include "common.h"
//#include <Controller.h>
//#include "OLEDDisplay.h"
//#include "ArduinoHardware.h"
////#include "EEPROMConfig.h"
//
//class HackDisplay : public Display {
//public:
//    void setup() override {
//
//    }
//
//    void splash() override {
//
//    }
//
//    void showCellVoltage(byte i, float voltage) override {
//
//    }
//
//    void showHome() override {
//
//    }
//
//};
//
//Display *display;
//ArduinoHardware *hardware;
//Rotary *rotary;
//Controller *controller;
//
//
//void rotaryRotated() { rotary->handleRotation(); }
//
//void rotaryClicked() { rotary->handleClick(); }
//
//void setup() {
//    Serial.begin(9600);
//    while (!Serial);
//
//    controller = new Controller();
////    display = new HackDisplay();
//    controller->display = new OLEDDisplay();
//    controller->hardware = new ArduinoHardware();
//    controller->rotary = new Rotary(controller->hardware, 2, 4, 3);
//    controller->mux = new Mux(controller->hardware, 5, 6, 7, 8, 9);
//    controller->fetSwitch = new Switch(controller->hardware, 10);
//    controller->capSwitch = new Switch(controller->hardware, 12);
//    controller->balanceSwitch = new Switch(controller->hardware, 11);
//    controller->cellSensor = new VoltageSensor(controller->hardware, A3, 4.74);
//    controller->loadSensor = new VoltageSensor(controller->hardware, A1, 4.74);
//
//    controller->setup();
//
//    controller->hardware->pinToOutput(11);
//    analogReference(EXTERNAL);
////    analogReference(DEFAULT);
//
//    attachInterrupt(digitalPinToInterrupt(rotary->getSW()), rotaryClicked, FALLING);
//    attachInterrupt(digitalPinToInterrupt(rotary->getCLK()), rotaryRotated, FALLING);
//
//    Serial.print("availableMemory(): ");
//    Serial.println(availableMemory());
//}
//
//void loop() {
//    controller->tick(millis());
//}


// the setup function runs once when you press reset or power the board
void setup() {
    // initialize digital pin LED_BUILTIN as an output.
    pinMode(LED_BUILTIN, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
    digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
    delay(1000);                       // wait for a second
    digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
    delay(1000);                       // wait for a second
}