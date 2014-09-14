#include <stdio.h>

int main()
{
    int N, i, Pre, Num, Ans;
    scanf("%d", &N);
    Pre = -1;
    Ans = 0;
    for(i=0; i<N; ++i)
    {
        scanf("%d ", &Num);
        if(Num == 1)
        {
            if(Pre == -1)
            {
                Ans = 1;
            }
            else
            {
                if(i-Pre >= 2)
                {
                    Ans += 2;
                }
                else
                {
                    ++Ans;
                }
            }
            Pre = i;
        }
    }
    printf("%d\n", Ans);
    return 0;
}
