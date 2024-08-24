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

/*bool Infantry::operator==(const Infantry &other) const{
    if (other.getDefence() == defence && other.getDamage() == damage && other.getHealth() == health && other.getSize()
        == size && other.getX() == x && other.getY() == y) {
        return true;
    }
    return false;
}*/

void Infantry::move(Direction direction) {
    switch (direction) {
        case Direction::North:
            ++y;
            std::cout << "Infantry moves to the north"<< std::endl;
            break;
        case Direction::South:
            --y;
            std::cout << "Infantry moves to the east"<< std::endl;
            break;
        case Direction::East:
            ++x;
            std::cout << "Infantry moves to the east"<< std::endl;
            break;
        case Direction::West:
            --x;
            std::cout << "Infantry moves to the west"<< std::endl;
            break;
        default:
            x = x;
            std::cout << "Infantry moves in all directions"<< std::endl;
            break;
    }
}

void Infantry::fight(Direction direction) {
    switch (direction) {
        case Direction::North:
            ++y;
             std::cout << "Infantry attacks to the North "<< std::endl;
            break;
        case Direction::South:
            --y;
            std::cout << "Infantry attacks to the south" << std::endl;
            break;
        case Direction::East:
            ++x;
            std::cout << "Infantry attacks to the east" << std::endl;
            break;
        case Direction::West:
            --x;
            std::cout << "Infantry attacks to the west "  << std::endl;
            break;
        default:
            x = x;
            std::cout << "Infantry attacks in all directions" << std::endl;
            break;
    }
}

Infantry::~Infantry() = default;

UnitComponent* Infantry::clone() {
    return new Infantry(*this);
}

void Infantry::applyDamage(int damage) {
    if(damage > this->health) {
        //kill
        std::cout << "Unit had died" << std::endl;
        die();
    }else {
        this->setHealth(this->getHealth()-damage);
        std::cout << "Unit has taken damage!" << std::endl;
    }
}

void Infantry::die() {
    this->setHealth(0);
    this->setDamage(0);
    this->setDefence(0);
}

bool Infantry::operator==(UnitComponent &other) {
    if(other.getDefence() == defence && other.getDamage() == damage && other.getHealth() == health && other.getSize() == size && other.getX() == x && other.getY() == y) {
        return true;
    }
    return false;
}
