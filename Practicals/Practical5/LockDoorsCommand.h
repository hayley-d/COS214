#ifndef LOCKDOORSCOMMAND_H
#define LOCKDOORSCOMMAND_H
#include "Command.h"
#include <iostream>
#include <memory>
class LockDoorsCommand : public Command {
  std::shared_ptr<SmartRoom> room;

public:
  LockDoorsCommand(std::shared_ptr<SmartRoom> room);
  ~LockDoorsCommand() override = default;
  void execute(double parameter = 0) override;
};
#endif // LOCKDOORSCOMMAND_H
