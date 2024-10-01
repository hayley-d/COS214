#ifndef UNLOCKDOORSCOMMAND_H
#define UNLOCKDOORSCOMMAND_H

#include "Command.h"
#include <iostream>
#include <memory>
class UnlockDoorsCommand : public Command {
  std::shared_ptr<SmartRoom> room;

public:
  UnlockDoorsCommand(std::shared_ptr<SmartRoom> room);
  ~UnlockDoorsCommand() override = default;
  void execute(double parameter = 0) override;
};
#endif // UNLOCKDOORSCOMMAND_H
