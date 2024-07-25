//
// Created by hayley on 2024/07/24.
//

#include "MainCourse.h"

MainCourse::MainCourse(int maxNumberOfItems) : Course("Main", maxNumberOfItems){

}

void MainCourse::recommendBeverage() {
    std::cout << "Coke" << std::endl;
}
