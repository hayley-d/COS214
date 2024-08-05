#include "Boatman.h"

Boatman::Boatman() {
    this->damagePerSoldier = 50;
    this->defencePerSoldier = 0;
    this->healthPerSoldier = 20;
    this->amountOfSoldiersPerUnit = 20;
    this->unitName = "Boatman";
}

Boatman::~Boatman() = default;

void Boatman::vivificaMemento(ConcreteMemento &mem) {
    Soldiers::vivificaMemento(mem);
}

ConcreteMemento * Boatman::militusMemento() {
    return Soldiers::militusMemento();
}
