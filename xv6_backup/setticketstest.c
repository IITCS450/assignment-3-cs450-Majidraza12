#include "types.h"
#include "stat.h"
#include "user.h"

int
main(int argc, char *argv[])
{
  int r;

  printf(1, "Testing settickets syscall...\n");

  r = settickets(10);
  if(r == 0)
    printf(1, "Success: tickets set to 10\n");
  else
    printf(1, "Error: failed to set tickets\n");

  r = settickets(0);
  if(r == -1)
    printf(1, "Correct: rejected invalid value\n");
  else
    printf(1, "BUG: accepted invalid value!\n");

  exit();
}