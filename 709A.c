#include <stdio.h>

int main()
{
    int n, b, d, a, cur = 0, ans = 0;
    scanf("%d %d %d", &n, &b, &d);
    for(int i = 0; i < n; ++i) {
        scanf("%d", &a);
        if(a <= b) {
            cur += a;
            if(cur > d) {
                ++ans;
                cur = 0;
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}
