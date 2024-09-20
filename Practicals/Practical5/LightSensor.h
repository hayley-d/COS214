#ifndef LIGHTSENSOR_H
#define LIGHTSENSOR_H
#include "Sensor.h"
#include "SmartRoom.h"
#include <memory>

/**
 * @class LightSensor
 *
 * @brief Concrete representation of the Sensor class.
 *
 * This sensor will be triggered during a movement event and trigger all lights
 * in a room to turn on.
 */
class LightSensor : public Sensor {
  SmartRoom* room;

public:
  /**
   * @breif Constructor for a LightSensor.
   *
   * @param room Shared pointer to a SmartRoom.
   *
   * @param id An int representing the id of the sensor.
   */
  LightSensor(SmartRoom &room, int id);
  /**
   * @brief Destructor for the LightSensor.
   */
  ~LightSensor() override = default;
  /**
   * @brief Turns on all the lights in the room when a movement event is
   * triggered.
   *
   * @param e An event enum either representing a movement event or temperature
   * event.
   *
   * This method will only act when a movement event is triggered.
   */
  void update(Event e) override;
};
#endif // LIGHTSENSOR_H
