#ifndef SENSOR_H
#define SENSOR_H
#include "Event.h"

class Sensor {
protected:
    int id;

public:
    Sensor(int id) { this->id = id; }
    virtual ~Sensor() = default;
    virtual void update(Event e) = 0;
    int getId() { return id;}
};
#endif //SENSOR_H
