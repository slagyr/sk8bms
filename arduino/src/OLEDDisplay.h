#ifndef SK8BMS_OLEDDISPLAY_H
#define SK8BMS_OLEDDISPLAY_H

#include <Display.h>
#include <oled/Oled.h>
#include "GFX/Canvas.h"

class OLEDDisplay : public Display {
public:
    OLEDDisplay();

    void setup() override;

    void splash() override;

    void showCellVoltage(byte cell, float voltage) override;

    void showHome() override;

    void showBalancing(bool isBalancing, byte to, byte from) override;

private:

    void showLabeledBars() const;

    void updateBar(byte cell, int percentage) const;

    Oled *oled;
    Canvas *voltageBar;
};


#endif //SK8BMS_OLEDDISPLAY_H
