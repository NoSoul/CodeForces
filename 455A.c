#include <stdio.h>

#define MAXN    100001
typedef __int64 LL_t;

int main()
{
    int N, Num, Max;
    LL_t i;
    LL_t Sum[MAXN];
    int Cnt[MAXN];
    scanf("%d", &N);
    Max = 0;
    for(i = 0; i < N; ++i)
    {
        scanf("%d", &Num);
        ++Cnt[Num];
        if(Num > Max)
        {
            Max = Num;
        }
    }
    Sum[0] = 0;
    Sum[1] = Cnt[1];
    for(i = 2; i <= Max; ++i)
    {
        Sum[i] = (Sum[i - 1] > (Sum[i - 2] + Cnt[i] * i)) ? Sum[i - 1] : Sum[i - 2] + Cnt[i] * i;
    }
    printf("%I64d\n", Sum[Max]);
    return 0;
}
