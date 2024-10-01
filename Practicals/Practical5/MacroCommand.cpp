#include "MacroCommand.h"
#include <iostream>
#include <iterator>
MacroCommand::MacroCommand() {}

void MacroCommand::execute(double parameter) {
  // list<std::shared_ptr<Command>>::iterator it;
  for (auto it = commands.begin(); it != commands.end(); ++it) {
    (*it)->execute(parameter);
  }
  std::cout << "Executed macro with " << commands.size() << " procedures"
            << std::endl;
}

bool MacroCommand::addProcedure(std::shared_ptr<Command> command) {
  commands.push_back(command);
  std::cout << "Added a procedure" << std::endl;
  return true;
}

bool MacroCommand::removeProcedure(int macroStep) {
  auto it = commands.begin();
  std::advance(it, macroStep);
  commands.erase(it);
  return true;
}
