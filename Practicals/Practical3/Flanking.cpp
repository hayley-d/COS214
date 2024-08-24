#include "Flanking.h"

void Flanking::engage(std::shared_ptr<UnitComponent> &unit,std::shared_ptr<UnitComponent> &enemy) {
    if (unit->getSize() < this->getMinimumTroops()) {
        std::cout << "Flanking failed! Not enough troops to execute the strategy.\n";
        return;
    }

    // flanking == inceased damage && decreased enemy defence
    int defence = enemy->getDefence() * 0.7;
    int damage = this->getDamagePotential() * 1.2;
    unit->setDamage(damage);

    if (static_cast<float>(rand()) / RAND_MAX <= this->getSuccessRate()) {
        enemy->applyDamage(damage);
        enemy->setDefence(defence);
        std::cout << "Flanking successful! Dealt " << damage << " damage and enemy lost " << defence << " defense.\n";
    } else {
        std::cout << "Flanking failed! The enemy anticipated the move.\n";
    }
}

Flanking::~Flanking() {
}

BattleStrategy * Flanking::clone() const {
    return new Flanking(*this);
}
