#ifndef FACTORYFACTORY_H
#define FACTORYFACTORY_H

#include "BuildingFactory.h"

/**
 * @brief Factory for creating factories/industrial buildings.
 *
 * ConcreteCreator participant in the Factory Method pattern. It implements the factory method to create factories/industrial buildings.
 */
class FactoryFactory : public BuildingFactory {
public:
    /**
     * @brief Constructs a new FactoryFactory object.
     */
    FactoryFactory();

    /**
     * @brief Destroys the FactoryFactory object.
     */
    virtual ~FactoryFactory();
    
    /**
     * @brief Creates a Factory building.
     * @param type The type of Factory building to create.
     * @return Pointer to the created Factory building object.
     *
     * This method overrides the factory method to create a Factory building.
     */
    Building* createBuilding(std::string type) override;
};

#endif // FACTORYFACTORY_H

