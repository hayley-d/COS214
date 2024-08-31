#include "FarmIterator.h"

FarmIterator::FarmIterator(TraversalStrategy *strategy, FarmUnit *root) : strategy(strategy), current(nullptr) {
    if (this->strategy != nullptr) {
        this->strategy->initialize(root);
        current = root;
    } else {
        //default traversal is BFS
        strategy = new BFSStrategy();
        strategy->initialize(root);
        current = root;
    }
}

FarmUnit *FarmIterator::firstFarm() {
    return root;
}


FarmUnit *FarmIterator::currentFarm() {
    return current;
}


bool FarmIterator::isDone() {
    return strategy->isDone();
}


FarmUnit *FarmIterator::next() {
    current = strategy->getNext();
    return current;
}
