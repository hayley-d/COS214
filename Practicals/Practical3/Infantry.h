#ifndef INFANTRY_H
#define INFANTRY_H

#include "UnitComponent.h"

class Infantry : public UnitComponent{
public:
    void move() override;

    void fight() override;

    bool add(UnitComponent &component) override;

    bool remove(UnitComponent &component) override;

    ~Infantry() override;
};



#endif //INFANTRY_H
