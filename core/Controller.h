#ifndef SK8BMS_CONTROLLER_H
#define SK8BMS_CONTROLLER_H

#include "Hardware.h"
#include "Display.h"
#include "Rotary.h"
#include "Mux.h"
#include "VoltageSensor.h"
#include "Screen.h"
#include "Switch.h"

#define CELL_COUNT 10

class Controller {

public:
    Controller(Hardware *hardware, Display *display, Rotary *rotary, Mux *mux, Switch *fetSwitch, VoltageSensor *sensor);

    Hardware *getHardware() const;

    Display *getDisplay() const;

    Rotary *getRotary() const;

    Mux *getMux() const;

    Switch *getFetSwitch() const;

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
    bool currentCellVoltageChanged;

private:
    Hardware *hardware;
    Display *display;
    Rotary *rotary;
    Mux *mux;
    Switch *fetSwitch;
    VoltageSensor *sensor;
    Screen *screen;

    unsigned long lastUserEventTime;

    void measureNextCell();

    void photoMosOn() const;

    void photoMosOff() const;

    float readFlyingCapVoltage() const;

    void syncFlyingCap(uint8_t cell) const;
};


#endif //SK8BMS_CONTROLLER_H
