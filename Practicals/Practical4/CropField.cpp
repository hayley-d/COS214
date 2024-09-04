#include "CropField.h"

#include <algorithm>

#include "Truck.h"

struct FarmUnit::pImplFarmUnit {
    int totalCapacity;
    int surfaceArea;
    Crop crop;
    SoilState *soilState;
    int currentCapacity = 0;
    std::vector<Truck *> observers;

    pImplFarmUnit(int totalCapacity, int surfaceArea, Crop crop,
                  SoilState &soilState) : totalCapacity(totalCapacity), soilState(&soilState), surfaceArea(surfaceArea),
                                          crop(crop) {
    }
};

int CropField::getTotalcapacity() {
    int total = this->impl->totalCapacity;
    FarmIterator it(new BFSStrategy(), this->farms);
    for (auto item = it.begin(); it != it.end(); ++it) {
        //implement
    }
}

int CropField::getSurfaceArea() {
    int total = this->impl->surfaceArea;
    FarmIterator it(new BFSStrategy(), this->farms);
    for (auto item = it.begin(); it != it.end(); ++it) {
        //implement
    }
}

std::string &CropField::getSoilStateName() {
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

    if (this->impl->soilState->getName() == "Dry Soil") {
        this->callTruck(Event::SOIL_CHANGE);
    }
}

void CropField::addFarmUnit(FarmUnitPtr unit) {
}

void CropField::removeFarmUnit(FarmUnitPtr unit) {
}

std::unique_ptr<FarmIterator> CropField::getIterator() {
    return std::make_unique<FarmIterator>(farms);
}

void CropField::storeCrops(int harvestBonus) {
    this->impl->currentCapacity += (this->impl->crop.harvestYield * harvestBonus);
}

int CropField::getCurrentStorageCapacity() {
    return this->impl->currentCapacity();
}

bool CropField::hasStorageSpace(int spaceNeeded) {
    bool space = (this->impl->currentCapacity() + spaceNeeded) <= this->impl->totalCapacity();
    if (!space) {
        this->callTruck(Event::STORAGE_FULL);
    }
    return space;
}

bool CropField::isComposite() const {
    return true;
}

std::vector<std::shared_ptr<FarmUnit> > CropField::getChildren() const {
    return this->farms;
}

void CropField::buyTruck(Truck &truck) {
    this->impl->observers.push_back(&truck);
}

void CropField::sellTruck(Truck &truck) {
    // Use an iterator to find the truck in the trucks vector
    auto it = std::find_if(this->impl->observers.begin(), this->impl->observers.end(),
                           [&truck](Truck *t) {
                               return t == &truck;
                           });

    // If the truck is found, remove it from the vector
    if (it != this->impl->observers.end()) {
        this->impl->observers.erase(it);
    }
}

void CropField::callTruck(Event e) {
    for (auto ob: this->impl->observers) {
        ob->startEngine(e);
    }
}

void CropField::fertilizeCrops() {
    this->impl->soilState->fertilize();
}

void CropField::collectCrops() {
    FarmIterator it(new BFSStrategy(), this->farms);
    for (auto item = it.begin(); it != it.end(); ++it) {
        it->collectCrops();
    }
    this->impl->currentCapacity = 0;
}
