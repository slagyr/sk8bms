#ifndef OLEDCOMM_H
#define OLEDCOMM_H

#include "common.h"

class OledComm {
public:
    virtual void setup() = 0;

    virtual void sendCommand(uint8_t cmd) = 0;

    virtual void sendData(const uint8_t *data, int size) = 0;

    virtual void beginTransmission() = 0;

    virtual void includeByte(uint8_t b) = 0;

    virtual void endTransmission() = 0;

    virtual uint8_t pmgByte(const uint8_t *bpm, int i) = 0;

    void setInverted(bool inverted) {
        OledComm::inverted = inverted;
    }

    bool isInverted() const {
        return inverted;
    }

protected:

    uint8_t applyInversion(uint8_t g) {
        return inverted ? ~g : g;
    }

private:
    bool inverted = false;
};

#endif
