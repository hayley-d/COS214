#ifndef LEGACYTHERMOSTAT_H
#define LEGACYTHERMOSTAT_H

class LegacyThermostat {
  double temperature;
  bool on;

public:
  LegacyThermostat(double temperature = 0) { this->temperature = temperature; }
  ~LegacyThermostat() = default;
  double getTemperature();
  void decreaseTemperature(double temperatureDecrease);
  void increaseTemperature(double temperatureIncrease);
  void switchOff();
  void switchOn();
  bool isOn() { return this->on; }
};
#endif // LEGACYTHERMOSTAT_H
