#ifndef SK8BMS_CANVAS_H
#define SK8BMS_CANVAS_H

#include "Adafruit_GFX.h"

class Canvas : public Adafruit_GFX {
public:
    Canvas(int16_t w, int16_t h);

    ~Canvas();

    byte *getBuffer();

    void drawPixel(byte x, byte y, byte color) override;

    void clear();

private:
    byte *buffer;
};


#endif
