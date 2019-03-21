#include <stdio.h>

int Cnt[101];

int main()
{
    int n, k, a, max = 0;
    scanf("%d %d", &n, &k);
    for(int i = 0; i < n; ++i) {
        scanf("%d", &a);
        ++Cnt[a];
        if(max < Cnt[a]) {
            max = Cnt[a];
        }
    }
    if(max % k != 0) {
        max += k - 1;
        max /= k;
        max *= k;
    }
    int ans = 0;
    for(int i = 1; i < 101; ++i) {
        if(Cnt[i]) {
            ans += max - Cnt[i];
        }
    }
    printf("%d\n", ans);
    return 0;
}
