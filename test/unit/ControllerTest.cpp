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
    MockVoltageSensor *sensor;
    Rotary *rotary;
    MockDisplay *display;
    MockScreen *screen;


    virtual void SetUp() {
        hardware = new MockHardware();
        mux = new Mux(hardware, 0, 1, 2, 3, 4);
        sensor = new MockVoltageSensor(hardware, 5);
        rotary = new Rotary(hardware, 6, 7, 8);
        display = new MockDisplay();
        controller = new Controller(hardware, display, rotary, mux, sensor);
        screen = new MockScreen(controller);

        controller->setup();
    }

    virtual void TearDown() {
        delete hardware;
        delete controller;
        delete mux;
        delete sensor;
        delete rotary;
        delete display;
        delete screen;
    }
};

TEST_F(ControllerTest, ContructionWithStuff) {
    EXPECT_EQ(hardware, controller->getHardware());
    EXPECT_EQ(display, controller->getDisplay());
    EXPECT_EQ(rotary, controller->getRotary());
    EXPECT_EQ(mux, controller->getMux());
    EXPECT_EQ(sensor, controller->getSensor());
}

TEST_F(ControllerTest, Screens) {
    EXPECT_STREQ("Splash", controller->splashScreen->getName());
    EXPECT_STREQ("Home", controller->homeScreen->getName());
    EXPECT_EQ(controller->splashScreen, controller->getScreen());
}

TEST_F(ControllerTest, Setup) {
    controller->setup();

    EXPECT_EQ("OUTPUT", hardware->pinModes[0]); // mux
    EXPECT_EQ("INPUT", hardware->pinModes[5]); // voltage sensor
    EXPECT_EQ("INPUT", hardware->pinModes[6]); // rotarysensor
    EXPECT_EQ(true, display->wasSetup);
}

TEST_F(ControllerTest, CellVoltages) {
    controller->setScreen(screen);
    EXPECT_EQ(9, controller->getCurrentCell());
    sensor->volts = 3.14;

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
