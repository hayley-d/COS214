//
// Created by hayley on 2024/07/24.
//

#include "Course.h"

Course::Course(std::string description, int maxNumberOfItems) : description(description), maxNumberOfItems(maxNumberOfItems){}

bool Course::addMenuItem(std::string description, float price, int stock) {

    bool found = false;

    for(const auto& item : menuItems) {
        if(item->getDescription() == description) {
            found = true;
            break;
        }
    }

    if(!found) {
        menuItems.push_back(new MenuItem(description,price,stock));
        return true;
    }

    return false;
}

void Course::printMenuItems() {
    char index = 'a';
    for(const auto& item : menuItems) {
        std::cout << '\t' << index << "." << '\t' << item->getDescription() << std::endl;
        ++index;
    }
}

void Course::printInventory() {
    char index = 'a';
    for(const auto& item : menuItems) {
        std::cout << '\t' << index << "." << '\t' << item->getDescription() << '\t' << item->getPrice() << '\t' << item->getStock() << std::endl;
        ++index;
    }
}

MenuItem *Course::getMenuItem(int index) {
    if(index >= 0 || index < menuItems.size()) {
        return menuItems[index];
    }
    return nullptr;
}

std::string Course::getDescription() {
    return description;
}

Course::~Course() {
    for(auto& item : menuItems) {
        delete item;
    }

    menuItems.clear();
}
