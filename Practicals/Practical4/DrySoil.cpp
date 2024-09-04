#include "DrySoil.h"

#include "FruitfulSoil.h"

std::string & DrySoil::getName() {
    return this->name;
}

void DrySoil::rain() {
    this->farmUnit->changeSoilState(new FruitfulSoil(*this->farmUnit));
}

void DrySoil::harvestCrops() {
}
