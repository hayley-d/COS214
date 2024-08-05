#ifndef SHIELDBEARERFACTORY_H
#define SHIELDBEARERFACTORY_H

#include "SoldiersFactory.h"

class ShieldBearerFactory : public SoldiersFactory{

public:
    ShieldBearerFactory();
    ~ShieldBearerFactory() override;
    Soldiers * createUnit() override;
};



#endif //SHIELDBEARERFACTORY_H
