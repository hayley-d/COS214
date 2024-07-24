//
// Created by hayley on 2024/07/24.
//

#ifndef MENUITEM_H
#define MENUITEM_H

#include <string>




class MenuItem {
    std::string description;
    float price;
    int stock;

public:
    MenuItem(std::string description, float price, int stock);
    std::string getDescription();
    float getPrice();
    int getStock();
    void reduceStock();
};



#endif //MENUITEM_H
