#include <stdio.h>
#include <stdlib.h>

int main()
{
    int t;
    scanf("%d", &t);
    while(t--) {
        int n, x, a, b;
        scanf("%d %d %d %d", &n, &x, &a, &b);
        int ans = abs(a - b);
        ans += x;
        if(ans > n - 1) {
            ans = n - 1;
        }
        printf("%d\n", ans);
    }
    return 0;
}
