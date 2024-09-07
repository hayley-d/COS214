#ifndef FERTILIZERTRUCK_H
#define FERTILIZERTRUCK_H
#include "Truck.h"
#include "FarmUnit.h"
class FarmUnit;

/**
 * @class FertilizerTruck
 * @brief concrete observer class representing a truck
 * This truck waits for the state of a farm unit to change to dry and then delivers fertilizer
 */
class FertilizerTruck : public Truck{
public:
    /**
     * @brief Notifies the truck to deliver fertilizer to the farm unit to change the soil from dry to fruitful
     */
    void startEngine(Event e) override;

    FertilizerTruck(FarmUnit& farmUnit){
        this->subject = &farmUnit;
    }
protected:
    FarmUnit* subject;///< Shared pointer to the observed FarmUnit.
};



#endif //FERTILIZERTRUCK_H
