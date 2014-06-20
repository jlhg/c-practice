#include <stdio.h>


void bubble_sort(int *data, int len);
void swap(int *data, int x, int y);


void bubble_sort(int *data, int len)
{
        int i, j;
        for (i = len - 1; i > 1; --i) {
                for (j = 0; j < i; ++j) {
                        if (data[j] > data[j + 1]) {
                                swap(data, j, j + 1);
                        }
                }
        }
}


void swap(int *data, int x, int y)
{
        int temp;

        temp = data[x];
        data[x] = data[y];
        data[y] = temp;
}


int main(int argc, char *argv[])
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