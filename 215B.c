#include <stdio.h>

int F(int id)
{
    int N, i, Max, Min, Now;
    Min = 0x7fffffff;
    Max = 0;
    scanf("%d", &N);
    for(i = 0; i < N; ++i)
    {
        scanf("%d", &Now);
        if(Now > Max)
        {
            Max = Now;
        }
        if(Now < Min)
        {
            Min = Now;
        }
    }
    if(id)
    {
        return Max;
    }
    return Min;
}

int main()
{
    int R1, P1, P2, i, A, B;
    double R2;
    R1 = F(1);
    P1 = F(1);
    P2 = F(0);
    scanf("%d %d", &A, &B);
    R2 = 1.0 * B * P1 * R1 * R1 / (A * P2 + B * P1);
    printf("%.12f\n", sqrt(R2));
    return 0;
}
