#ifndef CAVALRY_H
#define CAVALRY_H

#include "UnitComponent.h"

class Cavalry : public UnitComponent{
    int defence;
    int damage;
    int health;

    int x;
    int y;

public:
    Cavalry() : defence(15), damage(15), health(100), x(0), y(0){}

    Cavalry(const int defence, const int damage, const int health, const int x, const int y) : defence(defence), damage(damage), health(health), x(x), y(y){}

    Cavalry(const Cavalry &other);

    Cavalry & operator=(const Cavalry &other);

    bool operator<(const Cavalry& other) const;

    void move(Direction direction) override;

    void fight(Direction direction) override;

    ~Cavalry() override;

    int getDamage() const override{return damage;}

    int getDefence() const override{return defence;}

    int getHealth() const override{return health;}

    int getX() const override{return x;}

    int getY() const override {return y;}
};



#endif //CAVALRY_H
