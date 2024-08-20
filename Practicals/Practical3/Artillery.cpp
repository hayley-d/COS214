#include "Artillery.h"

Artillery &Artillery::operator=(const Artillery &other) {
    this->damage = other.getDamage();
    this->defence = other.getDefence();
    this->health = other.getHealth();
    this->x = other.getX();
    this->y = other.getY();
    return *this;
}

bool Artillery::operator<(const Artillery &other) const {
    return this->getDamage() < other.getDamage();
}

void Artillery::move(Direction direction) {
    switch (direction) {
        case Direction::North:
            ++y;
            break;
        case Direction::South:
            --y;
            break;
        case Direction::East:
            ++x;
            break;
        case Direction::West:
            --x;
            break;
        default:
            x = x;
            break;
    }
}

void Artillery::fight(Direction direction) {
    switch (direction) {
        case Direction::North:
            ++y;
            break;
        case Direction::South:
            --y;
            break;
        case Direction::East:
            ++x;
            break;
        case Direction::West:
            --x;
            break;
        default:
            x = x;
            break;
    }
}

Artillery::~Artillery() = default;

std::shared_ptr<UnitComponent> Artillery::clone() {
    return std::make_shared<UnitComponent>(*this);
}
