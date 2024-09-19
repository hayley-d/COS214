#ifndef SMARTDOOR_H
#define SMARTDOOR_H
#include "SmartDevice.h"

/**
 * @class SmartDoor
 * @brief Concrete implementation of SmartDevice representing a smart door.
 *
 * This class implements a smart door which can toggle the lock on and off.
 */
class SmartDoor : public SmartDevice {
  bool locked;
  int id;

public:
  SmartDoor(int id) {
    this->id = id;
    this->locked = false;
  }
  /**
   * @brief The destructor method for the SmartDoor to ensure proper cleanup.
   */
  ~SmartDoor() override = default;
  /**
   * @brief The toggle method will change the door lock from locked to unlocked
   * or from unlocked to locked.
   */
  void toggle() override;
  /**
   * @brief The ToggleOn method is used to toggle the door into a locked state.
   */
  void toggleOn() override;
  /**
   * @brief The ToggleOff method is used to toggle the door into an unlocked
   * state.
   */
  void toggleOff() override;
  /**
   * @brief Gets the current status of the Smart door.
   *
   * @return std::string Representaton of the device's state.
   */
  std::string getStatus() override;
  /**
   * @brief Gets the DeviceType of the door
   *
   * @return DeviceType Enum representing the door smart device.
   */
  DeviceType getDeviceType() override { return DeviceType::Door; }
  /**
   * @breif Gets the id of the door
   *
   * @return int Representing the id of the door.
   */
  int getId() override { return this->id; }

  /**
   * @breif Gets the state of the door lock.
   *
   * @return bool True if locked, False if unlocked.
   */
  bool isLocked() { return this->locked; }
};
#endif // SMARTDOOR_H
