#ifndef CAVALRY_H
#define CAVALRY_H

#include "UnitComponent.h"

class Cavalry : public UnitComponent{
public:
    Cavalry() : UnitComponent(15,15,100,0,0){}

    Cavalry(const int defence, const int damage, const int health, const int x, const int y) :UnitComponent(defence,damage,health,x,y) {}

    Cavalry(const Cavalry &other) : UnitComponent(other.defence,other.damage,other.health,other.x,other.y){}

    Cavalry & operator=(const Cavalry &other);

    bool operator<(const Cavalry& other) const;

    void move(Direction direction) override;

    void fight(Direction direction) override;

    ~Cavalry() override;

    std::shared_ptr<UnitComponent> clone() override;
};



#endif //CAVALRY_H
