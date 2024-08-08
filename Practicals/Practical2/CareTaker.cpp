#include "CareTaker.h"

ConcreteMemento *CareTaker::undo() {
    if (history.empty()) {
        return nullptr;
    } else {
        ConcreteMemento *top = history.top();
        history.pop();
        return top;
    }
}

void CareTaker::saveState(Soldiers &soldiers) {
    history.push(soldiers.militusMemento());
}

CareTaker::~CareTaker() {
    while (!history.empty()) {
        if (history.top() != nullptr) {
            delete history.top();
        }
        history.pop();
    }
}

int CareTaker::getSize() const {
    return static_cast<int>(history.size());
}
