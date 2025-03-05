#include "tcxxpl-2p5p1-c.hxx"

extern void handle_error();

void f()
{
  stack s1 = Stack_create(); // make a new stack
  stack s2 = Stack_create(); // make another new stack

  Stack_push(s1, 'c');
  Stack_push(s2, 'k');

  if (Stack_pop(s1) != 'c') handle_error();
  if (Stack_pop(s2) != 'k') handle_error();

  Stack_destroy(s1);
  Stack_destroy(s2);
}
