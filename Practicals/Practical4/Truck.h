#ifndef TRUCK_H
#define TRUCK_H
#include <memory>

#include "Event.h"
#include "FarmUnit.h"

/**
 * @class Truck
 * @brief Abstract base class representing a truck that observes a FarmUnit.
 *
 * The Truck class acts as an observer in the observer pattern. It monitors a
 * `FarmUnit` and performs actions when the engine starts.
 */
class Truck {
public:
     Truck(){}
    /**
     * @brief Constructs a Truck object with the specified FarmUnit.
     * @param farmUnit A shared pointer to a FarmUnit that the truck will observe.
     */
    Truck(std::shared_ptr<FarmUnit>& farmUnit) : subject(farmUnit){}
    /**
     * @brief Pure virtual function to start the truck's engine.
     *
     * This function must be overridden by derived classes to implement the
     * specific behavior when the truck's engine starts.
     */
    virtual void startEngine(Event e) = 0;//the update method for the observer pattern
    /**
     * @brief Virtual destructor for Truck.
     *
     * Ensures proper cleanup of resources in derived classes.
     */
    virtual ~Truck() = default;

protected:
    std::shared_ptr<FarmUnit> subject;///< Shared pointer to the observed FarmUnit.
};
#endif //TRUCK_H
