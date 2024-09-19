#ifndef SMARTDEVICE_H
#define SMARTDEVICE_H
#include "DeviceType.h"
#include <string>
/**
 * @class SmartDevice
 * @brief Interface for smart devices that defines the basic functionality of a
 * smart device.
 */
class SmartDevice {
public:
  /**
   * @brief Toggles the device between on and off states.
   *
   * This method should toggle the current state of the smart device either on
   * to off or off to on. Must be implemented by derived classes.
   */
  virtual void toggle() = 0;
  /**
   * @brief Toggles the device on.
   *
   * This method should change the state of the device to on regardless of it's
   * current state. Must be implemented by derived classes.
   */
  virtual void toggleOn() = 0;
  /**
   * @brief Toggles the device off.
   *
   * This method should toggle the state of the deivce to off regardless of it's
   * current state. Must be implemented by dereived classes.
   */
  virtual void toggleOff() = 0;
  /**
   * @brief Gets the status of the device.
   * Must be implemented by the derived classes.
   * @return std::string The current status of the device.
   */
  virtual std::string getStatus() = 0;
  /**
   * @brief Gets the type of device.
   *
   * @return DeviceType The type of device (Light/Thermostat/Door).
   */
  virtual DeviceType getDeviceType() = 0;
  /**
   * @brief Virtual destructor for the SmartDevice
   *
   * Ensures proper cleanup of the derived classes.
   */
  virtual ~SmartDevice() = default;
  /**
   * @breif Virtual method to get the device's id
   *
   * @return int The id of the device.
   */
  virtual int getId() = 0;
};
#endif // SMARTDEVICE_H
