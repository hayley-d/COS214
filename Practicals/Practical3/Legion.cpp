#include "Legion.h"

Legion::Legion(const Legion &other) : UnitComponent(other.defence, other.damage, other.health, other.size, other.x,
                                                    other.y) {
    for (const auto &unit: other.units) {
        units.push_back(unit->clone());
    }
}

Legion &Legion::operator=(const Legion &other) {
    this->defence = other.defence;
    this->damage = other.damage;
    this->health = other.health;
    this->size = other.size;
    this->x = other.x;
    this->y = other.y;
    return *this;
}

bool Legion::operator<(const Legion &other) const {
    return this->size < other.size;
}


void Legion::move(Direction direction) {
    for (auto it = units.begin(); it != units.end(); ++it) {
        (*it)->move(direction);
    }
}

void Legion::fight(Direction direction) {
    for (auto it = units.begin(); it != units.end(); ++it) {
        (*it)->fight(direction);
    }
}

bool Legion::add(UnitComponent &component) {
    units.push_back(&component);
    return true;
}

bool Legion::remove(UnitComponent &component) {
    bool deletedUnit = false;

    for (auto it = units.begin(); it != units.end();) {
        if (*it == &component) {
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
    for (auto it = units.begin(); it != units.end(); ++it) {
        totalDamage += (*it)->getHealth();
    }

    return totalDamage;
}

int Legion::getDefence() const {
    int totalDefence = 0;
    for (auto it = units.begin(); it != units.end(); ++it) {
        totalDefence += (*it)->getHealth();
    }

    return totalDefence;
}

int Legion::getHealth() const {
    int totalHealth = 0;
    for (auto it = units.begin(); it != units.end(); ++it) {
        totalHealth += (*it)->getHealth();
    }
    return totalHealth;
}

int Legion::getSize() const {
    int totalSize = 0;
    for (auto it = units.begin(); it != units.end(); ++it) {
        totalSize += (*it)->getSize();
    }
    return totalSize;
}

Legion::~Legion() {
   for (auto it = units.begin(); it != units.end(); ++it) {
        delete *it;
        *it = nullptr;
    }
    units.clear();
}

UnitComponent *Legion::clone() {
    return new Legion(*this);
}

bool Legion::operator==(UnitComponent &other) {
    if (other.getDefence() == defence && other.getDamage() == damage && other.getHealth() == health && other.getSize()
        == size && other.getX() == x && other.getY() == y) {
        return true;
    }
    return false;
}

void Legion::applyDamage(int damage) {
    for (auto it = units.begin(); it != units.end(); ++it) {
        (*it)->applyDamage(damage);
    }
}

void Legion::die() {
    for (auto it = units.begin(); it != units.end(); ++it) {
        delete *it;
        *it = nullptr;
    }
    units.clear();
}
