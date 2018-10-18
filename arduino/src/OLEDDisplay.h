#ifndef SK8BMS_OLEDDISPLAY_H
#define SK8BMS_OLEDDISPLAY_H

#include <Display.h>

class OLEDDisplay : public Display {
public:
    OLEDDisplay();

    void setup() override;

    void splash() override;

    void setCellVoltage(uint8_t i, float voltage) override;

    void updateCell(uint8_t cell) override;

    void showHome() override;
};


#endif //SK8BMS_OLEDDISPLAY_H
