#ifndef COMMAND_H
#define COMMAND_H
#include "SmartRoom.h"

class Command {
public:
  virtual void execute(double parameter = 0) = 0;
  virtual ~Command() = default;
};
#endif // COMMAND_H
