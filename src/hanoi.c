#include <stdio.h>

void hanoi(int n, char src, char buffer, char dst);

void hanoi(int n, char src, char buffer, char dst)
{
        if (n == 1) {
                printf("Move disk %d from %c to %c\n", n, src, dst);
        } else {
                hanoi(n - 1, src, dst, buffer);
                printf("Move disk %d from %c to %c\n", n, src, dst);
                hanoi(n - 1, buffer, src, dst);
        }
}

int main(void)
{
        int n = 3;
        hanoi(n, 'A', 'B', 'C');

        return 0;
}
