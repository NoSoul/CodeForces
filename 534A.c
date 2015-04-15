#include <stdio.h>

int main()
{
    int N;
    scanf("%d", &N);
    if(N <= 2)
    {
        printf("1\n1\n");
    }
    else if(N == 3)
    {
        printf("2\n1 3\n");
    }
    else
    {
        printf("%d\n", N);
        int i;
        for(i = 2; i <= N; i += 2)
        {
            printf("%d ", i);
        }
        for(i = 1; i <= N; i += 2)
        {
            printf("%d ", i);
        }
        puts("");
    }
    return 0;
}
