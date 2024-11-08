#include "Visitor.h"

float Visitor::visit(Square& s) {
    return s.side * 4;
}

float Visitor::visit(Circle& c) {
    return c.radius * c.radius * c.PI;
}

