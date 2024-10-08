#ifndef CAVALRY_H
#define CAVALRY_H

#include "UnitComponent.h"

class Cavalry : public UnitComponent{
public:
    Cavalry() : UnitComponent(15,15,100,1,0,0){}

    Cavalry(const int defence, const int damage, const int health, const int x, const int y) :UnitComponent(defence,damage,health,1,x,y) {}

    Cavalry(const Cavalry &other) : UnitComponent(other.defence,other.damage,other.health,1,other.x,other.y){}

    Cavalry & operator=(const Cavalry &other);

    bool operator<(const Cavalry& other) const;

    virtual void move(Direction direction);

    virtual void fight(Direction direction);

    virtual ~Cavalry() override{}

    virtual UnitComponent* clone() override;

    void applyDamage(int damage) override;

    void die() override;

    bool operator==(UnitComponent &other) override;
};



#endif //CAVALRY_H
