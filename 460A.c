#include <stdio.h>

int main()
{
    int N, M, Sum;
    scanf("%d %d", &N, &M);
    Sum = N;
    while(N >= M)
    {
        Sum += N / M;
        N = N / M + N % M;
    }
    printf("%d\n", Sum);
    return 0;
}
