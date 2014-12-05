#include <stdio.h>

int F[200000];
int S[200000];
int SizeF, SizeS;

int main()
{
    int N, i, a;
    long long Sum;
    scanf("%d", &N);
    Sum = 0;
    for(i = 0; i < N; ++i)
    {
        scanf("%d", &a);
        if(a > 0)
        {
            F[SizeF++] = a;
        }
        else
        {
            S[SizeS++] = -a;
        }
        Sum += a;
    }
    if(Sum > 0)
    {
        puts("first");
    }
    else if(Sum < 0)
    {
        puts("second");
    }
    else
    {
        for(i = 0; i < SizeF && i < SizeS; ++i)
        {
            if(F[i] > S[i])
            {
                puts("first");
                return 0;
            }
            else if(F[i] < S[i])
            {
                puts("second");
                return 0;
            }
        }
        if(SizeF > SizeS)
        {
            puts("first");
        }
        else if(SizeF < SizeS)
        {
            puts("second");
        }
        else
        {
            puts(a > 0 ? "first" : "second");
        }
    }
    return 0;
}
