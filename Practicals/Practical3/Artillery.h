#ifndef ARTILLERY_H
#define ARTILLERY_H

#include "UnitComponent.h"

class Artillery : public UnitComponent{
public:
    void move(Direction direction) override;

    void fight(Direction direction) override;

    ~Artillery() override;
};



#endif //ARTILLERY_H
