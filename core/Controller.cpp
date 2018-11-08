#include <screen/SplashScreen.h>
#include <screen/HomeScreen.h>
#include "Controller.h"
#include "math.h"

Controller::Controller(Hardware *hardware, Display *display, Rotary *rotary, Mux *mux, Switch *fetSwitch,
                       VoltageSensor *sensor) {
    this->hardware = hardware;
    this->display = display;
    this->rotary = rotary;
    this->mux = mux;
    this->fetSwitch = fetSwitch;
    this->sensor = sensor;

    currentCell = CELL_COUNT - 1;
    cellVoltages = new float[CELL_COUNT];
    for (int i = 0; i < CELL_COUNT; i++)
        cellVoltages[i] = 0.0;
    lastUserEventTime = 0;
    balancing = false;

    splashScreen = new SplashScreen(this);
    homeScreen = new HomeScreen(this);
}

void Controller::setup() {
    display->setup();
    rotary->setup();
    mux->setup();
    fetSwitch->setup();
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
    if (cell > CELL_COUNT - 1)
        return 0.0;
    else
        return cellVoltages[cell];
}

void Controller::tick(unsigned long millis) {
    measureNextCell();
    configureBalancing();
    if (balancing)
        balance();

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

//    hardware->print(voltage);
//    hardware->print("\t");
//    hardware->print(cellVoltages[currentCell]);
//    hardware->print("\t");
//    hardware->println(voltage - cellVoltages[currentCell]);

    float diff = voltage - cellVoltages[currentCell];
    currentCellVoltageChanged = diff > 0.02 || diff < -0.02;
    cellVoltages[currentCell] = voltage;
}

void Controller::configureBalancing() {
    balancingChanged = false;
    if (currentCell == CELL_COUNT - 1) {
        lowestVoltage = 5.0;
        highestVoltage = 0.0;
        for (uint8_t i = 0; i < CELL_COUNT; i++) {
            if (cellVoltages[i] < lowestVoltage) {
                lowestVoltage = cellVoltages[i];
                if (lowestVoltageCell != i) {
                    lowestVoltageCell = i;
                    balancingChanged = true;
                }
            } else if (cellVoltages[i] > highestVoltage) {
                highestVoltage = cellVoltages[i];
                if (highestVoltageCell != i) {
                    highestVoltageCell = i;
                    balancingChanged = true;
                }
            }
        }
        bool shouldBalance = highestVoltage - lowestVoltage > 0.05;
        if (shouldBalance != balancing) {
            balancing = shouldBalance;
            balancingChanged = true;
        }
    }
}

void Controller::syncFlyingCap(uint8_t cell) const {
    mux->select(cell);
    photoMosOn();
    hardware->sleep(10); // give the flying cap time to charge
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
    hardware->sleep(10);
}

uint8_t Controller::getLowestVoltageCell() const {
    return lowestVoltageCell;
}

float Controller::getLowestVoltage() const {
    return lowestVoltage;
}

uint8_t Controller::getHighestVoltageCell() const {
    return highestVoltageCell;
}

float Controller::getHighestVoltage() const {
    return highestVoltage;
}

bool Controller::didBalancingChanged() const {
    return balancingChanged;
}

bool Controller::isBalancing() const {
    return balancing;
}

void Controller::balance() {
    for (uint8_t i = 0; i < 3; i++) {
        syncFlyingCap(highestVoltageCell);
        syncFlyingCap(lowestVoltageCell);
    }
}
