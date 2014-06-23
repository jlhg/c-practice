#include <stdio.h>

int gcd(int i, int j);

int gcd(int i, int j)
{
        int k = i % j;
        if (k == 0) {
                return j;
        } else {
                return gcd(j, k);
        }
}

int main(void)
{
        int i = 10;
        int j = 12;
        printf("%d\n", gcd(i, j));

        return 0;
}
