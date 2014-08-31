#include <stdio.h>

int main()
{
    int N, i, Pre, Num, Sum, Ans, first;
    scanf("%d", &N);
    scanf("%d", &Num);
    if(N == 1)
    {
        printf("%d\n", Num);
        return 0;
    }
    Pre = Num;
    first = Num;
    Ans = 0;
    Sum = 0;
    for(i=1; i<N; ++i)
    {
        scanf("%d", &Num);
        if(Pre - Num + Sum < 0)
        {
            Ans += -(Pre - Num + Sum);
            Sum = 0;
        }
        else
        {
            Sum += Pre - Num;
        }
        Pre = Num;
    }
    printf("%d\n", Ans+first);
    return 0;
}
