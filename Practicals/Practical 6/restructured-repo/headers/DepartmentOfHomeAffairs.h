#ifndef DEPARTMENTOFHOMEAFFAIRS_H
#define DEPARTMENTOFHOMEAFFAIRS_H

#include "CitizenIterator.h"
#include "CitizenFactory.h"
#include "TaxAuthority.h"
#include <vector>
#include <algorithm>
#include <string>
#include <memory>

class Citizen;
class TaxAuthority;

/**
 * @brief Manages citizen registrations and identity-related services.
 *
 * This class is responsible for handling the registration of citizens, including 
 * births and deaths. It maintains a list of citizens and tracks the overall population.
 */
class DepartmentOfHomeAffairs {
private:
    std::shared_ptr<TaxAuthority> taxAuthority;
    std::unique_ptr<CitizenFactory> factory;

public:
    int population;                ///< The total population of citizens.
    std::vector<Citizen*> citizens;  ///< List of registered citizens.

    /**
     * @brief Construct a new DepartmentOfHomeAffairs object.
     *
     * Initializes the Department of Home Affairs and sets up necessary components.
     */
    DepartmentOfHomeAffairs(std::shared_ptr<TaxAuthority> taxAuth);

    /**
     * @brief Destroy the DepartmentOfHomeAffairs object.
     *
     * Cleans up resources and deletes any dynamically allocated components.
     */
     ~DepartmentOfHomeAffairs();

    /**
     * @brief Registers a birth in the department.
     *
     * This function will create a new citizen and add them to the population.
     */
    void registerBirth();

    /**
     * @brief Registers a death for a specified citizen.
     *
     * @param citizen Pointer to the Citizen object to be removed from the population.
     */
    void registerDeath(Citizen* citizen);
};

#endif // DEPARTMENTOFHOMEAFFAIRS_H
