#ifndef LEGIONFACTORY_H
#define LEGIONFACTORY_H
//(Abstract Base Class)
#include "Infantry.h"
#include "Cavalry.h"
#include "Artillery.h"
#include "Legion.h"

class LegionFactory{

public:
    virtual Infantry* createInfantry() = 0;
    virtual Cavalry* createCavalry() = 0;
    virtual Artillery* createArtillery() = 0;
    virtual Legion* createLegion() =0;
    virtual ~LegionFactory() = default;
};
#endif //LEGIONFACTORY_H
