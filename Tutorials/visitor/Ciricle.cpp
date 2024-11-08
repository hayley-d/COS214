#include "Circle.h"

float Circle::accept(Visitor& v) {
    return v.visit(*this);
}
