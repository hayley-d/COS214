#include <iostream>

#include "Dessert.h"
#include "MainCourse.h"
#include "Menu.h"
#include "Starter.h"

int main() {
    Menu menu;

    std::cout << menu.orderItem("Starter",'a') << std::endl;

    if(menu.isCourseEmpty()) {
        std::cout << "Empty" << std::endl;
    }
    else {
        std::cout << "Not Empty" << std::endl;
    }

   Starter* course = new Starter(3);

    if(course->addMenuItem("Waffles",10,3)) {
        std::cout << "Added waffles to menu" << std::endl;
    }
    if(course->addMenuItem("Eggs",12,100)) {
        std::cout << "Added eggs to menu" << std::endl;
    }
    if(course->addMenuItem("Oats",2,40)) {
        std::cout << "Added oats to the menu" << std::endl;
    }

    MainCourse* course2 = new MainCourse(3);

    if(course2->addMenuItem("Cheese Burger",10,3)) {
        std::cout << "Added cheese burger to menu" << std::endl;
    }
    if(course2->addMenuItem("Pineapple Pizza",12,100)) {
        std::cout << "Added pizza to menu" << std::endl;
    }
    if(course2->addMenuItem("Haggis",2,40)) {
        std::cout << "Added haggis to the menu" << std::endl;
    }



    menu.addCourse(course);
    menu.addCourse(course2);
    menu.inventory();
    menu.printMenu();

    menu.orderItem("Starter",'b');
    menu.inventory();



    return 0;
}
