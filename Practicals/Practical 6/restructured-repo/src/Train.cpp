#include "Train.h"
#include <iostream>

Train::Train(int capacity) : Vehicle("Train", capacity) {}

void Train::checkState() {
    if (getState()) {
        getState()->checkCapacity(this);
    }
    else {
        std::cout << "Train has no assigned state!" << std::endl;
    }
}

void Train::collect(int amount) {
    std::cout << "Train collected " << amount << " units of cargo." << std::endl;
}

void Train::run() {
    std::cout << "Train is running on tracks." << std::endl;
}

void Train::breakDown() {
    std::cout << "Train has broken down on the tracks!" << std::endl;
    if (getState()) {
        getState()->breakTransport(this);
    }
}

void Train::delay() {
    std::cout << "Train is delayed." << std::endl;
}

Vehicle* Train::clone() {
    return new Train(capacity);
}
