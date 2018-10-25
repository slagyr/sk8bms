#ifndef SK8BMS_I2COLEDCOMM_H
#define SK8BMS_I2COLEDCOMM_H

#include <oled/OledComm.h>
#include <Wire.h>


class I2cOledComm : public OledComm {
public:
    I2cOledComm();

    void setup() override;

    void sendCommand(uint8_t cmd) override;

    void sendData(const uint8_t *data, int size) override;

    void beginTransmission() override;

    void includeByte(uint8_t b) override;

    void endTransmission() override;

    uint8_t pmgByte(const uint8_t *bmp, int i) override;

private:
    uint8_t packetSize;
};


#endif
