#include <stdio.h>

int main()
{
    int N, S, i, Max, Sum, Num;
    Sum = 0;
    scanf("%d %d", &N, &S);
    Max = 1;
    for(i = 0; i < N; ++i)
    {
        scanf("%d", &Num);
        if(Num > Max)
        {
            Max = Num;
        }
        Sum += Num;
    }
    if(Sum - Max <= S)
    {
        puts("YES");
    }
    else
    {
        puts("NO");
    }
    return 0;
}
