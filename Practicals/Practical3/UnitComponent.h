#ifndef UNITCOMPONENT_H
#define UNITCOMPONENT_H
#include "Direction.h"

class UnitComponent {
public:
    virtual void move(Direction direction) = 0;
    virtual void fight(Direction direction) = 0;
    virtual int getDamage() const =0;
    virtual int getDefence() const =0;
    virtual int getHealth() const =0;
    virtual int getX() const =0;
    virtual int getY() const =0;
    virtual ~UnitComponent() = default;

};

#endif //UNITCOMPONENT_H
