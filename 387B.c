#include <stdio.h>

int main()
{
    int N, M, i, j, Sum = 0;
    int A[3000];
    int B[3000];
    scanf("%d %d", &N, &M);
    for(i = 0; i < N; ++i)
    {
        scanf("%d", &A[i]);
    }
    for(i = 0; i < M; ++i)
    {
        scanf("%d", &B[i]);
    }
    for(i = 0; i < N; ++i)
    {
        for(j = 0; j < M; ++j)
        {
            if(B[j] >= A[i])
            {
                A[i] = B[j] = 0;
                break;
            }
        }
    }
    for(i = 0; i < N; ++i)
    {
        Sum += A[i] != 0;
    }
    printf("%d\n", Sum);
    return 0;
}
