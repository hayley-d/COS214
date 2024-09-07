#ifndef FARMDECORATOR_H
#define FARMDECORATOR_H

#include "FarmUnit.h"

class FarmDecorator : public FarmComposite {
    typedef std::shared_ptr<FarmUnit> FarmUnitPtr; ///< Type alias for shared pointer to FarmUnit.
    typedef std::vector<std::shared_ptr<FarmUnit> > FarmUnitPtrVector;
public:
    FarmDecorator(FarmComposite& wrapee) :  FarmComposite(wrapee.getTotalcapacity(),wrapee.getSurfaceArea(),wrapee.getCropType().crop),wrapee(&wrapee) {}

    void printFarm() override{
        this->wrapee->printFarm();
    };

    //decorator method
    virtual void applyEnhancement() = 0;

    ~FarmDecorator() override {
        delete wrapee;
    };

    void addFarmUnit(FarmUnitPtr unit)  {
        wrapee->addFarmUnit(unit);
    }

    void removeFarmUnit(FarmUnitPtr unit) {
        wrapee->removeFarmUnit(unit);
    }

protected:
    FarmComposite* wrapee;
};



#endif //FARMDECORATOR_H
