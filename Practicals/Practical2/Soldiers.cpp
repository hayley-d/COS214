
#include "Soldiers.h"

Soldiers::Soldiers() : amountOfSoldiersPerUnit(20), damagePerSoldier(10), defencePerSoldier(10), healthPerSoldier(20), unitName("Soldier") {
}

Soldiers::~Soldiers() = default;

Soldiers::Soldiers(const int amountOfSoldiersPerUnit, const int damagePerSoldier, const int defencePerSoldier, const int healthPerSoldier,
    const std::string &unitName) : amountOfSoldiersPerUnit(amountOfSoldiersPerUnit), damagePerSoldier(damagePerSoldier), defencePerSoldier(defencePerSoldier), healthPerSoldier(healthPerSoldier), unitName(unitName){
}

Soldiers::Soldiers(const Soldiers &other) {
    healthPerSoldier = other.healthPerSoldier;
    damagePerSoldier = other.damagePerSoldier;
    defencePerSoldier = other.defencePerSoldier;
    amountOfSoldiersPerUnit = other.amountOfSoldiersPerUnit;
    unitName = other.unitName;
}

void Soldiers::setUnitName(const std::string &unitName) {
    this->unitName = unitName;
}

void Soldiers::vivificaMemento(ConcreteMemento &mem) {
    this->amountOfSoldiersPerUnit = mem.getAmountOfSoldiersPerUnit();
    this->damagePerSoldier = mem.getDamagePerSoldier();
    this->defencePerSoldier = mem.getDefencePerSoldier();
    this->healthPerSoldier = mem.getHealthPerSoldier();
    this->unitName = mem.getUnitName();
}

ConcreteMemento * Soldiers::militusMemento() {
    return new ConcreteMemento(amountOfSoldiersPerUnit,damagePerSoldier,defencePerSoldier,healthPerSoldier,unitName);
}

void Soldiers::setDamagePerSoldier(const int damagePerSoldier) {
    this->damagePerSoldier = damagePerSoldier;
}

void Soldiers::setDefencePerSoldier(const int defencePerSoldier) {
    this->defencePerSoldier = defencePerSoldier;
}

void Soldiers::setHealthPerSoldier(const int healthPerSoldier) {
    this->healthPerSoldier = healthPerSoldier;
}

void Soldiers::setAmountOfSoldiersPerUnit(int amountOfSoldiersPerUnit) {
    this->amountOfSoldiersPerUnit = amountOfSoldiersPerUnit;
}

