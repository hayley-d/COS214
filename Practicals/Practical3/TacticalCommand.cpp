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

void TacticalCommand::executeStrategy(std::shared_ptr<UnitComponent>& unit) {
    this->strategy->engage(unit);
}

TacticalCommand::TacticalCommand(BattleStrategy &strategy) {
    this->strategy = &strategy;
}
