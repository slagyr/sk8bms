#ifndef SK8BMS_MOCKCONTROLLER_H
#define SK8BMS_MOCKCONTROLLER_H

#include <Controller.h>
#include "MockVoltageSensor.h"
#include "MockDisplay.h"
#include "MockHardware.h"

class MockController : public Controller {
public:

    MockVoltageSensor *mockVoltageSensor;
    MockDisplay *mockDisplay;

    static MockController *create() {
        Hardware *hardware = new MockHardware();
        Mux *mux = new Mux(hardware, 0, 1, 2, 3, 4);
        MockVoltageSensor *sensor = new MockVoltageSensor(hardware, 5);
        Rotary *rotary = new Rotary(hardware, 6, 7, 8);
        Switch *fetSwitch = new Switch(hardware, 9);
        MockDisplay *display = new MockDisplay();

        MockController *controller = new MockController();

        controller->hardware = hardware;
        controller->mux = mux;
        controller->fetSwitch = fetSwitch;
        controller->cellSensor = sensor;
        controller->rotary = rotary;
        controller->display = display;

        return controller;
    }

    MockController() : Controller() {}

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
