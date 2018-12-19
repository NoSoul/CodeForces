#include <stdio.h>

int main()
{
    int A, B, x, y, z;
    long long yCnt, bCnt, ans;
    ans = yCnt = bCnt = 0;
    scanf("%d %d %d %d %d", &A, &B, &x, &y, &z);
    yCnt += 2LL * x + y;
    bCnt += 3LL * z + y;
    if(A < yCnt) {
        ans += yCnt - A;
    }
    if(B < bCnt) {
        ans += bCnt - B;
    }
    printf("%I64d\n", ans);
    return 0;
}
