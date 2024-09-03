#ifndef CROPFIELD_H
#define CROPFIELD_H

#include "FarmComposite.h";
/**
 * @class CropField
 * @brief Represents a crop field within the farm, derived from FarmComposite and FarmUnit.
 *
 * The CropField class is a concrete implementation of FarmComposite, representing
 * a collection of crops and barns
 */
class CropField : public FarmComposite{
public:
    /**
     * @brief Gets the total capacity of the crop field.
     * @return The total capacity of the crop field as an integer.
     */
    int getTotalcapacity() override;
    /**
     * @brief Gets the surface area of the crop field.
     * @return The surface area of the crop field as an integer.
     */
    int getSurfaceArea() override;

    /**
    * @brief Returns an iterator pointing to the end of the farm units in the crop field.
    * @return An iterator to the end of the farm units.
    */
    FarmIterator end() override;

    /**
     * @brief Returns an iterator pointing to the beginning of the farm units in the crop field.
     * @return An iterator to the beginning of the farm units.
     */
    FarmIterator begin() override;

 /**
  * @brief Prints the details of the crop field and its farm units.
  */
    void printFarm() override;

 /**
  * @brief Adds a farm unit to the crop field.
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
    * @brief A vector holding pointers to the farm units in the crop field.
    */
    std::vector<FarmUnit*> farms;
};



#endif //CROPFIELD_H
