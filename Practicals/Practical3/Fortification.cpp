#include "Fortification.h"

void Fortification::engage(std::shared_ptr<UnitComponent> &unit) {
    if(unit->getSize() < getMinimumTroops()){
        //kill all troops
        return;
    }
    
}

Fortification::~Fortification() {
}
