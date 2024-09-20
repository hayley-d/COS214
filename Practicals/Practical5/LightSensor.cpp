#include "LightSensor.h"

LightSensor::LightSensor(SmartRoom& room, int id) : Sensor(id) {
    this->room = &room;
}

void LightSensor::update(Event e) {
    if(e == Event::Movement) {
        this->room->turnOnLights();
    }
}

