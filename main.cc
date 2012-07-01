#include <iostream>
#include "helper.h"

using namespace std;

void saveProgress()
{
  TODO("saveProgress()");
}

int main(int argc, char **argv) {
  while (true)
  {
    SET_ATTR(RESET);
    SET_FG(WHITE);
    cout << "> ";

    string line;
    SET_ATTR(BRIGHT);
    SET_FG(GREEN);
    cin >> line;

    line = normalize(line);

    if (line == "QUIT")
    {
      saveProgress();
      return 0;
    }
  }
}
