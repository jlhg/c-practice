#include <stdio.h>
#include <stdlib.h>
#include <assert.h>


typedef struct listnode {
        int data;
        struct listnode *next;
} ListNode;

void print_linked_list(ListNode *head);


void print_linked_list(ListNode *head)
{
        ListNode *ptr;
        for (ptr = head; ptr != NULL; ptr = ptr->next)
                printf("data = %d\n", ptr->data);

}


int main()
{
        int i;
        int array_size = 5;
        int array[] = {4, 6, 2, 9, 7};
        ListNode *head;
        ListNode *previous = NULL;

        for (i = 0; i < array_size; ++i) {
                head = malloc(sizeof(ListNode));
                assert(head != NULL);
                head->data = array[i];
                head->next = previous;
                previous = head;
        }

        print_linked_list(head);

        return 0;
}
