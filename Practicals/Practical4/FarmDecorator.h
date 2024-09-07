#ifndef FARMDECORATOR_H
#define FARMDECORATOR_H

#include "FarmUnit.h"

class FarmDecorator : public FarmComposite {
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

protected:
    FarmComposite* wrapee;
};



#endif //FARMDECORATOR_H
