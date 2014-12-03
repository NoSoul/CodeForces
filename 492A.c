#include <stdio.h>

int main()
{
    int Ans, Sum, N;
    scanf("%d", &N);
    Ans = 0;
    Sum = 0;
    while(1)
    {
        ++Ans;
        Sum += Ans;
        N -= Sum;
        if(N == 0)
        {
            break;
        }
        if(N < 0)
        {
            --Ans;
            break;
        }
    }
    printf("%d\n", Ans);
    return 0;
}
