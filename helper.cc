#include "helper.h"
#include <string>
#include <sstream>

using namespace std;

namespace ansi
{
const string set_attribute(Attribute attribute)
{
    stringstream out;
    out << ESC << "[" << (char) (attribute + '0') << "m";
    return out.str();
}

const string set_foreground_color(Color color)
{
    stringstream out;
    out << ESC << "[3" << (char) (color + '0') << "m";
    return out.str();

}

const string set_background_color(Color color)
{
    stringstream out;
    out << ESC << "[4" << (char) (color + '0') << "m";
    return out.str();
}
};

string normalize(const string in)
{
  int len = in.length();
  const char* input = in.c_str();
  stringstream out;

  bool first = true;
  bool space = false;
  for (int i = 0; i < len; i++)
  {
    // Compress multiple spaces down to one
    if (isspace(input[i]))
    {
      space = !first;
      continue;
    }
    else if (space)
    {
      space = false;
      out << ' ';
    }

    first = false;
    out << (char) toupper(input[i]);
  }

  return out.str();
}