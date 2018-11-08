#ifndef SK8BMS_MOCKDISPLAY_H
#define SK8BMS_MOCKDISPLAY_H

#include <Display.h>

class MockDisplay : public Display {
public:
    void setup() override {
        wasSetup = true;
    }

    void splash() override {
        splashed = true;
    }

    void showCellVoltage(uint8_t i, float voltage) override {
        voltages[i] = voltage;
    }

    void showHome() override {
        showedHome = true;
    }

    void showBalancing(bool isOn, uint8_t low, uint8_t high) override {
        balancingIndicated = isOn;
        balanceToCell = low;
        balanceFromCell = high;
    }

    bool wasSetup = false;
    bool splashed;
    float *voltages = new float[10]{0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0};
    bool showedHome;

    uint8_t balanceToCell;
    uint8_t balanceFromCell;
    bool balancingIndicated;
};

#endif
