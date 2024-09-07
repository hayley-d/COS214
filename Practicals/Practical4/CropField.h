#ifndef CROPFIELD_H
#define CROPFIELD_H
#include<string>
#include <vector>
#include "FarmComposite.h"
/**
 * @class CropField
 * @brief Represents a crop field within a farm, derived from `FarmComposite` and `FarmUnit`.
 *
 * The `CropField` class is a concrete implementation of `FarmComposite`, representing
 * a specific crop field in a farm. It manages a collection of farm units, such as
 * crops fields or barns, and provides methods for interacting with them.
 */
class CropField : public FarmComposite {
    typedef std::shared_ptr<FarmUnit> FarmUnitPtr; ///< Type alias for shared pointer to FarmUnit.
    typedef std::vector<std::shared_ptr<FarmUnit> > FarmUnitPtrVector;
    ///< Type alias for vector of shared pointers to `FarmUnit`.

public:
    /**
     * @brief Constructor for the `CropField` class.
     *
     * Initializes a `CropField` with specified total capacity, surface area, crop type, and soil state.
     *
     * @param totalCapacity The total capacity of the crop field.
     * @param surfaceArea The surface area of the crop field.
     * @param cropType The type of crop grown in the field.
     * @param soilState A reference to the soil state of the crop field.
     */
    CropField(int totalCapacity, int surfaceArea, CropType cropType) : FarmComposite(
        totalCapacity, surfaceArea, cropType) {}

    /**
     * @brief Gets the total capacity of the crop field.
     * Calculates and returns the total capacity of the crop field, aggregating capacities of child units.
     * @return The total capacity of the crop field as an integer.
     */
    int getTotalcapacity() override;

    /**
     * @brief Gets the surface area of the crop field.
     *
     * Calculates and returns the surface area of the crop field, aggregating surface areas of child units.
     *
     * @return The surface area of the crop field as an integer.
     */
    int getSurfaceArea() override;

    /**
     * @brief Prints the details of the crop field and its farm units.
     *
     * Displays information about the crop field, including its child units.
     */
    void printFarm() override;


    /**
     * @brief Adds a farm unit to the crop field.
     *
     * Adds a new farm unit to the collection of units in the crop field.
     *
     * @param unit A shared pointer to the farm unit to be added.
     */
    void addFarmUnit(FarmUnitPtr unit) override;

    /**
     * @brief Removes a farm unit from the crop field.
     *
     * Removes the specified farm unit from the collection of units in the crop field.
     *
     * @param unit A shared pointer to the farm unit to be removed.
     */
    void removeFarmUnit(FarmUnitPtr unit) override;

    /**
     * @brief Returns a unique pointer to an iterator for the crop field's collection.
     *
     * Provides an iterator that can be used to traverse the crop field's collection of units.
     *
     * @return A unique pointer to a `FarmIterator` for the crop field's collection.
     */
    std::unique_ptr<FarmIterator> getIterator() override;

    /**
     * @brief Gets the current storage capacity of the crop field.
     *
     * Returns the amount of storage capacity currently available in the crop field.
     *
     * @return The current storage capacity as an integer.
     */
    int getCurrentStorageCapacity() override;

    /**
     * @brief Checks if the crop field is a composite of multiple units.
     *
     * Determines whether the crop field is a composite (i.e., it contains other farm units).
     *
     * @return `true` if the crop field is a composite, `false` otherwise.
     */
    bool isComposite() const override;

    /**
     * @brief Gets the child units of the crop field.
     *
     * Returns a vector of shared pointers to the child farm units within the crop field.
     *
     * @return A vector of shared pointers to `FarmUnit` objects.
     */
    FarmUnitPtrVector getChildren() const override;

    void collectCrops() override;



};


#endif //CROPFIELD_H
