#ifndef SK8BMS_DISPLAY_H
#define SK8BMS_DISPLAY_H

#include "common.h"

class Display {

public:
    virtual void setup() = 0;

    virtual void splash() = 0;

    virtual void showCellVoltage(byte i, float voltage) = 0;

    virtual void showHome() = 0;

    virtual void showBalancing(bool isOn, byte low, byte high) = 0;

};


#endif //SK8BMS_DISPLAY_H
