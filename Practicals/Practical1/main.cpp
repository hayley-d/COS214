#include <iostream>

#include "Dessert.h"
#include "MainCourse.h"
#include "Menu.h"
#include "Starter.h"

int main() {
   Starter starter(2);
    if(starter.addMenuItem("Snails",9,4)) {
        std::cout << "Added snails to starters" << std::endl;
    }
    if(starter.addMenuItem("Chicken pate",9,4)) {
        std::cout << "Added pate to starters" << std::endl;
    }
    if(!starter.addMenuItem("Salad",9,4)) {
        std::cout << "Did NOT add salad to starters" << std::endl;
    }

    starter.recommendBeverage();
    starter.printMenuItems();
    starter.printInventory();

    return 0;
}
