//
// Created by hayley on 2024/07/27.
//

#ifndef CALCULATOR_H
#define CALCULATOR_H


template<typename T>
class Calculator {
    T num1;
    T num2;
public:
    Calculator(T n1, T n2) : num1(n1), num2(n2){}
    T add() {
        return num1 + num2;
    }
    T subtract() {
        return num1-num2;
    }
    T multiply() {
        return num1*num2;
    }
    T divide() {
        return num1/num2;
    }
};



#endif //CALCULATOR_H
