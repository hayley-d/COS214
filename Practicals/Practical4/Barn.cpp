#include "Barn.h"
struct FarmUnit::pImplFarmUnit {
    int totalCapacity;
    int surfaceArea;
    Crop crop;
    SoilState *soilState;
    int currentCapacity = 0;

    pImplFarmUnit(int totalCapacity, int surfaceArea, Crop crop,
                  SoilState &soilState) : totalCapacity(totalCapacity), soilState(&soilState), surfaceArea(surfaceArea),
                                          crop(crop){}
};

int Barn::getTotalcapacity() {
    return this->impl->totalCapacity;
}

std::string & Barn::getSoilStateName() {
    return this->impl->soilState->getName();
}

Crop Barn::getCropType() {
    return this->impl->crop;
}

int Barn::getSurfaceArea() {
    return this->impl->surfaceArea;
}

FarmIterator Barn::end() {
    //leaf node does not have an iterator
    return nullptr;
}

std::unique_ptr<FarmIterator> Barn::getIterator() {
    //leaf node does not have an iterator
    return nullptr;
}

void Barn::changeSoilState(SoilState &soilState) {
    //delete the current state
    delete this->impl->soilState;
    //add the new state
    this->impl->soilState = &soilState;
}

void Barn::storeCrops(int harvestBonus) {
    this->impl->currentCapacity += (this->impl->crop.harvestYield*harvestBonus);
}

int Barn::getCurrentStorageCapacity() {
    return this->impl->currentCapacity();
}

bool Barn::hasStorageSpace(int spaceNeeded) {
    return (this->impl->currentCapacity()+spaceNeeded) <= this->impl->totalCapacity();
}

FarmIterator Barn::begin() {
    //leaf node does not have an iterator
    return nullptr;
}

void Barn::printFarm() {

}
