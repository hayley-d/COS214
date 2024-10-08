#include "TacticalCommand.h"

void TacticalCommand::setStrategy(BattleStrategy *strategy) {
    if(strategy!=nullptr) {
        //delete old stategy
        delete strategy;
        this->strategy = strategy;
    }
    this->planner->restoreMemento(new TacticalMemento(strategy));
}

void TacticalCommand::chooseBestStrategy() {

}

void TacticalCommand::executeStrategy() {
    this->strategy->engage();
}

TacticalCommand::TacticalCommand(BattleStrategy &strategy) {
    this->strategy = &strategy;
}

TacticalCommand::TacticalCommand(BattleStrategy &strategy, WarArchives *archives) {
}

TacticalCommand::~TacticalCommand() {
    delete planner;
    delete strategy;
}
