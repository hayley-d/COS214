#ifndef SMARTROOM_H
#define SMARTROOM_H
#include "Event.h"
#include "Sensor.h"
#include "SmartDevice.h"
#include <map>
#include <memory>
#include <vector>
#include "SmartLight.h"
#include "SmartThermostat.h"
#include "SmartDoor.h"

class Sensor;
/**
 * @class SmartRoom
 *
 * @brief Representaion of a smart room that can contain smart devices such as
 * lights, thermostat and doors.
 */
class SmartRoom {
  std::map<int, std::shared_ptr<SmartLight>> lights;
  std::map<int, std::shared_ptr<SmartThermostat>> thermostats;
  std::map<int, std::shared_ptr<SmartDoor>> doors;
  std::map<int, std::shared_ptr<Sensor>> sensors;

public:
  /**
   * @brief Constructor for the smart room
   */
  SmartRoom();
  /**
   * @brief Destructor for the SmartRoom
   */
  ~SmartRoom() = default;
  /**
   * @brief Adds a light to the devices map.
   *
   * @param device A shared pointer to a Smart Device
   */
  void addSmartDevice(std::shared_ptr<SmartLight> device);
  /**
   * @brief Adds a Thermostat to the devices map.
   *
   * @param device A shared pointer to a Smart Device
   */
  void addSmartDevice(std::shared_ptr<SmartThermostat> device);
  /**
   * @brief Adds a Door to the devices map.
   *
   * @param device A shared pointer to a Smart Device
   */
  void addSmartDevice(std::shared_ptr<SmartDoor> device);

  /**
   * @brief Removes a device from the device map using the id and device type.
   *
   * @param id Int representing the id of the device to remove.
   *
   * @param type the device type of the device to remove.
   */
  bool removeSmartDevice(int id, DeviceType type);
  /**
   * @brief Sets the light intensity of the room based on the parameter.
   *
   * @param intensity Int representing the intensity of the light.
   *
   * 0 is the lowest intensity (off) and 100 is the highest intensity (on)
   */
  void setRoomLightIntensity(int intensity);
  /**
   * @brief Sets the temperature of the room.
   *
   * @param temperature The temperature to set the room to.
   */
  void setRoomTemperature(double temperature);
  /**
   * @brief Locks all doors in the room.
   */
  void lockRoomDoors();
  /**
   * @brief Unlocks all room doors.
   */
  void unlockRoomDoors();
  /**
   * @brief Turns on all lights linked to the room.
   */
  void turnOnLights();
  /**
   * @brief Turns off all the lights linked to the room.
   */
  void turnOffLights();
  /**
   * @brief Adds a sensor to the room.
   *
   * @param e Event for the type of sensor to add.
   */
  void addSensor(Event e);
  /**
   * @brief Removes a sensor from the room.
   *
   * @param sensorId The int representation of the sensor id.
   *
   * @return bool true if sensor with associated id is removed.
   */
  bool removeSensor(int sensorId);
  /**
   * @brief Notifies all sensors with the current event that occured in the
   * room.
   *
   * @param e Event enum for the type of event that occured.
   */
  void notify(Event e);
};
#endif // SMARTROOM_H
