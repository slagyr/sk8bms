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
    Controller(Hardware *hardware, Display *display, Rotary *rotary, Mux *mux, Switch *fetSwitch, Switch *capSwitch,
                   Switch *balanceSwitch, VoltageSensor *sensor);

    Hardware *getHardware() const;

    Display *getDisplay() const;

    Rotary *getRotary() const;

    Mux *getMux() const;

    Switch *getFetSwitch() const;

    Switch *getCapSwitch() const;

    Switch *getBalanceSwitch() const;

    VoltageSensor *getSensor() const;

    void setup();

    uint8_t getCurrentCell();

    float getCellVoltage(uint8_t cell);

    void tick(unsigned long millis);

    Screen *getScreen() const;

    void setScreen(Screen *screen);

    uint8_t getCellCount() { return CELL_COUNT; }

    bool didCurrentCellVoltageChanged() const;

    uint8_t getLowestVoltageCell() const;

    float getLowestVoltage() const;

    uint8_t getHighestVoltageCell() const;

    float getHighestVoltage() const;

    bool didBalancingChanged() const;

    bool isBalancing() const;

    // Screens
    Screen *splashScreen;
    Screen *homeScreen;

protected:

    uint8_t currentCell;
    float *cellVoltages;
    bool currentCellVoltageChanged;
    uint8_t lowestVoltageCell = 0;
    float lowestVoltage = 5.0;
    uint8_t highestVoltageCell = 0;
    float highestVoltage = 0.0;
    bool balancingChanged;
    bool balancing;

private:

    Hardware *hardware;
    Display *display;
    Rotary *rotary;
    Mux *mux;
    Switch *fetSwitch;
    Switch *capSwitch;
    Switch *balanceSwitch;
    VoltageSensor *sensor;
    Screen *screen;

    unsigned long lastUserEventTime;

    void measureNextCell();

    void openMuxFet() const;

    void closeMuxFet() const;

    float readFlyingCapVoltage() const;

    void syncFlyingCap(uint8_t cell) const;

    void configureBalancing();

    void balance();
};


#endif //SK8BMS_CONTROLLER_H
