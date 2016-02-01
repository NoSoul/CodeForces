#include <stdio.h>

int CntA[2000];
int CntB[2000];

int GetIdxInA(int x, int y)
{
    return x + y;
}

int GetIdxInB(int x, int y)
{
    int xprime = y;
    int yprime = 1000 - 1 - x;
    return xprime + yprime;
}

int main()
{
    int N, x, y;
    long long Ans = 0;
    scanf("%d", &N);
    while(N--) {
        scanf("%d %d", &x, &y);
        --x;
        --y;
        ++CntA[GetIdxInA(x, y)];
        ++CntB[GetIdxInB(x, y)];
    }
    for(x = 0; x < 2000; ++x) {
        Ans += CntA[x] * (CntA[x] - 1) / 2;
    }
    for(x = 0; x < 2000; ++x) {
        Ans += CntB[x] * (CntB[x] - 1) / 2;
    }
    printf("%I64d\n", Ans);
    return 0;
}
