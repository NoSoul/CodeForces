#include <stdio.h>

int main()
{
    int N, i, curMin = 1, curMax = 9;
    long long Ans = 0;
    scanf("%d", &N);
    for(i = 1; i <= 10; ++i) {
        if(N <= curMax) {
            Ans += (long long)(N - curMin + 1) * i;
            break;
        } else {
            Ans += (long long)(curMax - curMin + 1) * i;
        }
        curMin *= 10;
        curMax *= 10;
        curMax += 9;
    }
    printf("%I64d\n", Ans);
    return 0;
}
