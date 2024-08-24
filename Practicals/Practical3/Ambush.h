#ifndef AMBUSH_H
#define AMBUSH_H

#include "BattleStrategy.h"

class Ambush : public BattleStrategy{
public:
    void engage( UnitComponent&unit,UnitComponent &enemy) override;

    ~Ambush() override;

    BattleStrategy * clone() const override;


};



#endif //AMBUSH_H
