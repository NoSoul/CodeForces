#include <stdio.h>

char flag[10];

int main()
{
    int n, m;
    int x[10], y;
    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; ++i) {
        scanf("%d", &x[i]);
    }
    for(int i = 0; i < m; ++i) {
        scanf("%d", &y);
        flag[y] = 1;
    }
    for(int i = 0; i < n; ++i) {
        if(flag[x[i]]) {
            printf("%d ", x[i]);
        }
    }
    return 0;
}
