/*
#include "Farm.h"
#include "SoilState.h"
#include <algorithm>

#include "Barn.h"
#include "DrySoil.h"
#include "FloodedSoil.h"
#include "FruitfulSoil.h"
#include "Truck.h"
*/

/*
struct FarmUnit::pImplFarmUnit {
    int totalCapacity;
    int surfaceArea;
    Crop crop;
    std::unique_ptr<SoilState> soilState;
    int currentCapacity = 0;
    std::vector<Truck *> observers;
    std::vector<std::shared_ptr<FarmUnit>> farms;

    pImplFarmUnit(const int totalCapacity,const int surfaceArea, const Crop crop,
                  std::unique_ptr<SoilState> soilState) : totalCapacity(totalCapacity), surfaceArea(surfaceArea),
                                          crop(crop) , soilState(std::move(soilState)) {
        //farms.push_back(std::make_shared<Barn>(12,12,Corn));
        std::cout << "I was created" << std::endl;
    }

    std::vector<std::shared_ptr<FarmUnit>>* getFarms() {
        return &farms;
    }

    std::vector<std::shared_ptr<FarmUnit>> getFarm() {
        return farms;
    }

    void addUnit( std::shared_ptr<FarmUnit> unit) {
        std::cout << "Hi" << std::endl;
        farms.push_back(unit);
    }

    ~pImplFarmUnit() {
        for(const auto item : observers) {
            delete item;
        }
        observers.clear();
    };
};

int Farm::getTotalcapacity() {
    //if empty then return only this farm
    if(this->impl->getFarms()->empty()) return this->impl->totalCapacity;

    //add current farm capacity
    int total = this->impl->totalCapacity;

    //create iterator
    FarmIterator it(std::make_shared<BFSStrategy>(), this->impl->getFarms());

    //iterate through the children summing the total
    for (auto item = it.begin(); it != it.end(); ++it) {
       total += item->getTotalcapacity();
    }

    //return total
    return total;
}

int Farm::getSurfaceArea() {
    //If no children then only return the current value
    if(this->impl->getFarms()->empty()) return this->impl->surfaceArea;

    //add onto the current value
    int total = this->impl->surfaceArea;
    //create iterator
    FarmIterator it(std::make_shared<BFSStrategy>(), this->impl->getFarms());
    //iterator through adding to the total
    for (auto item = it.begin(); it != it.end(); ++it) {
        total += item->getSurfaceArea();
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
    //if empty do nothing
    if(this->impl->getFarms()->empty()) return;
    //create iterator
    FarmIterator it(std::make_shared<BFSStrategy>(), this->impl->getFarms());
    //iterate through
    for (auto item = it.begin(); it != it.end(); ++it) {
        item->printFarm();
    }
}

void Farm::changeSoilState(std::string soilState) {
    if (soilState == "Fruitful") {
        this->impl->soilState = std::make_unique<FruitfulSoil>(*this);
    } else if (soilState == "Flooded") {
        this->impl->soilState = std::make_unique<FloodedSoil>(*this);
    } else {
        this->impl->soilState = std::make_unique<DrySoil>(*this);  // Default case
    }

    //if the new state is dry notify the observers
    if (this->impl->soilState->getName() == "Dry Soil") {
        //call the notify() method to notify observers
        this->callTruck(Event::SOIL_CHANGE);
    }
}

//tested
void Farm::addFarmUnit(FarmUnitPtr unit) {
    this->impl->getFarms()->push_back(unit);
}

void Farm::removeFarmUnit(const FarmUnitPtr unit) {
    //if empty do nothing
    if(this->impl->getFarms()->empty()) return;

    //check if in the vector by using iterator
    bool found = false;

    //create iterator
    FarmIterator it(this->impl->getFarms());

    for (auto item = it.begin(); it != it.end(); ++it) {
        if(*it == unit) {
            found = true;
            break;
        }
    }

    if(!found) return;

    std::cout << "Removing unit...." << std::endl;

    //remove from vector and if success minus attributes
    this->impl->totalCapacity -= unit->getTotalcapacity();
    this->impl->surfaceArea -= unit->getSurfaceArea();
    this->impl->currentCapacity -= unit->getCurrentStorageCapacity();
}

std::unique_ptr<FarmIterator> Farm::getIterator() {
    return std::make_unique<FarmIterator>(this->impl->getFarms());
}

void Farm::storeCrops(int harvestBonus) {
    this->impl->currentCapacity += (this->impl->crop.harvestYield * harvestBonus);
}

int Farm::getCurrentStorageCapacity() {
    if(this->impl->getFarms()->empty()) return 0;
    return this->impl->currentCapacity;
}

bool Farm::hasStorageSpace(int spaceNeeded) {
    if(this->impl->getFarms()->empty()) return true;
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
    if(this->impl->getFarms()->empty()) return;
    FarmIterator it(std::make_shared<BFSStrategy>(), this->impl->getFarms());
    for (auto item = it.begin(); it != it.end(); ++it) {
        it->collectCrops();
    }
    this->impl->currentCapacity = 0;
}

std::vector<std::shared_ptr<FarmUnit>> Farm::getChildren() const {
    return this->impl->getFarm();
}
*/
