#include <stdio.h>

int main()
{
    int n, c, pre, t, ans = 1;
    scanf("%d %d", &n, &c);
    for(int i = 0; i < n; ++i) {
        scanf("%d", &t);
        if(i) {
            if(t - pre <= c) {
                ++ans;
            } else {
                ans = 1;
            }
        }
        pre = t;
    }
    printf("%d\n", ans);
    return 0;
}
