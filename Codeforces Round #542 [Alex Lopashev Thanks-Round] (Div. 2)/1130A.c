#include <stdio.h>

int main()
{
    int n, a, pCnt = 0, nCnt = 0;
    scanf("%d", &n);
    for(int i = 0; i < n; ++i) {
        scanf("%d", &a);
        pCnt += a > 0;
        nCnt += a < 0;
    }
    if(pCnt >= (n + 1) / 2) {
        puts("1");
    } else if(nCnt >= (n + 1) / 2) {
        puts("-1");
    } else {
        puts("0");
    }
    return 0;
}
