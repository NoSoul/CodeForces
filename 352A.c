#include <stdio.h>

int main()
{
    int N, i, j, Num, Cnt, Mod, Ans;
    scanf("%d", &N);
    for(Cnt = i = 0; i < N; ++i)
    {
        scanf("%d", &Num);
        if(Num == 5)
        {
            ++Cnt;
        }
    }
    if(Cnt == N)
    {
        puts("-1");
        return 0;
    }
    Ans = 0;
    for(i = Cnt; i >= 0; --i)
    {
        Mod = 0;
        for(j = 0; j < i; ++j)
        {
            Mod *= 10;
            Mod += 5;
            Mod %= 9;
        }
        if(Mod == 0)
        {
            Ans = i;
            break;
        }
    }
    if(Ans == 0)
    {
        puts("0");
        return 0;
    }
    for(i = 0; i < Ans; ++i)
    {
        printf("5");
    }
    for(i = 0; i < N - Cnt; ++i)
    {
        printf("0");
    }
    return 0;
}
