#include <stdio.h>

int main()
{
    int N, i, Num;
    long long Ans;
    scanf("%d", &N);
    Ans = N;
    for(i = 0; i < N; ++i)
    {
        scanf("%d", &Num);
        Ans += (long long)(i + 1) * (Num - 1);
    }
    printf("%I64d\n", Ans);
    return 0;
}
