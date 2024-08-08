#include "Boatman.h"

Boatman::Boatman() {
    this->damagePerSoldier = 50;
    this->defencePerSoldier = 0;
    this->healthPerSoldier = 20;
    this->amountOfSoldiersPerUnit = 20;
    this->unitName = "Boatman";
}

Boatman::Boatman(const int amountOfSoldiersPerUnit, const int damagePerSoldier, const int defencePerSoldier, const int healthPerSolider,
    const std::string &unitName) : Soldiers(amountOfSoldiersPerUnit,damagePerSoldier,defencePerSoldier,healthPerSolider,unitName){}

Boatman::~Boatman() = default;

void Boatman::vivificaMemento(ConcreteMemento &mem) {
    Soldiers::vivificaMemento(mem);
}

ConcreteMemento * Boatman::militusMemento() {
    return Soldiers::militusMemento();
}

Boatman::Soldiers* clonis(){
    Soldiers* newShieldBearer = new Boatman();
    return newShieldBearer;
}
