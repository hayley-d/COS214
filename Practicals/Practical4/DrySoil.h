#ifndef DRYSOIL_H
#define DRYSOIL_H
#include "SoilState.h"

/**
 * @class DrySoil
 * @brief Concrete implementation of SoilState representing a dry soil state.
 *
 * The DrySoil class defines the behavior of a farm unit when the soil is dry.
 * It overrides the methods of SoilState to provide specific functionality for
 * handling the dry soil state, including reacting to rainfall and harvesting crops.
 */
class DrySoil : public SoilState{
public:
    /**
     * @brief Constructor for DrySoil.
     * @param farmUnit A reference to the FarmUnit associated with this soil state.
     *
     * Initializes the SoilState with a reference to the FarmUnit it belongs to and the soil state's name
     */
     DrySoil(FarmUnit& farmUnit) : SoilState(farmUnit,"Dry Soil") {
     }

    /**
     * @brief Destructor for DrySoil.
     *
     * Cleans up resources used by the DrySoil state.
     */
     ~DrySoil() override = default;

    /**
    * @brief Returns the name of the soil state.
    * @return A reference to a string containing the name "Dry Soil".
    *
    * This method provides the specific name of this soil state, which is "Dry Soil".
    */
    std::string & getName() override;

    /**
     * @brief Simulates the effect of rain on dry soil.
     *
     * This method defines how the dry soil state changes in response to rainfall.
     * When rain() dry soil becomes fruitful soil
     */
    void rain() override;

    /**
     * @brief Harvests crops based on the dry soil state.
     *
     * This method defines the process of harvesting crops when the soil is in a dry state.
     * In dry state the soil yields x1 crops
     */
    void harvestCrops() override;

    /**
     * @brief When the fertilizer is added to the dry soil it becomes fruitful
     */
     void fertilize() override;


};



#endif //DRYSOIL_H
