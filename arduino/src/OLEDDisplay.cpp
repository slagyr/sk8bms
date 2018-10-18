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

int availableMemory() {
    int size = 2048; // Use 2048 with ATmega328
    byte *buf;

    while ((buf = (byte *) malloc(--size)) == NULL)
        ;

    free(buf);

    return size;
}

void OLEDDisplay::setCellVoltage(uint8_t i, float voltage) {


    auto percentage = (int)((voltage - 2.5) / 1.7 * 100);

    Serial.print("cell:\t");
    Serial.print(i);
    Serial.print("\tvoltage:\t");
    Serial.print(voltage);
    Serial.print("\tpercentage:\t");
    Serial.println(percentage);

    percentage = percentage > 99 ? 99 : percentage;
    percentage = percentage < 0 ? 0 : percentage;

    char buf[10];
    sprintf(buf, "%d", percentage);

    uint8_t x = i * BAR_WID;
    uint8_t y = BAR_BOT - ((BAR_BOT - BAR_TOP) / 100 * percentage);
    y = y > BAR_BOT - 2 ? BAR_BOT - 2 : y;
    ssd1306_printFixed(x, 0, buf, STYLE_NORMAL);
    ssd1306_drawRect(x + BAR_PAD + 1, y, x + BAR_WID - BAR_PAD - 1, y + 1);

    Serial.println("done setCellVoltage");
//
//    Serial.print("availableMemory(): ");
//    Serial.println(availableMemory());
}

void OLEDDisplay::updateCell(uint8_t cell) {
    Serial.print("update cell: ");
    Serial.println(cell);
}

void OLEDDisplay::showHome() {
    ssd1306_setFixedFont(ssd1306xled_font6x8);
    ssd1306_clearScreen();
//    ssd1306_printFixed(0,  8, "Normal text", STYLE_NORMAL);
//    ssd1306_printFixed(0, 16, "Bold text", STYLE_BOLD);
//    ssd1306_printFixed(0, 24, "Italic text", STYLE_ITALIC);
//    ssd1306_negativeMode();
//    ssd1306_printFixed(0, 32, "Inverted bold", STYLE_BOLD);
//    ssd1306_positiveMode();

//    char* buf[2];
//    for(int i = 0; i < 10; i++){
//        int voltage =
//        int percentage =
//        sprintf(buf, "%d", );
//        ssd1306_printFixed(0, 56, buf, STYLE_NORMAL);
//    }

    ssd1306_printFixed(0, 56, "1 2 3 4 5 6 7 8 9 10", STYLE_NORMAL);
    for (int i = 0; i < 10; i++) {
        uint8_t x = i * BAR_WID;
        ssd1306_drawRect(x + BAR_PAD, BAR_TOP, x + BAR_WID - BAR_PAD, BAR_BOT);
    }
}
