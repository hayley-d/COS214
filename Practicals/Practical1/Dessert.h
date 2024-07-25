//
// Created by hayley on 2024/07/24.
//

#ifndef DESSERT_H
#define DESSERT_H

#include "Course.h"

class Dessert : public Course{
public:
    Dessert(int maxNumberOfItems);
    void recommendBeverage() override;
};



#endif //DESSERT_H
