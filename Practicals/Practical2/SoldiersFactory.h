#ifndef SOLDIERSFACTORY_H
#define SOLDIERSFACTORY_H
#include "Soldiers.h"


class SoldiersFactory {
    Soldiers* soldiers;
protected:
    virtual Soldiers* createUnit();
public:
    SoldiersFactory();
    virtual ~SoldiersFactory();
    virtual int calculateTotalDamagePerUnit();
    virtual int calculateTotalDefencePerUnit();
    virtual int calculateTotalHealthPerUnit();

};



#endif //SOLDIERSFACTORY_H
