#ifndef SK8BMS_CANVAS_H
#define SK8BMS_CANVAS_H

#include "../.piolibdeps/Adafruit GFX Library_ID13/Adafruit_GFX.h"

class Canvas : public Adafruit_GFX {
public:
    Canvas(int16_t w, int16_t h);

    ~Canvas();

    uint8_t *getBuffer();

    void drawPixel(int16_t x, int16_t y, uint16_t color) override;

    void clear();

private:
    uint8_t *buffer;
};


#endif
