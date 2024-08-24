
#include "TacticalPlanner.h"
TacticalMemento* TacticalPlanner::createMemento() const {
    return new TacticalMemento(currentStrategy);
}

void TacticalPlanner::restoreMemento(TacticalMemento* memento) {
    currentStrategy = memento->getStoredStrategy();
}