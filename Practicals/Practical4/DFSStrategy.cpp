#include "DFSStrategy.h"

void DFSStrategy::initialize(FarmUnit *root) {
    while (!stack.empty()) stack.pop();
    if (root) stack.push(root);
}

FarmUnit * DFSStrategy::getNext() {
    if (stack.empty()) return nullptr;
    FarmUnit* current = stack.top();
    stack.pop();

    for (FarmUnit* child : current->getFarms()) {
        stack.push(child);
    }

    return current;
}

bool DFSStrategy::isDone() const {
    return stack.empty();
}
