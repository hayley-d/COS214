#include "Farm.h"
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

int Farm::getTotalcapacity() {
    int total = this->impl->totalCapacity;
    FarmIterator it(new BFSStrategy(),this->farms);
    for(auto item = it.begin(); it != it.end(); ++it) {
        //implement
    }
}

int Farm::getSurfaceArea() {
    int total = this->impl->surfaceArea;
    FarmIterator it(new BFSStrategy(),this->farms);
    for(auto item = it.begin(); it != it.end(); ++it) {
        //implement
    }
}

std::string & Farm::getSoilStateName() {
    return this->impl->soilState->getName();
}

Crop Farm::getCropType() {
    return this->impl->crop;
}

void Farm::printFarm() {
}

void Farm::changeSoilState(SoilState &soilState) {
    //delete the current state
    delete this->impl->soilState;
    //add the new state
    this->impl->soilState = &soilState;
}


void Farm::addFarmUnit(FarmUnitPtr unit) {
    this->impl->totalCapacity += unit->getTotalcapacity();
    this->impl->surfaceArea += unit->getSurfaceArea();
    this->impl->currentCapacity += unit->getCurrentStorageCapacity();

    //add to vector
}

void Farm::removeFarmUnit(FarmUnitPtr unit) {

    //remove from vector and if success minus attributes
    this->impl->totalCapacity -= unit->getTotalcapacity();
    this->impl->surfaceArea -= unit->getSurfaceArea();
    this->impl->currentCapacity -= unit->getCurrentStorageCapacity();
}

std::unique_ptr<FarmIterator> Farm::getIterator() {
    return std::make_unique<FarmIterator>(farms);
}

void Farm::storeCrops(int harvestBonus) {
    this->impl->currentCapacity += (this->impl->crop.harvestYield*harvestBonus);
}

int Farm::getCurrentStorageCapacity() {
    return this->impl->currentCapacity();
}

bool Farm::hasStorageSpace(int spaceNeeded) {
    return (this->impl->currentCapacity()+spaceNeeded) <= this->impl->totalCapacity();
}

bool Farm::isComposite() const {
    return true;
}
