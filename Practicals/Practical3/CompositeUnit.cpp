#include "CompositeUnit.h"

void CompositeUnit::move() {

}

void CompositeUnit::fight() {

}

bool CompositeUnit::add(UnitComponent &component) {

}

bool CompositeUnit::remove(UnitComponent &component) {

}

CompositeUnit::~CompositeUnit() {
    for(UnitComponent* ptr : units) {
        delete ptr;
    }
    units.clear();
}
