#include <stdio.h>

int main()
{
    int N, A, B;
    scanf("%d", &N);
    if(N >= 0)
    {
        printf("%d\n", N);
    }
    else
    {
        N = -N;
        if(N < 10)
        {
            printf("0\n");
        }
        else
        {
            A = (N / 100) * 10 + N % 10;
            B = N / 10;
            if(A < B)
            {
                printf("%d\n", -A);
            }
            else
            {
                printf("%d\n", -B);
            }
        }
    }
    return 0;
}
