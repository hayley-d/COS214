//
// Created by hayley on 2024/07/24.
//

#ifndef STARTER_H
#define STARTER_H

#include "Course.h"

class Starter : public Course {
public:
    Starter(int maxNumberOfItems);
    void recommendBeverage() override;
};



#endif //STARTER_H
