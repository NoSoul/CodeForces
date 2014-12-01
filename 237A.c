#include <stdio.h>

typedef struct
{
    int h, m;
} Time;
Time Now, Pre;

int main()
{
    int N, Max, Ans, Cnt;
    scanf("%d %d %d", &N, &Pre.h, &Pre.m);
    Ans = 1;
    Max = Cnt = 0;
    while(--N)
    {
        scanf("%d %d", &Now.h, &Now.m);
        if(Now.h == Pre.h && Now.m == Pre.m)
        {
            ++Cnt;
        }
        else
        {
            if(Cnt > Max)
            {
                Max = Cnt;
            }
            Cnt = 0;
            Pre = Now;
        }
    }
    if(Cnt > Max)
    {
        Max = Cnt;
    }
    printf("%d\n", Ans + Max);
    return 0;
}
