#ifndef SOLDIERSFACTORY_H
#define SOLDIERSFACTORY_H
#include <memory>

#include "Soldiers.h"

class SoldiersFactory {
protected:
    Soldiers* soldiers;
    virtual Soldiers* createUnit() =0;
public:
    SoldiersFactory();
    SoldiersFactory(Soldiers* s);
    virtual ~SoldiersFactory();
    virtual int calculateTotalDamagePerUnit();
    virtual int calculateTotalDefencePerUnit();
    virtual int calculateTotalHealthPerUnit();
};



#endif //SOLDIERSFACTORY_H
