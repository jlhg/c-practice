#include <stdio.h>


void quick_sort(int *data, int left, int right);
void swap(int *x, int *y);


void quick_sort(int *data, int left, int right)
{
        if (left >= right)
                return;

        int pivot = data[left];
        int i = left + 1;
        int j = right;

        while (1) {
                while (i <= right) {
                        if (data[i] > pivot) {
                                break;
                        }
                        i += 1;
                }

                while (j > left) {
                        if (data[j] < pivot) {
                                break;
                        }
                        j -= 1;
                }

                if (i > j) {
                        break;
                }

                swap(&data[i], &data[j]);
        }

        swap(&data[left], &data[j]);
        quick_sort(data, left, j - 1);
        quick_sort(data, j + 1, right);
}


void swap(int *x, int *y) {
        int temp = *x;
        *x = *y;
        *y = temp;
}


int main()
{

        int data[] = {26, 13, 73, 31, 38};
        int len = 5;
        quick_sort(data, 0, len - 1);

        int i;
        for (i = 0; i < len; ++i)
                printf("%d ", data[i]);

        printf("\n");

        return 0;
}
