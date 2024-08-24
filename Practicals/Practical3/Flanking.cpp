#include "Flanking.h"

UnitComponent * Flanking::engage() {
    //Create fortification legion
    Legion* legion = factory->createLegion();

    // 4 infantry in legion
    for(int i = 0; i < 4; ++i) {
        legion->add(*factory->createInfantry());
    }

    //create 2 cavalry
    for(int i = 0; i < 2; i++) {
        legion->add(*factory->createCavalry());
    }

    //defence low
    legion->setDefence(10);

    //damage mid
    legion->setDamage(30);

    return legion;
}

Flanking::~Flanking() {
    delete factory;
    factory = nullptr;
}

BattleStrategy * Flanking::clone() const {
    return new Flanking(*this);
}
