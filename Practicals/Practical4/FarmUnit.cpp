#include "FarmUnit.h"
#include "Truck.h"
#include "Crop.h"
#include "Farm.h"
#include "FruitfulSoil.h"
#include "SoilState.h"
#include <algorithm>

#include "Barn.h"
#include "CropField.h"
#include "DrySoil.h"
#include "FloodedSoil.h"


struct FarmUnit::pImplFarmUnit {
    int totalCapacity;
    int surfaceArea;
    Crop crop;
    std::unique_ptr<SoilState> soilState;
    int currentCapacity = 0;
    std::vector<Truck *> observers;
    std::vector<std::shared_ptr<FarmUnit> > farms;

    pImplFarmUnit(const int totalCapacity, const int surfaceArea, const Crop crop,
                  std::unique_ptr<SoilState> soilState) : totalCapacity(totalCapacity), surfaceArea(surfaceArea),
                                                          crop(crop), soilState(std::move(soilState)) {
        //farms.push_back(std::make_shared<Barn>(12,12,Corn));
    }

    std::vector<std::shared_ptr<FarmUnit> > *getFarms() {
        return &farms;
    }

    std::vector<std::shared_ptr<FarmUnit> > getFarm() {
        return farms;
    }

    void addUnit(std::shared_ptr<FarmUnit> unit) {
        farms.push_back(unit);
    }

    ~pImplFarmUnit() {
        for (const auto item: observers) {
            delete item;
        }
        observers.clear();
    };
};

FarmUnit::FarmUnit(int totalCapacity, int surfaceArea, CropType cropType) {
    Crop crop(cropType);
    this->impl = new pImplFarmUnit(totalCapacity, surfaceArea, crop, std::make_unique<FruitfulSoil>(*this));
}

FarmUnit::~FarmUnit() {
    delete impl;
}

int Farm::getTotalcapacity() {
    //if empty then return only this farm
    if (this->impl->getFarms()->empty()) return this->impl->totalCapacity;

    //add current farm capacity
    int total = this->impl->totalCapacity;

    //create iterator
    FarmIterator it(std::make_shared<BFSStrategy>(), this->impl->getFarms());

    //iterate through the children summing the total
    while (!it.isDone()) {
        total += it->getSurfaceArea();
        ++it;
    }

    //return total
    return total;
}

int Farm::getSurfaceArea() {
    //If no children then only return the current value
    if (this->impl->getFarms()->empty()) return this->impl->surfaceArea;

    //add onto the current value
    int total = this->impl->surfaceArea;
    //create iterator
    FarmIterator it(std::make_shared<BFSStrategy>(), this->impl->getFarms());
    //iterator through adding to the total
    while (!it.isDone()) {
        total += it->getSurfaceArea();
        ++it;
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
    if (this->impl->getFarms()->empty()) return;
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
        this->impl->soilState = std::make_unique<DrySoil>(*this); // Default case
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
    if (this->impl->getFarms()->empty()) return;

    //check if in the vector by using iterator
    bool found = false;

    //create iterator
    FarmIterator it(this->impl->getFarms());

    for (auto item = it.begin(); it != it.end(); ++it) {
        if (*it == unit) {
            found = true;
            break;
        }
    }

    if (!found) return;

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
    if (this->impl->getFarms()->empty()) return 0;
    return this->impl->currentCapacity;
}

bool Farm::hasStorageSpace(int spaceNeeded) {
    if (this->impl->getFarms()->empty()) return true;
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
    if (this->impl->getFarms()->empty()) return;
    FarmIterator it(std::make_shared<BFSStrategy>(), this->impl->getFarms());
    for (auto item = it.begin(); it != it.end(); ++it) {
        it->collectCrops();
    }
    this->impl->currentCapacity = 0;
}

std::vector<std::shared_ptr<FarmUnit> > Farm::getChildren() const {
    return this->impl->getFarm();
}

int CropField::getTotalcapacity() {
    if (this->impl->getFarms()->empty()) return this->impl->totalCapacity;

    int total = this->impl->totalCapacity;

    FarmIterator it(std::make_shared<BFSStrategy>(), this->impl->getFarms());

    while (!it.isDone()) {
        total += it->getSurfaceArea();
        ++it;
    }
    return total;
}

int CropField::getSurfaceArea() {
    if (this->impl->getFarms()->empty()) return this->impl->surfaceArea;
    int total = this->impl->surfaceArea;
    FarmIterator it(std::make_shared<BFSStrategy>(), this->impl->getFarms());
    while (!it.isDone()) {
        total += it->getSurfaceArea();
        ++it;
    }
    return total;
}

std::string &CropField::getSoilStateName() {
    return this->impl->soilState->getName();
}

Crop CropField::getCropType() {
    return this->impl->crop;
}

void CropField::printFarm() {
    if (this->impl->getFarms()->empty()) return;
}

void CropField::changeSoilState(std::string soilState) {

    if (soilState == "Fruitful") {
        this->impl->soilState = std::make_unique<FruitfulSoil>(*this);
    } else if (soilState == "Flooded") {
        this->impl->soilState = std::make_unique<FloodedSoil>(*this);
    } else {
        this->impl->soilState = std::make_unique<DrySoil>(*this); // Default case
    }

    if (this->impl->soilState->getName() == "Dry Soil") {
        this->callTruck(Event::SOIL_CHANGE);
    }
}

void CropField::addFarmUnit(const FarmUnitPtr unit) {
    this->impl->getFarms()->push_back(unit);
}

void CropField::removeFarmUnit(FarmUnitPtr unit) {
    if (this->impl->getFarms()->empty()) return;
}

std::unique_ptr<FarmIterator> CropField::getIterator() {
    return std::make_unique<FarmIterator>(this->impl->getFarms());
}

void CropField::storeCrops(const int harvestBonus) {
    this->impl->currentCapacity += (this->impl->crop.harvestYield * harvestBonus);
}

int CropField::getCurrentStorageCapacity() {
    return this->impl->currentCapacity;
}

bool CropField::hasStorageSpace(int spaceNeeded) {
    if (this->impl->getFarms()->empty()) return true;
    bool space = (this->impl->currentCapacity + spaceNeeded) <= this->impl->totalCapacity;
    if (!space) {
        this->callTruck(Event::STORAGE_FULL);
    }
    return space;
}

bool CropField::isComposite() const {
    return true;
}

std::vector<std::shared_ptr<FarmUnit> > CropField::getChildren() const {
    return this->impl->getFarm();
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
    if (this->impl->getFarms()->empty()) return;
    FarmIterator it(std::make_shared<BFSStrategy>(), this->impl->getFarms());
    for (auto item = it.begin(); it != it.end(); ++it) {
        it->collectCrops();
    }
    this->impl->currentCapacity = 0;
}

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

void Barn::changeSoilState(std::string soilState) {
    if (soilState == "Fruitful") {
        this->impl->soilState = std::make_unique<FruitfulSoil>(*this);
    } else if (soilState == "Flooded") {
        this->impl->soilState = std::make_unique<FloodedSoil>(*this);
    } else {
        this->impl->soilState = std::make_unique<DrySoil>(*this); // Default case
    }

    if (this->impl->soilState->getName() == "Dry Soil") {
        this->callTruck(Event::SOIL_CHANGE);
    }
}

void Barn::storeCrops(int harvestBonus) {
    this->impl->currentCapacity += (this->impl->crop.harvestYield * harvestBonus);
}

int Barn::getCurrentStorageCapacity() {
    return this->impl->currentCapacity;
}

bool Barn::hasStorageSpace(int spaceNeeded) {
    bool space = (this->impl->currentCapacity + spaceNeeded) <= this->impl->totalCapacity;
    if (!space) {
        this->callTruck(Event::STORAGE_FULL);
    }
    return space;
}

void Barn::printFarm() {
    std::cout << "Barn:\n" << "Total Capacity: " << this->impl->totalCapacity << "\nSurface Area: " << this->impl->
            surfaceArea << std::endl;
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

void Farm::makeItRain() {
    this->impl->soilState->rain();
    std::cout << "Making it rain" << std::endl;
}

void CropField::makeItRain() {
    this->impl->soilState->rain();
    std::cout << "Making it rain" << std::endl;
}

void Barn::makeItRain() {
    this->impl->soilState->rain();
    std::cout << "Making it rain" << std::endl;
}

void FarmUnit::heatWave() {
    this->changeSoilState("Dry");
    std::cout << "Soil dried out" << std::endl;
}
