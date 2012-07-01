#include "helper.h"
#include "command.h"
#include "dungtext.h"

#include <random>
#include <ctime>

using namespace std;

void intro()
{
#define NUM_LOGO_LINES 20
  const string logo[NUM_LOGO_LINES] = {
    "|#######    #     #  ##    #    ######  |",
    "|#      #   #     #  # #   #   #      # |",
    "|#       #  #     #  # #   #  #        #|",
    "|#       #  #     #  #  #  #  #         |",
    "|#       #  #     #  #  #  #  #     ####|",
    "|#       #  #     #  #   # #  #     #  #|",
    "|#      #    #   #   #   # #   #      # |",
    "|#######      ###    #    ##    ######  |",
    "|                                       |",
    "|            #            Revision 82   |",
    "|                 #        July 1978    |",
    "|                                       |",
    "|         #           # #               |",
    "|       #                               |",
    "|                 ####     #            |",
    "|              ##########               |",
    "|         ######################        |",
    "|      ############################     |",
    "|   #################################   |",
    "+~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~+"
  };

  SET_ATTR(RESET);
  SET_FG(YELLOW);
  for (int i = 0; i < NUM_LOGO_LINES; i++)
  {
    cout << logo[i];
    NEXT_LINE;
  }
}

int main(int argc, char **argv) {
  srandom(time(NULL));

  intro();

  while (true)
  {
    SET_ATTR(RESET);
    SET_FG(WHITE);
    cout << "> ";

    SET_ATTR(BRIGHT);
    SET_FG(GREEN);
    string line;
    getline(cin, line);

    line = normalize(line);

    PAUSE;

    if (line == "")
    {
      // Short-circuit for empty input
      continue;
    }

    if (line == "QUIT")
    {
      command::save();
      return 0;
    }

    if (line == "SAVE" || line == "SAVE PROGRESS")
    {
      command::save();
      continue;
    }

    string firstWord = line.find(' ') == string::npos ? line : line.substr(0, line.find(' '));
    if (firstWord == "LOOK")
    {
      command::look(line);
      continue;
    }

    // No handler was found, so print out an error.
    SET_ATTR(RESET);
    SET_FG(YELLOW);
    cout << dungtext::unknown_command();
    NEXT_LINE;
  }
}
