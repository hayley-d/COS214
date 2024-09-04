#include "FruitfulSoil.h"

#include "FloodedSoil.h"

std::string & FruitfulSoil::getName() {
    return this->name;
}

void FruitfulSoil::rain() {
    this->farmUnit->changeSoilState(new FloodedSoil(*this->farmUnit));
}

void FruitfulSoil::harvestCrops() {
    int spaceNeeded = farmUnit->getCropType().harvestYield * 3;
    if(farmUnit->hasStorageSpace(spaceNeeded)) {
        this->farmUnit->storeCrops(3);
    } else {
        std::cout << "More space required for harvest, build a new barn." <<std::endl;
    }
}
