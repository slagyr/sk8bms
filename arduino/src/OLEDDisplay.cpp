#include <avr/pgmspace.h>
#include <Wire.h>
#include <GFX/Canvas.h>
#include <oled/Oled.h>
#include <oled/OledFonts.h>
#include "splash.h"
#include "OLEDDisplay.h"
#include "I2cOledComm.h"

#define BAR_TOP_ROW 2
#define BAR_ROWS 5
#define BAR_WID 12
#define BAR_X_PAD 2
#define BAR_Y_BOT_PAD 1
#define WHITE 1

OLEDDisplay::OLEDDisplay() {
    I2cOledComm *comm = new I2cOledComm();
    oled = new Oled(comm);
    voltageBar = new Canvas(BAR_WID, BAR_ROWS * 8);
}

void OLEDDisplay::setup() {
    oled->setup();
}

void OLEDDisplay::splash() {
    oled->drawBitmap(0, 0, 128, 64, splashBMP);
}

void OLEDDisplay::showCellVoltage(uint8_t cell, float voltage) {
    auto percentage = (int)((voltage - 2.5) / 1.7 * 100);

    Serial.print("cell:\t");
    Serial.print(cell);
    Serial.print("\tvoltage:\t");
    Serial.print(voltage);
    Serial.print("\tpercentage:\t");
    Serial.println(percentage);

    percentage = percentage > 99 ? 99 : percentage;
    percentage = percentage < 0 ? 0 : percentage;

    updateBar(cell, percentage);
}

void OLEDDisplay::showHome() {
    oled->clearScreen();
    showLabeledBars();
}

void OLEDDisplay::updateBar(uint8_t cell, int percentage) const {
    oled->setFont(oled_font5x7);
    char buf[10];

    uint8_t x = cell * BAR_WID;

    oled->clear(x, 1, BAR_WID, 6);
    itoa(percentage, buf, 10);
    oled->writeString(x + BAR_X_PAD, 1, buf);


    voltageBar->clear();
    voltageBar->drawRect(BAR_X_PAD, 0,
                         voltageBar->width() - BAR_X_PAD,
                         voltageBar->height() - BAR_Y_BOT_PAD,
                         WHITE);
    uint8_t h = (voltageBar->height() - BAR_Y_BOT_PAD) * percentage / 100.0;
    voltageBar->fillRect(BAR_X_PAD + 2,
                         voltageBar->height() - h,
                         voltageBar->width() - 4 - BAR_X_PAD,
                         h - BAR_Y_BOT_PAD - 1,
                         WHITE);
    oled->drawCanvas(x, BAR_TOP_ROW,
                     voltageBar->width(), voltageBar->height(),
                     voltageBar->getBuffer());
}

void OLEDDisplay::showLabeledBars() const {
    oled->setFont(oled_font6x8);
    char buf[10];
    for (int i = 0; i < 10; i++) {
        uint8_t x = i * BAR_WID;
        itoa(i, buf, 10);
        oled->writeString(x + 3, 7, buf);
    }
}

void OLEDDisplay::showBalancing(bool isBalancing, uint8_t to, uint8_t from) {
    oled->clear(0, 0, 128, 1);
    if(isBalancing) {
        Serial.print("to: ");
        Serial.println(to);
        Serial.print("from: ");
        Serial.println(from);

        uint8_t x = to * BAR_WID;
        oled->writeString(x + BAR_X_PAD, 0, "+");

        x = from * BAR_WID;
        oled->writeString(x + BAR_X_PAD, 0, "-");
    }
}
