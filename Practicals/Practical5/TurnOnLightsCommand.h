#ifndef TURNONLIGHTSCOMMAND_H
#define TURNONLIGHTSCOMMAND_H
#include "Command.h"
#include <iostream>
#include <memory>
class TurnOnLightsCommand : public Command {
  std::shared_ptr<SmartRoom> room;

public:
  TurnOnLightsCommand(std::shared_ptr<SmartRoom> room);
  ~TurnOnLightsCommand() override = default;
  void execute(double parameter = 0) override;
};
#endif // TURNONLIGHTSCOMMAND_H
