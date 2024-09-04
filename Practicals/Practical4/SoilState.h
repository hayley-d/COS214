#ifndef SOILSTATE_H
#define SOILSTATE_H
#include <string>
#include <iostream>
#include "FarmUnit.h"

class FarmUnit;
/**
 * @class SoilState
 * @brief Abstract base class representing the state of the soil in a farm unit.
 *
 * The SoilState class defines the interface for various soil states. It allows
 * for simulating the effects of rain on the soil and harvesting crops based on
 * the current soil state. Concrete implementations of this class will define the
 * specific behavior for different soil states.
 */
class SoilState {
public:
    /**
     * @brief Constructor for SoilState.
     * @param farmUnit A reference to the FarmUnit associated with this soil state.
     * @param name A reference to the name associated with this soil state.
     * Initializes the SoilState with a reference to the FarmUnit it belongs to.
     */
    SoilState(FarmUnit &farmUnit, std::string name) {
        this->farmUnit = &farmUnit;
        this->name = name;
    }

    /**
     * @brief Virtual destructor for SoilState.
     *
     * Ensures proper cleanup of derived classes.
     */
    virtual ~SoilState() = default;

    /**
     * @brief Pure virtual function to get the name of the soil state.
     * @return A reference to a string containing the name of the soil state.
     *
     * This function must be implemented by derived classes to return the name
     * of the specific soil state.
     */
    virtual std::string &getName() = 0; //return the name of the soil state

    /**
     * @brief Pure virtual function to simulate rainfall that influences the soil state.
     *
     * This function must be implemented by derived classes to simulate how
     * rainfall affects the soil state.
     */
    virtual void rain() = 0;

    /**
     * @brief Pure virtual function to harvest crops based on the current soil state.
     *
     * This function must be implemented by derived classes to define how
     * crops are harvested depending on the current state of the soil.
     */
    virtual void harvestCrops() = 0;

    /**
     * @brief When the fertilizer is added to the dry soil it becomes fruitful
     */
    virtual void fertilize() = 0;

protected:
    /**
     * @brief Pointer to the FarmUnit associated with this soil state.
     */
    FarmUnit *farmUnit;

    /**
     * @brief The name of the soil state
     */
    std::string name;
};
#endif //SOILSTATE_H
