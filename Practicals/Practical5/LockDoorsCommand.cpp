#include "LockDoorsCommand.h"
LockDoorsCommand::LockDoorsCommand(std::shared_ptr<SmartRoom> room) {
  this->room = room;
}

void LockDoorsCommand::execute(double parameter) {
  this->room->lockRoomDoors();
}
