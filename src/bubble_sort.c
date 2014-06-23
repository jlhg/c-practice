#include <stdio.h>

void bubble_sort(int data[], int len);
void swap(int *x, int *y);

void bubble_sort(int data[], int len)
{
        int i, j;
        for (i = len - 1; i > 1; --i) {
                for (j = 0; j < i; ++j) {
                        if (data[j] > data[j + 1]) {
                                swap(&data[j], &data[j + 1]);
                        }
                }
        }
}

void swap(int *x, int *y)
{
        int temp;

        temp = *x;
        *x = *y;
        *y = temp;
}

int main(void)
{
        int data[] = {1, 43, 6, 79, 50, 2};
        int len = 6;
        bubble_sort(data, len);

        int i;
        for (i = 0; i < len; ++i) {
                printf("%d ", data[i]);
        }
        printf("\n");

        return 0;
}
