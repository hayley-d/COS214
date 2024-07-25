//
// Created by hayley on 2024/07/24.
//

#ifndef COURSE_H
#define COURSE_H

#include <string>
#include <vector>
#include <iostream>

#include "MenuItem.h"


class Course {
protected:
    std::string description;
    int maxNumberOfItems;
    std::vector<MenuItem*> menuItems;

public:
    Course(std::string description, int maxNumberOfItems);
    std::string getDescription();
    bool addMenuItem(std::string description, float price, int stock);
    void printMenuItems();
    void printInventory();
    MenuItem* getMenuItem(int index);
    virtual void recommendBeverage() = 0;
    ~Course();
};



#endif //COURSE_H
