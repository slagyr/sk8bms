
#include "Hardware.h"
#include "VoltageSensor.h"

#define AnalogToVoltMultiplier 0.004887585532747f;
#define SAMPLES 10

VoltageSensor::VoltageSensor(Hardware *hardware, uint8_t pin) {
    this->hardware = hardware;
    this->pin = pin;
    this->interferenceAdjustment = 0.0;
}

Hardware *VoltageSensor::getHardware() {
    return hardware;
}

uint8_t VoltageSensor::getPin() {
    return pin;
}

float VoltageSensor::readVoltage() {
    int sum = 0;
    for(int i = 0; i < SAMPLES; i++) {
        sum += hardware->readAnalogPin(pin);
        if( i < SAMPLES - 1)
            hardware->sleep(100);
    }
//    float voltage = float(sum) / SAMPLES * AnalogToVoltMultiplier;
    float voltage = float(sum) / SAMPLES / 1024 * 5.0;
    lastReading = voltage + interferenceAdjustment;
    return lastReading;
}

void VoltageSensor::setInterferenceAdjustment(float error) {
    interferenceAdjustment = error;
}

float VoltageSensor::getInterferenceAdjustment() {
    return interferenceAdjustment;
}

float VoltageSensor::getLastReading() {
    return lastReading;
}

void VoltageSensor::setup() {
    hardware->pinToInput(pin);
}
