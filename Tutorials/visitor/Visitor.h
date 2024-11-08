#ifndef VISITOR_H
#define VISITOR_H
#include "Circle.h"
#include "Square.h"

class Visitor {
public:
    Visitor() = default;
    ~Visitor() = default;
    float visit(Square& s);
    float visit(Circle& c);
};
#endif //VISITOR_H
