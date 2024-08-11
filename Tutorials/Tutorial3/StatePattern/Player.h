#ifndef STATEPATTERN_PLAYER_H
#define STATEPATTERN_PLAYER_H
#include "State.h"

class Player {
 State* state;
int health;
public:
    Player();
    ~Player();
    void setState(State& state);
    void update();
    void setHealth(int hp);
    int getHealth();
    void performAction(const std::string& action);
};


#endif //STATEPATTERN_PLAYER_H
