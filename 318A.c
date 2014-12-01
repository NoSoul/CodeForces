#include <stdio.h>

typedef long long LL_t;

int main()
{
    LL_t N, K, Mid;
    scanf("%I64d %I64d", &N, &K);
    Mid = (N + 1) / 2;
    if(K <= Mid)
    {
        printf("%I64d\n", 2 * K - 1);
    }
    else
    {
        K -= Mid;
        printf("%I64d\n", 2 * K);
    }
    return 0;
}
