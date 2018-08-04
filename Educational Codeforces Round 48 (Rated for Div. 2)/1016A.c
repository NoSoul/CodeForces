#include <stdio.h>

int main()
{
    int n, m, a, cur = 0;
    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; ++i) {
        scanf("%d", &a);
        cur += a;
        if(cur < m) {
            printf("%d\n", 0);
        } else {
            printf("%d\n", cur / m);
            cur %= m;
        }
    }
    return 0;
}
