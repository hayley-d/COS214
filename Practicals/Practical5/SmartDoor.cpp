#include "SmartDoor.h"

void SmartDoor::toggle() {
    this->locked = locked ? false:true;
}

void SmartDoor::toggleOn() {
    this->locked = true;
}

void SmartDoor::toggleOff() {
    this->locked = false;
}

std::string SmartDoor::getStatus() {
    if(this->locked) {
        return "Door is locked";
    }

    return "Door is unlocked";
}
