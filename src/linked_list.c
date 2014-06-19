#include <stdio.h>
#include <stdlib.h>


typedef struct ns
{
        int data;
        struct ns *next;
} Node;


Node *create_node(int data);
void insert_node(Node *n1, Node *n2);
void remove_node(Node *n);
void print_lists(Node *n);
void free_lists(Node *n);


Node *create_node(int data)
{
        Node *n = malloc(sizeof(Node));
        n->data = data;
        n->next = NULL;

        return n;
}


// Insert n2 after n1
void insert_node(Node *n1, Node *n2)
{
        n2->next = n1->next;
        n1->next = n2;
}


// Remove the next node of n
void remove_node(Node *n)
{
        n->next = n->next->next;
}


// Print the node data of a lists
void print_lists(Node *lists)
{
        Node *n = lists;
        while (n != NULL) {
                printf("%d", n->data);
                n = n->next;
        }
        printf("\n");
}


// Remove all nodes of a lists
void free_lists(Node *lists)
{
        if (lists->next != NULL) {
                free_lists(lists->next);
        }

        free(lists);
}


int main(int argc, char *argv[])
{
        Node *lists = create_node(0);
        Node *a = create_node(1);
        Node *b = create_node(2);
        Node *c = create_node(3);
        Node *d = create_node(4);
        Node *e = create_node(5);

        // 0 -> 5
        insert_node(lists, e);

        // 0 -> 1 -> 5
        insert_node(lists, a);

        // 1 -> 2 -> 5
        insert_node(a, b);

        // 1 -> 3 -> 2
        insert_node(a, c);

        // 5 -> 4
        insert_node(e, d);

        print_lists(lists);
        free_lists(lists);

        return 0;
}
