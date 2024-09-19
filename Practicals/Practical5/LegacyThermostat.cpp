#include "LegacyThermostat.h"

void LegacyThermostat::increaseTemperature(double temperatureIncrease) {
    this->temperature += temperatureIncrease;
}

void LegacyThermostat::decreaseTemperature(double temperatureDecrease) {
    this->temperature += temperatureDecrease;
}

double LegacyThermostat::getTemperature() {
    return this->temperature;
}

void LegacyThermostat::switchOn() {
    this->on = true;
}

void LegacyThermostat::switchOff() {
    this->on = false;
}
