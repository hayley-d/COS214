#ifndef FLANKING_H
#define FLANKING_H

#include "BattleStrategy.h"


class Flanking : public BattleStrategy {

public:
    Flanking(LegionFactory& factory) : BattleStrategy(factory){}

    UnitComponent * engage() override;

    ~Flanking() override;

    BattleStrategy * clone() const override;
};


#endif //FLANKING_H
