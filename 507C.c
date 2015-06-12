#include <stdio.h>

int main()
{
    char goL = 1;
    int H;
    long long N, M, Ans = 0;
    scanf("%d %I64d", &H, &N);
    M = 1LL << H;
    while(H) {
        if(goL) {
            if(N > (M >> 1)) {
                Ans += M;
                N -= M >> 1;
            } else {
                ++Ans;
                goL = 0;
            }
        } else {
            if(N <= (M >> 1)) {
                Ans += M;
            } else {
                ++Ans;
                goL = 1;
                N -= M >> 1;
            }
        }
        --H;
        M = 1LL << H;
    }
    printf("%I64d\n", Ans);
    return 0;
}
