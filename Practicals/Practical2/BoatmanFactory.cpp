#include "BoatmanFactory.h"

#include "Boatman.h"

BoatmanFactory::BoatmanFactory() {
    this->soldiers = new Boatman();
}

BoatmanFactory::~BoatmanFactory() {
    delete soldiers;
}

Soldiers * BoatmanFactory::createUnit() {
    return new Boatman();
}
