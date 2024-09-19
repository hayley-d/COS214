#include "SmartThermostat.h"

void SmartThermostat::setTemperature(double temperature) {
  this->temperature = temperature;
}

void SmartThermostat::toggle() { this->on = on ? false : true; }

void SmartThermostat::toggleOn() { this->on = true; }

void SmartThermostat::toggleOff() { this->on = false; }

std::string SmartThermostat::getStatus() {
  if (this->on) {
    return "Thermostat is on";
  }
    return "Thermostat is off";
}
