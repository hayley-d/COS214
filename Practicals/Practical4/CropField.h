#ifndef CROPFIELD_H
#define CROPFIELD_H
#include<string>
#include "FarmComposite.h";
/**
 * @class CropField
 * @brief Represents a crop field within the farm, derived from FarmComposite and FarmUnit.
 *
 * The CropField class is a concrete implementation of FarmComposite, representing
 * a collection of crops and barns
 */
class CropField : public FarmComposite {
public:
    /**
     * @brief Constructor for the `FarmUnit` class.
     *
     * Initializes a `FarmUnit` with the given total capacity and surface area.
     *
     * @param totalCapacity The total capacity of the farm unit.
     * @param surfaceArea The surface area of the farm unit.
     * @param cropType The crop type of the farm unit.
     * @param soilState The soil state of the farm unit.
     */
    CropField(int totalCapacity, int surfaceArea, Crop cropType, SoilState &soilState) : FarmComposite(
        totalCapacity, surfaceArea, cropType, soilState) {
    }

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
     * @brief Gets the surface area of the crop field.
     * @return The surface area of the crop field as an integer.
     */
    std::string &getSoilStateName() override;

    /**
    * @brief Gets the crop type of the Crop field
    * @return The crop type
    */
    virtual Crop getCropType();

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
     * @brief Changes the soil state of the farm uni
     * @param soilState A reference to the new soil state of the farm unit
     */
     void changeSoilState(SoilState &soilState) override;

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

    /**
    * @brief Returns an unique pointer to an iterator to the start of the collection.
    * @return FarmIterator pointer to the start of the collection.
    */
    std::unique_ptr<FarmIterator> getIterator() override;

    void storeCrops(int harvestBonus) override;

    int getCurrentStorageCapacity() override;

    bool hasStorageSpace(int spaceNeeded) override;

    bool isComposite() const override;

    std::vector<std::shared_ptr<FarmUnit>> getChildren() const override;

   private:
    /**
       * @brief A vector holding pointers to the farm units in the crop field.
       */
    std::vector<std::shared_ptr<FarmUnit>> farms;
};


#endif //CROPFIELD_H
