#include <stdio.h>

int main()
{
    int t;
    scanf("%d", &t);
    while(t--) {
        int n, a;
        scanf("%d", &n);
        int cnt[3] = {0};
        for(int i = 0; i < n; ++i) {
            scanf("%d", &a);
            ++cnt[a % 3];
        }
        int min = cnt[1];
        if(min > cnt[2]) {
            min = cnt[2];
        }
        cnt[0] += min;
        cnt[1] -= min;
        cnt[2] -= min;
        printf("%d\n", cnt[0] + cnt[1] / 3 + cnt[2] / 3);
    }
    return 0;
}
