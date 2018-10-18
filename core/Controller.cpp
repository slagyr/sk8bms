#include <screen/SplashScreen.h>
#include <screen/HomeScreen.h>
#include "Controller.h"


Controller::Controller(Hardware *hardware, Display *display, Rotary *rotary, Mux *mux, VoltageSensor *sensor) {
    this->hardware = hardware;
    this->display = display;
    this->rotary = rotary;
    this->mux = mux;
    this->sensor = sensor;

    currentCell = CELL_COUNT - 1;
    cellVoltages = new float[CELL_COUNT]{0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0};
    lastUserEventTime = 0;

    splashScreen = new SplashScreen(this);
    homeScreen = new HomeScreen(this);
}

void Controller::setup() {
    display->setup();
    rotary->setup();
    mux->setup();
    sensor->setup();

    setScreen(splashScreen);
}

Hardware *Controller::getHardware() const {
    return hardware;
}

Display *Controller::getDisplay() const {
    return display;
}

Rotary *Controller::getRotary() const {
    return rotary;
}

Mux *Controller::getMux() const {
    return mux;
}

VoltageSensor *Controller::getSensor() const {
    return sensor;
}

uint8_t Controller::getCurrentCell() {
    return currentCell;
}

float Controller::getCellVoltage(uint8_t cell) {
    if(cell > CELL_COUNT - 1)
        return 0.0;
    else
        return cellVoltages[cell];
}

void Controller::tick(unsigned long millis) {
    measureNextCell();

    if (millis > lastUserEventTime + screen->getIdleTimeout()) {
        setScreen(homeScreen);
        lastUserEventTime = millis;
//        lastUpdate = millis;
    }

    screen->update();
}

void Controller::measureNextCell() {
    currentCell = currentCell == CELL_COUNT - 1 ? 0 : currentCell + 1;
    mux->select(currentCell);
    cellVoltages[currentCell] = sensor->readVoltage();
}

Screen *Controller::getScreen() const {
    return screen;
}

void Controller::setScreen(Screen *screen) {
    this->screen = screen;
    screen->enter();
}
