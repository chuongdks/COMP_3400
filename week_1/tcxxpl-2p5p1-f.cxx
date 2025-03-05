#include "tcxxpl-2p5p1.hxx"

struct Bad_pop { };

void f()
{
  Stack::stack s1 = Stack::create(); // make a new stack
  Stack::stack s2 = Stack::create(); // make another new stack

  Stack::push(s1, 'c');
  Stack::push(s2, 'k');

  if (Stack::pop(s1) != 'c') throw Bad_pop();
  if (Stack::pop(s2) != 'k') throw Bad_pop();

  Stack::destroy(s1);
  Stack::destroy(s2);
}
