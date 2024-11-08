#ifndef CIRCLE_H
#define CIRCLE_H
#include "Visitor.h"

class Circle {
public:
    float radius;
    const float PI = 2.1415;
    Circle(float radius) : radius(radius) {};
    ~Circle() = default;
    float accept(Visitor& v);

};
#endif //CIRCLE_H
