#include "Barn.h"

#include <algorithm>

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

int Barn::getTotalcapacity() {
    return this->impl->totalCapacity;
}

std::string &Barn::getSoilStateName() {
    return this->impl->soilState->getName();
}

Crop Barn::getCropType() {
    return this->impl->crop;
}

int Barn::getSurfaceArea() {
    return this->impl->surfaceArea;
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

    if (this->impl->soilState->getName() == "Dry Soil") {
        this->callTruck(Event::SOIL_CHANGE);
    }
}

void Barn::storeCrops(int harvestBonus) {
    this->impl->currentCapacity += (this->impl->crop.harvestYield * harvestBonus);
}

int Barn::getCurrentStorageCapacity() {
    return this->impl->currentCapacity();
}

bool Barn::hasStorageSpace(int spaceNeeded) {
    bool space = (this->impl->currentCapacity() + spaceNeeded) <= this->impl->totalCapacity();
    if (!space) {
        this->callTruck(Event::STORAGE_FULL);
    }
    return space;
}

void Barn::printFarm() {
}

void Barn::buyTruck(Truck &truck) {
    this->impl->observers.push_back(&truck);
}

void Barn::sellTruck(Truck &truck) {
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

void Barn::callTruck(Event e) {
    for (auto ob: this->impl->observers) {
        ob->startEngine(e);
    }
}

void Barn::fertilizeCrops() {
    this->impl->soilState->fertilize();
}

void Barn::collectCrops() {
    this->impl->currentCapacity = 0;
}
