#include <stdio.h>

int main()
{
    int n, a;
    long long ans = 0;
    int cnt[2] = {0};
    scanf("%d", &n);
    for(int i = 0; i < n; ++i) {
        scanf("%d", &a);
        if(a > 0) {
            ans += a - 1;
        } else if(a < 0) {
            ans += -1 - a;
            ++cnt[1];
        } else {
            ++cnt[0];
        }
    }
    if((cnt[1] & 1) == 0) {
        ans += cnt[0];
    } else {
        if(cnt[0]) {
            ans += cnt[0];
        } else {
            ans += 2;
        }
    }
    printf("%I64d\n", ans);
    return 0;
}
