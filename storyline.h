#ifndef STORYLINE_H
#define STORYLINE_H

#include <string>
#include <map>

class Location
{
public:
  inline Location(std::string look_output,
		  std::initializer_list<std::pair<const std::string, std::string>> look_object_output,
		  std::initializer_list<std::pair<const std::string, Location*>> location_commands) :
  look(look_output), look_object(look_object_output), command_location(location_commands)
  {}

  std::string look;
  std::map<std::string, std::string> look_object;
  std::map<std::string, Location*> command_location;
};

inline Location* storyline(Location* set = NULL)
{
  static Location* story = NULL;

  if (set != NULL)
    story = set;

  return story;
}

#define SET_STORYLINE(name) storyline(&storyline_##name::start);

#endif // STORYLINE_H