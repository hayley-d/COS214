#include "Fortification.h"

#include <iostream>

#include "LegionFactory.h"
#include "OpenFieldFactory.h"
#include "RiverbankFactory.h"
#include "WoodlandsFactory.h"

UnitComponent* Fortification::engage() {
    //Create fortification legion
    Legion* legion = factory->createLegion();

    // 6 atillery in legion
    for(int i = 0; i < 6; ++i) {
        legion->add(*factory->createArtillery());
    }

    //high defence
    legion->setDefence(30);

    //low damage
    legion->setDamage(10);

    return legion;
}

Fortification::~Fortification() {
    delete factory;
    factory = nullptr;
}

BattleStrategy * Fortification::clone() const {
    return new Fortification(*this);
}
