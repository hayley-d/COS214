#include "CropField.h"

struct FarmUnit::pImplFarmUnit{
    int totalCapacity;
    int surfaceArea;
    Crop cropType;
    SoilState* soilState;
};

int CropField::getTotalcapacity() {
}

int CropField::getSurfaceArea() {
}

std::string & CropField::getSoilStateName() {
}

FarmIterator CropField::end() {
}

FarmIterator CropField::begin() {
}

void CropField::printFarm() {
}

void CropField::changeSoilState(SoilState &soilState) {
    //delete the current state
    delete this->impl->soilState;
    //add the new state
    this->impl->soilState = &soilState;
}

void CropField::addFarmUnit(FarmUnit *unit) {
}

void CropField::removeFarmUnit(FarmUnit *unit) {
}

FarmIterator CropField::getIterator() {
}
