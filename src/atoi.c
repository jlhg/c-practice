#include <stdio.h>

int atoi(char s[]);

int atoi(char s[])
{
        int i, n;

        n = 0;
        for (i = 0; s[i] != '\0'; ++i) {
                n = 10 * n + (s[i] - '0');
        }

        return n;
}

int main(void)
{
        char s[] = "hello";
        printf("%d\n", atoi(s));

        return 0;
}
