#include <stdexcept>
#include "helper.h"
#include "command.h"
#include "storyline.h"
#include "dungtext.h"

namespace command
{
  using namespace std;
  using namespace dungtext;

  bool location(const string line)
  {
    try
    {
      Location* loc = storyline()->command_location.at(line);
      print(storyline(loc)->look);
      return true;
    }
    catch (const out_of_range ex)
    {
      return false;
    }
  }
}