#include "UnlockDoorsCommand.h"
UnlockDoorsCommand::UnlockDoorsCommand(std::shared_ptr<SmartRoom> room) {
  this->room = room;
}

void UnlockDoorsCommand::execute(double parameter) {
  this->room->unlockRoomDoors();
}
