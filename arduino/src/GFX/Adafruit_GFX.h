#ifndef _ADAFRUIT_GFX_H
#define _ADAFRUIT_GFX_H

#include "Arduino.h"


/// A generic graphics superclass that can handle all sorts of drawing. At a minimum you can subclass and provide drawPixel(). At a maximum you can do a ton of overriding to optimize. Used for any/all Adafruit displays!
class Adafruit_GFX {

public:

    Adafruit_GFX(uint8_t w, uint8_t h); // Constructor

    // This MUST be defined by the subclass:
    virtual void drawPixel(uint8_t x, uint8_t y, uint8_t color) = 0;    ///< Virtual drawPixel() function to draw to the screen/framebuffer/etc, must be overridden in subclass. @param x X coordinate.  @param y Y coordinate. @param color 16-bit pixel color.

    virtual void writeFillRect(uint8_t x, uint8_t y, uint8_t w, uint8_t h, uint8_t color);

    virtual void writeFastVLine(uint8_t x, uint8_t y, uint8_t h, uint8_t color);

    virtual void writeFastHLine(uint8_t x, uint8_t y, uint8_t w, uint8_t color);

    virtual void writeLine(uint8_t x0, uint8_t y0, uint8_t x1, uint8_t y1, uint8_t color);

    // BASIC DRAW API
    // These MAY be overridden by the subclass to provide device-specific
    // optimized code.  Otherwise 'generic' versions are used.

    // It's good to implement those, even if using transaction API
    virtual void drawFastVLine(uint8_t x, uint8_t y, uint8_t h, uint8_t color);

    virtual void drawFastHLine(uint8_t x, uint8_t y, uint8_t w, uint8_t color);

    virtual void fillRect(uint8_t x, uint8_t y, uint8_t w, uint8_t h, uint8_t color);

    virtual void fillScreen(uint8_t color);

    // Optional and probably not necessary to change
    virtual void drawLine(uint8_t x0, uint8_t y0, uint8_t x1, uint8_t y1, uint8_t color);

    virtual void drawRect(uint8_t x, uint8_t y, uint8_t w, uint8_t h, uint8_t color);

    // These exist only with Adafruit_GFX (no subclass overrides)
    void drawCircle(uint8_t x0, uint8_t y0, uint8_t r, uint8_t color);

    void drawCircleHelper(uint8_t x0, uint8_t y0, uint8_t r, uint8_t cornername, uint8_t color);

    void fillCircle(uint8_t x0, uint8_t y0, uint8_t r, uint8_t color);

    void fillCircleHelper(uint8_t x0, uint8_t y0, uint8_t r, uint8_t cornername, uint8_t delta, uint8_t color);

    void drawTriangle(uint8_t x0, uint8_t y0, uint8_t x1, uint8_t y1, uint8_t x2, uint8_t y2, uint8_t color);

    void fillTriangle(uint8_t x0, uint8_t y0, uint8_t x1, uint8_t y1, uint8_t x2, uint8_t y2, uint8_t color);

    void drawRoundRect(uint8_t x0, uint8_t y0, uint8_t w, uint8_t h, uint8_t radius, uint8_t color);

    void fillRoundRect(uint8_t x0, uint8_t y0, uint8_t w, uint8_t h, uint8_t radius, uint8_t color);

    uint8_t height() const;

    uint8_t width() const;


protected:
    const uint8_t WIDTH, HEIGHT;
};


#endif
