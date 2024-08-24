#include "Ambush.h"
#include <iostream>

UnitComponent * Ambush::engage() {
    //Create fortification legion
    Legion* legion = factory->createLegion();

    // 4 cavalry in legion
    for(int i = 0; i < 4; ++i) {
        legion->add(*factory->createCavalry());
    }

    //create 3 artillery
    for(int i = 0; i < 3; i++) {
        legion->add(*factory->createArtillery());
    }

    //create 10 infantry
    for(int i = 0; i < 10; i++) {
        legion->add(*factory->createInfantry());
    }

    //damage high
    legion->setDamage(70);

    //defence low
    legion->setDefence(10);

    return legion;}

Ambush::~Ambush() {
    delete factory;
    factory = nullptr;
}

BattleStrategy * Ambush::clone() const {
    return new Ambush(*this);
}
