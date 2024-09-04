#ifndef FARMCOMPOSITE_H
#define FARMCOMPOSITE_H
#include <vector>
#include "SoilState.h"
#include "FarmUnit.h"
class FarmComposite : public FarmUnit {
public:
    /**
     * @brief Constructor for the `FarmUnit` class.
     *
     * Initializes a `FarmUnit` with the given total capacity and surface area.
     *
     * @param totalCapacity The total capacity of the farm unit.
     * @param surfaceArea The surface area of the farm unit.
     * @param cropType The crop type of the farm unit.
     * @param soilState The soil state of the farm unit.
     */
    FarmComposite(int totalCapacity, int surfaceArea, Crop cropType, SoilState& soilState) : FarmUnit(totalCapacity,  surfaceArea,  cropType,  soilState){}
    virtual void addFarmUnit(FarmUnit* unit) = 0;
    virtual void removeFarmUnit(FarmUnit * unit) = 0;
    virtual std::vector<FarmUnit*>& getFarms();
};
#endif //FARMCOMPOSITE_H
