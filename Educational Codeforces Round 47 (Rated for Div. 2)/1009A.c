#include <stdio.h>

int main()
{
    int n, m;
    int c[1000];
    int a[1000];
    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; ++i) {
        scanf("%d", &c[i]);
    }
    for(int i = 0; i < m; ++i) {
        scanf("%d", &a[i]);
    }
    int i = 0, j = 0;
    int ans = 0;
    while(i < n && j < m) {
        if(a[j] >= c[i]) {
            ++j;
            ++ans;
        }
        ++i;
    }
    printf("%d\n", ans);
    return 0;
}
