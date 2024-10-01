#ifndef SETTEMPERATURECOMMAND_H
#define SETTEMPERATURECOMMAND_H
#include "Command.h"
#include <iostream>
#include <memory>
class SetTemperatureCommand : public Command {
  std::shared_ptr<SmartRoom> room;

public:
  SetTemperatureCommand(std::shared_ptr<SmartRoom> room);
  ~SetTemperatureCommand() override = default;
  void execute(double parameter = 0) override;
};
#endif // SETTEMPERATURECOMMAND_H
