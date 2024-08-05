#include "ShieldBearer.h"

ShieldBearer::ShieldBearer() {
    this->damagePerSoldier = 20;
    this->defencePerSoldier = 90;
    this->healthPerSoldier = 40;
    this->amountOfSoldiersPerUnit = 3;
    this->unitName = "Shield Bearers";
}
ShieldBearer::~ShieldBearer() = default;
