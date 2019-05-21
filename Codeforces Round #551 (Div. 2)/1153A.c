#include <stdio.h>

int main()
{
    int n, t;
    scanf("%d %d", &n, &t);
    int s[101], d[101];
    int min = 0x7fffffff, ans = -1;
    for(int i = 1; i <= n; ++i) {
        scanf("%d %d", &s[i], &d[i]);
        int cur = 0;
        if(t <= s[i]) {
            cur = s[i];
        } else {
            cur = s[i] + (t - s[i] + d[i] - 1) / d[i] * d[i];
        }
        if(min > cur) {
            min = cur;
            ans = i;
        }
    }
    printf("%d\n", ans);
    return 0;
}
