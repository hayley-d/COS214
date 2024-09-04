#include "BFSStrategy.h"
typedef std::shared_ptr<FarmUnit> FarmUnitPtr;
typedef std::vector<std::shared_ptr<FarmUnit>> FarmUnitPtrVector;

void BFSStrategy::initialize(FarmUnitPtrVector farmUnits) {
    // Clear the queue before initializing
    while (!queue.empty()) queue.pop();

    // Add all the initial farm units to the queue
    for (const auto &unit : farmUnits) {
        queue.push(unit);
    }
}

FarmUnitPtr BFSStrategy::getNext() {
    if (queue.empty()) return nullptr;

    // Get the next FarmUnit in the queue
    FarmUnitPtr current = queue.top();
    queue.pop();

    // Check if the current FarmUnit is a composite
    if (current->isComposite()) {
        // Add all children of the current unit to the queue
        for (const auto &child : current->getChildren()) {
            queue.push(child);
        }
    }

    return current;
}

bool BFSStrategy::isDone() const {
    return queue.empty();
}

bool BFSStrategy::hasNext() {
    return !queue.empty();
}
