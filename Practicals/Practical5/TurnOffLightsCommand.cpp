#include "TurnOffLightsCommand.h"
#include <iostream>

TurnOffLightsCommand::TurnOffLightsCommand(std::shared_ptr<SmartRoom> room) {
  this->room = room;
}

void TurnOffLightsCommand::execute(double parameter) {
  room->turnOffLights();
  std::cout << "Command turned off room lights" << std::endl;
}
