#ifndef UNITCOMPONENT_H
#define UNITCOMPONENT_H
#include "Direction.h"
#include <memory>
#include <iostream>
class UnitComponent {
protected:
    int defence;
    int damage;
    int health;
    int size;
    int x;
    int y;

public:
    UnitComponent(const int defence, const int damage, const int health, const int size, const int x, const int y): defence(defence), damage(damage), health(health), size(size), x(x), y(y){}
    virtual void move(Direction direction) = 0;
    virtual void fight(Direction direction) = 0;
    virtual ~UnitComponent() = default;

    virtual void setDamage(int damage){this->damage = damage;}

    virtual void setDefence(int defence){this->defence = defence;}

    virtual void setHealth(int health){this->health = health;}

    virtual void setSize(int size){this->size = size;}

    virtual void setX(int x){this->x = x;}

    virtual void setY(int y){this->y = y;}

    virtual int getDamage() const {return damage;}

    virtual int getDefence() const {return defence;}

    virtual int getHealth() const {return health;}

    virtual int getSize() const {return size;}

    virtual int getX() const {return x;}

    virtual int getY() const  {return y;}

    virtual std::shared_ptr<UnitComponent> clone() =0;

    UnitComponent(const UnitComponent& other): defence(other.defence), damage(other.damage), health(other.health), size(other.size), x(other.x), y(other.y){}

    virtual void applyDamage(int damage) =0;

    virtual void die() =0;
};

#endif //UNITCOMPONENT_H
