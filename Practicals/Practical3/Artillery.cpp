#include "Artillery.h"
#include <iostream>
Artillery &Artillery::operator=(const Artillery &other) {
    this->damage = other.getDamage();
    this->defence = other.getDefence();
    this->health = other.getHealth();
    this->size = other.getSize();
    this->x = other.getX();
    this->y = other.getY();
    return *this;
}

bool Artillery::operator<(const Artillery &other) const {
    return this->getSize() < other.getSize();
}

bool Artillery::operator==(const Artillery &other) const {
    if (other.getDefence() == defence && other.getDamage() == damage && other.getHealth() == health && other.getSize()
        == size && other.getX() == x && other.getY() == y) {
        return true;
    }
    return false;
}

void Artillery::move(Direction direction) {
    switch (direction) {
        case Direction::North:
            ++y;
            std::cout << "Artillery moves to the north"<< std::endl;
            break;
        case Direction::South:
            --y;
            std::cout << "Artillery moves to the east"<< std::endl;
            break;
        case Direction::East:
            ++x;
            std::cout << "Artillery moves to the east"<< std::endl;
            break;
        case Direction::West:
            --x;
            std::cout << "Artillery moves to the west"<< std::endl;
            break;
        default:
            x = x;
            std::cout << "Artillery moves in all directions"<< std::endl;
            break;
    }

}

void Artillery::fight(Direction direction) {
    switch (direction) {
        case Direction::North:
            ++y;
             std::cout << "Artillery attacks to the North "<< std::endl;
            break;
        case Direction::South:
            --y;
            std::cout << "Artillery attacks to the south" << std::endl;
            break;
        case Direction::East:
            ++x;
            std::cout << "Artillery attacks to the east" << std::endl;
            break;
        case Direction::West:
            --x;
            std::cout << "Artillery attacks to the west "  << std::endl;
            break;
        default:
            x = x;
            std::cout << "Artillery attacks in all directions" << std::endl;
            break;
    }

}

Artillery::~Artillery() = default;

UnitComponent* Artillery::clone() {
    return new Artillery(*this);
}

void Artillery::applyDamage(int damage) {
     if(damage > this->health) {
        //kill
        std::cout << "Unit had died" << std::endl;
        die();
    }else {
        this->setHealth(this->getHealth()-damage);
        std::cout << "Unit has taken damage!" << std::endl;
    }
}

void Artillery::die() {
    this->setHealth(0);
    this->setDamage(0);
    this->setDefence(0);
}

bool Artillery::operator==(UnitComponent &other) {
    if(other.getDefence() == defence && other.getDamage() == damage && other.getHealth() == health && other.getSize() == size && other.getX() == x && other.getY() == y) {
        return true;
    }
    return false;
}
