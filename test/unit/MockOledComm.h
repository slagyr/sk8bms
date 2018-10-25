#ifndef SK8BMS_MOCKOLEDCOMM_H
#define SK8BMS_MOCKOLEDCOMM_H

#include <oled/OledComm.h>
#include <LinkedList.h>
#include <iostream>
using namespace std;

class MockOledComm : public OledComm {
public:
    MockOledComm() {
        commands = new LinkedList<uint8_t>();
        transmission = new LinkedList<uint8_t>();
    }

    void setup() override {
        wasSetup = true;
    }

    void sendCommand(uint8_t cmd) override {
        commands->add(cmd);
    }

    void sendData(const uint8_t *data, int size) override {
        transmission->clear();
        for(int i = 0; i < size; i++)
            includeByte(data[i]);
    }

    void beginTransmission() override {
        transmission->clear();
        inTransmission = true;
    }

    void includeByte(uint8_t b) override {
        transmission->add(applyInversion(b));
    }

    void endTransmission() override {
        inTransmission = false;
    }

    uint8_t pmgByte(const uint8_t *bmp, int i) override {
        return bmp[i];
    }

    bool wasSetup;
    LinkedList<uint8_t> *commands;
    LinkedList<uint8_t> *transmission;
    bool inTransmission;
};

#endif //SK8BMS_MOCKOLEDCOMM_H
