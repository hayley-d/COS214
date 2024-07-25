//
// Created by hayley on 2024/07/24.
//

#ifndef MAINCOURSE_H
#define MAINCOURSE_H

#include "Course.h"

class MainCourse : Course {
public:
    MainCourse(int maxNumberOfItems);
    void recommendBeverage() override;
};



#endif //MAINCOURSE_H
