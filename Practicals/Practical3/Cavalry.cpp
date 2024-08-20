#include "Cavalry.h"

Cavalry &Cavalry::operator=(const Cavalry &other) {
    this->damage = other.getDamage();
    this->defence = other.getDefence();
    this->health = other.getHealth();
    this->size = other.getSize();
    this->x = other.getX();
    this->y = other.getY();
    return *this;
}

bool Cavalry::operator<(const Cavalry &other) const {
    return this->getSize() < other.getSize();
}

bool Cavalry::operator==(const Cavalry &other) const{
    return this->getSize() == other.getSize();
}

void Cavalry::move(Direction direction) {
    /*switch (direction) {
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
    }*/
}

void Cavalry::fight(Direction direction) {
    /*switch (direction) {
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
    }*/
}

Cavalry::~Cavalry() = default;

std::shared_ptr<UnitComponent> Cavalry::clone() {
    return std::make_shared<Cavalry>(*this);
}
