#include <stdio.h>
#include <assert.h>


int maxprod(int data[], int len);
int maxprod_2(int data[], int len);

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

/* http://www.ptt.cc/bbs/Soft_Job/M.1404478881.A.E1B.html */
int maxprod_2(int data[], int len)
{
        assert(len >= 2);
        int i;
        int max = data[0] * data[1];
        int current = data[0];
        for (i = 1; i < len; ++i) {
                if (data[i] == 0)
                        current = 1;
                else
                        current *= data[i];
                if (current > max)
                        max = current;
        }

        current = data[len - 1];
        for (i = len - 2; i >= 0; --i) {
                if (data[i] == 0)
                        current = 1;
                else
                        current *= data[i];
                if (current > max)
                        max = current;
        }

        return max;
}


int main()
{
        int data[] = {2, -7, 0, 2, 3, 8, -6, 5};
        printf("Case 1: %d\n", maxprod_2(data, 8));

        int data_2[] = {-2, 0, 3, 5, -7};
        printf("Case 2: %d\n", maxprod_2(data_2, 5));

        int data_3[] = {-2, 1, 3};
        printf("Case 3: %d\n", maxprod_2(data_3, 3));

        int data_4[] = {-2, 2, 2, -2};
        printf("Case 4: %d\n", maxprod_2(data_4, 4));

        int data_5[] = {2, 4, -3};
        printf("Case 5: %d\n", maxprod_2(data_5, 3));

        int data_6[] = {2, 5, -1, 2, -1};
        printf("Case 6: %d\n", maxprod_2(data_6, 5));

        int data_7[] = {-1, -2, -3, -4, -5, -6, -7};
        printf("Case 7: %d\n", maxprod_2(data_7, 7));

        return 0;
}
