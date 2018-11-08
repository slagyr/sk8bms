#include <gtest/gtest.h>
#include "VoltageSensor.h"
#include "MockHardware.h"

class VoltageSensorTest : public ::testing::Test {
protected:

    VoltageSensor *sensor;
    MockHardware *hardware;

    virtual void SetUp() {
        hardware = new MockHardware();
        sensor = new VoltageSensor(hardware, 7, 5.0);
    }

    virtual void TearDown() {
        delete hardware;
        delete sensor;
    }
};

TEST_F(VoltageSensorTest, CreationWithPins) {
    EXPECT_EQ(hardware, sensor->getHardware());
    EXPECT_EQ(7, sensor->getPin());
    EXPECT_NEAR(0, sensor->getInterferenceAdjustment(), 0.01);
}

TEST_F(VoltageSensorTest, Setup) {
    sensor->setup();

    EXPECT_EQ("INPUT", hardware->pinModes[7]);
}

TEST_F(VoltageSensorTest, ReadingZeroVolts) {
    for(int i = 0; i < 10; i++)
        hardware->analogReads[7].push(0);
    EXPECT_DOUBLE_EQ(0, sensor->readVoltage());
}

TEST_F(VoltageSensorTest, Reading5Volts) {
    for(int i = 0; i < 10; i++)
        hardware->analogReads[7].push(1023);
    EXPECT_NEAR(5.0, sensor->readVoltage(), 0.01);
}

TEST_F(VoltageSensorTest, Reading2_5Volts) {
    for(int i = 0; i < 10; i++)
        hardware->analogReads[7].push(512);
    EXPECT_NEAR(2.5, sensor->readVoltage(), 0.01);
}

TEST_F(VoltageSensorTest, WithInterferenceAdjustment) {
    sensor->setInterferenceAdjustment(-0.6);
    for(int i = 0; i < 10; i++)
        hardware->analogReads[7].push(512);
    EXPECT_NEAR(1.9, sensor->readVoltage(), 0.01);
}

TEST_F(VoltageSensorTest, LastReading) {
    for(int i = 0; i < 10; i++)
        hardware->analogReads[7].push(512);
    sensor->readVoltage();
    EXPECT_NEAR(2.5, sensor->getLastReading(), 0.01);

    for(int i = 0; i < 10; i++)
        hardware->analogReads[7].push(1023);
    sensor->readVoltage();
    EXPECT_NEAR(5.0, sensor->getLastReading(), 0.01);
}

TEST_F(VoltageSensorTest, Reading2_5VoltsWith4_5Rref) {
    sensor->setReferenceVoltage(4.5);
    for(int i = 0; i < 10; i++)
        hardware->analogReads[7].push(569);
    EXPECT_NEAR(2.5, sensor->readVoltage(), 0.01);
}
