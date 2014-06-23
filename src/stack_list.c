#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "stack_list.h"

void init_stack(stack *s)
{
        s->top = NULL;
}

int stack_full(stack *s)
{
        return 0;
}

int stack_empty(stack *s)
{
        return s->top == NULL;
}

void push_stack(stack *s, char data)
{
        listnode *current = malloc(sizeof(listnode));
        assert(current != NULL);
        current->data = data;
        current->next = s->top;
        s->top = current;
}

char pop_stack(stack *s)
{
        listnode *current;
        char c;

        if (stack_empty(s)) {
                printf("stack is empty\n");
                return -1;
        }

        current = s->top;
        s->top = s->top->next;
        c = current->data;
        free(current);

        return c;
}
