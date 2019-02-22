#include <screen/SplashScreen.h>
#include <screen/HomeScreen.h>
#include "Controller.h"
#include "math.h"

Controller::Controller() {
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
    capSwitch->setup();
    balanceSwitch->setup();
    cellSensor->setup();
    loadSensor->setup();

    setScreen(splashScreen);
}

void Controller::setScreen(Screen *screen) {
    this->screen = screen;
    screen->enter();
}

Screen *Controller::getScreen() {
    return screen;
}

bool Controller::didCurrentCellVoltageChanged() const {
    return currentCellVoltageChanged;
}

byte Controller::getCurrentCell() {
    return currentCell;
}

float Controller::getCellVoltage(byte cell) {
    if (cell > CELL_COUNT - 1)
        return 0.0;
    else
        return cellVoltages[cell];
}

void Controller::tick(unsigned long millis) {
    measureNextCell();

    float loadVoltage = loadSensor->readVoltage();
    hardware->print("loadVoltage: ");
    hardware->println(loadVoltage);

    if(currentCell == CELL_COUNT - 1)
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
        for (byte i = 0; i < CELL_COUNT; i++) {
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

void Controller::syncFlyingCap(byte cell) const {
    mux->select(cell);

    capSwitch->on();
    openMuxFet();

    hardware->sleep(10); // give the flying cap time to charge

    capSwitch->off();
    closeMuxFet();
}

float Controller::readFlyingCapVoltage() const {
    mux->select(CELL_COUNT); // sensor optoFET;

    capSwitch->on();
    openMuxFet();

    float readVoltage = cellSensor->readVoltage();

    capSwitch->off();
    closeMuxFet();

    return readVoltage;
}

void Controller::closeMuxFet() const {
    fetSwitch->off();
    hardware->sleep(2);
}

void Controller::openMuxFet() const {
    fetSwitch->on();
    hardware->sleep(3);
}

byte Controller::getLowestVoltageCell() const {
    return lowestVoltageCell;
}

float Controller::getLowestVoltage() const {
    return lowestVoltage;
}

byte Controller::getHighestVoltageCell() const {
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
    mux->select(lowestVoltageCell);

    balanceSwitch->on();
    openMuxFet();

    hardware->sleep(2000);

    balanceSwitch->off();
    closeMuxFet();

//    for (byte i = 0; i < 3; i++) {
//        syncFlyingCap(highestVoltageCell);
//        syncFlyingCap(lowestVoltageCell);
//    }
}
