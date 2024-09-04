#include "FloodedSoil.h"

std::string & FloodedSoil::getName() {
    return this->name;
}

void FloodedSoil::rain() {
    //stays the same do nothing
    std::cout << "Rain has caused the soil to become more flooded" << std::endl;
}

void FloodedSoil::harvestCrops() {
    std::cout << "Soil is flooded, crops cannot be harvested at this time." << std::endl;
}

void FloodedSoil::fertilize() {
    //does nothing
}
