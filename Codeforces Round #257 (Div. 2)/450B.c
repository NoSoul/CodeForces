#include <stdio.h>

#define MOD 1000000007

int main()
{
    int x, y, N, Ans;
    scanf("%d %d %d", &x, &y, &N);
    --N;
    if(N % 6 == 0) {
        Ans = x % MOD;
    } else if(N % 6 == 1) {
        Ans = y % MOD;
    } else if(N % 6 == 2) {
        Ans = (y - x) % MOD;
    } else if(N % 6 == 3) {
        Ans = (-x) % MOD;
    } else if(N % 6 == 4) {
        Ans = (-y) % MOD;
    } else if(N % 6 == 5) {
        Ans = (-y + x) % MOD;
    }
    if(Ans < 0) {
        Ans += MOD;
    }
    printf("%d\n", Ans);
    return 0;
}
