#include "SmartLight.h"

SmartLight::SmartLight(int id, int intensity) {
    this->id = id;
    this->intensity = intensity;
}

void SmartLight::setIntensity(int intensity) {
    this->intensity = intensity;
}

void SmartLight::toggle() {
    this->intensity = intensity>0 ? 0:100;
}

void SmartLight::toggleOn() {
    this->intensity = 100;
}

void SmartLight::toggleOff() {
    this->intensity = 0;
}

std::string SmartLight::getStatus() {
    if(this->intensity > 0) {
        return "Light is on";
    }
    return "Light is off";
}


