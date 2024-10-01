#include "TurnOnLightsCommand.h"

TurnOnLightsCommand::TurnOnLightsCommand(std::shared_ptr<SmartRoom> room) {
  this->room = room;
}

void TurnOnLightsCommand::execute(double parameter) {
  this->room->turnOnLights();
  std::cout << "Command turned on room lights" << std::endl;
}
