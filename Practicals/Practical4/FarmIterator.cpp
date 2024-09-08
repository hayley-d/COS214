#include "FarmIterator.h"
#include "DFSStrategy.h"

typedef std::shared_ptr<FarmUnit> FarmUnitPtr;

FarmIterator::FarmIterator(std::shared_ptr<TraversalStrategy> strategy, FarmUnitPtrVector* farms) : strategy(std::move(strategy)), current(nullptr) {
    this->strategy->initialize(farms);
    current = farms->at(0);
    this->farms = farms;
}

FarmIterator::FarmIterator(FarmUnitPtrVector* farms){
    this->strategy = std::make_shared<DFSStrategy>();
    this->strategy->initialize(farms);
    current = farms->at(0);
    this->farms = farms;
}

std::shared_ptr<FarmUnit>FarmIterator::firstFarm() {
    return farms->at(0);
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


FarmUnitPtr& FarmIterator::operator*() {
    return current;
}

std::shared_ptr<FarmUnit> FarmIterator::operator->() {
    return current;
}

bool FarmIterator::hasNext() {
    return this->strategy->hasNext();
}

