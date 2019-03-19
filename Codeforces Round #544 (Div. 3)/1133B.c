#include <stdio.h>

int Cnt[100];

int main()
{
    int n, k, d;
    scanf("%d %d", &n, &k);
    for(int i = 0; i < n; ++i) {
        scanf("%d", &d);
        ++Cnt[d % k];
    }
    int ans = 0;
    for(int i = 0; i <= k / 2; ++i) {
        int j = (k - i) % k;
        if(i == j) {
            ans += Cnt[i] / 2;
        } else {
            ans += Cnt[i] < Cnt[j] ? Cnt[i] : Cnt[j];
        }
    }
    printf("%d\n", ans * 2);
    return 0;
}
