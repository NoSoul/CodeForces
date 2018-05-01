#include <stdio.h>

int Cnt[1001];

int main()
{
    int n, m, c, ans;
    scanf("%d %d", &n, &m);
    for(int i = 0; i < m; ++i) {
        scanf("%d", &c);
        ++Cnt[c - 1];
    }
    ans = Cnt[0];
    for(int i = 1; i < n; ++i) {
        if(ans > Cnt[i]) {
            ans = Cnt[i];
        }
    }
    printf("%d\n", ans);
    return 0;
}
