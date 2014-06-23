#include <stdio.h>
#include <string.h>
#include "stack_list.h"

int main(void)
{
        char string[] = "racecar";
        stack stack;
        int i;
        int half;
        int length;

        length = strlen(string);
        half = length / 2;
        init_stack(&stack);

        for (i = 0; i < half; ++i)
                push_stack(&stack, string[i]);

        for (i = length - half; i < length; ++i) {
                if (string[i] != pop_stack(&stack)) {
                        printf("not a palindrome\n");
                        return 0;
                }
        }
        printf("palindrome\n");

        return 0;
}
