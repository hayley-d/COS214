#ifndef SMARTLIGHT_H
#define SMARTLIGHT_H
#include "SmartDevice.h"

/*
 * @class SmartLight
 * @brief The concrete implementation of the SmartDevice interface to represent
 * a smart light.
 */
class SmartLight : public SmartDevice {
  int intensity;
  int id;

public:
  SmartLight(int id, int intensity = 0);
  ~SmartLight() override = default;
  void setIntensity(int intensity);
  int getIntensity() { return this->intensity; }
  void toggle() override;
  void toggleOn() override;
  void toggleOff() override;
  std::string getStatus() override;
  DeviceType getDeviceType() override { return DeviceType::Light; }
  int getId() override { return this->id; }
};
#endif // SMARTLIGHT_H
