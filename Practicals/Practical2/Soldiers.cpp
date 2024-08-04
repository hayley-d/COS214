
#include "Soldiers.h"

Soldiers::Soldiers() : amountOfSoldiersPerUnit(0), damagePerUnit(0), defencePerUnit(0), healthPerUnit(0), unitName("") {
}

Soldiers::~Soldiers() = default;

Soldiers::Soldiers(const int amountOfSoldiersPerUnit, const int damagePerUnit, const int defencePerUnit, const int healthPerUnit,
    const std::string &unitName) : amountOfSoldiersPerUnit(amountOfSoldiersPerUnit), damagePerUnit(damagePerUnit), defencePerUnit(defencePerUnit), healthPerUnit(healthPerUnit), unitName(unitName){
}

void Soldiers::setDamagePerUnit(int damagePerUnit) {
    if(damagePerUnit > 0) {
        this->damagePerUnit = damagePerUnit;
    }
}

void Soldiers::setDefencePerUnit(int defencePerUnit) {
    if(defencePerUnit > 0) {
        this->defencePerUnit = defencePerUnit;
    }
}

void Soldiers::setHealthPerUnit(int healthPerUnit) {
    if(healthPerUnit > 0) {
        this->healthPerUnit = healthPerUnit;
    }
}

void Soldiers::setUnitName(const std::string &unitName) {
    this->unitName = unitName;
}

void Soldiers::vivificaMemento(ConcreteMemento &mem) {
    this->amountOfSoldiersPerUnit = mem.getAmountOfSoldiersPerUnit();
    this->damagePerUnit = mem.getDamagePerUnit();
    this->defencePerUnit = mem.getDefencePerUnit();
    this->healthPerUnit = mem.getHealthPerUnit();
    this->unitName = mem.getUnitName();
}

ConcreteMemento * Soldiers::militusMemento() {
    return new ConcreteMemento(amountOfSoldiersPerUnit,damagePerUnit,defencePerUnit,healthPerUnit,unitName);
}
