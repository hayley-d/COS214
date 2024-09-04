#ifndef FRUITFULSOIL_H
#define FRUITFULSOIL_H
#include "SoilState.h"

/**
 * @class FruitfulSoil
 * @brief Concrete implementation of SoilState representing a fruitful soil state.
 *
 * The FruitfulSoil class defines the behavior of a farm unit when the soil is fruitful.
 * It overrides the methods of SoilState to provide specific functionality for
 * handling the fruitful soil state, including reacting to rainfall and harvesting crops.
 */
class FruitfulSoil : public SoilState {
public:
    /**
     * @brief Constructor for DrySoil.
     * @param farmUnit A reference to the FarmUnit associated with this soil state.
     *
     * Initializes the SoilState with a reference to the FarmUnit it belongs to and the soil state's name
     */
    FruitfulSoil(FarmUnit &farmUnit) : SoilState(farmUnit, "Fruitful Soil") {
    }

    /**
     * @brief Destructor for DrySoil.
     *
     * Cleans up resources used by the DrySoil state.
     */
    ~FruitfulSoil() override = default;

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
     * This method defines how the fruitful soil state changes in response to rainfall.
     * When rain() fruitful soil becomes flooded soil
     */
    void rain() override;

    /**
     * @brief Harvests crops based on the dry soil state.
     *
     * This method defines the process of harvesting crops when the soil is in a fruitful state.
     * In fruitful state the soil yields x3 crops
     */
    void harvestCrops() override;
};


#endif //FRUITFULSOIL_H
