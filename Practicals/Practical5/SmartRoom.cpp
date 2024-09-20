#include "SmartRoom.h"
#include "TemperatureSensor.h"
#include "LightSensor.h"
#include "LightSensor.h"
#include <algorithm>
#include <iostream>

SmartRoom::SmartRoom() {
}

void SmartRoom::addSmartDevice(std::shared_ptr<SmartLight> device) {
    //get the device type
    lights[device->getId()] = device;
    std::cout << "Device Added to the room" << std::endl;
    std::cout << "Room now has " << lights.size()<< " lights" << std::endl;
}

void SmartRoom::addSmartDevice(std::shared_ptr<SmartThermostat> device) {
    //get the device type
    thermostats[device->getId()] = device;
    std::cout << "Device Added to the room" << std::endl;
    std::cout << "Room now has " << thermostats.size()<< " thermostats" << std::endl;
}

void SmartRoom::addSmartDevice(std::shared_ptr<SmartDoor> device) {
    //get the device type
    doors[device->getId()] = device;
    std::cout << "Device Added to the room" << std::endl;
    std::cout << "Room now has " << doors.size()<< " doors" << std::endl;
}

bool SmartRoom::removeSmartDevice(int id, DeviceType type) {
    if(type == DeviceType::Light) {
        lights.erase(id);
    } else if(type == DeviceType::Thermostat) {
        thermostats.erase(id);
    } else {
        doors.erase(id);
    }
    return true;
}

void SmartRoom::setRoomLightIntensity(int intensity) {
    for(auto& [key, device]  : lights) {
        device->setIntensity(intensity);
    }
}

void SmartRoom::setRoomTemperature(double temperature) {
    for(auto& [key, device]: thermostats) {
        device->setTemperature(temperature);
    }
}

void SmartRoom::lockRoomDoors() {
    for(auto& [key, device]: doors) {
        device->toggleOn();
    }
}

void SmartRoom::unlockRoomDoors() {
    for(auto& [key, device]: doors) {
        device->toggleOff();
    }
}

void SmartRoom::turnOnLights() {
    for(auto& [key, device]: lights) {
        device->toggleOn();
    }
}

void SmartRoom::turnOffLights() {
    for(auto& [key,device] : lights) {
        device->toggleOff();
    }
}

void SmartRoom::addSensor(Event e) {
    std::shared_ptr<Sensor> sensor;
    int id = sensors.size();
    if(e == Event::Movement) {
       sensor = std::make_shared<LightSensor>(*this,id);
    } else {
        sensor = std::make_shared<TemperatureSensor>(*this,id);
    }
    this->sensors[id] = sensor;
}

bool SmartRoom::removeSensor(int sensorId) {
    sensors.erase(sensorId);
    return true;
}

void SmartRoom::notify(Event e) {
    for(auto& [key,sensor]: sensors) {
        sensor->update(e);
    }
}


