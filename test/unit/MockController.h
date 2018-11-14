#ifndef SK8BMS_MOCKCONTROLLER_H
#define SK8BMS_MOCKCONTROLLER_H

#include <Controller.h>
#include "MockVoltageSensor.h"
#include "MockDisplay.h"
#include "MockHardware.h"

class MockController : public Controller {
public:

    Hardware *hardware_;
    Mux *mux_;
    Switch *fetSwitch_;
    MockVoltageSensor *sensor_;
    Rotary *rotary_;
    MockDisplay *display_;

    static MockController *create() {
        Hardware *hardware = new MockHardware();
        Mux *mux = new Mux(hardware, 0, 1, 2, 3, 4);
        MockVoltageSensor *sensor = new MockVoltageSensor(hardware, 5);
        Rotary *rotary = new Rotary(hardware, 6, 7, 8);
        Switch *fetSwitch = new Switch(hardware, 9);
        MockDisplay *display = new MockDisplay();

        MockController *controller = new MockController(hardware, display, rotary, mux, fetSwitch, sensor);

        controller->hardware_ = hardware;
        controller->mux_ = mux;
        controller->fetSwitch_ = fetSwitch;
        controller->sensor_ = sensor;
        controller->rotary_ = rotary;
        controller->display_ = display;

        return controller;
    }

    MockController(Hardware *hardware, Display *display, Rotary *rotary, Mux *mux, Switch *fetSwitch, VoltageSensor *sensor) : Controller(
            hardware, display, rotary, mux, fetSwitch, nullptr, nullptr, sensor) {}


    void hackVoltage(int i, float voltage) {
        cellVoltages[i] = voltage;
    }

    void hackCurrentCell(int i) {
        currentCell = i;
    }

    void hackCurrentCellVoltageChanged(bool b) {
        currentCellVoltageChanged = b;
    }

    void hackBalancing(uint8_t low, uint8_t high, bool balancing) {
        lowestVoltageCell = low;
        highestVoltageCell = high;
        this->balancing = balancing;
        balancingChanged = true;
    }
};

#endif
