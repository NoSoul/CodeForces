#include <stdio.h>

int main()
{
    long long N, Exp, Num, Min, Ans;
    scanf("%I64d", &N);
    Exp = 1;
    char flag = 1;
    Ans = 0;
    while(Exp <= N * 3)
    {
        if(N % Exp != 0)
        {
            Num = (N + Exp - 1) / Exp;
            if(flag)
            {
                Min = Num * Exp;
                Ans = Num;
                flag = 0;
            }
            else
            {
                if(Num * Exp < Min)
                {
                    Min = Num * Exp;
                    Ans = Num;
                }
            }
        }
        Exp *= 3;
    }
    printf("%I64d\n", Ans);
    return 0;
}
