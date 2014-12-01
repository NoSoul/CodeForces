#include <stdio.h>

int A[100], B[100];
char Flag[100];

int main()
{
    int N, i, j, Sum;
    scanf("%d", &N);
    for(i = 0; i < N; ++i)
    {
        scanf("%d %d", &A[i], &B[i]);
    }
    for(i = 0; i < N; ++i)
    {
        for(j = 0; j < N; ++j)
        {
            if(i != j && B[i] == A[j])
            {
                Flag[j] = 1;
            }
        }
    }
    for(Sum = i = 0; i < N; ++i)
    {
        Sum += Flag[i] ^ 1;
    }
    printf("%d\n", Sum);
    return 0;
}
