#include <stdio.h>

int main()
{
    int N, K;
    scanf("%d %d", &N, &K);
    N = N / K;
    ++N;
    printf("%I64d\n", (long long)N * K);
    return 0;
}
