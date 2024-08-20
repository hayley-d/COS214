#include "Legion.h"

Legion::Legion(const Legion &other) : UnitComponent(other.defence,other.damage,other.health,other.x,other.y){
    for(const auto&  unit : other.units) {
        units.push_back(unit->clone());
    }
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

bool Legion::add(std::shared_ptr<UnitComponent>&component) {
    units.push_back(component);
}

bool Legion::remove(std::shared_ptr<UnitComponent>&component) {
    bool deletedUnit = false;
    for(auto it = units.begin() ; it != units.end();) {
        if(*it == component) {
            it = units.erase(it);
           deletedUnit = true;
        } else {
            ++it;
        }
    }
    return deletedUnit;
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

std::shared_ptr<UnitComponent> Legion::clone() {
    return std::make_shared<UnitComponent>(*this);
}