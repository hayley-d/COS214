#ifndef INFANTRYFACTORY_H
#define INFANTRYFACTORY_H

#include "SoldiersFactory.h"

class InfantryFactory : public SoldiersFactory{
public:
    ~InfantryFactory() override;
    Soldiers * factoryMethod() override;
};



#endif //INFANTRYFACTORY_H
