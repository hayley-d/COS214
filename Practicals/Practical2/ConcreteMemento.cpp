#include "ConcreteMemento.h"

ConcreteMemento::ConcreteMemento(const int amountOfSoldiersPerUnit, const int damagePerUnit, const int defencePerUnit, const int healthPerUnit,
    const std::string &unitName) : amountOfSoldiersPerUnit(amountOfSoldiersPerUnit), damagePerUnit(damagePerUnit), defencePerUnit(defencePerUnit), healthPerUnit(healthPerUnit), unitName(unitName) {}

ConcreteMemento::~ConcreteMemento() = default;

int ConcreteMemento::getHealthPerUnit() {
    return this->healthPerUnit;
}

int ConcreteMemento::getDamagePerUnit() {
    return this->damagePerUnit;
}

int ConcreteMemento::getDefencePerUnit() {
    return this->defencePerUnit;
}

int ConcreteMemento::getAmountOfSoldiersPerUnit() {
    return this->amountOfSoldiersPerUnit;
}

std::string ConcreteMemento::getUnitName() {
    return this->unitName;
}
