#include "SetTemperatureCommand.h"
SetTemperatureCommand::SetTemperatureCommand(std::shared_ptr<SmartRoom> room) {
  this->room = room;
}

void SetTemperatureCommand::execute(double parameter) {
  this->room->setRoomTemperature(parameter);
}
