#ifndef MOCKVOLTAGESENSOR_H
#define MOCKVOLTAGESENSOR_H

#include "VoltageSensor.h"

class MockVoltageSensor : public VoltageSensor {
public:
    MockVoltageSensor() : VoltageSensor(nullptr, 0) {}

    MockVoltageSensor(Hardware* hardware, uint8_t pin) : VoltageSensor(hardware, pin) {}

    float readVoltage() override {
        lastReading = volts;
        return volts;
    }

    float volts = 5.0;
};

#endif
