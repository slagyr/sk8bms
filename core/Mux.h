#ifndef MUX_H
#define MUX_H


#include "Hardware.h"

class Mux {

public:
    Mux(Hardware* hardware, byte enablePin, byte a0, byte a1, byte a2, byte a3);

    void setup();

    Hardware *getHardware() const;

    byte getEnablePin() const;

    byte getA0() const;

    byte getA1() const;

    byte getA2() const;

    byte getA3() const;

    bool isEnabled() const;

    void enable();

    void disable();

    void select(byte input);

    void updateSelectorPins(byte i);

private:
    Hardware* hardware;
    byte enablePin;
    byte a0;
    byte a1;
    byte a2;
    byte a3;
    bool enabled = false;
};


#endif
