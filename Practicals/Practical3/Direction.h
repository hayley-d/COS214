#ifndef DIRECTION_H
#define DIRECTION_H
#include <ostream>
enum class Direction {
    North,
    East,
    South,
    West
};
std::ostream& operator<<(std::ostream& os, Direction direction);

#endif //DIRECTION_H
