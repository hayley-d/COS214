#ifndef KITCHEN_H
#define KITCHEN_H
#include <string>
#include <vector>

class Kitchen {
    std::vector<std::string> orders;
public:
    void addOrder(std::string& order);
};

#endif //KITCHEN_H
