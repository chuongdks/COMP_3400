#ifndef code_tcxxpl_2p5p1_c_hxx_
#define code_tcxxpl_2p5p1_c_hxx_

struct Stack_Rep;
typedef Stack_Rep* stack; // def'n of stack layout is elsewhere

extern stack Stack_create();     // make a new stack
extern void Stack_destroy(stack s);  // delete s
extern void Stack_push(stack s, char c); // push c onto s
extern char Stack_pop(stack s);  // pop s

#endif // #ifndef code_tcxxpl_2p5p1_c_hxx_
