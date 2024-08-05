#ifndef SOLDIERSFACTORY_H
#define SOLDIERSFACTORY_H
#include "Soldiers.h"


class SoldiersFactory {
protected:
    Soldiers* soldiers;
    virtual Soldiers* createUnit();
public:
    SoldiersFactory();
    virtual ~SoldiersFactory();
    virtual int calculateTotalDamagePerUnit();
    virtual int calculateTotalDefencePerUnit();
    virtual int calculateTotalHealthPerUnit();
};



#endif //SOLDIERSFACTORY_H
