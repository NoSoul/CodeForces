#include <stdio.h>

int main()
{
    int N;
    scanf("%d", &N);
    N -= 2;
    printf("%I64d\n", (long long)N * N);
    return 0;
}
