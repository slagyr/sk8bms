#include "Canvas.h"

Canvas::Canvas(int16_t w, int16_t h) : Adafruit_GFX(w, h) {
    uint16_t bytes = ((w + 7) / 8) * h;
    if ((buffer = (uint8_t *) malloc(bytes))) {
        memset(buffer, 0, bytes);
    }
}

Canvas::~Canvas(void) {
    if (buffer) free(buffer);
}

uint8_t *Canvas::getBuffer(void) {
    return buffer;
}

#define ssd1306_swap(a, b) { int16_t t = a; a = b; b = t; }

void Canvas::drawPixel(int16_t x, int16_t y, uint16_t color) {
    if ((x < 0) || (x >= width()) || (y < 0) || (y >= height()))
        return;

    // check rotation, move pixel around if necessary
    switch (getRotation()) {
        case 1:
            ssd1306_swap(x, y);
            x = WIDTH - x - 1;
            break;
        case 2:
            x = WIDTH - x - 1;
            y = HEIGHT - y - 1;
            break;
        case 3:
            ssd1306_swap(x, y);
            y = HEIGHT - y - 1;
            break;
    }

    // x is which column
    switch (color) {
        case 1:
            buffer[x + (y / 8) * width()] |= (1 << (y & 7));
            break;
        case 0:
            buffer[x + (y / 8) * width()] &= ~(1 << (y & 7));
            break;
        case 2:
            buffer[x + (y / 8) * width()] ^= (1 << (y & 7));
            break;
    }
}

void Canvas::clear() {
    if(buffer) {
        uint16_t bytes = ((WIDTH + 7) / 8) * HEIGHT;
        memset(buffer, 0x00, bytes);
    }
}
