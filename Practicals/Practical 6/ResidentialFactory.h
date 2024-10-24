#ifndef RESIDENTIALFACTORY_H
#define RESIDENTIALFACTORY_H

#include "BuildingFactory.h"

/**
 * @brief Factory for creating residential buildings.
 *
 * ConcreteCreator participant in the Factory Method pattern. It implements the factory method to create residential buildings.
 */
class ResidentialFactory : public BuildingFactory {
public:
    /**
     * @brief Constructs a new ResidentialFactory object.
     */
    ResidentialFactory();

    /**
     * @brief Destroys the ResidentialFactory object.
     */
    virtual ~ResidentialFactory();

    /**
     * @brief Creates a residential building.
     * @param type The type of residential building to create.
     * @return Pointer to the created Residential building object.
     *
     * This method overrides the factory method to create a residential building.
     */
    Building* createBuilding(std::string type) override;
};

#endif // RESIDENTIALFACTORY_H