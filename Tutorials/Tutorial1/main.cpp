#include <iostream>

#include "A.h"
#include "C.h"
#include "Calculator.h"
#include "D.h"

int main() {
    std::cout << "Hello, World!" << std::endl;

    Calculator<int> doubleCalc(741,13);
    std::cout << doubleCalc.divide() << std::endl;

    Calculator<double> calc(127.58,54.971);
    std::cout << calc.add() << std::endl;

    Calculator<std::string> stringCalc("Hello","World");
    std::cout << stringCalc.add() << std::endl;




    return 0;
}
