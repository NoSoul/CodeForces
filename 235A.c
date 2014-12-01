#include <stdio.h>

int main()
{
    int N;
    while(scanf("%d", &N) != EOF)
    {
        if(N < 3)
        {
            printf("%d\n", N);
            continue;
        }
        if(N & 1)
        {
            printf("%I64d\n", (__int64)N * (N - 1) * (N - 2));
        }
        else
        {
            if(N % 3 == 0)
            {
                printf("%I64d\n", (__int64)(N - 1) * (N - 2) * (N - 3));
            }
            else
            {
                printf("%I64d\n", (__int64)N * (N - 1) * (N - 3));
            }
        }
    }
    return 0;
}
