#include "FarmIterator.h"
#include "DFSStrategy.h"

FarmIterator::FarmIterator(TraversalStrategy *strategy, FarmUnitPtrVector& farms) : strategy(strategy), current(nullptr) {
    if (this->strategy == nullptr) {
        this->strategy = new DFSStrategy();
    }
    this->strategy->initialize(farms);
    current = farms.at(0);
    this->farms = farms;
}

FarmIterator::FarmIterator(FarmUnitPtrVector& farms){
    this->strategy = new DFSStrategy();
    this->strategy->initialize(farms);
    current = farms.at(0);
    this->farms = farms;
}

std::shared_ptr<FarmUnit>FarmIterator::firstFarm() {
    return farms.at(0);
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

bool FarmIterator::operator==(const FarmIterator &other) const {
    return current == other.current;
}

bool FarmIterator::operator!=(const FarmIterator &other) const{
    return current != other.current;
}

FarmIterator &FarmIterator::operator=(const FarmIterator &other) {
    if (this != &other) {
        current = other.current;
    }
    return *this;
}

bool FarmIterator::hasNext() {
    return this->strategy->hasNext();
}

FarmIterator FarmIterator::begin() {
    return *this; // Assumes that the iterator is already initialized to the start
}

FarmIterator FarmIterator::end() {
    FarmIterator endIterator = *this;
    endIterator.current = nullptr; // End iterator points to null
    return endIterator;
}