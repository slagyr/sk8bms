#ifndef SK8BMS_OLEDDISPLAY_H
#define SK8BMS_OLEDDISPLAY_H

#include <Display.h>
#include <oled/Oled.h>
#include "Canvas.h"

class OLEDDisplay : public Display {
public:
    OLEDDisplay();

    void setup() override;

    void splash() override;

    void setCellVoltage(uint8_t cell, float voltage) override;

    void updateCell(uint8_t cell) override;

    void showHome() override;

private:

    void showLabeledBars() const;

    void updateBar(uint8_t cell, int percentage) const;

    Oled *oled;
    Canvas *voltageBar;
};


#endif //SK8BMS_OLEDDISPLAY_H
