#include <gtest/gtest.h>
#include <Mux.h>
#include <Rotary.h>
#include "Controller.h"
#include "MockHardware.h"
#include "MockVoltageSensor.h"
#include "MockDisplay.h"
#include "MockScreen.h"

class ControllerTest : public ::testing::Test {
protected:

    Controller *controller;
    MockHardware *hardware;
    Mux *mux;
    Switch *fetSwitch;
    Switch *capSwitch;
    Switch *balanceSwitch;
    MockVoltageSensor *cellSensor;
    MockVoltageSensor *loadSensor;
    Rotary *rotary;
    MockDisplay *display;
    MockScreen *screen;

    virtual void SetUp() {
        controller = new Controller();

        controller->hardware = hardware = new MockHardware();
        controller->mux = mux = new Mux(hardware, 0, 1, 2, 3, 4);
        controller->cellSensor = cellSensor = new MockVoltageSensor(hardware, 5);
        controller->loadSensor = loadSensor = new MockVoltageSensor(hardware, 12);
        controller->rotary = rotary = new Rotary(hardware, 6, 7, 8);
        controller->display = display = new MockDisplay();
        controller->fetSwitch = fetSwitch = new Switch(hardware, 9);
        controller->capSwitch = capSwitch = new Switch(hardware, 10);
        controller->balanceSwitch = balanceSwitch = new Switch(hardware, 11);

        screen = new MockScreen(controller);

        controller->setup();
    }

    virtual void TearDown() {
        delete hardware;
        delete controller;
        delete mux;
        delete cellSensor;
        delete rotary;
        delete display;
        delete screen;
    }
};

TEST_F(ControllerTest, Screens) {
    EXPECT_STREQ("Splash", controller->splashScreen->getName());
    EXPECT_STREQ("Home", controller->homeScreen->getName());
    EXPECT_EQ(controller->splashScreen, controller->getScreen());
}

TEST_F(ControllerTest, Setup) {
    controller->setup();

    EXPECT_EQ("OUTPUT", hardware->pinModes[0]); // mux
    EXPECT_EQ("OUTPUT", hardware->pinModes[fetSwitch->getPin()]);
    EXPECT_EQ("OUTPUT", hardware->pinModes[capSwitch->getPin()]);
    EXPECT_EQ("OUTPUT", hardware->pinModes[balanceSwitch->getPin()]);
    EXPECT_EQ("INPUT", hardware->pinModes[5]); // cell sensor
    EXPECT_EQ("INPUT", hardware->pinModes[6]); // rotarysensor
    EXPECT_EQ("INPUT", hardware->pinModes[12]); // load sensor
    EXPECT_EQ(true, display->wasSetup);
}

TEST_F(ControllerTest, CellVoltages) {
    controller->setScreen(screen);
    EXPECT_EQ(9, controller->getCurrentCell());
    cellSensor->volts = 3.14;

    controller->tick(1111);

    EXPECT_NEAR(3.14, controller->getCellVoltage(0), 0.01);
    EXPECT_EQ(0, controller->getCurrentCell());
    EXPECT_EQ(true, screen->updated);
}

TEST_F(ControllerTest, ScreenTimeout) {
    screen->timeout = 123;
    controller->setScreen(screen);

    controller->tick(1111);

    EXPECT_STREQ("Home", controller->getScreen()->getName());
}

TEST_F(ControllerTest, EnteringScreen) {
    EXPECT_EQ(false, screen->entered);

    controller->setScreen(screen);

    EXPECT_EQ(true, screen->entered);
}

TEST_F(ControllerTest, BalancingSetup) {
    controller->setScreen(screen);
    for (int i = 0; i < 10; i++) {
        cellSensor->volts = float(3.0 + 0.1 * i);
        controller->tick(1111 * i);
    }

    EXPECT_EQ(0, controller->getLowestVoltageCell());
    EXPECT_NEAR(3.0, controller->getLowestVoltage(), 0.01);
    EXPECT_EQ(9, controller->getHighestVoltageCell());
    EXPECT_NEAR(3.9, controller->getHighestVoltage(), 0.01);
    EXPECT_EQ(true, controller->isBalancing());
}

TEST_F(ControllerTest, BalancingButDiffInCellsTooSmallToBalance) {
    controller->setScreen(screen);
    for (int i = 0; i < 10; i++) {
        cellSensor->volts = float(3.0 + 0.001 * i);
        controller->tick(1111 * i);
    }

    EXPECT_EQ(0, controller->getLowestVoltageCell());
    EXPECT_NEAR(3.0, controller->getLowestVoltage(), 0.01);
    EXPECT_EQ(9, controller->getHighestVoltageCell());
    EXPECT_NEAR(3.009, controller->getHighestVoltage(), 0.01);
    EXPECT_EQ(false, controller->isBalancing());
}
