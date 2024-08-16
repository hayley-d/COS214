#include "Legion.h"

#include "Cohort.h"

Legion::Legion(const Legion &other) {
    for(const auto&  unit : other.units) {
        units.push_back(new Cohort(*unit));
    }
    this->unitName = other.unitName;
    this->x = other.getX();
    this->y = other.getY();
}

Legion & Legion::operator=(const Legion &other) {
}

bool Legion::operator<(const Legion &other) const {
}

bool Legion::operator==(const Legion &other) const {
}

void Legion::move(Direction direction) {
}

void Legion::fight(Direction direction) {
}

bool Legion::add(UnitComponent *component) {
}

bool Legion::remove(UnitComponent *component) {
}

int Legion::getDamage() const {
    int totalDamage = 0;
    for(auto& unit : units) {
        totalDamage += unit->getDamage();
    }
    return totalDamage;
}

int Legion::getDefence() const {
    int totalDefence = 0;
    for(auto& unit : units) {
        totalDefence += unit->getDefence();
    }
    return totalDefence;
}

int Legion::getHealth() const {
    int totalHealth = 0;
    for(auto& unit : units) {
        totalHealth += unit->getHealth();
    }
    return totalHealth;
}

Legion::~Legion() {
    for (auto unit : units) {
        delete unit;
    }
    units.clear();
}


