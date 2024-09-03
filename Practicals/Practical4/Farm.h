
#ifndef FARM_H
#define FARM_H

#include "FarmComposite.h"
/**
 * @class Farm
 * @brief Represents a farm derived from FarmComposite and FarmUnit.
 *
 * The Farm class is a concrete implementation of FarmComposite, representing
 * a collection of crop fields and barns
 */
class Farm : public FarmComposite{
public:
    /**
     * @brief Gets the total capacity of the farm.
     * @return The total capacity of the farm as an integer.
     */
    int getTotalcapacity() override;
    /**
         * @brief Gets the surface area of the farm.
         * @return The surface area of the farm as an integer.
         */
    int getSurfaceArea() override;

    /**
   * @brief Returns an iterator pointing to the end of the farm units in the farm.
   * @return An iterator to the end of the farm units.
   */
    FarmIterator end() override;

    /**
     * @brief Returns an iterator pointing to the beginning of the farm units in the farm.
     * @return An iterator to the beginning of the farm units.
     */
    FarmIterator begin() override;

    /**
  * @brief Prints the details of the farm and its farm units.
  */
    void printFarm() override;

    /**
 * @brief Adds a farm unit to the farm.
 * @param unit A pointer to the farm unit to be added.
 */
    void addFarmUnit(FarmUnit *unit) override;

    /**
     * @brief Removes a farm unit from the crop field.
     * @param unit A pointer to the farm unit to be removed.
     */
    void removeFarmUnit(FarmUnit *unit) override;

private:
 /**
    * @brief A vector holding pointers to the farm units in the farm.
    */
    std::vector<FarmUnit*> farms;
};



#endif //FARM_H
