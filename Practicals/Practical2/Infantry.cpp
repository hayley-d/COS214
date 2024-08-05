#include "Infantry.h"

Infantry::Infantry() {
    this->damagePerSoldier = 40;
    this->defencePerSoldier = 20;
    this->healthPerSoldier = 50;
    this->amountOfSoldiersPerUnit = 8;
    this->unitName = "Infantry";
}
Infantry::~Infantry() = default;

ConcreteMemento * Infantry::militusMemento() {
    return Soldiers::militusMemento();
}
