#include <stdio.h>

int main()
{
    int N, i;
    scanf("%d", &N);
    if(N & 1)
    {
        printf("-1\n");
        return 0;
    }
    for(i = 1; i <= N; i += 2)
    {
        printf("%d %d ", i + 1, i);
    }
    return 0;
}
