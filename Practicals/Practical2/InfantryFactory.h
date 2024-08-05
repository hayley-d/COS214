#ifndef INFANTRYFACTORY_H
#define INFANTRYFACTORY_H

#include "Infantry.h"

#include "SoldiersFactory.h"

class InfantryFactory : public SoldiersFactory{
public:
    ~InfantryFactory() override;
    Soldiers * createUnit() override;
    InfantryFactory();
};



#endif //INFANTRYFACTORY_H
