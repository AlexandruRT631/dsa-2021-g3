#include <stdio.h>
#include <stdlib.h>

long long table[200][200];

int path(int n, int m) {
    if (table[n-1][m-1] != 0)
        return table[n-1][m-1];
    table[n-1][m-1] = path(n-1, m)+ path(n, m-1)+ path(n-1, m-1);
    return table[n-1][m-1];
}

int main()
{
    int n, m;
    int i;
    printf("n=");
    scanf("%d", &n);
    printf("m=");
    scanf("%d", &m);
    for (i=0; i<n; i++)
        table[i][0] = 1;
    for (i=1; i<m; i++)
        table[0][i] = 1;
    printf("Path length = %d", path (n, m));
    return 0;
}
