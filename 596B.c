#include <stdio.h>
#include <stdlib.h>

int main()
{
    int N, i, num;
    long long Ans, Off;
    Ans = 0;
    Off = 0;
    scanf("%d", &N);
    for(i = 0; i < N; ++i) {
        scanf("%d", &num);
        Ans += abs(num - Off);
        Off += num - Off;
    }
    printf("%I64d\n", Ans);
    return 0;
}
