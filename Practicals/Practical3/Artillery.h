#ifndef ARTILLERY_H
#define ARTILLERY_H

#include "UnitComponent.h"

class Artillery : public UnitComponent{
public:
    void move() override;

    void fight() override;

    bool add(UnitComponent &component) override;

    bool remove(UnitComponent &component) override;

    ~Artillery() override;
};



#endif //ARTILLERY_H
