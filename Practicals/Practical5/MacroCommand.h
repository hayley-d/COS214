#ifndef MACROCOMMAND_H
#define MACROCOMMAND_H
#include <iostream>
#include <list>
#include <memory>
#include "Command.h"
class MacroCommand : public Command {
  std::list<std::shared_ptr<Command>> commands;

public:
  MacroCommand();
  ~MacroCommand() override = default;
  void execute(double parameter = 0) override;
  bool addProcedure(std::shared_ptr<Command> command);
  bool removeProcedure(int macroStep);
};
#endif // MACROCOMMAND_H
