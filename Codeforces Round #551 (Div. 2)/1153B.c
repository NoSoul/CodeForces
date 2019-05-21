#include <stdio.h>

int Min(int a, int b)
{
    return a < b ? a : b;
}

int main()
{
    int n, m, h, t;
    int a[100], b[100];
    scanf("%d %d %d", &n, &m, &h);
    for(int i = 0; i < m; ++i) {
        scanf("%d", &a[i]);
    }
    for(int i = 0; i < n; ++i) {
        scanf("%d", &b[i]);
    }
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) {
            scanf("%d", &t);
            if(t) {
                printf("%d ", Min(b[i], a[j]));
            } else {
                printf("0 ");
            }
        }
        puts("");
    }
    return 0;
}
