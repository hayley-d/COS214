#ifndef ARTILLERY_H
#define ARTILLERY_H

#include "UnitComponent.h"

class Artillery : public UnitComponent{
public:
    Artillery(): UnitComponent(10,30,100,1,0,0){}

    Artillery(const int defence, const int damage, const int health, const int x, const int y) :UnitComponent(defence,damage,health,1,x,y){}

    Artillery(const Artillery &other): UnitComponent(other.defence,other.damage,other.health,1,other.x,other.y){}

    Artillery & operator=(const Artillery &other);

    bool operator<(const Artillery& other) const;

    bool operator==(const Artillery& other) const;

    void move(Direction direction) override;

    void fight(Direction direction) override;

    ~Artillery() override;

    UnitComponent* clone() override;

    void applyDamage(int damage) override;

    void die() override;

    bool operator==(UnitComponent &other) override;
};



#endif //ARTILLERY_H
