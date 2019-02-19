#include <stdio.h>

int Cnt[4];

int main()
{
    int n, a;
    scanf("%d", &n);
    for(int i = 0; i < n; ++i) {
        scanf("%d", &a);
        ++Cnt[a];
    }
    int ans = Cnt[2] + Cnt[3];
    if(ans > Cnt[1] + Cnt[3]) {
        ans = Cnt[1] + Cnt[3];
    }
    if(ans > Cnt[1] + Cnt[2]) {
        ans = Cnt[1] + Cnt[2];
    }
    printf("%d\n", ans);
    return 0;
}
