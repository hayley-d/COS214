#include "BoatmanFactory.h"

BoatmanFactory::BoatmanFactory() {
}

BoatmanFactory::~BoatmanFactory() {
    delete soldiers;
}

Soldiers * BoatmanFactory::createUnit() {
    return SoldiersFactory::createUnit();
}
