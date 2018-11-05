#ifndef SK8BMS_CONTROLLER_H
#define SK8BMS_CONTROLLER_H

#include "Hardware.h"
#include "Display.h"
#include "Rotary.h"
#include "Mux.h"
#include "VoltageSensor.h"
#include "Screen.h"

#define CELL_COUNT 10

class Controller {

public:
    Controller(Hardware *hardware, Display *display, Rotary *rotary, Mux *mux, VoltageSensor *sensor);

    Hardware *getHardware() const;

    Display *getDisplay() const;

    Rotary *getRotary() const;

    Mux *getMux() const;

    VoltageSensor *getSensor() const;

    void setup();

    uint8_t getCurrentCell();

    float getCellVoltage(uint8_t cell);

    void tick(unsigned long millis);

    Screen *getScreen() const;

    void setScreen(Screen *screen);

    uint8_t getCellCount() { return CELL_COUNT; }

    bool didCurrentCellVoltageChanged() const;

    // Screens
    Screen *splashScreen;
    Screen *homeScreen;

protected:

    uint8_t currentCell;
    float *cellVoltages;

private:
    Hardware *hardware;
    Display *display;
    Rotary *rotary;
    Mux *mux;
    VoltageSensor *sensor;
    Screen *screen;

    unsigned long lastUserEventTime;
    bool currentCellVoltageChanged;

    void measureNextCell();
};


#endif //SK8BMS_CONTROLLER_H
