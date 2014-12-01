#include <stdio.h>

int main()
{
    int N, D, i, Min = 0, Num, Ans = 0;
    scanf("%d %d", &N, &D);
    for(i = 0; i < N; ++i)
    {
        scanf("%d", &Num);
        Min += Num;
        Min += 10;
        Ans += 2;
    }
    Min -= 10;
    Ans -= 2;
    if(Min > D)
    {
        printf("-1\n");
    }
    else
    {
        printf("%d\n", Ans + (D - Min) / 5);
    }
    return 0;
}
