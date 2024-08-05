#include "InfantryFactory.h"

#include "Infantry.h"

InfantryFactory::~InfantryFactory() {
    delete soldiers;
}

Soldiers * InfantryFactory::createUnit() {
    return new Infantry();
}

InfantryFactory::InfantryFactory() {
    this->soldiers = new Infantry();
}
