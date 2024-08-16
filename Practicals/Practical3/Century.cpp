#include "Century.h"

Century::Century(const Century &other) {
for(const auto& unit : other.units) {
        units.push_back(new UnitComponent(*unit));
    }
    this->unitName = other.unitName;
    this->x = other.getX();
    this->y = other.getY();}

Century & Century::operator=(const Century &other) {
}

bool Century::operator<(const Century &other) const {
}

bool Century::operator==(const Century &other) const {
}

void Century::move(Direction direction) {
}

void Century::fight(Direction direction) {
}

int Century::getDamage() const {
    int totalDamage = 0;
    for(auto& unit : units) {
        totalDamage += unit->getDamage();
    }
    return totalDamage;
}

int Century::getDefence() const {
    int totalDefence = 0;
    for(auto& unit : units) {
        totalDefence += unit->getDefence();
    }
    return totalDefence;
}

int Century::getHealth() const {
    int totalHealth = 0;
    for(auto& unit : units) {
        totalHealth += unit->getHealth();
    }
    return totalHealth;
}

int Century::getX() const {
}

int Century::getY() const {
}

bool Century::add(UnitComponent *component) {
}

bool Century::remove(UnitComponent *component) {
}

const std::list<UnitComponent *> & Century::getUnits() const {
}

Century::~Century() {
    for (auto unit : units) {
        delete unit;
    }
    units.clear();
}
