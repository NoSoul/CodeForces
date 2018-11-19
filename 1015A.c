#include <stdio.h>
#include <string.h>

int Cnt[102];

int main()
{
    int n, m, l, r;
    int ans[101];
    int remain = 0;
    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; ++i) {
        scanf("%d %d", &l, &r);
        ++Cnt[l];
        --Cnt[r + 1];
    }
    int cur = 0;
    for(int i = 1; i <= m; ++i) {
        cur += Cnt[i];
        if(cur == 0) {
            ans[remain++] = i;
        }
    }
    printf("%d\n", remain);
    for(int i = 0; i < remain; ++i) {
        printf("%d ", ans[i]);
    }
    puts("");
    return 0;
}
