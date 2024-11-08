#include "Square.h"

float Square::accept(Visitor& v) {
    return v.visit(*this);
}
