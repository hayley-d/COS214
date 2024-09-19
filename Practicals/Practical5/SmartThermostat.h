#ifndef SMARTTHERMOSTAT_H
#define SMARTTHERMOSTAT_H
#include "SmartDevice.h"

/**
 * @class SmartThermostat
 *
 * @brief Concrete implementation of the smart device to represent a smart
 * thermostat
 */
class SmartThermostat : public SmartDevice {
protected:
  int id;
  double temperature;
  bool on;

public:
  SmartThermostat(int id, double temperature = 0) {
    this->id = id;
    this->temperature = temperature;
    this->on = false;
  }
  ~SmartThermostat() override = default;
  int getId() override { return this->id; }
  virtual double getTemperature() { return this->temperature; }
  virtual void setTemperature(double temperature);
  void toggle() override;
  void toggleOn() override;
  void toggleOff() override;
  std::string getStatus() override;
  DeviceType getDeviceType() override { return DeviceType::Thermostat; }
  virtual bool isOn() { return this->on; }
};
#endif // SMARTTHERMOSTAT_H
