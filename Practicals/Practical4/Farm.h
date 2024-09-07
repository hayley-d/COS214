#ifndef FARM_H
#define FARM_H

#include "FarmComposite.h"
/**
 * @class Farm
 * @brief Represents a concrete implementation of a farm that is a composite of various farm units.
 *
 * The `Farm` class extends `FarmComposite` and represents a collection of crop fields, barns,
 * or other farm units. It aggregates these units and provides methods to interact with them.
 */
class Farm : public FarmComposite {
    typedef std::shared_ptr<FarmUnit> FarmUnitPtr; ///< Type alias for shared pointer to `FarmUnit`.
    typedef std::vector<std::shared_ptr<FarmUnit> > FarmUnitPtrVector;
    ///< Type alias for vector of shared pointers to `FarmUnit`.
public:


    /**
     * @brief Constructor for the `Farm` class.
     *
     * Initializes a `Farm` with the given soil state, and default values for capacity, surface area, and crop type.
     *  soilState A reference to the soil state for the farm by default is fruitful
     * @param cropType A crop type for the farm.
     */
    Farm(CropType cropType) : FarmComposite(
        0, 0, cropType) {
    }

    /**
     * @brief Gets the total capacity of the farm.
     * Calculates and returns the total capacity of the farm by summing up the capacities of all child units.
     * @return The total capacity of the farm as an integer.
     */
    int getTotalcapacity() override;

    /**
     * @brief Gets the surface area of the farm.
     * Calculates and returns the surface area of the farm by summing up the surface areas of all child units.
     * @return The surface area of the farm as an integer.
     */
    int getSurfaceArea() override;

    /**
     * @brief Prints the details of the farm and its farm units.
     * Displays information about the farm, including its child units.
     */
    void printFarm() override;

    /**
     * @brief Changes the soil state of the farm.
     * Updates the soil state of the farm to the specified new value.
     * @param soilState A reference to the new soil state.
     */
    void changeSoilState(std::string soilState) override;

    /**
     * @brief Adds a farm unit to the farm.
     *
     * Adds a new farm unit to the collection of units in the farm.
     *
     * @param unit A shared pointer to the farm unit to be added.
     */
    void addFarmUnit(FarmUnitPtr unit) override;

    /**
     * @brief Removes a farm unit from the farm.
     *
     * Removes the specified farm unit from the collection of units in the farm.
     *
     * @param unit A shared pointer to the farm unit to be removed.
     */
    void removeFarmUnit(FarmUnitPtr unit) override;

    /**
     * @brief Returns a unique pointer to an iterator for the farm's collection.
     * Provides an iterator that can be used to traverse the farm's collection of units.
     * @return A unique pointer to a `FarmIterator` for the farm's collection.
     */
    std::unique_ptr<FarmIterator> getIterator() override;

    /**
     * @brief Gets the current storage capacity of the farm.
     *
     * Returns the amount of storage capacity currently available in the farm.
     *
     * @return The current storage capacity as an integer.
     */
    int getCurrentStorageCapacity() override;

    /**
     * @brief Checks if the farm is a composite of multiple units.
     *
     * Determines whether the farm is a composite (i.e., it contains other farm units).
     *
     * @return `true` if the farm is a composite, `false` otherwise.
     */
    bool isComposite() const override;

    void collectCrops() override;

    std::vector<std::shared_ptr<FarmUnit>> getChildren() const override;


};


#endif //FARM_H
