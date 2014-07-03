#include <stdio.h>
#include <assert.h>


int maxprod(int data[], int len);

int maxprod(int data[], int len)
{
        assert(len >= 2);
        int i, j, current;
        int max = data[0] * data[1];
        for (i = 0; i < len - 1; ++i) {
                current = data[i];
                for (j = i + 1; j < len; ++j) {
                        current *= data[j];
                        if (current == 0) {
                                if (current > max)
                                        max = current;
                                break;
                        }
                        if (current > max)
                                max = current;
                }
        }

        return max;
}


int main()
{
        int data[] = {2, -7, 0, 2, 3, 8, -6, 5};
        printf("Case 1: %d\n", maxprod(data, 8));

        int data_2[] = {-2, 0, 3, 5, -7};
        printf("Case 2: %d\n", maxprod(data_2, 5));

        int data_3[] = {-2, 1, 3};
        printf("Case 3: %d\n", maxprod(data_3, 3));

        int data_4[] = {-2, 2, 2, -2};
        printf("Case 4: %d\n", maxprod(data_4, 4));

        int data_5[] = {2, 4, -3};
        printf("Case 5: %d\n", maxprod(data_5, 3));

        int data_6[] = {2, 5, -1, 2, -1};
        printf("Case 6: %d\n", maxprod(data_6, 5));

        return 0;
}
