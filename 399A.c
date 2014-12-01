#include <stdio.h>

int main()
{
    int N, P, K, Min, Max, i;
    scanf("%d %d %d", &N, &P, &K);
    Min = P - K;
    Max = P + K;
    if(Min < 1)
    {
        Min = 1;
    }
    if(Max > N)
    {
        Max = N;
    }
    if(Min != 1)
    {
        printf("<< ");
    }
    for(i = 0; i < K && Min + i < P; ++i)
    {
        printf("%d ", Min + i);
    }
    printf("(%d) ", P);
    for(i = 1; i < K + 1 && P + i <= Max; ++i)
    {
        printf("%d ", P + i);
    }
    if(Max != N)
    {
        printf(">>");
    }
    return 0;
}
