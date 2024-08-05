#include "ConcreteMemento.h"

ConcreteMemento::ConcreteMemento(const int amountOfSoldiersPerUnit, const int damagePerSoldier, const int defencePerSoldier,
    const int healthPerSoldier, const std::string &unitName) : amountOfSoldiersPerUnit(amountOfSoldiersPerUnit), damagePerSoldier(damagePerSoldier), defencePerSoldier(defencePerSoldier),healthPerSoldier(healthPerSoldier) ,unitName(unitName){
}

int ConcreteMemento::getHealthPerSoldier() const {
    return healthPerSoldier;
}

int ConcreteMemento::getDamagePerSoldier() const {
    return damagePerSoldier;
}

int ConcreteMemento::getDefencePerSoldier() const {
    return defencePerSoldier;
}

ConcreteMemento::~ConcreteMemento() = default;

int ConcreteMemento::getAmountOfSoldiersPerUnit() const {
    return this->amountOfSoldiersPerUnit;
}

std::string ConcreteMemento::getUnitName() const {
    return this->unitName;
}
