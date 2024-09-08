#ifndef FARMUNIT_H
#define FARMUNIT_H
#include "Iterator.h"
#include <memory>
#include <vector>
#include "Crop.h"
#include "TraversalStrategy.h"
#include "FarmIterator.h"
#include "SoilState.h"
#include "Truck.h"

#include "Event.h"
class Truck;
class SoilState;
class FarmIterator;

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
     * soilState The soil state of the farm unit by default is fruitful
     */
    FarmUnit(int totalCapacity, int surfaceArea, CropType cropType);

    /**
     * @brief Gets the total capacity of the farm unit.
     *
     * This is a pure virtual function that must be implemented by derived classes.
     *
     * @return The total capacity of the farm unit.
     */
    virtual int getTotalcapacity();

    /**
     * @brief Gets the soil state name of the Farm unit
     * @return The soil state name
     */
    virtual std::string &getSoilStateName();

    /**
     * @brief Gets the crop type of the Farm unit
     * @return The crop type
     */
    virtual Crop getCropType();

    /**
     * @brief Gets the surface area of the farm unit.
     *
     * This is a pure virtual function that must be implemented by derived classes.
     *
     * @return The surface area of the farm unit.
     */
    virtual int getSurfaceArea();

    /**
     * @brief Virtual destructor for the `FarmUnit` class.
     *
     * Ensures proper cleanup of derived classes.
     */
    virtual ~FarmUnit() ;

    /**
     * @brief Returns an iterator to the start of the collection.
     * @return FarmIterator Iterator to the start of the collection.
     */
    virtual std::unique_ptr<FarmIterator> getIterator();

    /**
    * @brief Changes the soil state of the farm uni
    * @param soilState A reference to the new soil state of the farm unit
    */
    virtual void changeSoilState(std::string soilState);

    /**
     * @brief Stores the current crops
     * @param harvestBonus An int value for the harvest bonus if any
     */
     void storeCrops(int harvestBonus = 1);

    /**
     * @brief Returns the current storage capacity of the farm unit
     * @return An int value of the current storage capacity
     */
    virtual int getCurrentStorageCapacity();

    /**
     * @brief Returns a boolean value depending on if the farm unit has storage space
     * @param spaceNeeded An int value for how much storage space is required
     * @return An bool value indicating if the required space is available
     */
    virtual bool hasStorageSpace(int spaceNeeded);

    /**
     * @brief prints the current farm unit
     */
    virtual void printFarm() = 0;

    // Method to check if this unit is a composite (has children)
    virtual bool isComposite() const {
        return false; // By default, assume it's not a composite (leaf node)
    }

    // Method to get children (only valid for composites)
    virtual std::vector<std::shared_ptr<FarmUnit>> getChildren() const {
        return  {};
    }

     /**
    * @brief Attaches a new Truck (observer) to the FarmUnit.
    * @param truck a truck to add to the farm observer list
    * This method is used to add a Truck observer to the FarmUnit, allowing it to be notified of changes.
    */
    virtual void buyTruck(Truck& truck);

     /**
    * @brief Detaches a Truck (observer) from the FarmUnit.
    * @param truck a truck to sell
    * This method is used to remove a Truck observer from the FarmUnit, stopping it from receiving notifications.
    */
    virtual void sellTruck(Truck& truck);
    /**
   * @brief Notifies all attached Truck observers about changes.
   * @param e type of event to call correct truck type
   * This method is used to call all Truck observers, notifying them of any updates or changes in the FarmUnit.
   */
    virtual void callTruck(Event e);

     /**
    * @brief When the fertilizer truck delivers fertilizer it is added to the soil to change it from dry to fruitful
    */
    virtual void fertilizeCrops();

    virtual void collectCrops();

    virtual void makeItRain();

    virtual void heatWave();

 virtual void harvestWithBonus();

protected:
    /// The PImpl idiom for managing private implementation details.
    struct pImplFarmUnit;

    ///  pointer to the implementation details of the `FarmUnit`.
    pImplFarmUnit* impl;


    friend class Truck;
   friend class FarmDecorator;
};
#endif //FARMUNIT_H
