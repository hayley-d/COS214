#ifndef INFANTRY_H
#define INFANTRY_H

#include <utility>

#include "UnitComponent.h"

class Infantry : public UnitComponent{
    int defence;
    int damage;
    int health;

    int x;
    int y;

public:
    Infantry() : defence(10), damage(10), health(100){}

    Infantry(const int defence, const int damage, const int health) : defence(defence), damage(damage), health(health){}

    Infantry(const Infantry &other);

    Infantry & operator=(const Infantry &other);

    bool operator<(const Infantry& other) const;

    void move(Direction direction) override;

    void fight(Direction direction) override;

    ~Infantry() override;

    int getDamage() const override{return damage;}

    int getDefence() const override{return defence;}

    int getHealth() const override{return health;}

    int getX() const override{return x;}

    int getY() const override {return y;}
};



#endif //INFANTRY_H
