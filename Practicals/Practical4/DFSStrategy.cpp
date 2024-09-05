#include "DFSStrategy.h"
typedef std::shared_ptr<FarmUnit> FarmUnitPtr; ///< Type alias for shared pointer to FarmUnit.
typedef std::vector<std::shared_ptr<FarmUnit>> FarmUnitPtrVector; ///< Type alias for vector of shared pointers to FarmUnit.

void DFSStrategy::initialize(FarmUnitPtrVector farmUnits) {
    while (!stack.empty()) stack.pop();
    for (auto it = farmUnits.rbegin(); it != farmUnits.rend(); ++it) {
        stack.push(*it);
    }
}

bool DFSStrategy::hasNext()  {
    return !stack.empty();
}

FarmUnitPtr DFSStrategy::getNext() {
    if (stack.empty()) return nullptr;
    FarmUnitPtr current = stack.top();
    stack.pop();

    auto childIterator = current->getIterator();

    if (childIterator) {
        while (childIterator->hasNext()) {
            stack.push(childIterator->next());
        }
    }

    return current;
}

bool DFSStrategy::isDone() const {
    return stack.empty();
}
