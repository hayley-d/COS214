#include "ShieldBearer.h"

ShieldBearer::ShieldBearer() {
    this->damagePerSoldier = 20;
    this->defencePerSoldier = 90;
    this->healthPerSoldier = 40;
    this->amountOfSoldiersPerUnit = 3;
    this->unitName = "Shield Bearers";
}


ShieldBearer::ShieldBearer(const int amountOfSoldiersPerUnit, const int damagePerSoldier, const int defencePerSoldier,
                           const int healthPerSolider,
                           const std::string &unitName) : Soldiers(amountOfSoldiersPerUnit, damagePerSoldier,
                                                                   defencePerSoldier, healthPerSolider, unitName) {
}

ShieldBearer::~ShieldBearer() = default;

Soldiers *ShieldBearer::clonis() const {
    return new ShieldBearer(*this);
}

ShieldBearer::ShieldBearer(const ShieldBearer &other) {
    healthPerSoldier = other.healthPerSoldier;
    damagePerSoldier = other.damagePerSoldier;
    defencePerSoldier = other.defencePerSoldier;
    amountOfSoldiersPerUnit = other.amountOfSoldiersPerUnit;
    unitName = other.unitName;
}
