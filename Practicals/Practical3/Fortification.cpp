#include "Fortification.h"

#include <iostream>

void Fortification::engage(std::shared_ptr<UnitComponent> &unit,std::shared_ptr<UnitComponent> &enemy) {
    if(unit->getSize() < getMinimumTroops()){
        std::cout << "Fortification failed! Not enough troops to execute the strategy.\n";
        return;
    }
    //increase health and defence
    int defence = unit->getDefence() * 2;
    int health = unit->getHealth() * 1.2;

    if (static_cast<float>(rand()) / RAND_MAX <= this->getSuccessRate()) {
       unit->setDefence(defence);
        unit->setHealth(health);
        std::cout << "Fortification successful! Gained " << defence << " defence and " << health << " health bonus.\n";
    } else {
        unit->applyDamage(enemy->getDamage());
        std::cout << "Fortification failed! The enemy breached the defenses.\n";
    }
}

Fortification::~Fortification() {
}

BattleStrategy * Fortification::clone() const {
    return new Fortification(*this);
}
