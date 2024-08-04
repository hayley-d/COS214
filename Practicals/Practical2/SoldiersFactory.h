#ifndef SOLDIERSFACTORY_H
#define SOLDIERSFACTORY_H
#include "Soldiers.h"


class SoldiersFactory {
    Soldiers* soldiers;
protected:
    virtual Soldiers* factoryMethod();
public:
    virtual ~SoldiersFactory();
};



#endif //SOLDIERSFACTORY_H
