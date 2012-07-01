#include "storyline.h"
#include "storyline_defs.h"

BEGIN_STORYLINE(test)

DECLARE_LOCATION(button)

Location start(
    "You are in a room. Before you is a %BUTTON%. There are no obvious exits.",
    {
      {"BUTTON", "The %BUTTON% is bright red with the words \"do not %PUSH%\" on it."}
    },
    {
      {"PUSH BUTTON", &button}
    }
);

Location button(
  "The room has exploded. You are dead.", {}, {}
);

END_STORYLINE