#include "CropField.h"

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

int CropField::getTotalcapacity() {
    int total = this->impl->totalCapacity;
    FarmIterator it(new BFSStrategy(),this->farms);
    for(auto item = it.begin(); it != it.end(); ++it) {
        //implement
    }
}

int CropField::getSurfaceArea() {
    int total = this->impl->surfaceArea;
    FarmIterator it(new BFSStrategy(),this->farms);
    for(auto item = it.begin(); it != it.end(); ++it) {
        //implement
    }
}

std::string & CropField::getSoilStateName() {
    return this->impl->soilState->getName();
}

Crop CropField::getCropType() {
    return this->impl->crop;
}

void CropField::printFarm() {
}

void CropField::changeSoilState(SoilState &soilState) {
    //delete the current state
    delete this->impl->soilState;
    //add the new state
    this->impl->soilState = &soilState;
}

void CropField::addFarmUnit(FarmUnitPtr unit) {
}

void CropField::removeFarmUnit(FarmUnitPtr unit) {
}

std::unique_ptr<FarmIterator> CropField::getIterator() {
    return std::make_unique<FarmIterator>(farms);
}

void CropField::storeCrops(int harvestBonus) {
    this->impl->currentCapacity += (this->impl->crop.harvestYield*harvestBonus);
}

int CropField::getCurrentStorageCapacity() {
    return this->impl->currentCapacity();
}

bool CropField::hasStorageSpace(int spaceNeeded) {
    return (this->impl->currentCapacity()+spaceNeeded) <= this->impl->totalCapacity();
}

bool CropField::isComposite() const {
    return true;
}

std::vector<std::shared_ptr<FarmUnit>> CropField::getChildren() const {
    return this->farms;
}
