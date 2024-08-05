#include "SoldiersFactory.h"


SoldiersFactory::SoldiersFactory() : soldiers(new Soldiers()){
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
    return soldiers->getHealthPerSoldier() * soldiers->getAmountOfSoldiersPerUnit();
}
