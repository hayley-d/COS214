#include "SmartThermostatIntegrator.h"

double SmartThermostatIntegrator::getTemperature() {
    return this->legacyDevice->getTemperature();
}

std::string SmartThermostatIntegrator::getStatus() {
    if(this->legacyDevice->isOn()) {
        return "Thermostat is on";
    }
    return "Thermostat is off";
}

void SmartThermostatIntegrator::setTemperature(double temperature) {
    if(temperature > legacyDevice->getTemperature()) {
        double difference = temperature - legacyDevice->getTemperature();
        this->legacyDevice->increaseTemperature(difference);
    } else {
        //want to decrease temp
        double difference = legacyDevice->getTemperature() - temperature;
        this->legacyDevice->decreaseTemperature(difference);
    }
}

void SmartThermostatIntegrator::toggle() {
    if(this->legacyDevice->isOn()) {
        this->legacyDevice->switchOff();
    } else {
        this->legacyDevice->switchOn();
    }
}

void SmartThermostatIntegrator::toggleOn() {
    this->legacyDevice->switchOn();
}

void SmartThermostatIntegrator::toggleOff() {
    this->legacyDevice->switchOff();
}

bool SmartThermostatIntegrator::isOn() {
    return this->legacyDevice->isOn();
}
