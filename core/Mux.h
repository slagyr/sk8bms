#ifndef MUX_H
#define MUX_H


#include "Hardware.h"

class Mux {

public:
    Mux(Hardware* hardware, uint8_t enablePin, uint8_t a0, uint8_t a1, uint8_t a2, uint8_t a3);

    void setup();

    Hardware *getHardware() const;

    uint8_t getEnablePin() const;

    uint8_t getA0() const;

    uint8_t getA1() const;

    uint8_t getA2() const;

    uint8_t getA3() const;

    bool isEnabled() const;

    void enable();

    void disable();

    void select(uint8_t input);

    void updateSelectorPins(uint8_t i);

private:
    Hardware* hardware;
    uint8_t enablePin;
    uint8_t a0;
    uint8_t a1;
    uint8_t a2;
    uint8_t a3;
    bool enabled = false;
};


#endif
