#include <stdio.h>

int main()
{
    int n, v;
    scanf("%d %d", &n, &v);
    int ans = 0;
    int cur = 0;
    for(int i = 1; i <= n; ++i) {
        if(i + v >= n) {
            ans += (n - i - cur) * i;
            break;
        }
        ans += (v - cur) * i;
        cur = v - 1;
    }
    printf("%d\n", ans);
    return 0;
}
