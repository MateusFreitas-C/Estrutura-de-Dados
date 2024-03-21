#ifndef STACK_H
#define STACK_H

typedef struct stack Stack;

Stack* create_stack();

void print_stack(Stack* s);

void free_stack(Stack** s);

bool push(Stack* s, int value);

bool pop(Stack* s);

bool is_empty(Stack* s);

int size(Stack* s);

#endif