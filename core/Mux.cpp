#include "Mux.h"


Mux::Mux(Hardware *hardware, byte enablePin, byte a0, byte a1, byte a2, byte a3) {
    this->hardware = hardware;
    this->enablePin = enablePin;
    this->a0 = a0;
    this->a1 = a1;
    this->a2 = a2;
    this->a3 = a3;
}

void Mux::setup() {
    hardware->pinToOutput(enablePin);
    hardware->pinToOutput(a0);
    hardware->pinToOutput(a1);
    hardware->pinToOutput(a2);
    hardware->pinToOutput(a3);
    hardware->setPinLow(enablePin);
    hardware->setPinLow(a0);
    hardware->setPinLow(a1);
    hardware->setPinLow(a2);
    hardware->setPinLow(a3);
}

Hardware *Mux::getHardware() const {
    return hardware;
}


byte Mux::getEnablePin() const {
    return enablePin;
}

byte Mux::getA0() const {
    return a0;
}

byte Mux::getA1() const {
    return a1;
}

byte Mux::getA2() const {
    return a2;
}

byte Mux::getA3() const {
    return a3;
}

bool Mux::isEnabled() const {
    return enabled;
}

void Mux::disable() {
    hardware->setPinLow(enablePin);
    enabled = false;
}

void Mux::enable() {
    hardware->setPinHigh(enablePin);
    enabled = true;
}

void Mux::updateSelectorPins(byte input) {
    if(input % 2 == 1)
        hardware->setPinHigh(a0);
    else
        hardware->setPinLow(a0);
    if(input / 2 % 2 == 1)
        hardware->setPinHigh(a1);
    else
        hardware->setPinLow(a1);
    if(input / 4 % 2 == 1)
        hardware->setPinHigh(a2);
    else
        hardware->setPinLow(a2);
    if(input / 8 % 2 == 1)
        hardware->setPinHigh(a3);
    else
        hardware->setPinLow(a3);
}

void Mux::select(byte input) {
    disable();
    updateSelectorPins(input);
    enable();
}
