#include <stdio.h>

int main()
{
    int N, i, Sum = 0;
    int A[300];
    scanf("%d", &N);
    for(i = 0; i < N; ++i)
    {
        scanf("%d", &A[i]);
        Sum += A[i];
    }
    while(1)
    {
        for(i = 0; i < N - 1; ++i)
        {
            if(A[i])
            {
                printf("P");
                --A[i];
                if(--Sum == 0)
                {
                    return 0;
                }
            }
            printf("R");
        }
        for(i = N - 1; i > 0; --i)
        {
            if(A[i])
            {
                printf("P");
                --A[i];
                if(--Sum == 0)
                {
                    return 0;
                }
            }
            printf("L");
        }
    }
    return 0;
}
