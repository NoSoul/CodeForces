#include <stdio.h>

int Cnt[100001];

int main()
{
    int n, a, ans = 1;
    scanf("%d", &n);
    for(int i = 0; i < n; ++i) {
        scanf("%d", &a);
        ++Cnt[a];
    }
    for(int i = 2; i <= 100001; ++i) {
        int cur = 0;
        for(int j = i; j < 100001; j += i) {
            cur += Cnt[j];
        }
        if(ans < cur) {
            ans = cur;
        }
    }
    printf("%d\n", ans);
    return 0;
}
