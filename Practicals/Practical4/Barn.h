#ifndef BARN_H
#define BARN_H
#include "FarmUnit.h"


class Barn : FarmUnit{
public:
    int getTotalcapacity() override;

    std::string & getSoilStateName() override;

    Crop getCropType() override;

    int getSurfaceArea() override;

    FarmIterator end() override;

    std::unique_ptr<FarmIterator> getIterator() override;

    void changeSoilState(SoilState &soilState) override;

    void storeCrops(int harvestBonus) override;

    int getCurrentStorageCapacity() override;

    bool hasStorageSpace(int spaceNeeded) override;

    FarmIterator begin() override;

    void printFarm() override;
};



#endif //BARN_H
