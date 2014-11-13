#include <stdio.h>

int main()
{
    long long N;
    scanf("%I64d", &N);
    if((N&1) == 0)
    {
        printf("%I64d\n", N/2);
    }
    else
    {
        printf("%I64d\n", (N-1)/2-N);
    }
    return 0;
}
