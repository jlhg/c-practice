#include <stdio.h>


void hanoi(int n, char src, char buffer, char dst);


void hanoi(int n, char src, char buffer, char dst)
{
        if (n == 1) {
                printf("Move disk from %c to %c\n", src, dst);
        } else {
                hanoi(n - 1, src, dst, buffer);
                printf("Move disk from %c to %c\n", src, dst);
                hanoi(n - 1, buffer, src, dst);
        }
}


int main()
{
        int n = 3;
        hanoi(n, 'A', 'B', 'C');

        return 0;
}
