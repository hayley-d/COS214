#ifndef CITIZEN_H
#define CITIZEN_H

#include "TaxAuthority.h"
#include "Building.h"
#include <string>
#include <memory>
class TaxAuthority;
/**
 * @brief Represents a citizen in the city.
 *
 * The Citizen class encapsulates information and behaviors related to individual citizens,
 * including employment, taxes, and residence.
 */
class Citizen {
private:
    std::shared_ptr<TaxAuthority> taxAuth;

protected:
    int funds;                     ///< The amount of funds available to the citizen.

public:
    /**
     * @brief Construct a new Citizen object.
     *
     * @param type The type of the citizen.
     * @param satisfactionLevel The initial satisfaction level of the citizen.
     * @param funds The initial funds available to the citizen.
     */
    Citizen(int funds, std::shared_ptr<TaxAuthority> taxA) {
        this->funds = funds;
        this->taxAuth = taxA;
    };

    /**
     * @brief Destroy the Citizen object.
     *
     * Cleans up resources related to the citizen.
     */
     ~Citizen() = default;

    /**
     * @brief Pays taxes based on the citizen's income.
     *
     * This function handles the tax payment process for the citizen.
     */
    void payTax(int amount) {
        this->funds -= amount;
        //this->taxAuth->sendTaxMoney(amount);
    }
    /**
    * @brief Getter for the funds to the citizen.
    *
    * @return The funds of the citizen.
    */
    int getFunds() {
        return this->funds;
    }
};

#endif // CITIZEN_H
