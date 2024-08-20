#ifndef AMBUSH_H
#define AMBUSH_H

#include "BattleStrategy.h"

class Ambush : public BattleStrategy{
public:
    void engage(std::shared_ptr<UnitComponent> &unit) override;

    ~Ambush() override;
};



#endif //AMBUSH_H
