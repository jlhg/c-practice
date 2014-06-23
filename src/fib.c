/* Fibonacci Sequence */
#include <stdio.h>

int fib(int n);
int fib_2(int n);

int fib(int n) {
        if (n == 0 || n == 1)
                return n;

        return fib(n - 1) + fib(n - 2);
}

int fib_2(int n) {
        if (n == 0 || n == 1)
                return n;

        int i;
        int data[n];
        data[0] = 0;
        data[1] = 1;

        for (i = 2; i <= n; ++i)
                data[i] = data[i - 1] + data[i - 2];

        return data[n];
}

int main()
{
        int n = 6;
        printf("%d\n", fib(n));
        printf("%d\n", fib_2(n));

        return 0;
}
