#include "Infantry.h"

Infantry::Infantry() {
    this->damagePerSoldier = 40;
    this->defencePerSoldier = 20;
    this->healthPerSoldier = 50;
    this->amountOfSoldiersPerUnit = 8;
    this->unitName = "Infantry";
}

Infantry::Infantry(const int amountOfSoldiersPerUnit, const int damagePerSoldier, const int defencePerSoldier,
                   const int healthPerSolider,
                   const std::string &unitName) : Soldiers(amountOfSoldiersPerUnit, damagePerSoldier, defencePerSoldier,
                                                           healthPerSolider, unitName) {
}

Infantry::~Infantry() = default;

ConcreteMemento *Infantry::militusMemento() {
    return Soldiers::militusMemento();
}

Soldiers *Infantry::clonis() const {
    return new Infantry(*this);
}

Infantry::Infantry(const Infantry &other) {
    healthPerSoldier = other.healthPerSoldier;
    damagePerSoldier = other.damagePerSoldier;
    defencePerSoldier = other.defencePerSoldier;
    amountOfSoldiersPerUnit = other.amountOfSoldiersPerUnit;
    unitName = other.unitName;
}
