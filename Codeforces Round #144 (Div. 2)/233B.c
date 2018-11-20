#include <stdio.h>
#include <math.h>

typedef __int64 LL;

int Cal(int x)
{
    int m = x, Sum = 0;
    while(x) {
        Sum += x % 10;
        x /= 10;
    }
    return Sum + m;
}

int main()
{
    int i, j, ans, cnt;
    LL N, M;
    scanf("%I64d", &N);
    j = sqrt(N);
    for(cnt = 0, ans = -1, i = j; i > 0; --i) {
        M = Cal(i);
        if((LL)i * Cal(i) == N) {
            ans = i;
        }
        if(M < j) {
            ++cnt;
            if(cnt == 30) {
                break;
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}
