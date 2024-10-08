//
// Created by hayley on 2024/07/24.
//

#ifndef MENU_H
#define MENU_H

#include <string>
#include <iostream>
#include <map>

#include "Course.h"
#include "Starter.h"
#include "MainCourse.h"
#include "Dessert.h"

class Menu {
    std::map<std::string,Course*> courses;

public:
    Menu();
    bool addCourse(Course* course);
    bool addMenuItem(std::string courseDescription, std::string description, float price, int stock);
    void printMenu() const;
    void inventory();
    float orderItem(std::string courseDescription, char item);
    bool isCoursesEmpty();
    void closeShop();
    ~Menu();
};



#endif //MENU_H
