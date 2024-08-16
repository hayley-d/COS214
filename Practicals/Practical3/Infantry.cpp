#include "Infantry.h"

Infantry::Infantry(const Infantry &other) : defence(other.getDefence()), damage(other.getDamage()),
                                            health(other.getHealth()), x(other.getX()), y(other.getY()) {
}

Infantry &Infantry::operator=(const Infantry &other) {
    this->damage = other.getDamage();
    this->defence = other.getDefence();
    this->health = other.getHealth();
    this->x = other.getX();
    this->y = other.getY();
    return *this;
}

bool Infantry::operator<(const Infantry &other) const {
    return this->getDamage() < other.getDamage();
}

void Infantry::move(Direction direction) {
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

void Infantry::fight(Direction direction) {
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

Infantry::~Infantry() = default;
