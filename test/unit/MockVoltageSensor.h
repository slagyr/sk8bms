#ifndef MOCKVOLTAGESENSOR_H
#define MOCKVOLTAGESENSOR_H

#include "VoltageSensor.h"

class MockVoltageSensor : public VoltageSensor {
public:
    MockVoltageSensor() : VoltageSensor(nullptr, 0, 0) {}

    MockVoltageSensor(Hardware* hardware, byte pin) : VoltageSensor(hardware, pin, 0) {}

    float readVoltage() override {
        lastReading = volts;
        return volts;
    }

    float volts = 5.0;
};

#endif
