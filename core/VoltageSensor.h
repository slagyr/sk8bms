#ifndef VOLTAGESENSOR_H
#define VOLTAGESENSOR_H

#include "Hardware.h"

class VoltageSensor {

public:

    VoltageSensor(Hardware *hardware, byte pin, float referenceVoltage);
    virtual float readVoltage();
    virtual float getLastReading();
    Hardware* getHardware();
    byte getPin();
    void setInterferenceAdjustment(float error);
    float getInterferenceAdjustment();

    float getReferenceVoltage() const;

    void setReferenceVoltage(float referenceVoltage);

    void setup();

protected:
    float lastReading = 0;

private:
    byte pin;
    Hardware *hardware;
    float interferenceAdjustment = 0.0;
    float referenceVoltage = 5.0;
};

#endif
