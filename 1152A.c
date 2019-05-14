#include <stdio.h>

int Min(int a, int b)
{
    return a < b ? a : b;
}

int main()
{
    int n, m, x;
    int a[2] = {0}, b[2] = {0};
    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; ++i) {
        scanf("%d", &x);
        ++a[x & 1];
    }
    for(int i = 0; i < m; ++i) {
        scanf("%d", &x);
        ++b[x & 1];
    }
    printf("%d\n", Min(a[0], b[1]) + Min(a[1], b[0]));
    return 0;
}
