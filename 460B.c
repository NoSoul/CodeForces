#include <stdio.h>
#include <stdlib.h>

typedef __int64 LL_t;

int cmp(const void *a, const void *b)
{
    return *(LL_t *)a - *(LL_t *)b;
}

LL_t Pow(LL_t i, LL_t n)
{
    LL_t ret = 1;
    while(n--)
    {
        ret *= i;
    }
    return ret;
}

LL_t Fun(LL_t Num)
{
    LL_t ret = 0;
    while(Num)
    {
        ret += Num%10;
        Num /= 10;
    }
    return ret;
}

int main()
{
    LL_t A, B, C, i, Cnt;
    LL_t Data[100];
    scanf("%I64d %I64d %I64d", &A, &B, &C);
    for(Cnt=0, i=1; i<82; ++i)
    {
        LL_t Num = Pow(i, A)*B+C;
        if(Fun(Num) == i && Num>0 && Num<1e9)
        {
            Data[Cnt++] = Num;
        }
    }
    printf("%I64d\n", Cnt);
    qsort(Data, Cnt, sizeof(LL_t), cmp);
    for(i=0; i<Cnt; ++i)
    {
        printf("%I64d ", Data[i]);
    }
    return 0;
}
