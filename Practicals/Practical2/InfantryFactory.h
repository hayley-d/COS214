#ifndef INFANTRYFACTORY_H
#define INFANTRYFACTORY_H

#include "SoldiersFactory.h"

class InfantryFactory : public SoldiersFactory{
public:
    ~InfantryFactory() override;
    Soldiers * createUnit() override;
    InfantryFactory();
};



#endif //INFANTRYFACTORY_H
