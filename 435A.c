#include <stdio.h>

int main()
{
    int N, M, Sum, i, Num, Temp, Ans;
    scanf("%d %d", &N, &M);
    Temp = M;
    Ans = 0;
    for(i=0; i<N; ++i)
    {
        scanf("%d", &Num);
        if(Temp > Num)
        {
            Temp -= Num;
        }
        else if(Temp == Num)
        {
            ++Ans;
            Temp = M;
        }
        else
        {
            ++Ans;
            Ans += Num/M;
            Temp = M - Num %M;
        }
    }
    if(Temp != M)
    {
        ++Ans;
    }
    printf("%d\n", Ans);
    return 0;
}
