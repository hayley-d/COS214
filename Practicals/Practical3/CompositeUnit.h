#ifndef COMPOSITEUNIT_H
#define COMPOSITEUNIT_H

#include <list>
#include <vector>

#include "UnitComponent.h"

class CompositeUnit : public UnitComponent{
public:

    virtual bool add(UnitComponent *component) = 0;

    virtual bool remove(UnitComponent *component) = 0 ;

    virtual const std::list<UnitComponent*>& getUnits() const =0;

    virtual ~CompositeUnit() = default;
};

#endif //COMPOSITEUNIT_H
