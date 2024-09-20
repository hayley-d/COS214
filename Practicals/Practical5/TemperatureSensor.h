#ifndef TEMPERATURESENSOR_H
#define TEMPERATURESENSOR_H
#include "Sensor.h"
#include <memory>
#include "SmartRoom.h"

/**
* @class TemperatureSensor
*
* @brief Concrete representation of the Sensor that will trigger when a temperature event occurs.
*
* This sensor will trigger when a temperature event occurs and will set the room temperature to 20 degrees.
*/
class TemperatureSensor : public Sensor {
    SmartRoom* room;
public:
    /**
    * @brief Constructor for the TemperatureSensor.
    *
    * @param room Shared pointer to a SmartRoom.
    *
    * @param id Int value representing the id of the sensor.
    *
    */
    TemperatureSensor(SmartRoom& room, int id);

    /**
    * @brief Destructor for TemperatureSensor.
    */
    ~TemperatureSensor() override = default;

    /**
    * @brief Triggered on a Temperature event and will set the temperature of the room.
    *
    * @param e Event enum representing a Movement/Temperature event.
    */
    void update(Event e) override;
};
#endif //TEMPERATURESENSOR_H
