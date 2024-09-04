#include "FarmIterator.h"
#include "DFSStrategy.h"

FarmIterator::FarmIterator(TraversalStrategy *strategy, FarmUnit *root) : strategy(strategy), current(nullptr) {
    if (this->strategy == nullptr) {
        strategy = new DFSStrategy();
    }
    this->strategy->initialize(root);
    current = root;
    this->root = root;
}

FarmIterator::FarmIterator(FarmUnit *root) {
    this->strategy = new DFSStrategy();
    this->strategy->initialize(root);
    current = root;
    this->root = root;
}

std::shared_ptr<FarmUnit>FarmIterator::firstFarm() {
    return root;
}

std::shared_ptr<FarmUnit>FarmIterator::currentFarm() {
    return current;
}

bool FarmIterator::isDone() {
    return strategy->isDone();
}

std::shared_ptr<FarmUnit>FarmIterator::next() {
    current = strategy->getNext();
    return current;
}

FarmIterator &FarmIterator::operator++() {
    current = strategy->getNext();
    return *this;
}

FarmIterator FarmIterator::operator++(int) {
    FarmIterator temp = *this;
    strategy->getNext();
    return temp;
}

FarmUnit &FarmIterator::operator*() {
    return *current;
}

std::shared_ptr<FarmUnit> FarmIterator::operator->() {
    return current;
}

bool FarmIterator::operator==(FarmIterator &other) {
    return current == other.current;
}

bool FarmIterator::operator!=(FarmIterator &other) {
    return current != other.current;
}

FarmIterator &FarmIterator::operator=(FarmIterator &other) {
    if (this != &other) {
        current = other.current;
    }
    return *this;
}

bool FarmIterator::hasNext() {
    return this->strategy->hasNext();
}
