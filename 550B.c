#include <stdio.h>

int main()
{
    int mask, n, l, r, x, i, Ans = 0;
    int C[15];
    scanf("%d %d %d %d", &n, &l, &r, &x);
    for(i = 0; i < n; ++i) {
        scanf("%d", &C[i]);
    }
    for(mask = 1; mask < (1 << n); ++mask) {
        int Min = 0x7f7f7f7f;
        int Max = 0;
        int CurSum = 0;
        for(i = 0; i < n; ++i) {
            if((1 << i)&mask) {
                CurSum += C[i];
                if(Min > C[i]) {
                    Min = C[i];
                }
                if(Max < C[i]) {
                    Max = C[i];
                }
            }
        }
        if(CurSum >= l && CurSum <= r && Max - Min >= x) {
            ++Ans;
        }
    }
    printf("%d\n", Ans);
    return 0;
}
