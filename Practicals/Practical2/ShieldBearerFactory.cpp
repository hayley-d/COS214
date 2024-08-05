#include "ShieldBearerFactory.h"
#include "ShieldBearer.h"
ShieldBearerFactory::ShieldBearerFactory() {
    this->soldiers = new ShieldBearer();
}

ShieldBearerFactory::~ShieldBearerFactory() {
    delete soldiers;
}

Soldiers * ShieldBearerFactory::createUnit() {
    return new ShieldBearer();
}
