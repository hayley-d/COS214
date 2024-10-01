#ifndef SETLIGHTINTENSITYCOMMAND_H
#define SETLIGHTINTENSITYCOMMAND_H
#include "Command.h"
#include <iostream>
#include <memory>
class SetLightIntensityCommand : public Command {
  std::shared_ptr<SmartRoom> room;

public:
  SetLightIntensityCommand(std::shared_ptr<SmartRoom> room);
  ~SetLightIntensityCommand() override = default;
  void execute(double parameter = 0) override;
};

#endif // SETLIGHTINTENSITYCOMMAND_H
