#ifndef SK8BMS_CONTROLLER_H
#define SK8BMS_CONTROLLER_H

#include "Hardware.h"
#include "Display.h"
#include "Rotary.h"
#include "Mux.h"
#include "VoltageSensor.h"
#include "Screen.h"
#include "Switch.h"
#include "Context.h"

#define CELL_COUNT 10

class Controller {

public:
    Controller();

    void setup();

    byte getCurrentCell();

    float getCellVoltage(byte cell);

    void tick(unsigned long millis);

    void setScreen(Screen *screen);

    Screen* getScreen();

    byte getCellCount() { return CELL_COUNT; }

    bool didCurrentCellVoltageChanged() const;

    byte getLowestVoltageCell() const;

    float getLowestVoltage() const;

    byte getHighestVoltageCell() const;

    float getHighestVoltage() const;

    bool didBalancingChanged() const;

    bool isBalancing() const;

    // Screens
    Screen *splashScreen;
    Screen *homeScreen;

    Hardware *hardware;
    Display *display;
    Rotary *rotary;
    Mux *mux;
    Switch *fetSwitch;
    Switch *capSwitch;
    Switch *balanceSwitch;
    VoltageSensor *cellSensor;
    VoltageSensor *loadSensor;

protected:

    Screen* screen;

    byte currentCell;
    float *cellVoltages;
    bool currentCellVoltageChanged;
    byte lowestVoltageCell = 0;
    float lowestVoltage = 5.0;
    byte highestVoltageCell = 0;
    float highestVoltage = 0.0;
    bool balancingChanged;
    bool balancing;

private:

    unsigned long lastUserEventTime;

    void measureNextCell();

    void openMuxFet() const;

    void closeMuxFet() const;

    float readFlyingCapVoltage() const;

    void syncFlyingCap(byte cell) const;

    void configureBalancing();

    void balance();
};


#endif //SK8BMS_CONTROLLER_H
