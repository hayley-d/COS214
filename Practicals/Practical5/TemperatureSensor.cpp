#include "TemperatureSensor.h"

TemperatureSensor::TemperatureSensor(SmartRoom& room, int id) : Sensor(id) {
    this->room = &room;
}

void TemperatureSensor::update(Event e) {
    if(e == Event::Temperature) {
        this->room->setRoomTemperature(20.0);
    }
}
