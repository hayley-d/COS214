#include "FarmUnit.h"

struct FarmUnit::pImplFarmUnit{
    int totalCapacity;
    int surfaceArea;
};

FarmUnit::FarmUnit(int totalCapacity, int surfaceArea) {
    this->impl = std::make_unique<pImplFarmUnit>();
    this->impl->surfaceArea = surfaceArea;
    this->impl->totalCapacity = totalCapacity;
}
