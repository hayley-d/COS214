#ifndef COMPOSITEUNIT_H
#define COMPOSITEUNIT_H

#include "UnitComponent.h"
#include <vector>

class CompositeUnit : public UnitComponent{
protected:
    std::vector<UnitComponent*> units;

public:
    void move() override;

    void fight() override;

    bool add(UnitComponent &component) override;

    bool remove(UnitComponent &component) override;

    ~CompositeUnit() override;
};



#endif //COMPOSITEUNIT_H
