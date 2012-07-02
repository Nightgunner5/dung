#include <stdexcept>

#include "command.h"
#include "dungtext.h"
#include "storyline.h"

namespace command
{
  using namespace dungtext;

  bool generic(const string line)
  {
    try
    {
      print(storyline()->command_action.at(line));
      return true;
    }
    catch (const out_of_range ex)
    {
      return false;
    }
  }
}