#ifndef BARN_H
#define BARN_H
#include "FarmUnit.h"


class Barn : public FarmUnit{
public:
    Barn(int totalCapacity, int surfaceArea, CropType cropType) : FarmUnit(
        totalCapacity, surfaceArea, cropType) {}

    void printFarm() override;

};

#endif //BARN_H
