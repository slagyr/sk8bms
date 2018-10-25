#ifndef OLED_H
#define OLED_H

#include "OledComm.h"

class Oled {
public:
    Oled(OledComm *comm);

    OledComm *getComm() const;

    void setup();

    void drawBitmap(uint8_t x, uint8_t page, uint8_t widthPx, uint8_t heightPx, const uint8_t *bmp);

    void clearScreen();

    void setFont(const uint8_t font[]);

    uint8_t getFontWidth() const;

    void writeString(uint8_t x, uint8_t row, const char *string);

    void clear(uint8_t x, uint8_t row, uint8_t widthPx, uint8_t heightRows);

private:

    OledComm *comm;
    const uint8_t *font;
    uint8_t fontWidth;

    void prepareFullScreenUpdate() const;

    void prepareScreenUpdate(int startX, int endX, int startP, int endP) const;
};


#endif
