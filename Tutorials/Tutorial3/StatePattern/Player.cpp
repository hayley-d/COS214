#include "Player.h"

Player(){
    this->state = new IdelState();
}
~Player(){
    delete state;
}
void setState(State& state){
    delete this->state;
    this->state = state;
}
void update(){
    state->update(this);
}
void setHealth(int hp){
    health = hp;
    if(health <= 0){
        setState(new DeadState());
    }
}
int getHealth(){
    return health;
}
void performAction(const std::string& action){
    std::cout << "Player is " << action << ".\n" << std::endl;
}