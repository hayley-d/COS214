#ifndef CARETAKER_H
#define CARETAKER_H

#include <stack>
#include "ConcreteMemento.h"
#include "Soldiers.h"

class CareTaker {
    std::stack<ConcreteMemento*> history;

public:
    CareTaker() = default;
    ConcreteMemento* undo();
    void saveState(Soldiers& soldiers);
    ~CareTaker();
};



#endif //CARETAKER_H
