#ifndef CAVALRY_H
#define CAVALRY_H

#include "UnitComponent.h"

class Cavalry : public UnitComponent{
public:
    void move() override;

    void fight() override;

    bool add(UnitComponent &component) override;

    bool remove(UnitComponent &component) override;

    ~Cavalry() override;
};



#endif //CAVALRY_H
