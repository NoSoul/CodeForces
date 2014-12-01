#include <stdio.h>
#include <string.h>

char Hash[100001];

int main()
{
    int N, i, j;
    int A[4];
    scanf("%d %d %d %d", &A[0], &A[1], &A[2], &A[3]);
    scanf("%d", &N);
    for(i = 0; i < 4; ++i)
    {
        for(j = A[i]; j <= N; j += A[i])
        {
            Hash[j] = 1;
        }
    }
    for(j = 0, i = 1; i <= N; ++i)
    {
        if(!Hash[i])
        {
            ++j;
        }
    }
    printf("%d\n", N - j);
    return 0;
}
