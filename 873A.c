#include <stdio.h>

int main()
{
    int n, k, x, a;
    scanf("%d %d %d", &n, &k, &x);
    int ans = k * x;
    for(int i = 0; i < n; ++i) {
        scanf("%d", &a);
        if(i < (n - k)) {
            ans += a;
        }
    }
    printf("%d\n", ans);
    return 0;
}
