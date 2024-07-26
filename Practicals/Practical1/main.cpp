#include <iostream>

#include "Dessert.h"
#include "MainCourse.h"
#include "Menu.h"
#include "Starter.h"

int main() {
    Starter* starter = new Starter(3);
    MainCourse* main = new MainCourse(3);
    Dessert* dessert = new Dessert(3);

    //Test the recommended drink for each
    /*std::cout << "Starting Test for Recommended Drinks: \n" << std::endl;

    std::cout << "Sparkling Water == ";
    starter->recommendBeverage();
    std::cout << std::endl;

    std::cout << "Coke == ";
    main->recommendBeverage();
    std::cout << std::endl;

    std::cout << "Coffee == ";
    dessert->recommendBeverage();
    std::cout << std::endl;

    std::cout << "Ending Recommened Test....\n" << std::endl;*/

    Starter s(-1);
    if(s.addMenuItem("cream soda float" , 12, 13)) {
        std::cout << "FAILED" << std::endl;
    }else {
        std::cout << "PASSED" << std::endl;
    }

    std::cout << "Starting Course::Description" << std::endl;
    int passed = 0;

    if(starter->getDescription() == "Starter") {
        std::cout << "Passed Test 1" << std::endl;
        ++passed;
    }
    else {
        std::cout << "Failed Test 1" << std::endl;
    }

    if(main->getDescription() == "Main") {
        std::cout << "Passed Test 2" << std::endl;
        ++passed;
    }
    else {
        std::cout << "Failed Test 2" << std::endl;
    }

    if(dessert->getDescription() == "Dessert") {
        std::cout << "Passed Test 3" << std::endl;
        ++passed;
    }
    else {
        std::cout << "Failed Test 3" << std::endl;
    }

    std::cout << "Passed " << passed << "/3 Tests for Description \n" << std::endl;

    passed = 0;
    std::cout << "Starting Course::printInventory Test: \n" << std::endl;
    //empty course tests
    starter->printInventory();
    starter->printMenuItems();
    ++passed;
    main->printInventory();
    main->printMenuItems();
    ++passed;
    dessert->printInventory();
    dessert->printMenuItems();
    ++passed;
    std::cout << "Passed " << passed << "/3 Tests for Empty Inventory\n" << std::endl;

    passed = 0;

    std::cout << "Test Empty Course::getMenuItem: \n" << std::endl;

    if(starter->getMenuItem(1) == nullptr && starter->getMenuItem(-1) == nullptr) {
        ++passed;
        std::cout << "Passed Test 1" << std::endl;
    }

    if(main->getMenuItem(1) == nullptr && main->getMenuItem(-1) == nullptr) {
        ++passed;
        std::cout << "Passed Test 2" << std::endl;
    }

    if(dessert->getMenuItem(1) == nullptr && dessert->getMenuItem(-1) == nullptr) {
        ++passed;
        std::cout << "Passed Test 3" << std::endl;
    }

    std::cout << "Passed " << passed << "/3 Tests" << std::endl;

    passed = 0;
    if(starter->addMenuItem("Snails" , 12, 1)) {
        ++passed;
    }
    if(starter->addMenuItem("Cheese Balls" , 12, 3)) {
        ++passed;
    }
    if(starter->addMenuItem("Bread" , 0, 10)) {
        ++passed;
    }
    if(!starter->addMenuItem("Prawn Tempura",32,2)) {
        ++passed;
    }
    if(!starter->addMenuItem("Prawn Tempura",32,2)) {
        ++passed;
    }

    if(main->addMenuItem("Pizza" , 12, 1)) {
        ++passed;
    }
    if(main->addMenuItem("Steak" , 12, 3)) {
        ++passed;
    }
    if(main->addMenuItem("Salad" , 2, 10)) {
        ++passed;
    }

    if(dessert->addMenuItem("Ice Cream" , 12, 1)) {
        ++passed;
    }
    if(dessert->addMenuItem("Cake" , 12, 3)) {
        ++passed;
    }
    if(dessert->addMenuItem("Pudding" , 2, 10)) {
        ++passed;
    }

    std::cout << "Passed " << passed << "/11 Tests \n" << std::endl;

    /*starter->printMenuItems();
    starter->printInventory();

    main->printMenuItems();
    main->printInventory();

    dessert->printMenuItems();
    dessert->printInventory();*/

    passed = 0;
    std::cout << "Starting getMenuItem Test\n" << std::endl;

    if(starter->getMenuItem(-1) == nullptr && starter->getMenuItem(0)->getDescription() == "Snails" && starter->getMenuItem(1)->getDescription() == "Cheese Balls" && starter->getMenuItem(2)->getDescription() == "Bread" && starter->getMenuItem(3) == nullptr) {
        ++passed;
    }

    if(main->getMenuItem(-1) == nullptr && main->getMenuItem(0)->getDescription() == "Pizza" && main->getMenuItem(1)->getDescription() == "Steak" && main->getMenuItem(2)->getDescription() == "Salad" && main->getMenuItem(3) == nullptr) {
        ++passed;
    }

    if(dessert->getMenuItem(-1) == nullptr && dessert->getMenuItem(0)->getDescription() == "Ice Cream" && dessert->getMenuItem(1)->getDescription() == "Cake" && dessert->getMenuItem(2)->getDescription() == "Pudding" && dessert->getMenuItem(3) == nullptr) {
        ++passed;
    }

    std::cout << "Passed " << passed << "/3 Tests \n" << std::endl;

    delete starter;
    delete main;
    delete dessert;

    starter = new Starter(2);
    main = new MainCourse(3);
    dessert = new Dessert(1);

    starter->addMenuItem("Eggs",12,1);


    passed = 0;

    MenuItem item("item1",12,-1);
    if(item.getStock() == 0) ++passed;
    if(item.getDescription() == "item1") ++passed;
    if(item.getPrice() == 12) ++passed;

    std::cout << "Passed " << passed << "/3 Tests\n" << std::endl;

    MenuItem item2("item2",12,3);
    passed = 0;
    if(item2.getStock() == 3) ++passed;
    item2.reduceStock();
    if(item2.getStock() == 2) ++passed;
    item2.reduceStock();
    if(item2.getStock() == 1) ++passed;
    item2.reduceStock();
    if(item2.getStock() == 0) ++passed;
    item2.reduceStock();
    if(item2.getStock() == 0) ++passed;

    std::cout << "Passed " << passed << "/5 Tests\n" << std::endl;

    Menu menu;

    std::cout << "Starting Empty Tests:\n" << std::endl;
    passed = 0;
    if(menu.isCoursesEmpty()) passed++;
    if(menu.orderItem("Starter",'a') == static_cast<float>(0)) ++passed;
    menu.printMenu();
    passed++;
    menu.inventory();
    passed++;

    std::cout << "Passed " << passed << "/4 Tests\n" << std::endl;

    passed = 0;
    if(menu.addCourse(starter))
        ++passed;
    if(menu.addCourse(main))
        ++passed;
    if(menu.addCourse(dessert))
        ++passed;
    if(!menu.addCourse(nullptr))
        ++passed;
    if(!menu.addCourse(starter))
        ++passed;
    std::cout << "Passed " << passed << "/5 Tests\n" << std::endl;

    std::cout << "Starting add item test" << std::endl;
    passed = 0;
    if(menu.addMenuItem("Starter","Waffles",12,12)) ++passed;
    if(!menu.addMenuItem("Breakfast","Waffles",12,12)) ++passed;
    menu.printMenu();
    if(menu.orderItem("Starter",'a') == static_cast<float>(12)) ++passed;
    if(menu.orderItem("Starter",'a') == static_cast<float>(0)) ++passed;
    if(menu.orderItem("Starter",'a') == static_cast<float>(0)) ++passed;
    if(menu.addMenuItem("Main","Burger",32,4)) ++passed;
    if(!menu.isCoursesEmpty()) ++passed;
    std::cout << "Passed " << passed << "/7 Tests\n" << std::endl;

    menu.inventory();





    return 0;
}
