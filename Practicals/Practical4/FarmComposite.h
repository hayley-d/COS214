#ifndef FARMCOMPOSITE_H
#define FARMCOMPOSITE_H
#include <vector>
#include "SoilState.h"
#include "FarmUnit.h"
#include "DFSStrategy.h"
#include "BFSStrategy.h"

class FarmComposite : public FarmUnit {
    typedef std::shared_ptr<FarmUnit> FarmUnitPtr; ///< Type alias for shared pointer to FarmUnit.
    typedef std::vector<std::shared_ptr<FarmUnit> > FarmUnitPtrVector;

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
    FarmComposite(int totalCapacity, int surfaceArea, CropType cropType, SoilState &soilState) : FarmUnit(
        totalCapacity, surfaceArea, cropType, soilState) {
    }

    virtual void addFarmUnit(FarmUnitPtr unit) = 0;

    virtual void removeFarmUnit(FarmUnitPtr unit) = 0;
};
#endif //FARMCOMPOSITE_H
