#ifndef HELPER_H
#define HELPER_H

#include <string>
#include <iostream>

namespace ansi
{
using namespace std;

enum Attribute
{
    RESET = 0,
    BRIGHT,
    DIM,
    UNDERLINE,
    BLINK,
    REVERSE,
    HIDDEN
};

enum Color
{
    BLACK = 0,
    RED,
    GREEN,
    YELLOW,
    BLUE,
    MAGENTA,
    CYAN,
    WHITE
};

const static string ESC = "\x1B";

extern const string set_attribute(Attribute attribute);
#define SET_ATTR(attribute) std::cout << ansi::set_attribute(ansi:: attribute );

extern const string set_foreground_color(Color color);
#define SET_FG(color) std::cout << ansi::set_foreground_color(ansi:: color );

extern const string set_background_color(Color color);
#define SET_BG(color) std::cout << ansi::set_background_color(ansi:: color );
};

// Remove extra whitespace, remove symbols, convert to all caps.
extern std::string normalize(const std::string in);

#ifdef NDEBUG
#define TODO(text) ;
#else // NDEBUG
#define TODO(text) SET_ATTR(RESET); SET_ATTR(BRIGHT); SET_FG(RED); std::cout << "TODO: " << text << std::endl; SET_ATTR(RESET);
#endif // NDEBUG

#define PAUSE usleep(100000);
#define NEXT_LINE std::cout << std::endl; PAUSE

#endif // HELPER_H
