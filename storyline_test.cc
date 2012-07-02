#include "storyline_test.h"

namespace storyline_test
{
Location start(
    "You are in a room. There is nothing in the room. Except you. Obvious exits are: %DOOR%.",
    {
      {"LOOK DOOR", "The %DOOR% seems to be made of a solid material. You could %OPEN% it if you used your %HANDS%."},
      {"LOOK HANDS", "Yep, those are your %HANDS%."},
      {"OPEN HANDS", "You decide not to try %OPEN%ING your %HANDS% as that would probably be painful."}
    },
    {
      {"GO DOOR", &outdoor},
      {"OPEN DOOR", &outdoor},
      {"GO THROUGH DOOR", &outdoor}
    }
);

Location outdoor(
  "As you slowly open the %DOOR%, nothing interesting happens. Then, you go through the %DOOR% and close it behind you. A rabbit hops by and you hear the beautiful sound of tractors. Obvious exits are: %NORTH%, %WEST%, %JUMP UP AND DOWN%",
  {
    {"LOOK NORTH", "To be honest, you have no idea which way %NORTH% is. You look straight ahead and see two %COWS% making love. You quickly avert your eyes."},
    {"LOOK COWS", "No way I'm looking at that again. That's gross, man!"},
    {"LOOK WEST", "To your left is a small %POND%. Is that what you meant by %WEST%?"},
    {"LOOK POND", "The %POND%? It's small. And wet."},
    {"LOOK DOOR", "You're sure the door is still behind you, so you don't even bother looking at it."},
    {"LOOK EAST", "What do you think I am, a compass?"},
    {"LOOK UP", "What's up? Oh wait, that's just the sky."},
    {"LOOK DOWN", "The ground. That's the ground."},
    {"JUMP UP AND DOWN", "You %JUMP UP AND DOWN% a few times. You feel silly, so you stop."}
  },
  {
    {"GO WEST", &pond},
    {"GO POND", &pond},
    {"GO LEFT", &pond}
  }
);

Location pond(
  "As you approach the %POND%, it is revealed to be made of either chocolate ice cream or cow pies. Either way, it's dessert! Obvious exits are: %BACK%, %JUMP IN POND%",
  {
    {"SMELL POND", "Definitely cow pies, unless ice cream has a \"chocolate-covered manure\" flavor."},
    {"JUMP IN POND", "Y'know, on second thought, let's not do that. You wouldn't want to ruin your clothes."},
    {"TAKE OFF CLOTHES", "NO."}
  },
  {
    {"GO BACK", &outdoor},
    {"GO EAST", &outdoor}
  }
);
};