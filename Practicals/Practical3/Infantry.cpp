#include "Infantry.h"

Infantry &Infantry::operator=(const Infantry &other) {
    this->damage = other.getDamage();
    this->defence = other.getDefence();
    this->health = other.getHealth();
    this->size = other.getSize();
    this->x = other.getX();
    this->y = other.getY();
    return *this;
}

bool Infantry::operator<(const Infantry &other) const {
    return this->getSize() < other.getSize();
}

bool Infantry::operator==(const Infantry &other) const{
    return this->getSize() == other.getSize();
}

void Infantry::move(Direction direction) {
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

void Infantry::fight(Direction direction) {
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

Infantry::~Infantry() = default;

std::shared_ptr<UnitComponent> Infantry::clone() {
    return std::make_shared<Infantry>(*this);
}
