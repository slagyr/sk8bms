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
    MockVoltageSensor *sensor_;
    Rotary *rotary_;
    MockDisplay *display_;

    static MockController *create() {
        Hardware *hardware = new MockHardware();
        Mux *mux = new Mux(hardware, 0, 1, 2, 3, 4);
        MockVoltageSensor *sensor = new MockVoltageSensor(hardware, 5);
        Rotary *rotary = new Rotary(hardware, 6, 7, 8);
        MockDisplay *display = new MockDisplay();

        MockController *controller = new MockController(hardware, display, rotary, mux, sensor);

        controller->hardware_ = hardware;
        controller->mux_ = mux;
        controller->sensor_ = sensor;
        controller->rotary_ = rotary;
        controller->display_ = display;

        return controller;
    }

    MockController(Hardware *hardware, Display *display, Rotary *rotary, Mux *mux, VoltageSensor *sensor) : Controller(
            hardware, display, rotary, mux, sensor) {}


    void hackVoltage(int i, float voltage) {
        cellVoltages[i] = voltage;
    }

    void hackCurrentCell(int i) {
        currentCell = i;
    }
};

#endif //SK8BMS_MOCKCONTROLLER_H
