#include "SoldiersFactory.h"

Soldiers * SoldiersFactory::createUnit() {
    return new Soldiers();
}

SoldiersFactory::SoldiersFactory() {
    this->soldiers = new Soldiers();
}

SoldiersFactory::~SoldiersFactory() {
    delete soldiers;
}

int SoldiersFactory::calculateTotalDamagePerUnit() {
    return soldiers->getDamagePerSoldier() * soldiers->getAmountOfSoldiersPerUnit();

}

int SoldiersFactory::calculateTotalDefencePerUnit() {
    return soldiers->getDefencePerSoldier() * soldiers->getAmountOfSoldiersPerUnit();
}

int SoldiersFactory::calculateTotalHealthPerUnit() {
    return soldiers->getHealthPerSoldier() * soldiers->getHealthPerSoldier();
}
