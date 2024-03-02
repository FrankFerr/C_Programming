#ifndef STACK_ADT_H
#define STACK_ADT_H
#include <stdbool.h>

typedef struct stack_type *Stack;

Stack stack_create(void);
void stack_destroy(Stack s);
void stack_make_empty(Stack s);
void stack_push(Stack s, void *obj);
void *stack_pop(Stack s);
bool stack_is_empty(Stack s);
bool stack_is_full(Stack s);
int stack_length(Stack s);

#endif