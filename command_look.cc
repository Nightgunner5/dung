#include <stdexcept>
#include "helper.h"
#include "command.h"
#include "storyline.h"
#include "dungtext.h"

namespace command
{
  using namespace std;
  using namespace dungtext;

  void look(const string line)
  {
    if (line == "LOOK")
    {
      print(storyline()->look);
      return;
    }
    try
    {
      print(storyline()->command_action.at(line));
    }
    catch (const out_of_range ex)
    {
      print("You don't see any \"%" + line.substr(5) + "%\".");
    }
  }
};