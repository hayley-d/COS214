//
// Created by hayley on 2024/08/04.
//

#ifndef BOATMANFACTORY_H
#define BOATMANFACTORY_H

#include "SoldiersFactory.h"

class BoatmanFactory : public SoldiersFactory{

public:
    ~BoatmanFactory() override;
    Soldiers * factoryMethod() override;
};



#endif //BOATMANFACTORY_H
