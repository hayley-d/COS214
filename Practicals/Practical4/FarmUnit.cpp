#include "FarmUnit.h"
#include "Truck.h"
#include "Crop.h"
#include "Farm.h"
#include "FruitfulSoil.h"
#include "SoilState.h"
#include <algorithm>
#include "FarmDecorator.h"
#include "Barn.h"
#include "CropField.h"
#include "DrySoil.h"
#include "FertilizerDecorator.h"
#include "FloodedSoil.h"
#include "StorageDecorator.h"


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

std::string &FarmUnit::getSoilStateName() {
    return this->impl->soilState->getName();
}

void Farm::printFarm() {
    //if empty do nothing
    if (this->impl->getFarms()->empty()) return;
    //create iterator
    FarmIterator it(std::make_shared<BFSStrategy>(), this->impl->getFarms());
    //iterate through
    while (!it.isDone()) {
        it->printFarm();
        ++it;
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

int Farm::getCurrentStorageCapacity() {
    if (this->impl->getFarms()->empty()) return 0;
    return this->impl->currentCapacity;
}


bool Farm::isComposite() const {
    return true;
}

void Farm::collectCrops() {
    std::cout << "Truck has come to pick up crops" << std::endl;
    if (this->impl->getFarms()->empty()) return;
    FarmIterator it(std::make_shared<BFSStrategy>(), this->impl->getFarms());

    //iterator through adding to the total
    while (!it.isDone()) {
        it->collectCrops();
        ++it;
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

void CropField::printFarm() {
    if (this->impl->getFarms()->empty()) return;
    FarmIterator it(std::make_shared<BFSStrategy>(), this->impl->getFarms());
    std::cout << "Crop Field:\n" << "\tTotal Capacity: " << this->impl->totalCapacity << "\n\tSurface Area: " << this->impl
            ->
            surfaceArea << std::endl;
    while (!it.isDone()) {
        it->printFarm();
        ++it;
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

int CropField::getCurrentStorageCapacity() {
    return this->impl->currentCapacity;
}

//healper function
bool CropField::isComposite() const {
    return true;
}

std::vector<std::shared_ptr<FarmUnit> > CropField::getChildren() const {
    return this->impl->getFarm();
}

//healper function
void CropField::collectCrops() {
    std::cout << "Truck has come to pick up crops" << std::endl;
    if (this->impl->getFarms()->empty()) return;
    FarmIterator it(std::make_shared<BFSStrategy>(), this->impl->getFarms());
    while (!it.isDone()) {
        it->collectCrops();
        ++it;
    }
    this->impl->currentCapacity = 0;
}

int FarmUnit::getTotalcapacity() {
    return this->impl->totalCapacity;
}

Crop FarmUnit::getCropType() {
    return this->impl->crop;
}

int FarmUnit::getSurfaceArea() {
    return this->impl->surfaceArea;
}

std::unique_ptr<FarmIterator> FarmUnit::getIterator() {
    //leaf node does not have an iterator
    return nullptr;
}

void FarmUnit::changeSoilState(std::string soilState) {
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

void FarmUnit::storeCrops(int harvestBonus) {
    this->impl->currentCapacity += (this->impl->crop.harvestYield * harvestBonus);
}

int FarmUnit::getCurrentStorageCapacity() {
    return this->impl->currentCapacity;
}

bool FarmUnit::hasStorageSpace(int spaceNeeded) {
    bool space = (this->impl->currentCapacity + spaceNeeded) <= this->impl->totalCapacity;
    if (!space) {
        this->callTruck(Event::STORAGE_FULL);
    }
    return space;
}

void Barn::printFarm() {
    std::cout << "Barn:\n" << "\tTotal Capacity: " << this->impl->totalCapacity << "\n\tSurface Area: " << this->impl->
            surfaceArea << std::endl;
}

void FarmUnit::buyTruck(Truck &truck) {
    this->impl->observers.push_back(&truck);
}

void FarmUnit::sellTruck(Truck &truck) {
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

void FarmUnit::callTruck(Event e) {
    for (auto ob: this->impl->observers) {
        ob->startEngine(e);
    }
}

void FarmUnit::fertilizeCrops() {
    this->impl->soilState->fertilize();
}

void FarmUnit::collectCrops() {
    this->impl->currentCapacity = 0;
}


void FarmUnit::heatWave() {
    this->changeSoilState("Dry");
    std::cout << "Soil dried out" << std::endl;
}

void FarmUnit::makeItRain() {
    this->impl->soilState->rain();
    std::cout << "Making it rain" << std::endl;
}

void StorageDecorator::addExtraBarn() {
    //add a new barn
    wrapee->addFarmUnit(std::make_shared<Barn>(100,100,wrapee->getCropType().crop));
}

int StorageDecorator::getLeftoverCapacity() {
    return wrapee->getTotalcapacity() - wrapee->getCurrentStorageCapacity();
}
void StorageDecorator::applyEnhancement() {
    addExtraBarn();
    std::cout << "Storage increased to " << getLeftoverCapacity() << std::endl;
}

void FertilizerDecorator::increaseProduction() {
    //notify fertilizer trucks
    wrapee->callTruck(Event::SOIL_CHANGE);
}
void FertilizerDecorator::harvest() {
    wrapee->storeCrops();

}
void FertilizerDecorator::applyEnhancement() {
    increaseProduction();
    harvest();
}