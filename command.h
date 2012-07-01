#ifndef COMMAND_H
#define COMMAND_H

#include <string>

namespace command
{
  using namespace std;

  extern void save();
  extern void look(const string line);
  extern bool location(const string line);
};

#endif // COMMAND_H