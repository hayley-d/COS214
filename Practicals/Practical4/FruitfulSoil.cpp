#include "FruitfulSoil.h"

#include "FloodedSoil.h"

std::string & FruitfulSoil::getName() {
    return this->name;
}

void FruitfulSoil::rain() {
    this->farmUnit->changeSoilState("Flooded");
}

void FruitfulSoil::harvestCrops() {
    int spaceNeeded = farmUnit->getCropType().harvestYield * 3;
    if(farmUnit->hasStorageSpace(spaceNeeded)) {
        this->farmUnit->storeCrops(3);
    } else {
        std::cout << "More space required for harvest, build a new barn." <<std::endl;
    }
}

void FruitfulSoil::fertilize() {
    std::cout << "Applying fertilizer to fruitful crops..nothing happend" << std::endl;
    //does nothing
}
