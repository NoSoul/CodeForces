#include <stdio.h>

int A[100000];

int main()
{
    int N, i, Ans, j;
    scanf("%d", &N);
    for(i = 0; i < N; ++i)
    {
        scanf("%d", &A[i]);
    }
    for(Ans = 0, i = N - 1; i > 0; --i)
    {
        if(A[i] < A[i - 1])
        {
            Ans = N - 1 - i + 1;
            break;
        }
    }
    if(Ans == 0)
    {
        puts("0");
        return 0;
    }
    for(i = N - Ans, j = 0; j < N - 1; ++j)
    {
        if(A[i] > A[(i + 1) % N])
        {
            puts("-1");
            return 0;
        }
        if(++i == N)
        {
            i = 0;
        }
    }
    printf("%d\n", Ans);
    return 0;
}
