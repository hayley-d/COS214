#include "FruitfulSoil.h"

#include "FloodedSoil.h"

std::string & FruitfulSoil::getName() {
    return this->name;
}

void FruitfulSoil::rain() {
    this->farmUnit->changeSoilState(new FloodedSoil(*this->farmUnit));
}

void FruitfulSoil::harvestCrops() {

}
