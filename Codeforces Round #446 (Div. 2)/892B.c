#include <stdio.h>
int Cnt[1000001];

int main()
{
    int n, L;
    scanf("%d", &n);
    for(int i = 1; i <= n; ++i) {
        scanf("%d", &L);
        int start = i - L;
        if(start < 1) {
            start = 1;
        }
        ++Cnt[start];
        --Cnt[i];
    }
    int cur = 0, ans = 0;
    for(int i = 1; i <= n; ++i) {
        cur += Cnt[i];
        if(cur == 0) {
            ++ans;
        }
    }
    printf("%d\n", ans);
    return 0;
}
