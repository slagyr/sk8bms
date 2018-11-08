#include <screen/SplashScreen.h>
#include <screen/HomeScreen.h>
#include "Controller.h"
#include "math.h"

Controller::Controller(Hardware *hardware, Display *display, Rotary *rotary, Mux *mux, Switch *fetSwitch, VoltageSensor *sensor) {
    this->hardware = hardware;
    this->display = display;
    this->rotary = rotary;
    this->mux = mux;
    this->fetSwitch = fetSwitch;
    this->sensor = sensor;

    currentCell = CELL_COUNT - 1;
    cellVoltages = new float[CELL_COUNT];
    for(int i = 0; i < CELL_COUNT; i++)
        cellVoltages[i] = 0.0;
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

Switch *Controller::getFetSwitch() const {
    return fetSwitch;
}

Screen *Controller::getScreen() const {
    return screen;
}

void Controller::setScreen(Screen *screen) {
    this->screen = screen;
    screen->enter();
}

bool Controller::didCurrentCellVoltageChanged() const {
    return currentCellVoltageChanged;
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

    syncFlyingCap(currentCell);

    float voltage = readFlyingCapVoltage();

//    hardware->print("cell # ");
//    hardware->print(currentCell);
//    hardware->print(": ");
//    hardware->println(voltage);

    currentCellVoltageChanged = abs(voltage - cellVoltages[currentCell]) > 0.01;
    cellVoltages[currentCell] = voltage;
}

void Controller::syncFlyingCap(uint8_t cell) const {
    mux->select(cell);
    photoMosOn();
    hardware->sleep(10); // allow the flying cap time to charge
    photoMosOff();
}

float Controller::readFlyingCapVoltage() const {
    mux->select(CELL_COUNT); // sensor optoFET;
    photoMosOn();
    float readVoltage = sensor->readVoltage();
    photoMosOff();
    return readVoltage;
}

void Controller::photoMosOff() const {
    fetSwitch->off();
    hardware->sleep(2);
}

void Controller::photoMosOn() const {
    fetSwitch->on();
    hardware->sleep(3);
}
