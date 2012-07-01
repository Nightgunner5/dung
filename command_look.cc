#include "helper.h"
#include "command.h"

namespace command
{
  using namespace std;

  void look(const string line)
  {
    cout << "You look at the \"" << line.substr(5) << "\"" << endl;
  }
};