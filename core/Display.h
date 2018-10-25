#ifndef SK8BMS_DISPLAY_H
#define SK8BMS_DISPLAY_H

#include "common.h"

class Display {

public:
    virtual void setup() = 0;

    virtual void splash() = 0;

    virtual void showCellVoltage(uint8_t i, float voltage) = 0;

    virtual void showHome() = 0;

};


#endif //SK8BMS_DISPLAY_H
