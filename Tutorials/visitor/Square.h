#ifndef SQUARE_H
#define SQUARE_H
#include "Visitor.h"

class Square {
public:
    float side;
    Square(float side) : side(side) {}
    ~Square() = default;
    float accept(Visitor& v);
};

#endif //SQUARE_H
