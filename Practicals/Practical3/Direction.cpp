#include "Direction.h"

std::ostream& operator<<(std::ostream& os, Direction direction) {
    switch (direction) {
        case Direction::North:
            os << "to the North";
        break;
        case Direction::South:
            os << "to the South";
        break;
        case Direction::East:
            os << "to the East";
        break;
        case Direction::West:
            os << "to the West";
        break;
        default:
            os << "";
        break;
    }
    return os;
}
