#define DECLARE_LOCATION(name) extern Location name;

#define BEGIN_STORYLINE(name) namespace storyline_##name { DECLARE_LOCATION(start)
#define END_STORYLINE };