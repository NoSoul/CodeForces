#include <stdio.h>

int main()
{
    int N, i, Num, Sum, Ans;
    scanf("%d", &N);
    for(Ans=Sum=i=0; i<N; ++i)
    {
        scanf("%d", &Num);
        if(Num == -1)
        {
            if(Sum > 0)
            {
                --Sum;
            }
            else
            {
                ++Ans;
            }
        }
        else
        {
            Sum += Num;
        }
    }
    printf("%d\n", Ans);
    return 0;
}
