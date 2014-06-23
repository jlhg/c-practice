#ifndef STACK_H
#define STACK_H

typedef struct {
        int top;
        char elements[100];
} stack;

void init_stack(stack *s);
int stack_full(stack *s);
int stack_empty(stack *s);
void push_stack(stack *s, char c);
char pop_stack(stack *s);

#endif /* STACK_H */
