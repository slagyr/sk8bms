#ifndef SK8BMS_SLASH_H
#define SK8BMS_SLASH_H

const byte splashBMP[] PROGMEM = {
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x80, 0x80, 0xc0, 0xc0, 0xc0, 0xe0, 0xe0, 0xe0, 0xf0, 0xf0, 0xf0, 0x70, 0x70, 0x70, 0x70,
        0x70, 0x70, 0xf0, 0xf0, 0xf0, 0xe0, 0xe0, 0xe0, 0xe0, 0xc0, 0xc0, 0x80, 0x80, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x80, 0xc0, 0x80, 0x00, 0x70, 0xf0, 0xe0, 0x00, 0x00, 0xc0, 0xc0, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xc0, 0xe0, 0xf0, 0xf8, 0x7c, 0x3e, 0x1e,
        0x0f, 0x07, 0x07, 0x03, 0x03, 0x01, 0x81, 0x81, 0xc0, 0xc0, 0xe0, 0xe0, 0xe0, 0xe0, 0xe0, 0xe0,
        0xe0, 0xc0, 0xc0, 0xc0, 0x80, 0x80, 0x80, 0x81, 0x81, 0xc1, 0xc3, 0xc3, 0xc7, 0xef, 0xef, 0xfe,
        0xfc, 0xfc, 0xf8, 0xf0, 0xe0, 0xe0, 0xe0, 0xc0, 0xc0, 0x80, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0xa0, 0xf0, 0xf0, 0xe0, 0x00, 0x3e, 0xfe, 0xf8, 0xb8, 0x1c, 0xfc,
        0xfc, 0xe0, 0x01, 0xff, 0xff, 0xfc, 0xe0, 0x7f, 0xff, 0xfe, 0xf8, 0x8f, 0x07, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0xc0, 0xf0, 0xfc, 0xff, 0x1f, 0x07, 0x03, 0x01, 0x00, 0x00, 0x80, 0xc0,
        0xe0, 0xf8, 0xfc, 0xfe, 0xfe, 0xff, 0xff, 0xff, 0xff, 0xff, 0x1f, 0x0f, 0x07, 0xe3, 0xf3, 0xf3,
        0xf1, 0xe1, 0xc1, 0x0f, 0x3f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x01, 0x3f, 0xff, 0xff, 0xff,
        0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x7f, 0x3e, 0x1c, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x10,
        0x38, 0xf0, 0xf0, 0x70, 0xf0, 0xe1, 0x03, 0x3f, 0xff, 0xf8, 0xc0, 0xc1, 0x7f, 0x3f, 0x38, 0x00,
        0x03, 0x07, 0x07, 0x03, 0x01, 0x00, 0x00, 0x0f, 0x0d, 0x0f, 0x07, 0x07, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0xfe, 0xff, 0xff, 0x0f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xfc, 0xff, 0xff,
        0xff, 0xff, 0xff, 0xff, 0x7f, 0x3f, 0x1f, 0x8f, 0xc7, 0xe1, 0xf0, 0xf0, 0xf0, 0xf1, 0xf3, 0xf3,
        0xf3, 0xf3, 0xf1, 0xf8, 0xfc, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 0xf8, 0xf9, 0x3f,
        0x1f, 0x1f, 0x0f, 0x07, 0x03, 0x03, 0x01, 0x01, 0xff, 0xff, 0xff, 0xf8, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x80, 0x80, 0x00, 0x60, 0xf0, 0xc0, 0x00, 0x38, 0xfe, 0xff, 0x83, 0x07, 0xff, 0xfe,
        0xf0, 0x3f, 0x0f, 0x00, 0x03, 0x0f, 0x0f, 0x06, 0x03, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x7f, 0xff, 0xff, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0xff, 0xff,
        0xff, 0x3f, 0x07, 0x01, 0x60, 0xfc, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
        0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x03, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xff, 0xff, 0xff, 0x1f, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0xc0, 0xc0, 0x80, 0x00, 0xc0, 0xe0, 0xc0, 0x80, 0x80, 0x80, 0x00, 0x3c, 0xfc,
        0xf8, 0x00, 0x0f, 0xff, 0xfc, 0xe0, 0xc7, 0x7f, 0x3c, 0x0c, 0x07, 0x03, 0x03, 0x07, 0x03, 0x01,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x03, 0x0f, 0x3f, 0x7f, 0xfc, 0xf0, 0xc0, 0xc0, 0xf8, 0xff, 0xff, 0xff,
        0x0f, 0x00, 0x00, 0x00, 0x00, 0x03, 0x07, 0x0f, 0x0f, 0x0f, 0x07, 0x87, 0x83, 0xc3, 0xc3, 0xe1,
        0xe1, 0xe1, 0xe1, 0xe1, 0xe1, 0xe1, 0xe1, 0xe1, 0xe1, 0xe7, 0xdf, 0xff, 0xff, 0xfc, 0xf0, 0xe0,
        0x80, 0x00, 0x00, 0x80, 0xe0, 0xf0, 0xfc, 0x7f, 0x1f, 0x07, 0x01, 0x00, 0x7c, 0xfe, 0xff, 0x3e,
        0xfc, 0xf0, 0x80, 0x01, 0x1d, 0xfe, 0xfc, 0x80, 0x03, 0xff, 0xf9, 0x03, 0x1f, 0x3e, 0x38, 0x3f,
        0x0f, 0x07, 0x07, 0x03, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x03, 0x07, 0x0f, 0x1f, 0x3f, 0x7f, 0x7f,
        0xf0, 0xf0, 0xe0, 0xc0, 0xc0, 0xf0, 0xf8, 0xfc, 0xfe, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
        0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x7f,
        0x3f, 0x3f, 0x1f, 0x0f, 0x07, 0x03, 0x00, 0x00, 0x80, 0xc0, 0xe0, 0x60, 0x30, 0xff, 0xff, 0xf8,
        0x38, 0x3f, 0x3f, 0xfe, 0xfc, 0xcf, 0x07, 0x07, 0x07, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x01, 0x01, 0x03, 0x03, 0x07, 0x07, 0x07, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f,
        0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x07, 0x07, 0x03, 0x03, 0x03, 0x01, 0x01, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x0f, 0x1e, 0x1c, 0x0e, 0x07, 0x03, 0x01,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};


#endif
