#ifndef TACTICALCOMMAND_H
#define TACTICALCOMMAND_H

#include "BattleStrategy.h"

class TacticalCommand {
    BattleStrategy* strategy;
public:
    void setStrategy(BattleStrategy* strategy);
    void chooseBestStrategy();
    void executeStrategy(UnitComponent& unit,UnitComponent& enemy);
    TacticalCommand(BattleStrategy& strategy);
};



#endif //TACTICALCOMMAND_H
