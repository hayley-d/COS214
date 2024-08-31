#include "BFSStrategy.h"

void BFSStrategy::initialize(FarmUnit *root) {
    while (!queue.empty()) queue.pop();
    if (root) queue.push(root);
}

FarmUnit * BFSStrategy::getNext() {
    if(queue.empty()) return nullptr;
    FarmUnit* current = queue.top();
    queue.pop();

    for (FarmUnit* child : current->getFarms()) {
        queue.push(child);
    }

    return current;
}

bool BFSStrategy::isDone() const {
    return queue.empty();
}
