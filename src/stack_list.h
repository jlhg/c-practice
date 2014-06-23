#ifndef STACK_LIST_H
#define STACK_LIST_H

typedef struct _listnode {
        char data;
        struct _listnode *next;
} listnode;

typedef struct {
        listnode *top;
} stack;

void init_stack(stack *s);
int stack_full(stack *s);
int stack_empty(stack *s);
void push_stack(stack *s, char data);
char pop_stack(stack *s);

#endif /* STACK_LIST_H */
