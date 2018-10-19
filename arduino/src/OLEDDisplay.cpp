#include "OLEDDisplay.h"
#include <avr/pgmspace.h>
#include <Wire.h>
#include "../.piolibdeps/ssd1306_ID1904/src/ssd1306.h"
#include "splash.h"

OLEDDisplay::OLEDDisplay() {}

void OLEDDisplay::setup() {
    ssd1306_setFixedFont(ssd1306xled_font6x8);
    ssd1306_128x64_i2c_init();
    ssd1306_fillScreen(0x00);
//    ssd1306_createMenu( &menu, menuItems, sizeof(menuItems) / sizeof(char *) );
//    ssd1306_showMenu( &menu );
}

void OLEDDisplay::splash() {
    ssd1306_drawBitmap(0, 0, 128, 64, splashBMP);
}

#define BAR_TOP 12
#define BAR_BOT 52
#define BAR_WID 12
#define BAR_PAD 2
#define CELL_ID_Y 56

void OLEDDisplay::setCellVoltage(uint8_t cell, float voltage) {
    auto percentage = (int)((voltage - 2.5) / 1.7 * 100);

    Serial.print("cell:\t");
    Serial.print(cell);
    Serial.print("\tvoltage:\t");
    Serial.print(voltage);
    Serial.print("\tpercentage:\t");
    Serial.println(percentage);

    percentage = percentage > 99 ? 99 : percentage;
    percentage = percentage < 0 ? 0 : percentage;

    for(int i = percentage; i >= 0; i--) {
        updateBar(cell, i);
    }
    for(int i = 0; i <= 99; i++) {
        updateBar(cell, i);
    }
    updateBar(cell, percentage);
}

void OLEDDisplay::updateCell(uint8_t cell) {
//    Serial.print("update cell: ");
//    Serial.println(cell);
}

void OLEDDisplay::showHome() {
    ssd1306_setFixedFont(ssd1306xled_font6x8);
    ssd1306_clearScreen();

    showLabeledBars();
}

void OLEDDisplay::updateBar(uint8_t cell, int percentage) const {
    ssd1306_setFixedFont(ssd1306xled_font5x7);
    char buf[10];
    itoa(percentage, buf, 10);

    uint8_t x = cell * BAR_WID;
    uint8_t y = BAR_BOT - ((BAR_BOT - BAR_TOP) / 100.0 * percentage);
    y = y > BAR_BOT - 2 ? BAR_BOT - 2 : y;

    ssd1306_printFixed(x + 1, 0, buf, STYLE_NORMAL);

    ssd1306_clearBlock(x, 0, BAR_WID, 8);
    ssd1306_drawRect(x + BAR_PAD, BAR_TOP, x + BAR_WID - BAR_PAD, BAR_BOT);
    itoa(cell, buf, 10);
    ssd1306_printFixed(x + 3, 56, buf, STYLE_NORMAL);
    for(int i = x + 1; i < x + BAR_WID - 1; i++) {
        ssd1306_drawVLine(i, y, BAR_BOT - 1);
    }
//    ssd1306_drawRect(x + BAR_PAD + 1, y, x + BAR_WID - BAR_PAD - 1, y + 1);
}

void OLEDDisplay::showLabeledBars() const {
    char buf[10];
    for (int i = 0; i < 10; i++) {
        uint8_t x = i * BAR_WID;
        ssd1306_drawRect(x + BAR_PAD, BAR_TOP, x + BAR_WID - BAR_PAD, BAR_BOT);
        itoa(i, buf, 10);
        ssd1306_printFixed(x + 3, 56, buf, STYLE_NORMAL);
    }
}
