#include <stdio.h>

int main()
{
    int N;
    scanf("%d", &N);
    printf("%I64d\n", (1LL << (N + 1)) - 2);
    return 0;
}
