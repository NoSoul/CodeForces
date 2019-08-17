#include <stdio.h>

int main()
{
    int n, k, a;
    int cnt[1001] = {0};
    scanf("%d %d", &n, &k);
    for(int i = 0; i < n; ++i) {
        scanf("%d", &a);
        ++cnt[a];
    }
    int ans = 0;
    for(int i = 1; i <= k; ++i) {
        ans += cnt[i] >> 1;
        cnt[i] &= 1;
    }
    ans <<= 1;
    int remain = 0;
    for(int i = 1; i <= k; ++i) {
        remain += cnt[i];
    }
    ans += (remain + 1) >> 1;
    printf("%d\n", ans);
    return 0;
}
