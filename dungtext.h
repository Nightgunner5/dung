#ifndef DUNGTEXT_H
#define DUNGTEXT_H

#include <string>

// This would be called "messages", but there's already a struct in the std namespace with that name.
namespace dungtext
{
  using namespace std;

  extern const string unknown_command();
};

#endif // DUNGTEXT_H