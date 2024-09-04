#ifndef FLOODEDSOIL_H
#define FLOODEDSOIL_H
#include "SoilState.h"

/**
 * @class FloodedSoil
 * @brief Concrete implementation of SoilState representing a flooded soil state.
 *
 * The FloodedSoil class defines the behavior of a farm unit when the soil is flooded.
 * It overrides the methods of SoilState to provide specific functionality for
 * handling the flooded soil state, including reacting to rainfall and harvesting crops.
 */
class FloodedSoil : public SoilState{
public:
    /**
     * @brief Constructor for DrySoil.
     * @param farmUnit A reference to the FarmUnit associated with this soil state.
     *
     * Initializes the SoilState with a reference to the FarmUnit it belongs to and the soil state's name
     */
    FloodedSoil(FarmUnit &farmUnit) : SoilState(farmUnit, "Fruitful Soil") {
    }

    /**
     * @brief Destructor for DrySoil.
     *
     * Cleans up resources used by the DrySoil state.
     */
    ~FloodedSoil() override = default;

    /**
    * @brief Returns the name of the soil state.
    * @return A reference to a string containing the name "Dry Soil".
    *
    * This method provides the specific name of this soil state, which is "Dry Soil".
    */
    std::string &getName() override;

    /**
     * @brief Simulates the effect of rain on dry soil.
     *
     * This method defines how the flooded soil state changes in response to rainfall.
     * When rain() nothing happens the soil becomes more flooded
     */
    void rain() override;

    /**
     * @brief Harvests crops based on the dry soil state.
     *
     * This method defines the process of harvesting crops when the soil is in a flooded state.
     * In flooded state the soil prevents crop growth, crops cannot be harvested in this state
     */
    void harvestCrops() override;
};



#endif //FLOODEDSOIL_H
