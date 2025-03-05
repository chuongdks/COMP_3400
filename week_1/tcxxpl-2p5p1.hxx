#ifndef code_tcxxpl_2p5p1_hxx_
#define code_tcxxpl_2p5p1_hxx_

namespace Stack {
  struct Rep;
  typedef Rep& stack; // definition of stack layout is elsewhere
  stack create();     // make a new stack
  void destroy(stack s);  // delete s
  void push(stack s, char c); // push c onto s
  char pop(stack s);  // pop s
} // namespace Stack

#endif // #ifndef code_tcxxpl_2p5p1_hxx_
