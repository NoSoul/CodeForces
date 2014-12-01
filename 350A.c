#include <stdio.h>

int A[100], B[100];

int main()
{
    int N, M, i, Min, Max, Extra;
    scanf("%d %d", &N, &M);
    Min = 100, Max = 1, Extra = 100;
    for(i = 0; i < N; ++i)
    {
        scanf("%d", &A[i]);
        if(A[i] > Max)
        {
            Max = A[i];
        }
        if(A[i] < Extra)
        {
            Extra = A[i];
        }
    }
    for(i = 0; i < M; ++i)
    {
        scanf("%d", &B[i]);
        if(B[i] < Min)
        {
            Min = B[i];
        }
    }
    for(i = Max; i < Min; ++i)
    {
        if(i / Extra >= 2)
        {
            printf("%d\n", i);
            return 0;
        }
    }
    printf("-1\n");
    return 0;
}
