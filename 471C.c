#include <stdio.h>

typedef long long LL_t;

int main()
{
    LL_t h, N, Ans, F, E;
    scanf("%I64d", &N);
    h = 1;
    Ans = 0;
    while(1)
    {
        F = h*2 + h*(h-1)/2*3;
        if(F > N)
        {
            break;
        }
        E = N - F;
        if(E % 3 == 0)
        {
            ++Ans;
        }
        ++h;
    }
    printf("%I64d\n", Ans);
    return 0;
}
