#include <stdio.h>


void merge_sort(int data[], int len);
void merge(int data[], int *left, int *right, int x, int y);


void merge_sort(int data[], int len)
{
        if (len <= 1)
                return;

        int x, y, i, j;
        x = len / 2;
        y = len - x;

        int left[x], right[y];
        for (i = 0; i < x; ++i)
                left[i] = data[i];

        for (i = 0; i < y; ++i)
                right[i] = data[x + i];

        merge_sort(left, x);
        merge_sort(right, y);
        merge(data, left, right, x, y);
}


void merge(int data[], int *left, int *right, int x, int y)
{
        int i = 0, j = 0, k = 0;

        while (i < x  && j < y) {
                if (left[i] < right[j]) {
                        data[k] = left[i];
                        i += 1;
                } else {
                        data[k] = right[j];
                        j += 1;
                }
                k += 1;
        }

        while (i < x) {
                data[k] = left[i];
                i += 1;
                k += 1;
        }

        while (j < y) {
                data[k] = right[j];
                j += 1;
                k += 1;
        }
}


int main()
{
        int data[] = {84, 13, 73, 26, 32, 19, 91, 38};
        int len = 8;
        merge_sort(data, len);

        int i;
        for (i = 0; i < len; ++i) {
                printf("%d ", data[i]);
        }
        printf("\n");

        return 0;
}
