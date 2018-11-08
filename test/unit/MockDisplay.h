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

    bool wasSetup = false;
    bool splashed;
    float *voltages = new float[10]{0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0};
    bool showedHome;
};

#endif
