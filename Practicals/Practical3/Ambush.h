#ifndef AMBUSH_H
#define AMBUSH_H

#include "BattleStrategy.h"

class Ambush : public BattleStrategy{
public:
    void engage(std::shared_ptr<UnitComponent> &unit,std::shared_ptr<UnitComponent> &enemy) override;

    ~Ambush() override;

    BattleStrategy * clone() const override;


};



#endif //AMBUSH_H
