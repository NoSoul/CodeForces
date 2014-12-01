#include <stdio.h>

int main()
{
    int D, N, num;
    __int64 Sum = 0;
    scanf("%d %d", &D, &N);
    while(--N)
    {
        scanf("%d", &num);
        Sum += D - num;
    }
    printf("%I64d\n", Sum);
    return 0;
}
