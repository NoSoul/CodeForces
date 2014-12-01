#include <stdio.h>
#include <string.h>

#define MAXN 100001

int Last[MAXN];
int Ans[MAXN];

int main()
{
    int N, Num, i, Now, Cnt;
    scanf("%d", &N);
    memset(Ans, -1, sizeof(Ans));
    for(i = 1; i <= N; ++i)
    {
        scanf("%d", &Num);
        if(Last[Num] == 0)
        {
            Ans[Num] = 0;
        }
        else
        {
            Now = i - Last[Num];
            if(Ans[Num] == 0)
            {
                Ans[Num] = Now;
            }
            else if(Ans[Num] != Now)
            {
                Ans[Num] = -1;
            }
        }
        Last[Num] = i;
    }
    for(Cnt = 0, i = 1; i < MAXN; ++i)
    {
        if(Ans[i] != -1)
        {
            ++Cnt;
        }
    }
    printf("%d\n", Cnt);
    for(i = 1; i < MAXN; ++i)
    {
        if(Ans[i] != -1)
        {
            printf("%d %d\n", i, Ans[i]);
        }
    }
    return 0;
}
