#include <stdio.h>


void selection_sort(int *data, int len);
void swap(int *data, int x, int y);


void selection_sort(int *data, int len)
{
        int i, j, min;
        for (i = 0; i < len; ++i) {
                min = i;
                for (j = i + 1; j < len; ++j) {
                        if (data[j] < data[min]) {
                                min = j;
                        }
                }
                swap(data, i, min);
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
        int data[] = {19, 58, 33, 41, 28, 14, 53, 84};
        int len = 8;
        selection_sort(data, len);

        int i;
        for (i = 0; i < len; ++i) {
                printf("%d ", data[i]);
        }
        printf("\n");

        return 0;
}
