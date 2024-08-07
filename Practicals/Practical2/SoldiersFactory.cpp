#include "SoldiersFactory.h"


SoldiersFactory::SoldiersFactory() : soldiers(nullptr){
}

SoldiersFactory::SoldiersFactory(Soldiers *s) {
    this->soldiers = s;
}

SoldiersFactory::~SoldiersFactory() {
    delete soldiers;
}

int SoldiersFactory::calculateTotalDamagePerUnit() {
    if(soldiers!=nullptr) {
        return soldiers->getDamagePerSoldier() * soldiers->getAmountOfSoldiersPerUnit();
    }
    return 0;
}

int SoldiersFactory::calculateTotalDefencePerUnit() {
    if(soldiers!=nullptr) {
        return soldiers->getDefencePerSoldier() * soldiers->getAmountOfSoldiersPerUnit();
    }
   return 0;
}

int SoldiersFactory::calculateTotalHealthPerUnit() {
    if(soldiers!=nullptr) {
        return soldiers->getHealthPerSoldier() * soldiers->getAmountOfSoldiersPerUnit();
    }
    return 0;
}
