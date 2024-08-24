#include "Ambush.h"
#include <iostream>

void Ambush::engage(std::shared_ptr<UnitComponent> &unit,std::shared_ptr<UnitComponent> &enemy) {
    if (unit->getSize() < this->getMinimumTroops()) {
        std::cout << "Ambush failed! Not enough troops to execute the strategy.\n";
        return;
    }

    // ambush == increased damage potential
    int damage = this->getDamagePotential() * 1.5;
    unit->setDamage(damage);
    std::cout << "Ambush! The enemy is caught off guard and took heavy damage." << std::endl;

    //Attempt to damage Enemy
    if (static_cast<float>(rand()) / RAND_MAX <= this->getSuccessRate()) {
        enemy->applyDamage(damage);
        std::cout << "Ambush successful! Dealt " << damage << " damage.\n";
    } else {
        std::cout << "Ambush failed! The enemy was prepared.\n";
    }

}

Ambush::~Ambush() {
}

BattleStrategy * Ambush::clone() const {
    return new Ambush(*this);
}
