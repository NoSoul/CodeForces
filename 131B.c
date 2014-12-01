#include <stdio.h>

__int64 Hash[21];

int main()
{
    int N, i;
    __int64 sum;
    scanf("%d", &N);
    while(N--)
    {
        scanf("%d", &i);
        ++Hash[i + 10];
    }
    for(sum = i = 0; i < 10; ++i)
    {
        sum += Hash[i] * Hash[20 - i];
    }
    sum += Hash[10] * (Hash[10] - 1) / 2;
    printf("%I64d\n", sum);
    return 0;
}
