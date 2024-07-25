//
// Created by hayley on 2024/07/24.
//

#include "Dessert.h"

Dessert::Dessert(int maxNumberOfItems) : Course("Dessert",maxNumberOfItems) {

}

void Dessert::recommendBeverage() {
    std::cout << "Coffee" << std::endl;
}
