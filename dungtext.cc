#include "dungtext.h"
#include <random>

namespace dungtext
{
using namespace std;

const string unknown_command()
{
#define NUM_UNKNOWN_COMMAND 4
  static string msg[NUM_UNKNOWN_COMMAND] = {
    "I'm sorry, I didn't quite catch that. What did you say?",
    "WAHT?", // sic
    "Huh?",
    "What exactly are you talking about?"
  };

  return msg[random() % NUM_UNKNOWN_COMMAND];
}
};
