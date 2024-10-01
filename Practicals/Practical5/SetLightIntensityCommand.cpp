#include "SetLightIntensityCommand.h"

SetLightIntensityCommand::SetLightIntensityCommand(
    std::shared_ptr<SmartRoom> room) {
  this->room = room;
}

void SetLightIntensityCommand::execute(double parameter) {
  int param = (int)parameter;
  this->room->setRoomLightIntensity(param);
}
