#ifndef LEGIONUNIT_H
#define LEGIONUNIT_H
#include"Direction.h"

class LegionUnit {
public:
    virtual ~LegionUnit() = default;
    virtual void move(Direction direction) = 0; // Pure virtual function
    virtual void fight(Direction direction) = 0; // Pure virtual function

};
#endif //LEGIONUNIT_H
