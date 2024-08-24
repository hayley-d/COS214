#ifndef BATTLESTRATEGY_H
#define BATTLESTRATEGY_H
#include "UnitComponent.h"
#include <time.h>

#include "LegionFactory.h"

enum class Terrain {
    Woodlands,
    Riverbank,
    OpenField
};

class BattleStrategy {
protected:
    LegionFactory* factory;

public:
    BattleStrategy(LegionFactory& factory);

    virtual UnitComponent* engage() =0;

    virtual BattleStrategy* clone() const = 0;

    virtual ~BattleStrategy() = default;

    void setFactory(LegionFactory& newFactory) {
        if(factory != nullptr) {
            delete factory;
        }
        this->factory = &newFactory;
    }
};



#endif //BATTLESTRATEGY_H
