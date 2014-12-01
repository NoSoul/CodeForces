#include <stdio.h>

int main()
{
    int N, K, a, b, Sum = 0;
    scanf("%d %d", &N, &K);
    while(N--)
    {
        scanf("%d %d", &a, &b);
        Sum += b - a + 1;
    }
    if(Sum % K == 0)
    {
        printf("0\n");
    }
    else
    {
        printf("%d\n", K - Sum % K);
    }
    return 0;
}
