#include <stdio.h>

int Flag[1000001];

int main()
{
    int n, K, a;
    scanf("%d %d", &n, &K);
    for(int i = 0; i < n; ++i) {
        scanf("%d", &a);
        ++Flag[a];
    }
    int pre = -1, ans = 0;
    for(int i = 1; i < 1000001; ++i) {
        if(Flag[i]) {
            if(pre == -1) {
                pre = i;
            } else {
                if(i <= pre + K) {
                    pre = i;
                } else {
                    ans += Flag[pre];
                    pre = i;
                }
            }
        }
    }
    ans += Flag[pre];
    printf("%d\n", ans);
    return 0;
}
