#include "Farm.h"
#include "SoilState.h"
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
                  SoilState &soilState) : totalCapacity(totalCapacity), surfaceArea(surfaceArea),
                                          crop(crop) , soilState(&soilState){
    }
};

int Farm::getTotalcapacity() {
    int total = this->impl->totalCapacity;
    FarmIterator it(new BFSStrategy(), this->farms);
    for (auto item = it.begin(); it != it.end(); ++it) {
        //implement
    }
    return total;
}

int Farm::getSurfaceArea() {
    int total = this->impl->surfaceArea;
    FarmIterator it(new BFSStrategy(), this->farms);
    for (auto item = it.begin(); it != it.end(); ++it) {
        //implement
    }
    return total;
}

std::string &Farm::getSoilStateName() {
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

    if (this->impl->soilState->getName() == "Dry Soil") {
        this->callTruck(Event::SOIL_CHANGE);
    }
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
    this->impl->currentCapacity += (this->impl->crop.harvestYield * harvestBonus);
}

int Farm::getCurrentStorageCapacity() {
    return this->impl->currentCapacity;
}

bool Farm::hasStorageSpace(int spaceNeeded) {
    bool space = (this->impl->currentCapacity + spaceNeeded) <= this->impl->totalCapacity;
    if (!space) {
        this->callTruck(Event::STORAGE_FULL);
    }
    return space;
}

bool Farm::isComposite() const {
    return true;
}

void Farm::buyTruck(Truck &truck) {
    this->impl->observers.push_back(&truck);
}

void Farm::sellTruck(Truck &truck) {
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

void Farm::callTruck(Event e) {
    for (auto ob: this->impl->observers) {
        ob->startEngine(e);
    }
}

void Farm::fertilizeCrops() {
    this->impl->soilState->fertilize();
}

void Farm::collectCrops() {
    FarmIterator it(new BFSStrategy(), this->farms);
    for (auto item = it.begin(); it != it.end(); ++it) {
        it->collectCrops();
    }
    this->impl->currentCapacity = 0;
}
