#ifndef TURNOFFLIGHTSCOMMAND_H
#define TURNOFFLIGHTSCOMMAND_H
#include "Command.h"
#include <memory>
class TurnOffLightsCommand : public Command {
  std::shared_ptr<SmartRoom> room;

public:
  void execute(double parameter = 0) override;
  TurnOffLightsCommand(std::shared_ptr<SmartRoom> room);
  ~TurnOffLightsCommand() = default;
};
#endif // TURNOFFLIGHTSCOMMAND_H
