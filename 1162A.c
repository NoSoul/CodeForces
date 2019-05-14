#include <stdio.h>

int main()
{
    int n, h, m;
    char height[51] = {0};
    scanf("%d %d %d", &n, &h, &m);
    for(int i = 1; i <= n; ++i) {
        height[i] = h;
    }
    for(int i = 0; i < m; ++i) {
        int l, r, x;
        scanf("%d %d %d", &l, &r, &x);
        for(int j = l; j <= r; ++j) {
            if(height[j] > x) {
                height[j] = x;
            }
        }
    }
    int ans = 0;
    for(int i = 1; i <= n; ++i) {
        ans += height[i] * height[i];
    }
    printf("%d\n", ans);
    return 0;
}
