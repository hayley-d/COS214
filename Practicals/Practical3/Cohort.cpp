#include "Cohort.h"

Cohort::Cohort(const Cohort &other) {
for(const auto& unit : other.units) {
        units.push_back(new Century(*unit));
    }
    this->unitName = other.unitName;
    this->x = other.getX();
    this->y = other.getY();}

Cohort & Cohort::operator=(const Cohort &other) {
}

bool Cohort::operator<(const Cohort &other) const {
}

bool Cohort::operator==(const Cohort &other) const {
}

void Cohort::move(Direction direction) {
}

void Cohort::fight(Direction direction) {
}

int Cohort::getDamage() const {
    int totalDamage = 0;
    for(auto& unit : units) {
        totalDamage += unit->getDamage();
    }
    return totalDamage;
}

int Cohort::getDefence() const {
    int totalDefence = 0;
    for(auto& unit : units) {
        totalDefence += unit->getDefence();
    }
    return totalDefence;
}

bool Cohort::add(UnitComponent *component) {
}

bool Cohort::remove(UnitComponent *component) {
}

const std::list<UnitComponent *> & Cohort::getUnits() const {
}

Cohort::~Cohort() {
    for (auto unit : units) {
        delete unit;
    }
    units.clear();
}

int Cohort::getHealth() const {
    int totalHealth = 0;
    for(auto& unit : units) {
        totalHealth += unit->getHealth();
    }
    return totalHealth;
}

