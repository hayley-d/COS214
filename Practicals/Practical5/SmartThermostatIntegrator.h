#ifndef SMARTTHERMOSTATINTEGRATOR_H
#define SMARTTHERMOSTATINTEGRATOR_H
#include "LegacyThermostat.h"
#include "SmartThermostat.h"
#include <memory>

class SmartThermostatIntegrator : public SmartThermostat {
  std::shared_ptr<LegacyThermostat> legacyDevice;

public:
  SmartThermostatIntegrator(std::shared_ptr<LegacyThermostat> &legacyDevice,
                            int id)
      : SmartThermostat(id) {
    this->legacyDevice = legacyDevice;
  }

  ~SmartThermostatIntegrator() override = default;

  double getTemperature() override;
  std::string getStatus() override;
  void setTemperature(double temperature) override;
  DeviceType getDeviceType() override { return DeviceType::Thermostat; }
  void toggle() override;
  void toggleOn() override;
  void toggleOff() override;
  bool isOn() override;
};
#endif // SMARTTHERMOSTATINTEGRATOR_H
