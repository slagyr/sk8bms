
#include "Hardware.h"
#include "VoltageSensor.h"

#define SAMPLES 20

VoltageSensor::VoltageSensor(Hardware *hardware, uint8_t pin, float referenceVoltage) {
    this->hardware = hardware;
    this->pin = pin;
    this->referenceVoltage = referenceVoltage;
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
            hardware->sleep(1);
    }
//    float voltage = float(sum) / SAMPLES * AnalogToVoltMultiplier;
//    float voltage = float(sum) / SAMPLES / 1024.0 * 5.0;
    float voltage = float(sum) / SAMPLES / 1024.0 * referenceVoltage;
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

float VoltageSensor::getReferenceVoltage() const {
    return referenceVoltage;
}

void VoltageSensor::setReferenceVoltage(float referenceVoltage) {
    VoltageSensor::referenceVoltage = referenceVoltage;
}
