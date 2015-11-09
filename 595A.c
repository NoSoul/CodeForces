#include <stdio.h>

int main()
{
    int N, M, a, b, i;
    scanf("%d %d", &N, &M);
    N *= M;
    M = 0;
    for(i = 0; i < N; ++i) {
        scanf("%d %d", &a, &b);
        M += a | b;
    }
    printf("%d\n", M);
    return 0;
}
