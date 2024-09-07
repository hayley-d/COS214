/*#include "CropField.h"

#include <algorithm>

#include "DrySoil.h"
#include "FloodedSoil.h"
#include "FruitfulSoil.h"
#include "Truck.h"
#include "Barn.h"

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
        farms.push_back(std::make_shared<Barn>(12,12,Corn));
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
};*/

/*
int CropField::getTotalcapacity() {
    if(this->impl->getFarms()->empty()) return this->impl->totalCapacity;
    int total = this->impl->totalCapacity;
    FarmIterator it(std::make_shared<BFSStrategy>(), this->impl->getFarms());
    for (auto item = it.begin(); it != it.end(); ++it) {
        //implement
        std::cout << "Farm Unit added to the crop field" << std::endl;
    }
    return total;
}

int CropField::getSurfaceArea() {
    if(this->impl->getFarms()->empty()) return this->impl->surfaceArea;
    int total = this->impl->surfaceArea;
    FarmIterator it(std::make_shared<BFSStrategy>(), this->impl->getFarms());
    for (auto item = it.begin(); it != it.end(); ++it) {
        //implement
        std::cout << "Farm Unit added to the crop field" << std::endl;
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
    if(this->impl->getFarms()->empty()) return;
}

void CropField::changeSoilState(std::string soilState) {
    if (soilState == "Fruitful") {
        this->impl->soilState = std::make_unique<FruitfulSoil>(*this);
    } else if (soilState == "Flooded") {
        this->impl->soilState = std::make_unique<FloodedSoil>(*this);
    } else {
        this->impl->soilState = std::make_unique<DrySoil>(*this);  // Default case
    }

    if (this->impl->soilState->getName() == "Dry Soil") {
        this->callTruck(Event::SOIL_CHANGE);
    }
}

void CropField::addFarmUnit(const FarmUnitPtr unit) {
    this->impl->addUnit(unit);
    std::cout << "Farm Unit added to the crop field" << std::endl;
}

void CropField::removeFarmUnit(FarmUnitPtr unit) {
    if(this->impl->getFarms()->empty()) return;
}

std::unique_ptr<FarmIterator> CropField::getIterator() {
    return std::make_unique<FarmIterator>( this->impl->getFarms());
}

void CropField::storeCrops(const int harvestBonus) {
    this->impl->currentCapacity += (this->impl->crop.harvestYield * harvestBonus);
}

int CropField::getCurrentStorageCapacity() {
    return this->impl->currentCapacity;
}

bool CropField::hasStorageSpace(int spaceNeeded) {
    if(this->impl->getFarms()->empty()) return true;
    bool space = (this->impl->currentCapacity + spaceNeeded) <= this->impl->totalCapacity;
    if (!space) {
        this->callTruck(Event::STORAGE_FULL);
    }
    return space;
}

bool CropField::isComposite() const {
    return true;
}

std::vector<std::shared_ptr<FarmUnit>> CropField::getChildren() const {
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

void CropField::collectCrops(){
    if(this->impl->getFarms()->empty()) return;
    FarmIterator it(std::make_shared<BFSStrategy>(), this->impl->getFarms());
    for (auto item = it.begin(); it != it.end(); ++it) {
        it->collectCrops();
    }
    this->impl->currentCapacity = 0;
}
*/
