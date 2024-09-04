#ifndef FARMUNIT_H
#define FARMUNIT_H
#include "Iterator.h"
#include <memory>
#include "Crop.h"

#include "FarmIterator.h"
#include "SoilState.h"


/**
 * @brief Abstract base class representing the component for the composite pattern
 *
 * The FarmUnit class serves as an interface for components of the composite pattern
 * which can have different capacities and surface areas. This class provides
 * a common interface for all farm units and enforces the implementation of
 * key methods in derived classes.
 * The class uses the PImpl (Pointer to Implementation) idiom to hide implementation
 * details and reduce compilation dependencies. The PImpl idiom is used to store
 * private data members and implementation details in a separate structure, which
 * is managed by a unique pointer.
 */
class FarmUnit {
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
    FarmUnit(int totalCapacity, int surfaceArea, CropType cropType, SoilState &soilState);

    /**
     * @brief Gets the total capacity of the farm unit.
     *
     * This is a pure virtual function that must be implemented by derived classes.
     *
     * @return The total capacity of the farm unit.
     */
    virtual int getTotalcapacity() = 0;

    /**
     * @brief Gets the soil state name of the Farm unit
     * @return The soil state name
     */
    virtual std::string &getSoilStateName() = 0;

    /**
     * @brief Gets the crop type of the Farm unit
     * @return The crop type
     */
    virtual Crop getCropType() = 0;

    /**
     * @brief Gets the surface area of the farm unit.
     *
     * This is a pure virtual function that must be implemented by derived classes.
     *
     * @return The surface area of the farm unit.
     */
    virtual int getSurfaceArea() = 0;

    /**
     * @brief Virtual destructor for the `FarmUnit` class.
     *
     * Ensures proper cleanup of derived classes.
     */
    virtual ~FarmUnit() = default;

    /**
     * @brief Returns an iterator to the end of the collection.
     *
     * This function should be implemented by derived classes to provide an iterator
     * representing the position beyond the last element of the collection.
     *
     * @return FarmIterator Iterator to the end of the collection.
     */
    virtual FarmIterator end() = 0;

    /**
     * @brief Returns an iterator to the start of the collection.
     * @return FarmIterator Iterator to the start of the collection.
     */
    virtual std::unique_ptr<FarmIterator> getIterator() = 0;

    /**
    * @brief Changes the soil state of the farm uni
    * @param soilState A reference to the new soil state of the farm unit
    */
    virtual void changeSoilState(SoilState &soilState) = 0;

    /**
     * @brief Stores the current crops
     * @param harvestBonus An int value for the harvest bonus if any
     */
    virtual void storeCrops(int harvestBonus = 1) = 0;

    /**
     * @brief Returns the current storage capacity of the farm unit
     * @return An int value of the current storage capacity
     */
    virtual int getCurrentStorageCapacity() = 0;

    /**
     * @brief Returns a boolean value depending on if the farm unit has storage space
     * @param spaceNeeded An int value for how much storage space is required
     * @return An bool value indicating if the required space is available
     */
    virtual bool hasStorageSpace(int spaceNeeded) = 0;

    /**
     * @brief Returns an iterator to the beginning of the collection.
     *
     * This function should be implemented by derived classes to provide an iterator
     * representing the start of the collection.
     *
     * @return FarmIterator Iterator to the beginning of the collection.
     */
    virtual FarmIterator begin() = 0;

    /**
     * @brief prints the current farm unit
     */
    virtual void printFarm() = 0;

    // Method to check if this unit is a composite (has children)
    virtual bool isComposite() const {
        return false; // By default, assume it's not a composite (leaf node)
    }

    // Method to get children (only valid for composites)
    virtual std::vector<std::shared_ptr<FarmUnit> > getChildren() const {
        return {}; // Return an empty vector by default
    }

protected:
    /// The PImpl idiom for managing private implementation details.
    struct pImplFarmUnit;

    /// Unique pointer to the implementation details of the `FarmUnit`.
    std::unique_ptr<pImplFarmUnit> impl;
};
#endif //FARMUNIT_H
