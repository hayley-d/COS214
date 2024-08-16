#ifndef CAVALRY_H
#define CAVALRY_H

#include "UnitComponent.h"

class Cavalry : public UnitComponent{
public:
    void move(Direction direction) override;

    void fight(Direction direction) override;

    ~Cavalry() override;
};



#endif //CAVALRY_H
