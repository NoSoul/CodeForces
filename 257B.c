#include <stdio.h>

int main()
{
    int N, M ;
    scanf("%d %d", &N, &M);
    if(N >= M)
    {
        printf("%d %d\n", N - 1, M);
    }
    else
    {
        printf("%d %d\n", M - 1, N);
    }
    return 0;
}
