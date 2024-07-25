//
// Created by hayley on 2024/07/24.
//

#include "Starter.h"

Starter::Starter(int maxNumberOfItems) : Course("Starter",maxNumberOfItems) {
}

void Starter::recommendBeverage() {
    std::cout << "Sparkling Water" << std::endl;
}
