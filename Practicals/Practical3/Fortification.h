#ifndef FORTIFICATION_H
#define FORTIFICATION_H


#include "BattleStrategy.h"

class Fortification : public BattleStrategy{
public:
    Fortification(LegionFactory& factory) : BattleStrategy(factory){}

    UnitComponent* engage() override;

    ~Fortification() override;

    BattleStrategy * clone() const override;
};



#endif //FORTIFICATION_H
