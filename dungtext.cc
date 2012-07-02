#include "helper.h"
#include "dungtext.h"
#include <random>
#include <sstream>

namespace dungtext
{
using namespace std;
using namespace ansi;

inline void _format(const string in, stringstream& output)
{
    output << set_attribute(RESET) << set_foreground_color(YELLOW);

    size_t start = 0;
    bool bolded = false;
    while (start < in.length())
    {
        size_t nextControl = in.find('%', start);
        if (nextControl == string::npos)
            break;

        output << in.substr(start, nextControl - start);

        start = nextControl + 1;

        if (bolded)
        {
            output << set_attribute(RESET) << set_foreground_color(YELLOW);
            bolded = false;
        }
        else
        {
            output << set_attribute(RESET) << set_attribute(BRIGHT) << set_foreground_color(GREEN);
            bolded = true;
        }
    }

    if (start < in.length())
        output << in.substr(start);
}

void format(const string in, string& out)
{
    stringstream output;
    _format(in, output);
    output.str(out);
}

string format(const string in)
{
    stringstream output;
    _format(in, output);
    return output.str();
}

#define WORD_WRAP_SIZE 45
inline size_t find_next_wrap(const string text)
{
  size_t real_length = 0, visible_length = 0, last_space = text.length();
  bool escape = false;
  while (visible_length < WORD_WRAP_SIZE && real_length < text.length())
  {
    if (text.at(real_length) == ' ')
      last_space = real_length;

    if (text.at(real_length) == '\x1B')
    {
      escape = true;
      real_length++;
      continue;
    }

    if (escape)
    {
      if (isalpha(text.at(real_length)))
	escape = false;
    }
    else
    {
      visible_length++;
    }

    real_length++;
  }

  if (real_length == text.length())
    return -1;

  return last_space;
}

void print(const string in)
{
    string out = format(in);

    while (out.length() > WORD_WRAP_SIZE)
    {
        string next = out.substr(0, find_next_wrap(out));

        cout << next;
        NEXT_LINE;
        out = out.substr(next.length());
	if (!out.empty())
	  out = out.substr(1);
    }

    cout << out;
    NEXT_LINE;
}

void unknown_command()
{
#define NUM_UNKNOWN_COMMAND 4
    static string msg[NUM_UNKNOWN_COMMAND] = {
        "I'm sorry, I didn't quite catch that. What did you say?",
        "WAHT?", // sic
        "Huh?",
        "What exactly are you talking about?"
    };

    print(msg[random() % NUM_UNKNOWN_COMMAND]);
}
};
