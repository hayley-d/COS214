#ifndef BOATMANFACTORY_H
#define BOATMANFACTORY_H

#include "SoldiersFactory.h"

class BoatmanFactory : protected SoldiersFactory{

public:
    BoatmanFactory();
    ~BoatmanFactory() override;
    Soldiers * createUnit() override;
};



#endif //BOATMANFACTORY_H
