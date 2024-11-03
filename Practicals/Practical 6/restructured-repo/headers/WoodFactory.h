#ifndef WOODFACTORY_H
#define WOODFACTORY_H

#include "BuildingType.h"
#include "Building.h"
#include "Factory.h"

#include <vector>
#include <string>

/**
 * @brief Represents a wood processing factory.
 *
 * ConcreteProduct participant in the Factory Method pattern. It extends the Factory class and represents a factory that processes wood.
 */
class WoodFactory : public Factory {
public:
    /**
     * @brief Constructs a new WoodFactory object.
     * @param cost The construction cost of the factory.
     * @param location The location of the factory.
     * @param resources Pointer to the resources the factory consumes.
     * @param size The size of the factory.
     * @param owner Pointer to the factory's owner.
     * @param taxAuthority Pointer to the tax authority associated with the factory.
     */
    WoodFactory(int cost, std::string& location, Resources* resources, int size, Citizen& owner,BuildingType name, int productionRate, int max);

    /**
     * @brief Destroys the WoodFactory object.
     */
     ~WoodFactory() override = default;

    /**
     * @brief Produces wood in the factory.
     */
    int produceResource() override;

    /**
     * @brief Pays an employee working at the wood factory.
     * @param employee Pointer to the employee.
     */
     int pay() override;
};

#endif // WOODFACTORY_H
