#include "TacticalCommand.h"

void TacticalCommand::setStrategy(BattleStrategy *strategy) {
    if(strategy!=nullptr) {
        //delete old stategy
        delete strategy;
        this->strategy = strategy;
    }
}

void TacticalCommand::chooseBestStrategy() {

}

void TacticalCommand::executeStrategy(UnitComponent& unit,UnitComponent& enemy) {
    this->strategy->engage(unit,enemy);
}

TacticalCommand::TacticalCommand(BattleStrategy &strategy) {
    this->strategy = &strategy;
}
