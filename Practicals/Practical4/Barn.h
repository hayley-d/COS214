#ifndef BARN_H
#define BARN_H
#include "FarmUnit.h"


class Barn : FarmUnit{
public:
    int getTotalcapacity() override;

    std::string & getSoilStateName() override;

    Crop getCropType() override;

    int getSurfaceArea() override;

    std::unique_ptr<FarmIterator> getIterator() override;

    void changeSoilState(SoilState &soilState) override;

    void storeCrops(int harvestBonus) override;

    int getCurrentStorageCapacity() override;

    bool hasStorageSpace(int spaceNeeded) override;

    void printFarm() override;

    /**
     * @brief Detaches a Truck (observer) from the FarmUnit.
     *
     * This method is used to remove a Truck observer from the FarmUnit, stopping it from receiving notifications.
     */
    void buyTruck(Truck& truck) override;

    /**
    * @brief Detaches a Truck (observer) from the FarmUnit.
    *
    * This method is used to remove a Truck observer from the FarmUnit, stopping it from receiving notifications.
    */
    void sellTruck(Truck& truck) override;

    /**
    * @brief Notifies all attached Truck observers about changes.
    * @param e type of event to call correct truck type
    * This method is used to call all Truck observers, notifying them of any updates or changes in the FarmUnit.
    */
    void callTruck(Event e) override;

    void fertilizeCrops() override;

    void collectCrops() override;
};



#endif //BARN_H
