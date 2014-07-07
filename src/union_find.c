#include <stdio.h>

void init(int par[], int rank[], int n);
int find(int par[], int x);
void unite(int par[], int rank[], int x, int y);
int same(int par[], int x, int y);

void init(int par[], int rank[], int n)
{
        int i;
        for (i = 0; i < n; ++i) {
                par[i] = i;
                rank[i] = 0;
        }
}

int find(int par[], int x)
{
        if (par[x] == x) {
                return x;
        } else {
                return par[x] = find(par, par[x]);
        }
}

void unite(int par[], int rank[], int x, int y)
{
        x = find(par, x);
        y = find(par, y);

        if (x == y)
                return;

        if (rank[x] < rank[y]) {
                par[x] = y;
        } else {
                par[y] = x;
                if (rank[x] == rank[y])
                        ++rank[x];
        }
}

int same(int par[], int x, int y)
{
        return find(par, x) == find(par, y);
}

int main()
{
        int i;
        int len = 10;
        int par[len];
        int rank[len];
        init(par, rank, len);
        unite(par, rank, 2, 1);

        for (i = 0; i < len; ++i)
                printf("%d\n", par[i]);

        return 0;
}
