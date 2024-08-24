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
    switch (direction) {
        case Direction::North:
            ++y;
            std::cout << "Cavalry moves to the north"<< std::endl;
            break;
        case Direction::South:
            --y;
            std::cout << "Cavalry moves to the east"<< std::endl;
            break;
        case Direction::East:
            ++x;
            std::cout << "Cavalry moves to the east"<< std::endl;
            break;
        case Direction::West:
            --x;
            std::cout << "Cavalry moves to the west"<< std::endl;
            break;
        default:
            x = x;
            std::cout << "Cavalry moves in all directions"<< std::endl;
            break;
    }
}

void Cavalry::fight(Direction direction) {
    switch (direction) {
        case Direction::North:
            ++y;
             std::cout << "Cavalry attacks to the North "<< std::endl;
            break;
        case Direction::South:
            --y;
            std::cout << "Cavalry attacks to the south" << std::endl;
            break;
        case Direction::East:
            ++x;
            std::cout << "Cavalry attacks to the east" << std::endl;
            break;
        case Direction::West:
            --x;
            std::cout << "Cavalry attacks to the west "  << std::endl;
            break;
        default:
            x = x;
            std::cout << "Cavalry attacks in all directions" << std::endl;
            break;
    }
}

Cavalry::~Cavalry() = default;

std::shared_ptr<UnitComponent> Cavalry::clone() {
    return std::make_shared<Cavalry>(*this);
}

void Cavalry::applyDamage(int damage) {
    if(damage > this->health) {
        //kill
        std::cout << "Unit had died" << std::endl;
        die();
    }else {
        this->setHealth(this->getHealth()-damage);
        std::cout << "Unit has taken damage!" << std::endl;
    }
}

void Cavalry::die() {
    this->setHealth(0);
    this->setDamage(0);
    this->setDefence(0);
}
