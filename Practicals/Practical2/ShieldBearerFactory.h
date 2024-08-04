#ifndef SHIELDBEARERFACTORY_H
#define SHIELDBEARERFACTORY_H

#include "SoldiersFactory.h"

class ShieldBearerFactory : public SoldiersFactory{

public:
    ~ShieldBearerFactory() override;
    Soldiers * factoryMethod() override;
};



#endif //SHIELDBEARERFACTORY_H
