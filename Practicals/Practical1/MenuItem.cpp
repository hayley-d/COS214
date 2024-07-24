//
// Created by hayley on 2024/07/24.
//

#include "MenuItem.h"

MenuItem::MenuItem(std::string description, float price, int stock): description(description), price(price), stock(stock){}

std::string MenuItem::getDescription() {
    return description;
}

float MenuItem::getPrice() {
    return price;
}

int MenuItem::getStock() {
    return stock;
}

void MenuItem::reduceStock() {
    if(stock > 0) {
        this->stock--;
    }
}



