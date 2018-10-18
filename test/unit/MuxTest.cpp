#include <gtest/gtest.h>
#include "Mux.h"
#include "MockHardware.h"

class MuxTest : public ::testing::Test {
protected:

    MockHardware *controller;
    Mux *mux;

    virtual void SetUp() {
        controller = new MockHardware();
        mux = new Mux(controller, 0, 1, 2, 3, 4);
        mux->setup();
    }

    virtual void TearDown() {
        delete mux;
        delete controller;
    }
};

TEST_F(MuxTest, CreationWithPins) {
    EXPECT_EQ(controller, mux->getHardware());
    EXPECT_EQ(0, mux->getEnablePin());
    EXPECT_EQ(1, mux->getA0());
    EXPECT_EQ(2, mux->getA1());
    EXPECT_EQ(3, mux->getA2());
    EXPECT_EQ(4, mux->getA3());
}

TEST_F(MuxTest, Setup) {
    EXPECT_EQ("OUTPUT", controller->pinModes[0]);
    EXPECT_EQ("LOW", controller->digitalWrites[0]);
    EXPECT_EQ("OUTPUT", controller->pinModes[1]);
    EXPECT_EQ("LOW", controller->digitalWrites[1]);
    EXPECT_EQ("OUTPUT", controller->pinModes[2]);
    EXPECT_EQ("LOW", controller->digitalWrites[2]);
    EXPECT_EQ("OUTPUT", controller->pinModes[3]);
    EXPECT_EQ("LOW", controller->digitalWrites[3]);
    EXPECT_EQ("OUTPUT", controller->pinModes[4]);
    EXPECT_EQ("LOW", controller->digitalWrites[4]);
}

TEST_F(MuxTest, EnableDisable) {
    EXPECT_EQ(false, mux->isEnabled());

    mux->enable();
    EXPECT_EQ(true, mux->isEnabled());
    EXPECT_EQ("HIGH", controller->digitalWrites[0]);

    mux->disable();
    EXPECT_EQ(false, mux->isEnabled());
    EXPECT_EQ("LOW", controller->digitalWrites[0]);
}

TEST_F(MuxTest, UpdateSelectorPins) {
    mux->updateSelectorPins(0);
    EXPECT_EQ("LOW", controller->digitalWrites[1]);
    EXPECT_EQ("LOW", controller->digitalWrites[2]);
    EXPECT_EQ("LOW", controller->digitalWrites[3]);
    EXPECT_EQ("LOW", controller->digitalWrites[4]);

    mux->updateSelectorPins(1);
    EXPECT_EQ("HIGH", controller->digitalWrites[1]);
    EXPECT_EQ("LOW", controller->digitalWrites[2]);
    EXPECT_EQ("LOW", controller->digitalWrites[3]);
    EXPECT_EQ("LOW", controller->digitalWrites[4]);

    mux->updateSelectorPins(2);
    EXPECT_EQ("LOW", controller->digitalWrites[1]);
    EXPECT_EQ("HIGH", controller->digitalWrites[2]);
    EXPECT_EQ("LOW", controller->digitalWrites[3]);
    EXPECT_EQ("LOW", controller->digitalWrites[4]);

    mux->updateSelectorPins(3);
    EXPECT_EQ("HIGH", controller->digitalWrites[1]);
    EXPECT_EQ("HIGH", controller->digitalWrites[2]);
    EXPECT_EQ("LOW", controller->digitalWrites[3]);
    EXPECT_EQ("LOW", controller->digitalWrites[4]);

    mux->updateSelectorPins(4);
    EXPECT_EQ("LOW", controller->digitalWrites[1]);
    EXPECT_EQ("LOW", controller->digitalWrites[2]);
    EXPECT_EQ("HIGH", controller->digitalWrites[3]);
    EXPECT_EQ("LOW", controller->digitalWrites[4]);

    mux->updateSelectorPins(5);
    EXPECT_EQ("HIGH", controller->digitalWrites[1]);
    EXPECT_EQ("LOW", controller->digitalWrites[2]);
    EXPECT_EQ("HIGH", controller->digitalWrites[3]);
    EXPECT_EQ("LOW", controller->digitalWrites[4]);

    mux->updateSelectorPins(6);
    EXPECT_EQ("LOW", controller->digitalWrites[1]);
    EXPECT_EQ("HIGH", controller->digitalWrites[2]);
    EXPECT_EQ("HIGH", controller->digitalWrites[3]);
    EXPECT_EQ("LOW", controller->digitalWrites[4]);

    mux->updateSelectorPins(7);
    EXPECT_EQ("HIGH", controller->digitalWrites[1]);
    EXPECT_EQ("HIGH", controller->digitalWrites[2]);
    EXPECT_EQ("HIGH", controller->digitalWrites[3]);
    EXPECT_EQ("LOW", controller->digitalWrites[4]);

    mux->updateSelectorPins(8);
    EXPECT_EQ("LOW", controller->digitalWrites[1]);
    EXPECT_EQ("LOW", controller->digitalWrites[2]);
    EXPECT_EQ("LOW", controller->digitalWrites[3]);
    EXPECT_EQ("HIGH", controller->digitalWrites[4]);

    mux->updateSelectorPins(9);
    EXPECT_EQ("HIGH", controller->digitalWrites[1]);
    EXPECT_EQ("LOW", controller->digitalWrites[2]);
    EXPECT_EQ("LOW", controller->digitalWrites[3]);
    EXPECT_EQ("HIGH", controller->digitalWrites[4]);

    mux->updateSelectorPins(10);
    EXPECT_EQ("LOW", controller->digitalWrites[1]);
    EXPECT_EQ("HIGH", controller->digitalWrites[2]);
    EXPECT_EQ("LOW", controller->digitalWrites[3]);
    EXPECT_EQ("HIGH", controller->digitalWrites[4]);

    mux->updateSelectorPins(11);
    EXPECT_EQ("HIGH", controller->digitalWrites[1]);
    EXPECT_EQ("HIGH", controller->digitalWrites[2]);
    EXPECT_EQ("LOW", controller->digitalWrites[3]);
    EXPECT_EQ("HIGH", controller->digitalWrites[4]);

    mux->updateSelectorPins(12);
    EXPECT_EQ("LOW", controller->digitalWrites[1]);
    EXPECT_EQ("LOW", controller->digitalWrites[2]);
    EXPECT_EQ("HIGH", controller->digitalWrites[3]);
    EXPECT_EQ("HIGH", controller->digitalWrites[4]);

    mux->updateSelectorPins(13);
    EXPECT_EQ("HIGH", controller->digitalWrites[1]);
    EXPECT_EQ("LOW", controller->digitalWrites[2]);
    EXPECT_EQ("HIGH", controller->digitalWrites[3]);
    EXPECT_EQ("HIGH", controller->digitalWrites[4]);

    mux->updateSelectorPins(14);
    EXPECT_EQ("LOW", controller->digitalWrites[1]);
    EXPECT_EQ("HIGH", controller->digitalWrites[2]);
    EXPECT_EQ("HIGH", controller->digitalWrites[3]);
    EXPECT_EQ("HIGH", controller->digitalWrites[4]);

    mux->updateSelectorPins(15);
    EXPECT_EQ("HIGH", controller->digitalWrites[1]);
    EXPECT_EQ("HIGH", controller->digitalWrites[2]);
    EXPECT_EQ("HIGH", controller->digitalWrites[3]);
    EXPECT_EQ("HIGH", controller->digitalWrites[4]);
}
