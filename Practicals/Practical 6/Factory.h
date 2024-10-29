#ifndef FACTORY_H
#define FACTORY_H

#include "Building.h"
#include <algorithm>
#include <string>
#include <iostream>


/**
 * @brief Represents an industrial factory building.
 *
 * ConcreteProduct participant in the Factory Method pattern. It extends the Building class and adds functionality specific to factories, including production of resources.
 */
class Factory : public Building {
protected:
    int numOfEmployees;  ///< Number of employees working in the factory.
    int maxEmployees;  ///< Number of employees working in the factory.
    int productionRate;  ///< The rate at which resources are produced by the factory.
public:
    /**
     * @brief Constructs a new Factory object.
     * @param cost The construction cost of the factory.
     * @param location The location of the factory.
     * @param resources Pointer to the resources the factory consumes.
     * @param size The size of the factory.
     * @param owner Pointer to the factory's owner.
     * @param taxAuthority Pointer to the tax authority associated with the factory.
     */
    Factory(int cost, std::string location, Resources* resources, int size, Citizen* owner, TaxAuthority* taxAuthority, int productionRate, int max);

    /**
     * @brief Destroys the Factory object.
     */
    virtual ~Factory() = default;

    /**
     * @brief Gets details about the factory.
     * @return A string containing details about the factory.
     *
     * This is an abstract method that must be implemented by concrete factory subclasses.
     */
    virtual std::string getDetails() = 0;

    /**
     * @brief Pays taxes for the factory.
     * @param amount The amount of tax to be paid.
     * @param owner Pointer to the factory's owner.
     *
     * This is an abstract method that must be implemented by concrete factory subclasses.
     */
    virtual void payTax(int amount) = 0;

    /**
     * @brief Produces resources in the factory.
     *
     * This is an abstract method that must be implemented by concrete factory subclasses.
     */
    virtual void produceResource() = 0;
    virtual void employ(Citizen* employee) = 0;
    virtual int pay(Citizen* employee) = 0;
    virtual void fire(Citizen* employee) = 0;
    virtual void retire(Citizen* employee) = 0;
    virtual void update() = 0;
};

#endif // FACTORY_H
