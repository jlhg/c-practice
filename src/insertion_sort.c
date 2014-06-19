#include <stdio.h>
#include <stdlib.h>


void insertion_sort(int *data, int len);


void insertion_sort(int *data, int len)
{
        int i, j, temp;
        for (i = 1; i < len; ++i) {
                temp = data[i];
                j = i - 1;
                while (j >= 0 && data[j] > temp) {
                        data[j + 1] = data[j];
                        j -= 1;
                }
                data[j + 1] = temp;
        }
}


int main(int argc, char *argv[])
{
        int data[] = {83, 31, 96, 17, 42, 14, 54};
        int len = 7;
        insertion_sort(data, len);

        int i;
        for (i = 0; i < len; ++i) {
                printf("%d ", data[i]);
        }
        printf("\n");

        return 0;
}
