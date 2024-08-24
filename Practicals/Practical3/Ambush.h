#ifndef AMBUSH_H
#define AMBUSH_H

#include "BattleStrategy.h"

class Ambush : public BattleStrategy{
public:
    Ambush(LegionFactory& factory) : BattleStrategy(factory) {}

    UnitComponent * engage() override;

    BattleStrategy * clone() const override;

    ~Ambush() override;
};



#endif //AMBUSH_H
