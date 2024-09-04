#include "FarmUnit.h"

#include "Crop.h"

struct FarmUnit::pImplFarmUnit {
    int totalCapacity;
    int surfaceArea;
    Crop crop;
    SoilState *soilState;
    int currentCapacity = 0;

    pImplFarmUnit(int totalCapacity, int surfaceArea, Crop crop,
                  SoilState &soilState) : totalCapacity(totalCapacity), soilState(&soilState), surfaceArea(surfaceArea),
                                          crop(crop){}
};

FarmUnit::FarmUnit(int totalCapacity, int surfaceArea, CropType cropType, SoilState &soilState) {
    Crop crop (cropType);
    this->impl = std::make_unique<pImplFarmUnit>(totalCapacity,surfaceArea,crop,soilState);
}
