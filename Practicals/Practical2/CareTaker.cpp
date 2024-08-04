
#include "CareTaker.h"

ConcreteMemento * CareTaker::undo() {
    ConcreteMemento* top = history.top();
    history.pop();
    return top;
}

void CareTaker::saveState(Soldiers &soldiers) {
    history.push(soldiers.militusMemento());
}

CareTaker::~CareTaker() {
    while (!history.empty()) {
        ConcreteMemento* memento = history.top();
        history.pop();
        delete memento;
    }
}
