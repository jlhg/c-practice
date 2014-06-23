#include <stdio.h>
#include <stdlib.h>
#include <assert.h>


typedef struct listnode {
        int data;
        struct listnode *next;
} ListNode;


void print_linked_list(ListNode *head);
ListNode *insert_linked_list(ListNode *head, int data);


void print_linked_list(ListNode *head)
{
        ListNode *ptr;
        for (ptr = head; ptr != NULL; ptr = ptr->next) {
                printf("data = %d\n", ptr->data);
        }

}


ListNode *insert_linked_list(ListNode *head, int data)
{
        ListNode *current = malloc(sizeof(ListNode));
        assert(current != NULL);
        ListNode *ptr;
        ListNode *last;

        /*
          如果 head 為 NULL 代表鏈結序列是空的。回傳剛才要到的新節點
          current 即可。
         */
        current->data = data;
        if (head == NULL) {
                current->next = NULL;
                return current;
        }


        /*
          尋找第一個不小於要加入資料的節點。用變數 last 保留上一個節點。
         */
        last = NULL;
        ptr = head;
        while (ptr != NULL && ptr->data < data) {
                last = ptr;
                ptr = ptr->next;
        }

        /*
          如果 while 迴圈結束後 last 為 NULL，代表要加入的資料是最小的，
          要加在鏈結序列的開始。與第一個狀況類似，將剛才要到的新節點 current 的
          next 連到序列的頭，再回傳 current 即可。
         */
        if (last == NULL) {
                current->next = head;
                return current;
        } else {
                /*
                  如果 while 迴圈結束後 last 不為 NULL，則將剛才要到的新節點
                  current 加到 last 後面即可。
                 */
                current->next = last->next;
                last->next = current;
                return head;
        }
}


int main()
{
        int i;
        int array_size = 5;
        int array[] = {4, 6, 2, 9, 7};
        ListNode *head = NULL;

        for (i = 0; i < array_size; ++i)
                head = insert_linked_list(head, array[i]);

        print_linked_list(head);

        return 0;
}
