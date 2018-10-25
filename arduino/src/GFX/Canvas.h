#ifndef SK8BMS_CANVAS_H
#define SK8BMS_CANVAS_H

#include "Adafruit_GFX.h"

class Canvas : public Adafruit_GFX {
public:
    Canvas(int16_t w, int16_t h);

    ~Canvas();

    uint8_t *getBuffer();

    void drawPixel(uint8_t x, uint8_t y, uint8_t color) override;

    void clear();

private:
    uint8_t *buffer;
};


#endif
