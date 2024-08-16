#ifndef ARTILLERY_H
#define ARTILLERY_H

#include "UnitComponent.h"

class Artillery : public UnitComponent{

    int defence;
    int damage;
    int health;

    int x;
    int y;
public:
    Artillery() : defence(10), damage(30), health(100), x(0), y(0){}

    Artillery(const int defence, const int damage, const int health, const int x, const int y) : defence(defence), damage(damage), health(health), x(x), y(y){}

    Artillery(const Artillery &other);

    Artillery & operator=(const Artillery &other);

    bool operator<(const Artillery& other) const;

    void move(Direction direction) override;

    void fight(Direction direction) override;

    ~Artillery() override;

    int getDamage() const override {return damage;}

    int getDefence() const override{return defence;}

    int getHealth() const override{return health;}

    int getX() const override{return x;}

    int getY() const override {return y;}
};



#endif //ARTILLERY_H
