#include <stdio.h>

int Cnt[101];

int main()
{
    int n, k, a, ans = 0;
    scanf("%d %d", &n, &k);
    for(int i = 0; i < n; ++i) {
        scanf("%d", &a);
        ++Cnt[a];
    }
    while(1) {
        char update = 0;
        for(int i = k - 1; i >= 1; --i) {
            if(Cnt[i]) {
                --Cnt[i];
                ++Cnt[i + 1];
                update = 1;
            }
        }
        if(!update) {
            break;
        }
        ans += update;
    }
    printf("%d\n", ans);
    return 0;
}
